#include"BST_class.h"
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"����������������ĳ�ʼ����"<<endl;

	int num; BST B;
	cout<<"��ȷ��������������ȫ��Ԫ�ظ�����"; cin>>num; cin.sync(); 
	//ȷ��Ԫ�� 
	char* data=new char[num]; int* key=new int[num];
	cout<<"������Ԫ�����ݣ�"<<endl;
	for(int i=0; i<num;i++) cin>>data[i];
	cin.sync();
	cout<<"��������Ӧ�Ĺؼ��룺"<<endl;
	for(int i=0;i<num;i++) cin>>key[i];
	cin.sync();
	B.Build(num,key,data);
	
char operation; system("cls");
	while(1){
	   cout<< "\t\t|---------------------------------------------------------------|\n";
       cout<< "\t\t|                       1.���¹���                              |\n";
       cout<< "\t\t|                       2.ͨ���ؼ������Ԫ�أ��ǵݹ飩          |\n";
       cout<< "\t\t|                       3.ͨ���ؼ������Ԫ�أ��ݹ飩            |\n";
       cout<< "\t\t|                       4.����Ԫ�أ��ǵݹ飩                    |\n";
       cout<< "\t\t|                       5.���뺯�����ݹ飩                      |\n";
       cout<< "\t\t|                       6.ɾ��Ԫ��                              |\n";
       cout<< "\t\t|                       7.չʾ                                  |\n";
       cout<< "\t\t|                       8.��������Ԫ��д���ļ�                  |\n";
       cout<< "\t\t|                       9.���ļ��л�ȡ������Ԫ�ز�����          |\n";
       cout<< "\t\t|                       A.�˳�ϵͳ                             |\n";
       cout<< "\t\t|---------------------------------------------------------------|\n";
	   cout<<"��ѡ����Ҫ���еĲ�����"; cin>>operation; cin.sync();
	   
	   switch(operation){
	   	case'1':{//���¹��� 
	   		cout<<"��ȷ��������������ȫ��Ԫ�ظ�����"; cin>>num; cin.sync(); 
	        //ȷ��Ԫ�� 
	        data=new char[num]; key=new int[num];
	        cout<<"������Ԫ�����ݣ�"<<endl;
	        for(int i=0; i<num;i++) cin>>data[i];
	        cin.sync();
	        cout<<"��������Ӧ�Ĺؼ��룺"<<endl;
	        for(int i=0;i<num;i++) cin>>key[i];
	        cin.sync();
	        B.Build(num,key,data);
	   		break;
		}
		case'2':{//ͨ���ؼ�����Ԫ�أ��ǵݹ飩 
			int Key; BSTNode* purpose;
			cout<<"��������Ҫ���ҵĹؼ��룺"; cin>>Key; cin.sync();
			purpose=B.Search(Key);
			if(purpose==NULL) cout<<"����ؼ��벻��Ŀ��������������"<<endl;
			else cout<<"�������Ϊ��"<<purpose->data<<endl;
			break;
		}
		case'3':{//ͨ���ؼ�����Ԫ�أ��ݹ飩
			int Key; BSTNode* purpose;
			cout<<"��������Ҫ���ҵĹؼ��룺"; cin>>Key; cin.sync();
			purpose=B.search(Key);
			if(purpose==NULL) cout<<"����ؼ��벻��Ŀ��������������"<<endl;
			else cout<<"�������Ϊ��"<<purpose->data<<endl;
			break;
		}
		case'4':{//����Ԫ�أ��ǵݹ飩 
			int Key; char Data;
			cout<<"������Ҫ�����Ԫ�����ݣ�"; cin>>Data; cin.sync();
			cout<<"������Ҫ�����Ԫ�عؼ��룺"; cin>>Key; cin.sync();
			B.Insert(Key,Data);
			break;
		}
		case'5':{//����Ԫ�أ��ݹ飩
			int Key; char Data;
			cout<<"������Ҫ�����Ԫ�����ݣ�"; cin>>Data; cin.sync();
			cout<<"������Ҫ�����Ԫ�عؼ��룺"; cin>>Key; cin.sync();
			B.insert(Key,Data);
			break;
		}
		case'6':{//ɾ��Ԫ�� 
			int Key; BSTNode* purpose;
			cout<<"������Ҫɾ����Ԫ�عؼ��룺"; cin>>Key; cin.sync();
			purpose=B.Delete(Key);
			if(purpose==NULL) cout<<"����Ĺؼ��벻�ڸ�������������Χ��"<<endl;
			else cout<<"ɾ���ɹ�"<<endl;
			break;
		}
		case'7':{//չʾԪ�� 
			B.Show();
			cout<<endl<<endl;
			break;
		}
		case'8':{//���ļ���д�� 
			B.Outfile();
			cout<<"[д�����]"<<endl;
			break;
		}
		case'9':{//���ļ��ж�ȡ 
			B.Infile(); 
			cout<<"[��ȡ���������]"<<endl;
			break;
		}
		case'A':{
			exit(1);
			break;
		}
		default:{
			cout<<"����������������룺";
			continue;
		}
		break;
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
