#include "toTEXT.h"

void toTEXT::getDFA(int status_num, int Start_statu, int** miniDFA, string miniSymbol){
    Start=Start_statu;
    DFA=miniDFA;
    col=status_num;
    Symbol=miniSymbol;
}

string toTEXT::getstring (int n){
    int m=n,temp,i=0;
    string s="",temp_s="";
    if(n<0){ //为负数情况
        m=-n; s += '-'; i++;
    }
    else if(n==0) s += '0';

    while(m>0){
        temp=m%10;
        m=(int)(m/10);
        temp_s += (char)(temp+('0'-0));
        s.insert(i,temp_s);
        temp_s.clear();
        temp_s="";
    }

    return s;
}

string toTEXT::toText(){
    string Program, DFA_string,Total="";
    //得到DFA的string形式
    DFA_string="int DFA={";
    for(int i=0; i<col-1; i++){
        DFA_string += '{';
        for(int j=0; j<Symbol.length()-1; j++){
            DFA_string += getstring(DFA[i][j]);
            DFA_string += ',';
        }
        DFA_string += getstring(DFA[i][Symbol.length()-1]);
        DFA_string.append("},");
    }

    DFA_string += '{';
    for(int j=0; j<Symbol.length()-1; j++){
        DFA_string += getstring(DFA[col-1][j]);
        DFA_string += ',';
    }
    DFA_string += getstring(DFA[col-1][Symbol.length()-1]);
    DFA_string.append("}");
    DFA_string.append("}");

    Total = Total +"#include <stdio.h>\n"
                   "#include <iostream>\n"
                   "#include <string>\n"
                   "using namespace std;\n";
    Total = Total +DFA_string+";\n";
    Total = Total +"int Start="+getstring(Start)+";\n";
    Total = Total +"Symbol="+Symbol+";\n";
    Total = Total +"int main(){\n"
            "string s,total=\"\";\n"
            "int statu=Start,sy_no;\n"
            "cin>>s;\n"
            "for(int i=0; i<s.length(); i++){\n"
              "sy_no=Symbol.find(Symbol[i]);\n"
              "if(sy_no!=Symbol::npos){\n"
                "statu=DFS[statu][sy_no];\n"
                "total += s[i];\n"
              "}\n"
              "else{cout<<\"can\'t find this link!\"<<endl; break;}\n"
            "}\n"
            "cout<<\"Result:\"<<total<<endl;\n"
            "return 0;\n"
            "}\n";
    return Total;
}


