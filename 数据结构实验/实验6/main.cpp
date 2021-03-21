#include "HufTree_class.h"
#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"���Ƚ��й��������ĳ�ʼ����"<<endl; Huffman H; 
	char operation; system("cls");
	while(1){
	   cout<< "\t\t|---------------------------------------------------------------|\n";
       cout<< "\t\t|                       I.(Interlize)��ʼ��                     |\n";
       cout<< "\t\t|                       E.(Encoding)���ļ����б���              |\n";
       cout<< "\t\t|                       D.(Decoding)���ļ���������              |\n";
       cout<< "\t\t|                       P.(Print)��ӡ�ļ�����                   |\n";
       cout<< "\t\t|                       T.(Tree Print)��ӡ�����Ĺ�������        |\n";
       cout<< "\t\t|                       X.(Exit)�˳�ϵͳ                        |\n";
       cout<< "\t\t|---------------------------------------------------------------|\n";
	   cout<<"��ѡ����Ҫ���еĲ�����"; cin>>operation; cin.sync();
	   
	   switch (operation){
	   	      case 'i': 
			  case 'I':{//��ʼ�� 
	   	    	system("cls");
				H.Interlize();
	   		    break;
	   	      }
	   	      case'e':
			  case'E':{//���� 
				system("cls");
				H.Encoding();
				cout<<"�������"<<endl; 
				break;
	   	      }
	   	      case'd': 
			  case'D':{//���� 
	   	    	system("cls");
				H.Decoding();
				break;
	   	      }
	   	      case'p':
			  case'P':{//��ӡ�ļ����� 
	   	    	system("cls");
				cout<<"���ļ��ı���Ϊ��"<<endl;
				H.Print();
	   	    	break;
	   	      }
	   	      case't': 
			  case'T':{//��ӡ�������� 
	   	    	system("cls");
				H.TreePrint(); 
	   	    	break;
	   	      }
			  case'x':
			  case'X': {cout<<"[�����˳�����]"<<endl; return 0;}//�˳����� 
	   	      default:{
	   	    	system("cls");
				cout<<"�������,�����½�������"<<endl; 
                continue;	
	   	      }
	   }
	   
	   char con_judge;
	   while(1){
	   	cout<<"�Ƿ�������в�������Y/N����"; cin>>con_judge; cin.sync();
	   	system("cls");
	   	switch(con_judge){
	   		case'y':
	   		case'Y':{con_judge='Y';break;}
	   		case'n':
	   		case'N':{cout<<"[�����˳�����]"<<endl; return 0;}
	   		default:{cout<<"�����������������"<<endl;continue;}
	   	}
	   	break;
	   }
    }
	return 0;
}
