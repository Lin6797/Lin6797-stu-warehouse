#include"Student_class.h"
#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	BST B;
    char operation; system("cls");
	while(1){
	   cout<< "\t\t|---------------------------------------------------------------|\n";
       cout<< "\t\t|                       1.�½�ͨѶ��                            |\n";
       cout<< "\t\t|                       2.��������Ϣ                            |\n";
       cout<< "\t\t|                       3.ɾ����Ϣ                              |\n";
       cout<< "\t\t|                       4.���ļ��ж�ȡ��Ϣ�����µĶ�����        |\n";
       cout<< "\t\t|                       5.���ļ���д����Ϣ                      |\n";
       cout<< "\t\t|                       6.��ѯѧ����Ϣ                          |\n";
       cout<< "\t\t|                       7.���ȫ��ѧ����Ϣ                      |\n";
       cout<< "\t\t|                       8.�˳�ϵͳ                              |\n";
       cout<< "\t\t|---------------------------------------------------------------|\n";
	   cout<<"��ѡ����Ҫ���еĲ�����"; cin>>operation; cin.sync();
	   
	   switch(operation){
	   	case'1':{//�½� 
	   		cout<<"��ȷ��Ҫ�����ȫ��ѧ��������";int num;cin>>num;cin.sync(); 
			int* key=new int[num]; 
			Data** data=new Data*[num];//���ٿռ� 
			for(int i=0;i<num;i++){
			    data[i]=new Data[1];
		        cout<<"������ѧ�ţ�"; cin>>key[i]; cin.sync();
		        cout<<"������������"; cin>>(data[i]->name); cin.sync();
		        cout<<"�������Ա�(M/F)��"; cin>>(data[i]->sex); cin.sync();
		        cout<<"������������ڣ���ʽ��20200101��:"; cin>>(data[i]->birthday); cin.sync();
		        cout<<"������绰����:"; cin>>(data[i]->phone); cin.sync();
		        cout<<"�������ַ��"; cin>>(data[i]->adver); cin.sync();
		        system("cls");
	        }
	        B.Build(num,key,data);
			break; 
		}
		case'2':{//��������Ϣ 
			int key; Data* data=new Data[1];
			cout<<"����������ѧ����Ϣ��"<<endl;
			//���������Ϣ 
		    cout<<"������ѧ�ţ�"; cin>>key; cin.sync();
		    cout<<"������������"; cin>>(data->name); cin.sync();
		    cout<<"�������Ա�(M/F)��"; cin>>(data->sex); cin.sync();
		    cout<<"������������ڣ���ʽ��20200101��:"; cin>>(data->birthday); cin.sync();
		    cout<<"������绰����:"; cin>>(data->phone); cin.sync();
		    cout<<"�������ַ��"; cin>>(data->adver); cin.sync();
			//�������������Ϣ 
			B.Insert(key,data);
			break;
		}
		case'3':{//ɾ��ѧ����Ϣ 
			int Key; BSTNode* purpose;
			cout<<"������Ҫɾ����ѧ��ѧ�ţ�"; cin>>Key; cin.sync();
			purpose=B.Delete(Key);
			if(purpose==NULL) cout<<"����Ĺؼ��벻�ڸ�������������Χ��"<<endl;
			else cout<<"ɾ���ɹ�"<<endl;
			break;
		}
		case'4':{//���ļ��ж�ȡ��Ϣ�����µĶ����� 
			B.Infile();
			cout<<"[�������]"<<endl;
			break;
		}
		case'5':{//���ļ���д����Ϣ
			B.Outfile();
			break;
		}
		case'6':{//��ѯѧ����Ϣ
			int key; BSTNode* current;
			cout<<"������Ҫ��ѯ��ѧ��ѧ�ţ�"<<endl; cin>>key; cin.sync();
			current=B.Search(key);
			if(current!=NULL){
				cout<<"�õ�ѧ���ľ�����ϢΪ��"<<endl;
				cout<<"��ѧ��ѧ��Ϊ��"<<current->key<<endl;
				cout<<"��ѧ������Ϊ��"<<current->data->name<<endl;
				cout<<"��ѧ���Ա�Ϊ��"<<current->data->sex<<endl;
				cout<<"��ѧ����������Ϊ��"<<current->data->birthday<<endl; 
				cout<<"��ѧ���绰����Ϊ��"<<current->data->phone<<endl; 
				cout<<"��ѧ��סַΪ��"<<current->data->adver<<endl; 
			} 
			else cout<<"��ѧ����Ϣδ��¼��"<<endl;
			break;
		}
		case'7':{//չʾԪ�� 
			B.Show();
			cout<<endl<<endl;
			break;
		}
		case'8':{
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
