#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "fstream"
#include "cstring"
#include "stdio.h"
#include "QMessageBox"
using namespace std;

//树结点
class KeyWord{
    public:
        KeyWord *lc, *rc;
        string Key;
};

KeyWord *Build(string filename);
bool ifKey(string Word, KeyWord *key);
unsigned int wJudge(string Program, unsigned int now, KeyWord* Key);
unsigned int nJudge(string Program, unsigned int now);
unsigned int cJudge(string Program, unsigned int now, bool out);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//选择文件
//keybutton
void MainWindow::on_keyButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(NULL,"标题",".","*.txt");

    ui->keyEdit->setText(fileName);
}

//filebutton
void MainWindow::on_fileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(NULL,"标题",".","*.txt");

    ui->fileEdit->setText(fileName);
}

//开始分词
//startbutton
void MainWindow::on_startButton_clicked()
{
    QString QSkey,QSfile;
    string skey,sfile;
    string Program;
    KeyWord *key;
    unsigned int now,next;
    bool out=true;

    //准备开文件
    QSkey=ui->keyEdit->text(); QSfile=ui->fileEdit->text();
    skey=QSkey.toStdString(); sfile=QSfile.toStdString();

    //清空Final.txt文件
    ofstream write("Final.txt");
    write.close();

    //打开文件
    key=Build(skey);
    if(key==NULL) return ;

    ifstream in;
    in.open(sfile,ios_base::in);
    if(!in){//打开失败时用
        return ;
    }
    while( getline(in, Program) ){
        for(now=0; now<Program.size(); ){
            //首为字母
            if( (Program[now]>='A' && Program[now]<='Z' ) || (Program[now]>='a' && Program[now]<='z' ) ){
                next = wJudge(Program, now, key); now = next;
            }
            //首为数字
            else if( Program[now]>='0' && Program[now]<='9' ){
                next = nJudge(Program, now); now = next;
            }
            //首为符号
            else{
                if(Program[now]==' '  || Program[now] == '	'){
                    now++; continue;
                }
                next = cJudge(Program, now, out); now = next;
                if(now == Program.size()+1) out=false;
                else out=true;
            }
        }
    }
    in.close();//关闭文件

    QMessageBox::information(this,"信息","分词结果已写入Final.txt文件");
}

//建造二叉树
KeyWord *Build(string name){
    KeyWord *now, *temp, *root;
    ifstream Key_in;
    string keyword;

    //根结点设置
    root = new KeyWord[1];
    root->lc = NULL; root->rc = NULL; root->Key = "Root";

    Key_in.open(name, ios::in);
    if( !Key_in ){
        return NULL;
    }

    while( getline(Key_in, keyword) ){
        temp = root;
        now = new KeyWord[1];
        now->lc=NULL; now->rc=NULL; now->Key=keyword;

        while( temp!=NULL ){
            if( keyword < temp->Key ){
                if( temp->lc == NULL){
                    temp->lc=now; break;
                }
                else temp=temp->lc;
            }
            else{
                if( temp->rc == NULL ){
                    temp->rc=now; break;
                }
                else temp=temp->rc;
            }
        }
    }
    Key_in.close();
    return root;
}

//判断是否为关键词
bool ifKey(string Word, KeyWord *key){
    KeyWord *now = key;

    while( now!=NULL ){
        if( Word < now->Key ){
            now=now->lc;
        }
        else if( Word > now->Key){
            now=now->rc;
        }
        else return true;
    }
    return false;
}

//首为字母分词
unsigned int wJudge(string Program, unsigned int now, KeyWord* Key){
    string KeyWord, Total = "";
    unsigned int next;

    ofstream wirte("Final.txt",ios::app);

    Total += Program[now];
    for(next=now+1; next<Program.size(); next++){
        if (Program[next]=='_' || Program[next]=='.' || (Program[next]>='A' && Program[next]<='Z') || (Program[next]>='a' && Program[next]<='z') || (Program[next]>='0' && Program[next]<='9') )
          Total += Program[next];
        else break;
    }

    //检测是否为关键字,运算符，函数
    if( ifKey(Total,Key) ){
        wirte<<Total<<"    关键字"<<endl;
        return next;
    }
    if( Total=="sizeof" || Total=="Cast" ){
        wirte<<Total<<"    运算符"<<endl;
        return next;
    }
    for(unsigned int i=0; i<Total.size(); i++){
        if(Total[i]=='.'){
            wirte<<Total<<"      函数"<<endl;
            return next;
        }
    }
    wirte<<Total<<"     标识符"<<endl;

    wirte.close();

    return next;
}

