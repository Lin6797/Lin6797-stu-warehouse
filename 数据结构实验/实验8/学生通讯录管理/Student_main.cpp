#include"Student_class.h"
#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	BST B;
    char operation; system("cls");
	while(1){
	   cout<< "\t\t|---------------------------------------------------------------|\n";
       cout<< "\t\t|                       1.新建通讯表                            |\n";
       cout<< "\t\t|                       2.插入新信息                            |\n";
       cout<< "\t\t|                       3.删除信息                              |\n";
       cout<< "\t\t|                       4.从文件中读取信息构建新的二叉树        |\n";
       cout<< "\t\t|                       5.向文件中写入信息                      |\n";
       cout<< "\t\t|                       6.查询学生信息                          |\n";
       cout<< "\t\t|                       7.输出全体学生信息                      |\n";
       cout<< "\t\t|                       8.退出系统                              |\n";
       cout<< "\t\t|---------------------------------------------------------------|\n";
	   cout<<"请选择你要进行的操作："; cin>>operation; cin.sync();
	   
	   switch(operation){
	   	case'1':{//新建 
	   		cout<<"请确定要输入的全部学生人数：";int num;cin>>num;cin.sync(); 
			int* key=new int[num]; 
			Data** data=new Data*[num];//开辟空间 
			for(int i=0;i<num;i++){
			    data[i]=new Data[1];
		        cout<<"请输入学号："; cin>>key[i]; cin.sync();
		        cout<<"请输入姓名："; cin>>(data[i]->name); cin.sync();
		        cout<<"请输入性别(M/F)："; cin>>(data[i]->sex); cin.sync();
		        cout<<"请输入出生日期（格式：20200101）:"; cin>>(data[i]->birthday); cin.sync();
		        cout<<"请输入电话号码:"; cin>>(data[i]->phone); cin.sync();
		        cout<<"请输入地址："; cin>>(data[i]->adver); cin.sync();
		        system("cls");
	        }
	        B.Build(num,key,data);
			break; 
		}
		case'2':{//插入新信息 
			int key; Data* data=new Data[1];
			cout<<"请输入插入的学生信息："<<endl;
			//输入具体信息 
		    cout<<"请输入学号："; cin>>key; cin.sync();
		    cout<<"请输入姓名："; cin>>(data->name); cin.sync();
		    cout<<"请输入性别(M/F)："; cin>>(data->sex); cin.sync();
		    cout<<"请输入出生日期（格式：20200101）:"; cin>>(data->birthday); cin.sync();
		    cout<<"请输入电话号码:"; cin>>(data->phone); cin.sync();
		    cout<<"请输入地址："; cin>>(data->adver); cin.sync();
			//结束输入具体信息 
			B.Insert(key,data);
			break;
		}
		case'3':{//删除学生信息 
			int Key; BSTNode* purpose;
			cout<<"请输入要删除的学生学号："; cin>>Key; cin.sync();
			purpose=B.Delete(Key);
			if(purpose==NULL) cout<<"输入的关键码不在该搜索二叉树范围内"<<endl;
			else cout<<"删除成功"<<endl;
			break;
		}
		case'4':{//从文件中读取信息构建新的二叉树 
			B.Infile();
			cout<<"[构建完成]"<<endl;
			break;
		}
		case'5':{//向文件中写入信息
			B.Outfile();
			break;
		}
		case'6':{//查询学生信息
			int key; BSTNode* current;
			cout<<"请输入要查询的学生学号："<<endl; cin>>key; cin.sync();
			current=B.Search(key);
			if(current!=NULL){
				cout<<"得到学生的具体信息为："<<endl;
				cout<<"该学生学号为："<<current->key<<endl;
				cout<<"该学生姓名为："<<current->data->name<<endl;
				cout<<"该学生性别为："<<current->data->sex<<endl;
				cout<<"该学生出生日期为："<<current->data->birthday<<endl; 
				cout<<"该学生电话号码为："<<current->data->phone<<endl; 
				cout<<"该学生住址为："<<current->data->adver<<endl; 
			} 
			else cout<<"该学生信息未被录入"<<endl;
			break;
		}
		case'7':{//展示元素 
			B.Show();
			cout<<endl<<endl;
			break;
		}
		case'8':{
			exit(1);
			break;
		}
		default:{
			cout<<"输入错误，请重新输入：";
			continue;
		}
		break;
	   }
	   
	   char con_judge;
	   while(1){
	   	cout<<"是否继续进行操作？（Y/N）："; cin>>con_judge; cin.sync();
	   	system("cls");
	   	switch(con_judge){
	   		case'y':
	   		case'Y':{con_judge='Y';break;}
	   		case'n':
	   		case'N':{cout<<"[正在退出程序]"<<endl; return 0;}
	   		default:{cout<<"输入错误，请重新输入"<<endl;continue;}
	   	}
	   	break;
	   }
    }
	
	return 0;
}
