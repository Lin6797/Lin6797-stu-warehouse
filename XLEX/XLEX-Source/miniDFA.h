#ifndef MINIDFA_H
#define MINIDFA_H

#include <map>
#include <set>
#include <stack>
using namespace std;

class miniDFA
{
public:
    int Start, End, Col;
    miniDFA();
    void get_initial_DFA(char** DFA, string symbol, map<set<int>,int> Status,int End);
    int** miniDFA_main();
    int** toSwitch(char** G, int statu_num, string Symbol);
private:
    int NFAend;
    char** initial_DFA;
    int** DFA;
    string Symbol;
    map<set<int>,int> initial_Status;
};

#endif // MINIDFA_H
