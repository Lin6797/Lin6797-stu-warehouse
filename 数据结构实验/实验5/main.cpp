#include <iostream>
#include "Tree_class.h" 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Tree t;
	t.Build();
	
	char operation; //����  
	char judge; //�Ƿ�������в��� 
	
 
	while(1){
		cout<< "\t\t|--------------------------------------------------------------------------|\n";
        cout<< "\t\t|                       1.�����                                           |\n";
        cout<< "\t\t|                       2.��רҵ��                                         |\n";
        cout<< "\t\t|                       3.��༶��                                         |\n";
        cout<< "\t\t|                       4.��ѧ����                                         |\n";
        cout<< "\t\t|                       5.�˳�����                                         |\n";
	    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	    cout<<"��ѡ����Ҫ���еĲ�����";
	    cin>>operation;cin.sync();
		switch(operation) //ѡ������ 
		{
			case '1':{
				system("cls"); 
				cout<<"�����ű��������Ϊ:"<<endl; 
				t.output();
				cout<<endl;
				break;
			}
			case '2':{//��רҵ�� 
				t.Interlize();
				char major_operation; int major;
				while(1){
					cout<< "\t\t|--------------------------------------------------------------------------|\n";
                    cout<< "\t\t|                       1.��ѧУרҵ��                                     |\n";
                    cout<< "\t\t|                       2.������ѧԺרҵ��                               |\n";
                    cout<< "\t\t|                       3.�����ѧԺרҵ��                                 |\n";
                    cout<< "\t\t|                       4.�˳�ϵͳ                                         |\n";
                    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	                cout<<"��ѡ����Ҫ���еĲ�����"; cin>>major_operation; cin.sync();
	                switch(major_operation){
	            	   case'1':{
	            	   	 system("cls");
	            		 major=t.Major_number(t.root);
	            		 cout<<"ѧУרҵ��Ϊ��"<<major<<endl;
	            		 break;
	            	   }
	            	   case'2':{
	            	   	  system("cls");
	            		  major=t.Major_number(t.root->sons[0]);
	            		  cout<<"�����ѧԺרҵ��Ϊ��"<<major<<endl; 
						  break;
	            	   }
	            	   case'3':{
	            	   	   system("cls");
	            		   major=t.Major_number(t.root->sons[1]);
	            		   cout<<"����ѧԺרҵ��Ϊ��"<<major<<endl;
	            		   break;
	            	   }
	            	   case'4':{
	            	   	   return 0;
	            	   } 
	            	   default:{
	            	   	    system("cls");
	            	   	    cout<<"***********�����������������***********"<<endl;
	            	   	    continue;
	            	   }
	                }
	                break;
				}
				break;
			}
			case '3':{//��༶��Ŀ  
				t.Interlize();
				char class_operation;int class_num;
				while(1){
					cout<< "\t\t|--------------------------------------------------------------------------|\n";
                    cout<< "\t\t|                       1.��ѧУ�༶��                                     |\n";
                    cout<< "\t\t|                       2.������ѧԺ�༶��                               |\n";
                    cout<< "\t\t|                       3.�����ѧԺ�༶��                                 |\n";
                    cout<< "\t\t|                       4.��������ѧרҵ�༶��                           |\n";
                    cout<< "\t\t|                       5.����Ϣ��ȫרҵ�༶��                             |\n";
                    cout<< "\t\t|                       6.��������רҵ�༶��                               |\n";
                    cout<< "\t\t|                       7.�������Ϣ��רҵ�༶��                           |\n";
                    cout<< "\t\t|                       8.����Ϣ����רҵ�༶��                             |\n";
                    cout<< "\t\t|                       9.�˳�ϵͳ                                         |\n";
                    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	                cout<<"��ѡ����Ҫ���еĲ�����"; cin>>class_operation; cin.sync();
	                switch(class_operation){
	            	   case'1':{
	            	   	 system("cls");
	            		 class_num=t.Class_number(t.root);
	            		 cout<<"ѧУ�༶��Ϊ��"<<class_num<<endl; 
	            		 break;
	            	   }
	            	   case'2':{
	            	   	  system("cls");
	            		  class_num=t.Class_number(t.root->sons[0]);
	            		  cout<<"�����ѧԺ�༶��Ϊ��"<<class_num<<endl;
	            		  break;
	            	   }
	            	   case'3':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[1]);
	            		   cout<<"����ѧԺ�༶��Ϊ��"<<class_num<<endl; 
	            		   break;
	            	   }
	            	   case'4':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[0]->sons[0]);
	            		   cout<<"�������ѧרҵ�༶��Ϊ��"<<class_num<<endl;
						   break;
	            	   }
	            	   case'5':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[0]->sons[1]);
	            		   cout<<"��Ϣ��ȫרҵ�༶��Ϊ��"<<class_num; 
						   break;
	            	   }
	            	   case'6':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[0]->sons[2]);
	            		   cout<<"������רҵ�༶��Ϊ��"<<class_num<<endl; 
						   break;
	            	   }
	            	   case'7':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[1]->sons[0]);
	            		   cout<<"������Ϣ��רҵ�༶��Ϊ��"<<class_num<<endl; 
						   break;
	            	   }
	    	           case'8':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[1]->sons[1]);
	            		   cout<<"��Ϣ����רҵ�༶��Ϊ��"<<class_num<<endl; 
						   break;
	            	   }
	            	   case'9':{
	            	   	   return 0;
	            	   }
	            	   default:{
	            	   	    system("cls");
	            	   	    cout<<"***********�����������������***********"<<endl;
	            	   	    continue;
	            	   }
	                }
	                break;
				}
				break;
			}
			case '4':{//������ 
				t.Interlize();
				char class_operation;int student;
				while(1){
					cout<< "\t\t|--------------------------------------------------------------------------|\n";
                    cout<< "\t\t|                       1.��ѧУѧ����                                     |\n";
                    cout<< "\t\t|                       2.������ѧԺѧ����                               |\n";
                    cout<< "\t\t|                       3.�����ѧԺѧ����                                 |\n";
                    cout<< "\t\t|                       4.��������ѧרҵѧ����                           |\n";
                    cout<< "\t\t|                       5.����Ϣ��ȫרҵѧ����                             |\n";
                    cout<< "\t\t|                       6.��������רҵѧ����                               |\n";
                    cout<< "\t\t|                       7.�������Ϣ��רҵѧ����                           |\n";
                    cout<< "\t\t|                       8.����Ϣ����רҵѧ����                             |\n";
                    cout<< "\t\t|                       9.�˳�ϵͳ                                         |\n";
                    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	                cout<<"��ѡ����Ҫ���еĲ�����"; cin>>class_operation; cin.sync();
	                switch(class_operation){
	            	   case'1':{
	            	   	 system("cls");
	            		 student=t.Student_number(t.root);
	            		 cout<<"ѧУѧ����Ϊ��"<<student<<endl; 
						 break;
	            	   }
	            	   case'2':{
	            	   	  system("cls");
	            		  student=t.Student_number(t.root->sons[0]);
	            		  cout<<"�����ѧԺѧ����Ϊ��"<<student<<endl; 
						  break;
	            	   }
	            	   case'3':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[1]);
	            		   cout<<"����ѧԺѧ����Ϊ��"<<student<<endl; 
						   break;
	            	   }
	            	   case'4':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[0]->sons[0]);
	            		   cout<<"�������ѧרҵѧ����Ϊ��"<<student<<endl; 
						   break;
	            	   }
	            	   case'5':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[0]->sons[1]);
	            		   cout<<"��Ϣ��ȫרҵѧ����Ϊ��"<<student<<endl; 
						   break;
	            	   }
	            	   case'6':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[0]->sons[2]);
	            		   cout<<"������רҵѧ����Ϊ��"<<student<<endl; 
						   break;
	            	   }
	            	   case'7':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[1]->sons[0]);
	            		   cout<<"������Ϣ��רҵѧ����Ϊ��"<<student<<endl; 
						   break;
	            	   }
	    	           case'8':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[1]->sons[1]);
	            		   cout<<"��Ϣ����רҵѧ����Ϊ��"<<student<<endl; 
						   break;
	            	   }
	            	   default:{
	            	   	    system("cls");
	            	   	    cout<<"***********�����������������***********"<<endl;
	            	   	    continue;
	            	   }
	                }
	                break;
				}
	            break;
			}
			case '5':{ //�˳����� 
				return 0;
			}
			default:{
				cout<<cout<<"***********�����������������***********"<<endl;
				cin>>operation;cin.sync();
				continue;
			}
			break;
		}
		
		while(1){
			cout<<endl<<"�Ƿ�������в�������Y/N����"; cin>>judge; cin.sync();
			if(judge=='y'||judge=='Y') break;
			else if(judge=='n'||judge=='N') return 0;
			else{
				cout<<"***********�����������������***********";
			}
		}
	}
	
	return 0;
}