//首为数字分词
unsigned int nJudge(string Program, unsigned int now){
    string Total="";
    unsigned int next;

    ofstream wirte("Final.txt",ios::app);

    Total += Program[now];
    for(next=now+1; next<Program.size(); next++){
        if (Program[next]=='.' || (Program[next]>='0' && Program[next]<='9' ) || Program[next]=='E' ||Program[next]=='e' )
            Total += Program[next];
        else if( (Program[next-1]=='e' || Program[next-1]=='E') && Program[next]=='-'){
            Total += Program[next];
        }
        else break;
    }

    wirte<<Total<<"      数值"<<endl;

    wirte.close();

    return next;
}

//首为符号分词
unsigned int cJudge(string Program, unsigned int now, bool out){
    string Total="";
    unsigned int next;

    Total += Program[now];

    ofstream wirte("Final.txt",ios::app);

    if(!out){ //在多行注释中
        for(next=now; next<Program.size()-1; next++ ){
            if(Program[next]=='*' && Program[next+1]=='/'){//注释结束
                wirte<<Program[next]<<Program[next+1]<<"      特殊符号"<<endl;
                return (next+2);
            }
            else return ( Program.size()+1 );
        }
    }

    //‘/’情况
    if( Program[now]=='/' ){
        next = now+1;
        if( Program[next]=='/'){ //单行注释
            Total += Program[next]; next = Program.size();
        }
        else if( Program[next]=='*' ){ //多行注释
            Total += Program[next]; next = Program.size()+1;
        }
        else if( Program[next] == '='){
            Total += Program[next]; next++;
        }
        wirte<<Total<<"      特殊符号"<<endl; return next;
    }

    //为字符串或者字符类型的情况
    if( Program[now] == '\"'){
        for( next = now+1; next < Program.size(); next++ ){
            if( Program[next] != '\"'){
                Total += Program[next];
            }
            else{
                Total += Program[next];
                break;
            }
        }
        wirte<<Total<<"  为字符串"<<endl;
        return next+1;
    }
    if( Program[now] == '\'' ){
        for( next = now+1; next<Program.size(); next++){
            if( Program[next] != '\''){
                Total += Program[next];
            }
            else{
                Total += Program[next];
                break;
            }
        }
        wirte<<Total<<"  字符"<<endl;
        return next+1;
    }

    //为数值情况
    if( Program[now] == '-' ){
        for( next=now+1; next<Program.size(); next++){
            if( Program[next]>='0' && Program[next]<='9' )
            Total += Program[next];
            else break;
        }
        if( Total.size() > 1 ){
            wirte<<Total<<"   数值"<<endl;
            return next;
        }
    }


    next = now+1;
    switch( Program[now] ){
        case '-':{
            if( Program[next] == '-' || Program[next] == '>' || Program[next] == '='){
                Total += Program[next]; next++;
            }
            break;
        }
        case '!':{
            if( Program[next] == '='){
                Total += Program[next]; next++;
            }
            break;
        }
        case '*':{
            if( Program[next] == '='){
                Total += Program[next]; next++;
            }
            break;
        }
        case '%':{
            if( Program[next] == '='){
                Total += Program[next]; next++;
            }
            break;
        }
        case '^':{
            if( Program[next] == '='){
                Total += Program[next]; next++;
            }
            break;
        }
        case '=':{
            if( Program[next] == '='){
                Total += Program[next]; next++;
            }
            break;
        }
        case '+':{
            if( Program[next] == '=' || Program[next] == '+' ){
                Total += Program[next]; next++;
            }
            break;
        }
        case '&':{
            if( Program[next] == '=' || Program[next] == '&' ){
                Total += Program[next]; next++;
            }
            break;
        }
        case '|':{
            if( Program[next] == '=' || Program[next] == '|' ){
                Total += Program[next]; next++;
            }
            break;
        }
        case '<':{
            if( Program[next] == '<' ){
                Total += Program[next]; next++;
                if( Program[next] =='=' ){
                    Total += Program[next]; next++;
                }
            }
            break;
        }
        case '>':{
            if( Program[next] == '>' ){
                Total += Program[next]; next++;
                if( Program[next] =='=' ){
                    Total += Program[next]; next++;
                }
            }
            break;
        }

    }

    wirte<<Total<<"    特殊符号"<<endl;

    wirte.close();

    return next;
}
