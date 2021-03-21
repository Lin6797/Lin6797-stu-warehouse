#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "slr.h"
#include "iostream"
#include "fstream"
#include "QFileDialog"
#include "QMessageBox"
#include "QTextStream"

slr *SLR_class;

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

string getItems(){
    string s;
    map<int,string>::iterator it;
    map<int,string> content_num = SLR_class->getContent_num();

    for(it=content_num.begin(); it!=content_num.end(); it++){
        QString Temp_n = QString::number(it->first);
        string temp_n = Temp_n.toStdString();
        s = s+"no "+temp_n+":\n";
        s = s+it->second+"\n";
    }
    return s;
}

void MainWindow::on_Sure_clicked()
{
    QString Text=ui->textEdit->toPlainText();
    string text=Text.toStdString();
    SLR_class=new slr(text);
}

void MainWindow::on_ifExtend_clicked()
{
    bool ifextend = SLR_class->get_isExtend();
    if(ifextend){
        QMessageBox msg(this);
        msg.setWindowTitle("判断结果");//对话框标题
        msg.setText("需要进行语法扩充");//对话框提示文本
        msg.setIcon(QMessageBox::Information);//设置图标类型
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//对话框上包含的按钮
        msg.exec();//模态调用
    }
    else{
        QMessageBox msg(this);
        msg.setWindowTitle("判断结果");//对话框标题
        msg.setText("不需要进行语法扩充");//对话框提示文本
        msg.setIcon(QMessageBox::Information);//设置图标类型
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//对话框上包含的按钮
        msg.exec();//模态调用
    }
}

void MainWindow::on_getFButton_clicked()
{
    ui->textBrowser->show();
    ui->LRTable->close();
    ui->SLRTable->close();
    ui->textEdit->show();
    ui->showItem->close();
    ui->textBrowser->clear();

    map<string,set<string>> first, follow;
    map<string,set<string>>::iterator it;
    set<string>::iterator set_it;
    string output; QString Output;

    first = SLR_class->getfirst();
    follow = SLR_class->getfollow();

    output = "first\n";
    for(it=first.begin(); it!=first.end(); it++){
        output = output+it->first+":{";
        for(set_it=it->second.begin(); set_it!=it->second.end(); set_it++){
            output = output+*set_it+",";
        }
        output = output+"}"+"\n";
    }
    Output = QString::fromStdString(output);
    ui->textBrowser->append(Output);

    output = "follow\n";
    for(it=follow.begin(); it!=follow.end(); it++){
        output = output+it->first+":{";
        for(set_it=it->second.begin(); set_it!=it->second.end(); set_it++){
            output = output+*set_it+",";
        }
        output = output+"}"+"\n";
    }
    Output = QString::fromStdString(output);
    ui->textBrowser->append(Output);
}

void MainWindow::on_getLRButton_clicked()
{
    ui->textBrowser->close();
    ui->LRTable->show();
    ui->SLRTable->close();
    ui->textEdit->close();
    ui->showItem->show();

    QString S; string s=getItems();
    map<int,string> content_num;
    map<int,string>::iterator it;
    QStringList DFAhear;
    QString DFAitem;

    content_num = SLR_class->getContent_num();
    string** DFA = SLR_class->get_DFA();
    S = QString::fromStdString(s);
    ui->showItem->setText(S);

    for(int i=0; i<content_num.size(); i++)
        DFAhear<<QString::number(i);
    ui->LRTable->setRowCount(content_num.size());
    ui->LRTable->setColumnCount(content_num.size());
    ui->LRTable->setHorizontalHeaderLabels(DFAhear);
    ui->LRTable->setVerticalHeaderLabels(DFAhear);

    for(int i=0; i<content_num.size(); i++){
        for(int j=0; j<content_num.size(); j++){
            QString Item = QString::fromStdString(DFA[i][j]);
            ui->LRTable->setItem(i,j,new QTableWidgetItem(Item));
        }
    }
}

void MainWindow::on_beginInput_clicked()
{
    ui->textEdit->show();
    ui->showItem->close();
}

void MainWindow::on_ifSLR_clicked()
{
    bool ifSLR = SLR_class->get_isSLR1();
    if(ifSLR){
        QMessageBox msg(this);
        msg.setWindowTitle("判断结果");//对话框标题
        msg.setText("符合SLR(1)文法");//对话框提示文本
        msg.setIcon(QMessageBox::Information);//设置图标类型
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//对话框上包含的按钮
        msg.exec();//模态调用
    }
    else{
        QMessageBox msg(this);
        msg.setWindowTitle("判断结果");//对话框标题
        msg.setText(QString::fromStdString(SLR_class->get_reason()));//对话框提示文本
        msg.setIcon(QMessageBox::Warning);//设置图标类型
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//对话框上包含的按钮
        msg.exec();//模态调用
    }
}

void MainWindow::on_getSLR_clicked()
{
    ui->textBrowser->close();
    ui->LRTable->close();
    ui->SLRTable->show();
    ui->textEdit->close();
    ui->showItem->show();

    QString SLRitem,S; string s=getItems();
    QStringList SLRhear,SLRver;
    map<string,int>::iterator it;
    string** SLR=SLR_class->get_SLR();
    map<string,int> SLRcontent_num = SLR_class->SLRContent_num;
    map<int,string> content_num = SLR_class->Content_num;
    S = QString::fromStdString(s);
    ui->showItem->setText(S);

    //表头和表列
    for(it=SLRcontent_num.begin(); it!=SLRcontent_num.end(); it++){
        SLRhear<<QString::fromStdString(it->first);
    }
    for(int i=0; i<content_num.size(); i++)
        SLRver<<QString::number(i);

    ui->SLRTable->setRowCount(content_num.size());
    ui->SLRTable->setColumnCount(SLRcontent_num.size());
    ui->SLRTable->setHorizontalHeaderLabels(SLRhear);
    ui->SLRTable->setVerticalHeaderLabels(SLRver);

    for(int i=0; i<content_num.size(); i++){
        for(int j=0; j<SLRcontent_num.size(); j++){
            QString Item = QString::fromStdString(SLR[i][j]);
            ui->SLRTable->setItem(i,j,new QTableWidgetItem(Item));
        }
    }
}

void MainWindow::on_openButton_clicked()
{
    ui->textEdit->show();
    ui->showItem->close();
    ui->textEdit->clear();
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
    ui->lineEdit->setText(fileName);

    if(fileName==""){
        msg.setWindowTitle("打开文件出错");//对话框标题
        msg.setIcon(QMessageBox::Warning);//设置图标类型
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//对话框上包含的按钮
        msg.exec();//模态调用
    }
    //从文件中读取得到TINY程序
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
        ui->textEdit->append(toline);
     }
     in.close();
}

void MainWindow::on_Save_clicked()
{
    QFile  myfile("Test.txt");//创建一个输出文件的文档
    if (myfile.open(QFile::WriteOnly|QFile::Truncate))//注意WriteOnly是往文本中写入的时候用，ReadOnly是在读文本中内容的时候用，Truncate表示将原来文件中的内容清空
    {
        QString program=ui->textEdit->toPlainText();
        //读取之前setPlainText的内容，或直接输出字符串内容QObject::tr()
        QTextStream out(&myfile);
        out<<program<<QObject::tr("");
    }
    QMessageBox msg(this);
    msg.setWindowTitle("存储文件结果");//对话框标题
    msg.setText("已成功将其存储为Test.txt文件!");//对话框提示文本
    msg.setIcon(QMessageBox::Information);//设置图标类型
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//对话框上包含的按钮
    msg.exec();//模态调用
}
