#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "iostream"
#include "stdio.h"
#include "string.h"
#include "map"
#include "vector"
#include "ctype.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

typedef enum{
    //结束
    ENDFILE, ERROR_SYMBOL,
    //文法符号(最后一个为；)
    IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE, WHILE, DO, ENDWHILE, FOR, TO, DOWNTO, ENDDO, SPLIT,
    //特殊组合符号
    ID, NUM,
    //运算符号(:=，（，），*，+，+=，^，%，<，=，<=，<>，-，/)
    ASSIGN, LEFT, RIGHT, MULT, PLUS, PLUSEQUAL, TIMES, COMPLE, LESS, EQUAL, LESSEQUAL, UNEQUAL, REDUCE, DIVIDE,
} TokenTypeInProject;

class Gram{
    public:
        Gram(){tokenno=0; lineno=0; innotes=false; tree="statements{ ";} //初始化
        int Mid(); //内部主函数
        void gettext(QString QS);  //获得文本并分列
        vector<string>getERROR(){return ERROR_MES;} //得到错误信息
        string gettree(){return tree;}

    private:
        bool innotes;
        int tokenno;
        int lineno;
        string temp;
        string tree;
        //string tree;
        vector<string> text;
        vector<string> ERROR_MES;
        TokenTypeInProject token;
        TokenTypeInProject TEMP;
        string nowtext;
        //对输入的文本进行处理用
        TokenTypeInProject getnexttoken(); //获得下一个符号
        string getnextline(); //获得下一列文本

        //对文本语法探测用
        TokenTypeInProject program();
        TokenTypeInProject stmt_sequence();
        TokenTypeInProject statement();
        TokenTypeInProject if_stmt();
        TokenTypeInProject repeat_stmt();
        TokenTypeInProject assign_stmt();
        TokenTypeInProject read_stmt();
        TokenTypeInProject write_stmt();
        TokenTypeInProject dowhile_stmt();
        TokenTypeInProject for_stmt();
        TokenTypeInProject while_stmt();
        TokenTypeInProject exp();
        TokenTypeInProject com_op();
        TokenTypeInProject simple_exp();
        TokenTypeInProject addop();
        TokenTypeInProject term();
        TokenTypeInProject mulop();
        TokenTypeInProject factor();
        TokenTypeInProject Maket(TokenTypeInProject expect); //匹配
        void Error(string s); //错误函数
};



#endif // ANALYSIS_H
