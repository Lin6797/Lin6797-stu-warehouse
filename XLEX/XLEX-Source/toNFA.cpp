#include "toNFA.h"

struct nfa{int start,end;};

toNFA::toNFA(){}

//预处理
string toNFA::Pre(string init){

    //插入连接运算符
    for(int i=0; i<init.length()-1; i++){
        if((init[i]>='a' && init[i]<='z') || ( init[i]>='A' && init[i]<='Z') || ( init[i]>='0' && init[i]<='9')){
            if(init[i+1]=='|' || init[i+1]==')'){}
            else { init.insert(i+1,"$"); }
        }
        if(init[i]=='*' && ((init[i+1]>='a' && init[i+1]<='z') || ( init[i+1]>='A' && init[i+1]<='Z') || ( init[i+1]>='0' && init[i+1]<='9') )){
            init.insert(i+1,"$");
        }
    }

    //获取标识符
    for(int i=0; i<init.length(); i++){
        if((init[i]>='a' && init[i]<='z') || ( init[i]>='A' && init[i]<='Z') || ( init[i]>='0' && init[i]<='9')){
            if(symbol.find(init[i]) > init.length()){
                symbol += init[i];
            }
        }
    }

    //改为后缀表达式
    enum Caculate{left=61,right=16,chose=23,link=14,page=52};
    string init_changed; int temp;
    stack<int> caculate; caculate.push(00);
    for(int i=0; i<init.length(); i++){
        switch(init[i]){
            case'$':{
                if( (caculate.top()%10) <= (int)(link/10) ){
                    caculate.push(link);
                }
                else{
                    while( (caculate.top()%10) > (int)(link/10) ){
                        temp=caculate.top(); caculate.pop();
                        switch(temp){
                            case 14:{
                                init_changed += '$';
                                break;
                            }
                            case 23:{
                                init_changed += '|';
                                break;
                            }
                            case 52:{
                                init_changed += '*';
                                break;
                            }
                        }
                    }
                    caculate.push(link);
                }
                break;
            }
            case'|':{
                if( (caculate.top()%10) <= (int)(chose/10) ){
                    caculate.push(chose);
                }
                else{
                    while( (caculate.top()%10) > (int)(chose/10) ){
                        temp=caculate.top(); caculate.pop();
                        switch(temp){
                            case 14:{
                                init_changed += '$';
                                break;
                            }
                            case 23:{
                                init_changed += '|';
                                break;
                            }
                            case 52:{
                                init_changed += '*';
                                break;
                            }
                        }
                    }
                    caculate.push(chose);
                }
                break;
            }
            case'*':{
                if( (caculate.top()%10) <= (int)(page/10) ){
                    caculate.push(page);
                }
                else{
                    while( (caculate.top()%10) > (int)(page/10) ){
                        temp=caculate.top(); caculate.pop();
                        switch(temp){
                            case 14:{
                                init_changed += '$';
                                break;
                            }
                            case 23:{
                                init_changed += '|';
                                break;
                            }
                            case 52:{
                                init_changed += '*';
                                break;
                            }
                        }
                    }
                    caculate.push(page);
                }
                break;
            }
            case'(':{
                if( (caculate.top()%10) <= (int)(left/10) ){
                    caculate.push(left);
                }
                else{
                    while( (caculate.top()%10) > (int)(left/10) ){
                        temp=caculate.top(); caculate.pop();
                        switch(temp){
                            case 14:{
                                init_changed += '$';
                                break;
                            }
                            case 23:{
                                init_changed += '|';
                                break;
                            }
                            case 52:{
                                init_changed += '*';
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case')':{
                if( (caculate.top()%10) <= (int)(right/10) ){
                    caculate.push(right);
                }
                else{
                    while( (caculate.top()%10) > (int)(right/10) ){
                        temp=caculate.top(); caculate.pop();
                        switch(temp){
                            case 14:{
                                init_changed += '$';
                                break;
                            }
                            case 23:{
                                init_changed += '|';
                                break;
                            }
                            case 52:{
                                init_changed += '*';
                                break;
                            }
                        }
                    }
                }
                break;
            }
            default:{
                init_changed += init[i];
                break;
            }
        }
    }

    while(!caculate.empty()){
        temp=caculate.top(); caculate.pop();
        switch(temp){
            case 14:{
                init_changed += '$';
                break;
            }
            case 23:{
                init_changed +='|';
                break;
            }
            case 52:{
                init_changed += '*';
                break;
            }
        }
    }

    return init_changed;
}

char** toNFA::toNfa_main(string express){
    //建立并初始化NFA图存储
    nfaGraph = new char*[ 2*express.length() ];
    for(int i=0; i<2*express.length(); i++){
        nfaGraph[i]=new char[2*express.length()];
    }
    for(int i=0; i<2*express.length(); i++){
        for(int j=0; j<2*express.length(); j++){
            nfaGraph[i][j]=NULL;
        }
    }

    //开始建图
    stack<nfa> NFA_stack;
    nfa temp_nfa,temp1,temp2;
    int statu_num=0;

    for(int i=0; i<express.length(); i++){
        //为标识符情况
        if( (express[i]>='a' && express[i]<='z') || (express[i]>='A' && express[i]<='Z') || (express[i]>='0' && express[i]<='9') ){
            temp_nfa.start=statu_num; temp_nfa.end=statu_num+1; statu_num += 2;
            nfaGraph[temp_nfa.start][temp_nfa.end]=express[i];
            NFA_stack.push(temp_nfa);
        }
        else{//不为标识符情况
            switch(express[i]){
                case '$':{//新加statu在两个nfa中间
                    //从temp1到temp2
                    temp2=NFA_stack.top(); NFA_stack.pop();
                    temp1=NFA_stack.top(); NFA_stack.pop();

                    nfaGraph[temp1.end][statu_num]='~';
                    nfaGraph[statu_num][temp2.start]='~';
                    statu_num++;

                    //新建的nfa图
                    temp_nfa.start=temp1.start;
                    temp_nfa.end=temp2.end;

                    NFA_stack.push(temp_nfa);
                    break;
                }
                case '|':{//新加statu在两个nfa开头
                    temp2=NFA_stack.top(); NFA_stack.pop();
                    temp1=NFA_stack.top(); NFA_stack.pop();

                    nfaGraph[statu_num][temp1.start]='~';
                    nfaGraph[statu_num][temp2.start]='~';
                    temp_nfa.start=statu_num;
                    statu_num++;

                    nfaGraph[temp2.end][statu_num]='~';
                    nfaGraph[temp1.end][statu_num]='~';
                    temp_nfa.end=statu_num;
                    statu_num++;

                    NFA_stack.push(temp_nfa);
                    break;
                }
                case '*':{//新加的两个statu在一个nfa开头
                    temp1=NFA_stack.top(); NFA_stack.pop();
                    nfaGraph[statu_num][temp1.end]='~';
                    nfaGraph[statu_num][temp1.start]='~';
                    temp_nfa.start=statu_num;
                    statu_num++;

                    nfaGraph[statu_num][temp1.start]='~';
                    nfaGraph[temp1.end][statu_num]='~';
                    temp_nfa.end=statu_num;
                    statu_num++;

                    NFA_stack.push(temp_nfa);
                    break;
                }
            }
        }
    }

    //得到NFA的初态和终态
    temp_nfa=NFA_stack.top();
    Start=temp_nfa.start;
    End=temp_nfa.end;
    status_num=statu_num;

    return nfaGraph;
}

set<int>** toNFA::toSwitch(char** G, int statu_num, string Symbol){
    map<char,unsigned int> Symbol_no;
    set<int> temp;

    //标识符编号
    for(unsigned int i=0; i<Symbol.length(); i++){
        Symbol_no[Symbol[i]]=i;
    }

    //建表
    Switch=new set<int>* [statu_num];
    for(int i=0; i<statu_num; i++){
        Switch[i]=new set<int>[Symbol.length()];
    }
    for(int i=0; i<statu_num; i++){
        for(unsigned int j=0; j<Symbol.length(); j++){
            Switch[i][j]=temp;
        }
    }

    for(int i=0; i<statu_num; i++){
        for(int j=0; j<statu_num; j++){
            if(G[i][j]!=NULL){
                (Switch[i][Symbol_no[G[i][j]] ]).insert(j);
            }
        }
    }
    return Switch;
}
