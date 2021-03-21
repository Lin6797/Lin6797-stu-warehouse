#include "HufTree_class.h"
#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"请先进行哈夫曼树的初始化："<<endl; Huffman H; 
	char operation; system("cls");
	while(1){
	   cout<< "\t\t|---------------------------------------------------------------|\n";
       cout<< "\t\t|                       I.(Interlize)初始化                     |\n";
       cout<< "\t\t|                       E.(Encoding)对文件进行编码              |\n";
       cout<< "\t\t|                       D.(Decoding)对文件进行译码              |\n";
       cout<< "\t\t|                       P.(Print)打印文件编码                   |\n";
       cout<< "\t\t|                       T.(Tree Print)打印建立的哈夫曼树        |\n";
       cout<< "\t\t|                       X.(Exit)退出系统                        |\n";
       cout<< "\t\t|---------------------------------------------------------------|\n";
	   cout<<"请选择你要进行的操作："; cin>>operation; cin.sync();
	   
	   switch (operation){
	   	      case 'i': 
			  case 'I':{//初始化 
	   	    	system("cls");
				H.Interlize();
	   		    break;
	   	      }
	   	      case'e':
			  case'E':{//编码 
				system("cls");
				H.Encoding();
				cout<<"编码完成"<<endl; 
				break;
	   	      }
	   	      case'd': 
			  case'D':{//译码 
	   	    	system("cls");
				H.Decoding();
				break;
	   	      }
	   	      case'p':
			  case'P':{//打印文件编码 
	   	    	system("cls");
				cout<<"该文件的编码为："<<endl;
				H.Print();
	   	    	break;
	   	      }
	   	      case't': 
			  case'T':{//打印哈夫曼树 
	   	    	system("cls");
				H.TreePrint(); 
	   	    	break;
	   	      }
			  case'x':
			  case'X': {cout<<"[正在退出程序]"<<endl; return 0;}//退出程序 
	   	      default:{
	   	    	system("cls");
				cout<<"输入错误,请重新进行输入"<<endl; 
                continue;	
	   	      }
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
