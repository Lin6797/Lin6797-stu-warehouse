#include "analysis.h"

//内部主函数
int Gram::Mid() {
    do{
        nowtext=text[lineno];
        TEMP=getnexttoken(); if(TEMP==ENDFILE) break;
        TEMP=program(); if(TEMP==ENDFILE) break;
        nowtext=getnextline(); if(nowtext=="EOP") break;
    }while(lineno<text.size()-1);
    tree+="}";
    return 0;
}

//获得下一个字符
TokenTypeInProject Gram::getnexttoken(){
    temp="";
    while(innotes==true){
        for(int t=tokenno; t<nowtext.length(); t++){
            if(nowtext[t]=='}'){ //注释结束
                innotes=false;
            }
        }
        nowtext=getnextline();
    }

    while(tokenno>=nowtext.length()) nowtext=getnextline();

    int i=tokenno;

    while(nowtext[i]==' ') i++;//去除前面空格

    if(!innotes){
        //拼合
        //为字母情况
        if(isalpha(nowtext[i])){
            for(; i<nowtext.length(); i++){
                if(isalpha(nowtext[i]))
                temp += nowtext[i];
                else break;
            }
        }
        //为数字情况
        else if(isdigit(nowtext[i])){
            for(; i<nowtext.length(); i++){
                if(isdigit(nowtext[i]))
                temp += nowtext[i];
                else break;
            }
        }
        //为注释情况
        else if(nowtext[i]=='{'){
            temp+=nowtext[i];
        }
        //else if(nowtext[i]==';'){
        //    temp+=nowtext[i];
        //}
        //为其他符号情况
        else if(nowtext[i]!=' '){
            for(; i<nowtext.length(); i++){
                if(!isdigit(nowtext[i]) && !isalpha(nowtext[i]) && nowtext[i]!=' ' && nowtext[i]!='{')
                {temp += nowtext[i];}
                else break;
            }
        }

        tokenno=i;

        //筛选
        if(isalpha(temp[0])){ //首字符为字母
            if(temp=="if") {token=IF;}
            else if(temp=="then") {token=THEN;}
            else if(temp=="else") {token=ELSE;}
            else if(temp=="end") token=END;
            else if(temp=="repeat") {token=REPEAT;}
            else if(temp=="until") {token=UNTIL;}
            else if(temp=="read") {token=READ;}
            else if(temp=="write") {token=WRITE;}
            else if(temp=="while") {token=WHILE;}
            else if(temp=="do") {token=DO;}
            else if(temp=="endwhile") {token=ENDWHILE;}
            else if(temp=="for") {token=FOR;}
            else if(temp=="to") {token=TO;}
            else if(temp=="downto") {token=DOWNTO;}
            else if(temp=="enddo") token=ENDDO;
            else if(temp=="EOP") token=ENDFILE;
            else { token=ID; tree=tree+"ID:"+temp+", ";}
        }
        else if(isdigit(temp[0])){
            token=NUM;tree=tree+"NUM:"+temp+", ";
        }
        else{
            if(temp==":=") {token=ASSIGN;}
            else if(temp=="(") {token=LEFT;}
            else if(temp==")") {token=RIGHT;}
            else if(temp=="*") {token=MULT; tree=tree+"op:*,";}
            else if(temp=="+") {token=PLUS; tree=tree+"op:+,";}
            else if(temp=="+=") {token=PLUSEQUAL; tree=tree+"op:+=,";}
            else if(temp=="^") {token=TIMES; tree=tree+"op:^,";}
            else if(temp=="%") {token=COMPLE; tree=tree+"op:%,";}
            else if(temp=="<") {token=LESS; tree=tree+"op:<,";}
            else if(temp=="=") {token=EQUAL; tree=tree+"op:=,";}
            else if(temp=="<=") {token=LESSEQUAL; tree=tree+"op:<=,";}
            else if(temp=="<>") {token=UNEQUAL; tree=tree+"op:<>,";}
            else if(temp==";") {token=SPLIT;}
            else if(temp=="-") {token=REDUCE; tree=tree+"op:-,";}
            else if(temp=="/") {token=DIVIDE; tree=tree+"op:/,";}
            else if(temp[0]=='{'){ //为注释情况
                innotes=!innotes;
                token=getnexttoken();
            }
        }
    }
    return token;
}

//得到文本并进行拆分
void Gram::gettext(QString QS){
    string s=QS.toStdString();
    char ch='\n'; int pos;
    s.push_back(ch);
    int start = 0,end = 0,size = s.size();

    for(int i = 0;i < size;i++){
        if(s[i]==ch){
            end = i;
            string temp = s.substr(start,end-start);
            start = i+1;
            text.push_back(temp);
        }
    }
    text.push_back("EOP");
}

//得到下一行
string Gram::getnextline(){
    lineno=lineno+1; tokenno=0;
    //if(text[lineno]=="EOP") system("pause");
    return text[lineno];
}
