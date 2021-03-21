#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "analysis.h"
#include "fstream"
#include "QFileDialog"
#include "QMessageBox"
#include "QTextStream"

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

//生成语法树
void MainWindow::on_gettree_button_clicked()
{
    QString QS=ui->textEdit->toPlainText();
    Gram* G=new Gram();
    G->gettext(QS);
    G->Mid();

    //获得错误信息
    ERROR_MSG=G->getERROR();
    //获得语法树
    Tree=G->gettree();
    delete G;

    QMessageBox msg(this);
    msg.setWindowTitle("生成语法树结果");//对话框标题
    msg.setText("已成功生成语法树!");//对话框提示文本
    msg.setIcon(QMessageBox::Information);//设置图标类型
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//对话框上包含的按钮
    msg.exec();//模态调用
}

//展示语法树
void MainWindow::on_showtree_button_clicked()
{
    ui->textBrowser->clear(); //清理
    //显示错误信息
    ui->textBrowser->append("TINY Syntax Analyse");
    for(int i=0; i<ERROR_MSG.size(); i++){
        ui->textBrowser->append(">>>"+QString::fromStdString(ERROR_MSG[i]+"\n"));
    }
    //显示语法树
    string temp="",blank=" "; int layer=0;
    for(unsigned int i; i<Tree.length(); i++){
        if(Tree[i]=='{' && Tree[i]!=' ') {
            temp+=Tree[i];
            for(int t=0; t<layer; t++) temp=blank+temp;
            layer=layer+1;
            ui->textBrowser->append(QString::fromStdString(temp));
            temp="";
        }
        else if(Tree[i]==';' && Tree[i]!=' ') {
            temp+=Tree[i];
            for(int t=0; t<layer; t++) temp=blank+temp;
            ui->textBrowser->append(QString::fromStdString(temp));
            temp="";
        }
        else if(Tree[i]=='}' && Tree[i]!=' '){
            temp+=Tree[i];
            for(int t=0; t<layer; t++) temp=blank+temp;
            layer=layer-1;
            ui->textBrowser->append(QString::fromStdString(temp));
            temp="";
        }
        else temp+=Tree[i];
    }
}

//打开文件
void MainWindow::on_getfile_button_clicked()
{
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

//保存代码
void MainWindow::on_save_button_clicked()
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
