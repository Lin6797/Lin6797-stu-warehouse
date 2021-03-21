#include"BST_class.h"
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"请进行搜索二叉树的初始化："<<endl;

	int num; BST B;
	cout<<"请确定搜索二叉树的全部元素个数："; cin>>num; cin.sync(); 
	//确定元素 
	char* data=new char[num]; int* key=new int[num];
	cout<<"请输入元素内容："<<endl;
	for(int i=0; i<num;i++) cin>>data[i];
	cin.sync();
	cout<<"请输入相应的关键码："<<endl;
	for(int i=0;i<num;i++) cin>>key[i];
	cin.sync();
	B.Build(num,key,data);
	
char operation; system("cls");
	while(1){
	   cout<< "\t\t|---------------------------------------------------------------|\n";
       cout<< "\t\t|                       1.重新构建                              |\n";
       cout<< "\t\t|                       2.通过关键码查找元素（非递归）          |\n";
       cout<< "\t\t|                       3.通过关键码查找元素（递归）            |\n";
       cout<< "\t\t|                       4.插入元素（非递归）                    |\n";
       cout<< "\t\t|                       5.插入函数（递归）                      |\n";
       cout<< "\t\t|                       6.删除元素                              |\n";
       cout<< "\t\t|                       7.展示                                  |\n";
       cout<< "\t\t|                       8.将二叉树元素写入文件                  |\n";
       cout<< "\t\t|                       9.从文件中获取二叉树元素并建树          |\n";
       cout<< "\t\t|                       A.退出系统                             |\n";
       cout<< "\t\t|---------------------------------------------------------------|\n";
	   cout<<"请选择你要进行的操作："; cin>>operation; cin.sync();
	   
	   switch(operation){
	   	case'1':{//重新构建 
	   		cout<<"请确定搜索二叉树的全部元素个数："; cin>>num; cin.sync(); 
	        //确定元素 
	        data=new char[num]; key=new int[num];
	        cout<<"请输入元素内容："<<endl;
	        for(int i=0; i<num;i++) cin>>data[i];
	        cin.sync();
	        cout<<"请输入相应的关键码："<<endl;
	        for(int i=0;i<num;i++) cin>>key[i];
	        cin.sync();
	        B.Build(num,key,data);
	   		break;
		}
		case'2':{//通过关键码找元素（非递归） 
			int Key; BSTNode* purpose;
			cout<<"请输入需要查找的关键码："; cin>>Key; cin.sync();
			purpose=B.Search(Key);
			if(purpose==NULL) cout<<"输入关键码不在目标搜索二叉树内"<<endl;
			else cout<<"搜索结果为："<<purpose->data<<endl;
			break;
		}
		case'3':{//通过关键码找元素（递归）
			int Key; BSTNode* purpose;
			cout<<"请输入需要查找的关键码："; cin>>Key; cin.sync();
			purpose=B.search(Key);
			if(purpose==NULL) cout<<"输入关键码不在目标搜索二叉树内"<<endl;
			else cout<<"搜索结果为："<<purpose->data<<endl;
			break;
		}
		case'4':{//插入元素（非递归） 
			int Key; char Data;
			cout<<"请输入要插入的元素内容："; cin>>Data; cin.sync();
			cout<<"请输入要插入的元素关键码："; cin>>Key; cin.sync();
			B.Insert(Key,Data);
			break;
		}
		case'5':{//插入元素（递归）
			int Key; char Data;
			cout<<"请输入要插入的元素内容："; cin>>Data; cin.sync();
			cout<<"请输入要插入的元素关键码："; cin>>Key; cin.sync();
			B.insert(Key,Data);
			break;
		}
		case'6':{//删除元素 
			int Key; BSTNode* purpose;
			cout<<"请输入要删除的元素关键码："; cin>>Key; cin.sync();
			purpose=B.Delete(Key);
			if(purpose==NULL) cout<<"输入的关键码不在该搜索二叉树范围内"<<endl;
			else cout<<"删除成功"<<endl;
			break;
		}
		case'7':{//展示元素 
			B.Show();
			cout<<endl<<endl;
			break;
		}
		case'8':{//向文件中写入 
			B.Outfile();
			cout<<"[写入完成]"<<endl;
			break;
		}
		case'9':{//从文件中读取 
			B.Infile(); 
			cout<<"[读取并构建完成]"<<endl;
			break;
		}
		case'A':{
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
