#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include "toNFA.h"
#include "toDFA.h"
#include "miniDFA.h"
#include "toTEXT.h"
#include "fstream"
#include "QFileDialog"
#include "QMessageBox"

using namespace std;

string getstring (int n);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->toNFA_table->show();
    ui->toDFA_table->close();
    ui->miniDFA_table->close();
    ui->textBrowser->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//从文件读入
void MainWindow::on_file_Button_clicked()
{
    //定义文件对话框类
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(QStringLiteral("选择文件"));
    //设置文件过滤器
    fileDialog->setNameFilter(tr("File(*.txt)"));
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //得到选择的文件的路径
    QMessageBox msg(this);
    QString fileName,toline;
    string filename,express;
    fileName = fileDialog->getOpenFileName();
    filename=fileName.toStdString();

    if(fileName==""){
        msg.setWindowTitle("打开文件出错");//对话框标题
        msg.setText("请输入正则表达式！");//对话框提示文本
        msg.setIcon(QMessageBox::Warning);//设置图标类型
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//对话框上包含的按钮
        msg.exec();//模态调用
    }
    //从文件中读取得到正则表达式
    ifstream in(filename,ios::in);
    if(!in){
        msg.setWindowTitle("打开文件出错");//对话框标题
        msg.setText("请确定文件路径无中文字符!");//对话框提示文本
        msg.setIcon(QMessageBox::Warning);//设置图标类型
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//对话框上包含的按钮
        msg.exec();//模态调用
     }
     while(getline(in,express)){
        toline=QString::fromStdString(express);
     }
     in.close();

     ui->lineEdit->setText(toline);
}

