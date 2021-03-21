#include "analysis.h"

//匹配
TokenTypeInProject Gram::Maket(TokenTypeInProject expect){
    if(token!=expect){ //不匹配
        return ERROR_SYMBOL;
    }
    else{

        token=getnexttoken();
        //if(token==ENDFILE) cout<<"endfile"<<endl;
        return token;
    }
}

//错误
void Gram::Error(string s){
    string error_msg="Syntax error at line ";
    error_msg += to_string(lineno+1);
    error_msg += ": ";
    error_msg += s;
    ERROR_MES.push_back(error_msg);
    getnextline();
}

TokenTypeInProject Gram::program(){
    TEMP=stmt_sequence();
    if(TEMP==ERROR_SYMBOL) {Error(nowtext);}
    return TEMP;
}

TokenTypeInProject Gram::stmt_sequence(){
    if(token==IF || token==REPEAT || token==ID || token==READ ||token== WRITE || token==DO || token==FOR ||token==WHILE){
        TEMP=statement(); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
        while(token==SPLIT){
            TEMP=Maket(SPLIT); if(TEMP==ENDFILE) return ENDFILE;
            TEMP=statement(); if(TEMP==ERROR_SYMBOL) {return ERROR_SYMBOL;}
        }
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::statement(){
    switch (token){
        case IF: {TEMP=if_stmt();break;}
        case REPEAT: {TEMP=repeat_stmt(); break;}
        case ID: {TEMP=assign_stmt();break;}
        case READ: {TEMP=read_stmt();break;}
        case WRITE: {TEMP=write_stmt();break;}
        case WHILE: {TEMP=while_stmt();break;}
        case FOR: {TEMP=for_stmt();break;}
        case DO: {TEMP=dowhile_stmt();break;}
        default:{
            TEMP=ERROR_SYMBOL;
            break;
        }
    }
    return TEMP;
}

TokenTypeInProject Gram::if_stmt(){
    if(token==IF){
        tree=tree+"if-stmt{if:";
        TEMP=Maket(IF);
        TEMP=Maket(LEFT); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        TEMP=exp(); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;} else{tree+=";if_body:";}
        TEMP=Maket(RIGHT); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        TEMP=stmt_sequence(); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        if(token==ELSE){
            TEMP=Maket(ELSE); tree+="; else_body:";
            TEMP=stmt_sequence();
            if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        }
        tree+="}";
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::repeat_stmt(){
    if(token==REPEAT){
        tree=tree+"repeat-stmt{repeat_body:";
        TEMP=Maket(REPEAT);
        TEMP=stmt_sequence(); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;} else{tree+=";repeat:";}
        TEMP=Maket(UNTIL); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        TEMP=exp(); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        tree+="}";
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::assign_stmt(){
    if(token==ID){
        tree=tree+"assign{ ID:"+temp+",";
        TEMP=Maket(ID);
        TEMP=Maket(ASSIGN); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        TEMP=exp(); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        tree+="}";
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::read_stmt(){
    if(token==READ){
        tree=tree+"read-stmt{ ";
        TEMP=Maket(READ); tree=tree+"op:read,";
        TEMP=Maket(ID); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        tree+="}";
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::write_stmt(){
    if(token==WRITE){
        tree=tree+"write-stmt{ ";
        TEMP=Maket(WRITE); tree=tree+"op:write,";
        TEMP=exp(); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        tree+="}";
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::dowhile_stmt(){
    if(token==DO){
        tree=tree+"dowhile-stmt{dowhile_body: ";
        TEMP=Maket(DO);
        TEMP=stmt_sequence(); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        TEMP=Maket(WHILE); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}else{tree+="; while:";}
        TEMP=Maket(LEFT); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        TEMP=exp(); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        TEMP=Maket(RIGHT); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        TEMP=Maket(SPLIT); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        tree+="}";
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::for_stmt(){
    if(token==FOR){
        tree=tree+"for-stmt{ ";
        TEMP=Maket(FOR);
        TEMP=Maket(ID); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        TEMP=Maket(ASSIGN); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        TEMP=simple_exp(); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        switch (token){
            case TO:{TEMP=Maket(TO);break;}
            case DOWNTO: {TEMP=Maket(DOWNTO);break;}
            default:{TEMP=ERROR_SYMBOL;  {tree+="}"; return ERROR_SYMBOL;}}
        }
        TEMP=simple_exp(); if(TEMP==ERROR_SYMBOL)  {tree+="}"; return ERROR_SYMBOL;} else{tree+=";for_body:";}
        TEMP=Maket(DO); if(TEMP==ERROR_SYMBOL)  {tree+="}"; return ERROR_SYMBOL;}
        TEMP=stmt_sequence(); if(TEMP==ERROR_SYMBOL)  {tree+="}"; return ERROR_SYMBOL;}
        TEMP=Maket(ENDDO); if(TEMP==ERROR_SYMBOL)  {tree+="}"; return ERROR_SYMBOL;}
        tree+="}";
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::while_stmt(){
    if(token==WHILE){
        tree=tree+"while-stmt{while:";
        TEMP=Maket(WHILE);
        TEMP=Maket(LEFT); if(TEMP==ERROR_SYMBOL) {tree+="}"; return ERROR_SYMBOL;}
        TEMP=exp(); if(TEMP==ERROR_SYMBOL)  {tree+="}"; return ERROR_SYMBOL;} else{tree+=";while_body:";}
        TEMP=Maket(RIGHT); if(TEMP==ERROR_SYMBOL)  {tree+="}"; return ERROR_SYMBOL;}
        TEMP=stmt_sequence(); if(TEMP==ERROR_SYMBOL)  {tree+="}"; return ERROR_SYMBOL;}
        TEMP=Maket(ENDWHILE); if(TEMP==ERROR_SYMBOL)  {tree+="}"; return ERROR_SYMBOL;}
        tree+="}";
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::exp(){
    if(token==LEFT || token==NUM || token==ID){
        TEMP=simple_exp(); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
        if(token==LESS || token==EQUAL || token==LESSEQUAL || token==UNEQUAL){
            TEMP=com_op(); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
            TEMP=simple_exp(); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
        }
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::com_op(){
    switch(token){
        case LESS:{TEMP=Maket(LESS);break;}
        case EQUAL:{TEMP=Maket(EQUAL);break;}
        case LESSEQUAL:{TEMP=Maket(LESSEQUAL);break;}
        case UNEQUAL:{TEMP=Maket(UNEQUAL);break;}
        default:{TEMP=ERROR_SYMBOL;break;}
    }
    return TEMP;
}

TokenTypeInProject Gram::simple_exp(){
    if(token==LEFT || token==NUM || token==ID){
        TEMP=term(); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
        while(token==PLUS || token==REDUCE || token==PLUSEQUAL){
            TEMP=addop(); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
            TEMP=term(); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
        }
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::addop(){
    switch(token){
        case PLUS:{TEMP=Maket(PLUS);break;}
        case REDUCE:{TEMP=Maket(REDUCE);break;}
        case PLUSEQUAL:{TEMP=Maket(PLUSEQUAL);break;}
        default:{TEMP=ERROR_SYMBOL;break;}
    }
    return TEMP;
}

TokenTypeInProject Gram::term(){
    if(token==LEFT || token==NUM || token==ID){
        TEMP=factor(); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
        while(token==MULT || token==DIVIDE || token==TIMES || token==COMPLE){
            TEMP=mulop(); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
            TEMP=factor(); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
        }
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}

TokenTypeInProject Gram::mulop(){
    switch(token){
        case MULT:{TEMP=Maket(MULT);break;}
        case DIVIDE:{TEMP=Maket(DIVIDE);break;}
        case TIMES:{TEMP=Maket(TIMES);break;}
        case COMPLE:{TEMP=Maket(COMPLE);break;}
        default:{TEMP=ERROR_SYMBOL;break;}
    }
    return TEMP;
}

TokenTypeInProject Gram::factor(){
    if(token==LEFT){
        TEMP=Maket(LEFT);
        TEMP=exp(); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
        TEMP=Maket(RIGHT); if(TEMP==ERROR_SYMBOL) return ERROR_SYMBOL;
    }
    else if(token==NUM){
        TEMP=Maket(NUM);
    }
    else if(token==ID){
        TEMP=Maket(ID);
    }
    else {TEMP=ERROR_SYMBOL;}
    return TEMP;
}
