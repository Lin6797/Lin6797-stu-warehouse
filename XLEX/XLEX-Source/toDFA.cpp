#include "toDFA.h"

toDFA::toDFA(){}

void toDFA::getNFA(int Start, int End, char** nfa, int nfasize,string nfasymbol){
    nfaStart=Start;
    nfaEnd=End;
    Graphsize=nfasize;
    nfaGraph=nfa;
    symbol=nfasymbol;
}

char** toDFA::toDFA_main(){

    int statu_set_num=0;

    //获得初态集合
    set<int> Start_statu; //初始状态集合
    stack<int> status; //DFS用
    int temp_start;

    status.push(nfaStart);
    Start_statu.insert(nfaStart);

    while(!status.empty()){
        temp_start=status.top();
        for(int i=0; i<Graphsize; i++){
            if(nfaGraph[temp_start][i]=='~' && (Start_statu.find(i)==Start_statu.end() )){
                status.push(i);
                temp_start=i; i=0;
                Start_statu.insert(temp_start);
            }
        }
        status.pop();
    }
    Status[Start_statu]=statu_set_num;
    statu_set_num++;

    //开始建图并初始化
    stack< set<int> > Statu_stack;
    set<int> goal_statu,temp;
    dfaGraph=new char*[Graphsize];
    for(int i=0; i<Graphsize; i++){
        dfaGraph[i]=new char[Graphsize];
    }
    for(int i=0; i<Graphsize; i++){
        for(int j=0; j<Graphsize; j++)
            dfaGraph[i][j]=NULL;
    }

    Statu_stack.push(Start_statu);
    while(!Statu_stack.empty()){
        goal_statu=Statu_stack.top();
        for(int i=0; i<symbol.length(); i++){
            temp=findStatuSet(goal_statu,symbol[i]);
            if(temp.size()!=0){
                if(Status.find(temp)==Status.end()){
                    Status[temp]=statu_set_num;
                    statu_set_num++;
                    Statu_stack.push(temp);
                }
                dfaGraph[Status[goal_statu]][Status[temp]]=symbol[i];
            }
        }
        Statu_stack.pop();
    }

    Start=0;
    dfaStatus=Status;
    return dfaGraph;
}

set<int> toDFA::findStatuSet(set<int> begin, char purpose){
    set<int>::iterator it=begin.begin();
    stack<int> status; //DFS用
    set<int> goal_status;
    int temp_start;

    for(; it!=begin.end(); it++){
        for(int i=0; i<Graphsize; i++){
            if(nfaGraph[(*it)][i]==purpose){
                status.push(i); goal_status.insert(i);
                while(!status.empty()){
                    temp_start=status.top();
                    for(int j=0; j<Graphsize; j++){
                        if(nfaGraph[temp_start][j]=='~' && (goal_status.find(j)==goal_status.end() )){
                        status.push(j);
                        temp_start=j; j=0;
                        goal_status.insert(temp_start);
                        }
                    }
                    status.pop();
                }
            }
        }
    }
    return goal_status;
}

set<int>** toDFA::toSwitch(char** G, int statu_num, string Symbol){
    map<char,unsigned int> Symbol_no;
    map<int,set<int> > no_status;
    map<int,set<int> >::iterator no_status_it;
    map<set<int>, int> status_no=Status;
    map<set<int>, int>::iterator status_no_it;
    set<int> temp;
    set<int>::iterator set_it;

    //标识符编号
    for(unsigned int i=0; i<Symbol.length(); i++){
        Symbol_no[Symbol[i]]=i;
    }

    //status-no转为no-status
    for(status_no_it=status_no.begin(); status_no_it!=status_no.end(); status_no_it++){
        no_status[status_no_it->second]=status_no_it->first;
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

    for(int i=0; i<status_no.size(); i++){
        for(int j=0; j<status_no.size(); j++){
            if(G[i][j]!=NULL){
                Switch[i][Symbol_no[G[i][j]]]=no_status[j];
            }
        }
    }
    return Switch;
}
