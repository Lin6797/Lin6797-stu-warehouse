#include "miniDFA.h"

miniDFA::miniDFA(){}

void miniDFA::get_initial_DFA(char** DFA, string symbol, map<set<int>,int> Status,int End){
    initial_DFA=DFA;
    Symbol=symbol;
    initial_Status=Status;
    NFAend=End;
}

int** miniDFA::miniDFA_main(){
    int Graphsize=initial_Status.size();
    map<char,int> Symbol_no;
    set<int> end_set,nend_set; //终态与非终态集合
    map<int,set<int> > temp_map; //暂用map
    map<int,set<int> >::iterator temp_it; //暂用map的指针
    map<set<int>,int>::iterator initialmap_it; //初始DFA的map指针
    stack<set<int> > goal_stack; //目标集合栈
    stack<set<int> > temp_stack; //暂用集合栈
    set<int> temp; //暂用集合（用于获取从stack中取出的集合）
    set<int>::iterator tempset_it; //暂用集合指针
    set<int> maptemp; //暂用集合(用于存储将要放入temp_map的数据的集合)
    int status_no;

    for(int i=0; i<Symbol.length(); i++){
        Symbol_no[Symbol[i]]=i;
    }

    //先绘制转换表
    //建立并初始化
    int** Switch=new int*[Graphsize];
    for(int i=0; i<Graphsize; i++){
        Switch[i]=new int[Symbol.length()];
    }
    for(int i=0; i<Graphsize; i++){
        for(int j=0; j<Symbol.length(); j++){
            Switch[i][j]=-1;
        }
    }

    for(int i=0; i<Graphsize; i++){
        for(int j=0; j<Graphsize; j++){
            if(initial_DFA[i][j]!=NULL){
                Switch[i][Symbol_no[initial_DFA[i][j]] ]=j;
            }
        }
    }

    //开始通过扫描转换表得到最小化DFA
    //划分状态集合

    //划分终态集和非终态集
    for(initialmap_it=initial_Status.begin(); initialmap_it!=initial_Status.end(); initialmap_it++){
        if( (initialmap_it->first).find(NFAend)==(initialmap_it->first).end() ){ //为非终态集情况
            nend_set.insert( (initialmap_it->second) );
        }
        else{ //为终态集情况
            end_set.insert( (initialmap_it->second) );
        }
    }
    goal_stack.push(nend_set); goal_stack.push(end_set);

    //划分具体集合
    for(int i=0; i<Symbol.length(); i++){
        temp_stack=goal_stack;
        while(!goal_stack.empty()) goal_stack.pop();
        while(!temp_stack.empty()){
            //开始进行stack中一个集合的划分
            temp=temp_stack.top(); temp_stack.pop();
            for(tempset_it=temp.begin(); tempset_it!=temp.end(); tempset_it++){
                status_no=Switch[*tempset_it][Symbol_no[Symbol[i]]];
                if(temp_map.find(status_no)==temp_map.end()){ //不在temp_map内部
                    maptemp.insert(*tempset_it);
                    temp_map[status_no]= maptemp;
                    maptemp.clear();
                }
                else{ //在temp_map内部
                    temp_it=temp_map.find(status_no);
                    (temp_it->second).insert(*tempset_it);
                }
            }
            //完成一个集合的划分
            for(temp_it=temp_map.begin(); temp_it!=temp_map.end(); temp_it++){
                goal_stack.push((temp_it->second));
            }
            temp_map.clear();
        }
    }

    //转换表建图
    //初始化表格
    DFA=new int* [goal_stack.size()];
    for(int i=0; i<goal_stack.size(); i++){
        DFA[i]=new int[Symbol.length()];
    }
    for(int i=0; i<goal_stack.size(); i++){
        for(int j=0; j<Symbol.length(); j++){
            DFA[i][j]=-1;
        }
    }

    //将goal_stack内各个集合编号
    int status_number=0;
    map<int,set<int> > goal_map;
    while(!goal_stack.empty()){
        temp=goal_stack.top(); goal_stack.pop();
        goal_map[status_number]=temp;
        status_number++;
        if(temp.find(0)!=temp.end()) Start=status_number-1;
    }

    //开始正式建立表格
    int now_no,switch_now;
    for(temp_it=goal_map.begin(); temp_it!=goal_map.end(); temp_it++){
        map<int,set<int> >::iterator map_it;
        now_no=*((temp_it->second).begin());
        for(int i=0; i<Symbol.length(); i++){
            switch_now=Switch[now_no][Symbol_no[Symbol[i]]];
            for(map_it=goal_map.begin(); map_it!=goal_map.end(); map_it++){
                if((map_it->second).find(switch_now)!=(map_it->second).end()){
                    DFA[(temp_it->first)][Symbol_no[Symbol[i]]]=map_it->first;
                }
            }
        }
    }

    Col=status_number;

    return DFA;
}


int** miniDFA::toSwitch(char** G, int statu_num, string Symbol){
    int** Switch;
    map<char,int> statu_no;
    //标识符编号
    for(int i=0; i<Symbol.length(); i++){
        statu_no[Symbol[i]]=i;
    }

    //建立并初始化
    Switch=new int*[statu_num];
    for(int i=0; i<statu_num; i++){
        Switch[i]=new int[Symbol.length()];
    }
    for(int i=0; i<statu_num; i++){
        for(int j=0; j<Symbol.length(); j++){
            Switch[i][j]=-1;
        }
    }

    //正式建立
    for(int i=0; i<statu_num; i++){
        for(int j=0; j<statu_num; j++){
            Switch[i][statu_no[G[i][j]]]=j;
        }
    }

    return Switch;
}
