#ifndef TONFA_H
#define TONFA_H

#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;

class toNFA
{
public:
    int Start,End;
    string symbol;
    int status_num;
    toNFA();
    string Pre(string); //预处理
    char** toNfa_main(string express); //转为NFA的主要函数
    set<int>** toSwitch(char** G, int statu_num, string Symbol);//转为转换表
private:
    char** nfaGraph;
    set<int>** Switch;
};

#endif // TONFA_H
