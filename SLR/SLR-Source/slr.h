#include <string>
#include <set>
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include <QString>
using namespace std;

#ifndef _GRAMMAR_H_
#define _GRAMMAR_H_

class Item { //项目
public:
    string key; //项目的key
    int value_num; //项目key对应的value的编号
    int index; //'.'位置
    int type; //1为移进项 2为归约项
    Item(string a = "", int b = 0, int c = 0, int d = 1) {
        this->key = a;
        this->value_num = b;
        this->index = c;
        this->type = d;
    }
    bool operator == (const Item &other) {
        return (this->key == other.key) && (this->value_num == other.value_num) && (this->index == other.index) && (this->type == other.type);
    }
};

class slr {
public:
    map<int,string> Content_num; //表项和序号连接
    map<string,int> SLRContent_num; //表项和序号连接
private:
    map<string, vector<vector<string>>> m; //记录文法的每一条产生式，通过键值对的方式
    string start;  //记录开始符号
    set<string> ntSet; //终结符集合
    set<string> Vn; //非终结符集合
    map<string, set<string>> m_first; //记录每一个非终结符号对应的first集合
    map<string, set<string>> m_follow; //记录每一个非终结符对应的follow集合
    vector<vector<Item>> DFA_nodes; //记录DFA结点
    map<int, map<string, int>> forwards; //记录移进关系
    map<int, map<string, int>> backs; //记录归约关系
    bool isSLR1; //是否为SLR(1)文法
    string reason; //不是SLR(1)文法的原因
    bool isExtend;  //检测是否需要文法扩充
//    vector<vector<string>> DFA; //DFA图
public:
    slr(string inputString = ""); //构造函数(完成初始化操作)
    string get_start(); //得到开始符号
    bool get_isExtend();//得到需要文法扩充的判断信息
    set<string> get_ntSet();  //得到终结符集
    set<string> get_first(string key); //得到key的first集合
    set<string> get_follow(string key);//得到key的follow集合
    map<string,set<string>> getfirst();//返回所有非终结符key的first集合串
    map<string,set<string>> getfollow();//返回所有非终结符key的follow集合串
    map<int,string> getContent_num(); //得到串和编号
    string** get_DFA(); //返回DFA图
    map<string,int> getSLRContent_num(); //得到串和编号
    string** get_SLR();//返回SLR(1)分析图
    bool get_isSLR1();// 得到是否为SLR(1)文法判断信息
    string get_reason();//得到不是SLR(1)文法的原因
    void show();
private:
    void first_follow_all(); //求所有非终结符的first和follow函数
    set<string> first(vector<string> value); //求value序列的first集合
    void node_relationship(); //求DFA图，判断是否为SLR(1)
    void extend(int k); //扩展结点k
};

#endif
