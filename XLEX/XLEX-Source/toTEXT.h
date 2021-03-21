#ifndef TOTEXT_H
#define TOTEXT_H

#include <string>
#include <map>
#include <set>

using namespace  std;

class toTEXT
{
public:
    toTEXT(){}
    void getDFA(int status_num, int Start_statu, int** miniDFA, string miniSymbol);
    string toText();
private:
    int Start;
    int** DFA;
    int col;
    string Symbol;
    string getstring (int n);
};

#endif // TOTEXT_H