//开始进行生成XLEX词法分析器
void MainWindow::on_sure_Button_clicked()
{
    QString Express=ui->lineEdit->text();
    string s_changed,express=Express.toStdString();
    int col,row;

    //获得NFA
    QStringList NFAheader,NFAver;
    char **nfaG; string NFAitem="";
    set<int>::iterator NFAit;
    set<int>** NFASwitch;
    toNFA *tonfa=new toNFA();
    s_changed=tonfa->Pre(express);
    nfaG=tonfa->toNfa_main(s_changed);
    NFASwitch=tonfa->toSwitch(nfaG,tonfa->status_num,(tonfa->symbol)+'~');
    //输出转换表格
    //得到NFA列标签
    for(int i=0; i<(tonfa->symbol).length(); i++)
        NFAheader<<QString((tonfa->symbol)[i]);
    NFAheader<<QString('~');
    for(int i=0; i<(tonfa->status_num); i++)
        NFAver<<QString::number(i);

    col=(tonfa->symbol).size()+1; row=(tonfa->status_num);
    ui->toNFA_table->setColumnCount(col);
    ui->toNFA_table->setRowCount(row);
    ui->toNFA_table->setHorizontalHeaderLabels(NFAheader);
    ui->toNFA_table->setVerticalHeaderLabels(NFAver);

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            for( NFAit=NFASwitch[i][j].begin();NFAit!=NFASwitch[i][j].end(); NFAit++){
                NFAitem += getstring(*NFAit);
                NFAitem += ",";
            }
            if(NFAitem.length()!=0){NFAitem.erase(NFAitem.length()-1,1);}
            ui->toNFA_table->setItem(i,j,new QTableWidgetItem(QString::fromStdString(NFAitem)));
            NFAitem.clear();
        }
    }

    //获得DFA
    QStringList DFAheader,DFAver;
    char** dfaGraph; string DFAitem="";
    set<int>::iterator DFAit;
    set<int>** DFASwitch;
    toDFA *todfa=new toDFA();
    todfa->getNFA( tonfa->Start, tonfa->End, nfaG, 2*(s_changed.length()),tonfa->symbol);
    dfaGraph=todfa->toDFA_main();
    DFASwitch=todfa->toSwitch(dfaGraph,(todfa->dfaStatus).size(),tonfa->symbol);
    //输出转换表格
    //得到DFA列标签
    for(int i=0; i<(tonfa->symbol).length(); i++)
        DFAheader<<QString((tonfa->symbol)[i]);

    map<set<int>,int>::iterator map_it=todfa->dfaStatus.begin();
    for(; map_it!=todfa->dfaStatus.end(); map_it++){
       string temp="";
       set<int>::iterator set_it;
       for(set_it=(map_it->first).begin(); set_it!=(map_it->first).end(); set_it++){
            temp += getstring(*set_it);
            temp += ',';
       }
       temp.erase(temp.length()-1,1);
       DFAver<<QString::fromStdString(temp);
    }

    col=(tonfa->symbol).size(); row=(todfa->dfaStatus).size();
    ui->toDFA_table->setColumnCount(col);
    ui->toDFA_table->setRowCount(row);
    ui->toDFA_table->setHorizontalHeaderLabels(DFAheader);
    ui->toDFA_table->setVerticalHeaderLabels(DFAver);

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            for( DFAit=DFASwitch[i][j].begin();DFAit!=DFASwitch[i][j].end(); DFAit++){
                DFAitem += getstring(*DFAit);
                DFAitem += ",";
            }
            if(DFAitem.length()!=0){DFAitem.erase(DFAitem.length()-1,1);}
            ui->toDFA_table->setItem(i,j,new QTableWidgetItem(QString::fromStdString(DFAitem)));
            DFAitem.clear();
        }
    }

    //最小化DFA
    QStringList miniDFAheader,miniDFAver;
    int** DFA; QString miniDFAitem;
    int** miniDFASwitch;
    miniDFA *minidfa=new miniDFA();
    minidfa->get_initial_DFA(dfaGraph,tonfa->symbol,todfa->dfaStatus,tonfa->End);
    DFA=minidfa->miniDFA_main();
    miniDFASwitch=DFA;

    //输出转换表格
    //得到miniDFA列标签
    for(int i=0; i<(tonfa->symbol).length(); i++)
        miniDFAheader<<QString((tonfa->symbol)[i]);
    for(int i=0; i<(todfa->dfaStatus).size(); i++)
        miniDFAver<<QString::number(i);

    col=(tonfa->symbol).size(); row=minidfa->Col;
    ui->miniDFA_table->setColumnCount(col);
    ui->miniDFA_table->setRowCount(row);
    ui->miniDFA_table->setHorizontalHeaderLabels(miniDFAheader);
    ui->miniDFA_table->setVerticalHeaderLabels(miniDFAver);

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(miniDFASwitch[i][j]!=-1){
                miniDFAitem=QString::number(miniDFASwitch[i][j]);
                ui->miniDFA_table->setItem(i,j,new QTableWidgetItem(miniDFAitem));
            }
        }
    }

    //输出程序
    string text; QString Text;
    toTEXT *totext = new toTEXT();
    totext->getDFA(minidfa->Col, minidfa->Start, DFA, (tonfa->symbol));
    text=totext->toText();
    Text=QString::fromStdString(text);
    ui->textBrowser->setText(Text);
}

int XLEX_Start(string s){
    return 0;
}

string getstring (int n){
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


void MainWindow::on_toNFA_Button_clicked()
{
    ui->toNFA_table->show();
    ui->toDFA_table->close();
    ui->miniDFA_table->close();
    ui->textBrowser->close();
}

void MainWindow::on_toDFA_Button_clicked()
{
    ui->toNFA_table->close();
    ui->toDFA_table->show();
    ui->miniDFA_table->close();
    ui->textBrowser->close();
}

void MainWindow::on_miniDFA_button_clicked()
{
    ui->toNFA_table->close();
    ui->toDFA_table->close();
    ui->miniDFA_table->show();
    ui->textBrowser->close();
}

void MainWindow::on_toText_Button_clicked()
{
    ui->toNFA_table->close();
    ui->toDFA_table->close();
    ui->miniDFA_table->close();
    ui->textBrowser->show();
}
