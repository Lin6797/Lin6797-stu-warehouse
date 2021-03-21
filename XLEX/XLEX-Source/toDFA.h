#ifndef TODFA_H
#define TODFA_H

#include <string>
#include <set>
#include <map>
#include <stack>
using namespace std;

class toDFA
{
public:
    int Start;
    map<set<int>,int> dfaStatus;
    toDFA();
    void getNFA(int Start, int End, char** nfa, int nfasize,string nfasymbol);
    //得到nfa图，初态，终态,图长度和各个标识符
    char** toDFA_main(); //转为DFA
    set<int>** toSwitch(char** G, int statu_num, string Symbol);
private:
    int nfaStart,nfaEnd,Graphsize;
    char** nfaGraph;
    char** dfaGraph;
    string symbol;
    map<set<int>,int > Status;//全部状态及其编号
    set<int>** Switch;
    set<int> findStatuSet(set<int> begin, char purpose);
};

#endif // TODFA_H
