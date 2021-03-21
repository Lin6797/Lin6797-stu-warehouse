/*************������****************/
/**********���ߣ���ӱ��************/
/*********2019��10��21���հ�*******/ 

#include <iostream>
#include"Stack_class.h"
#include"Queue_class.h"
using namespace std;

int main() {
	char operation; //���� 
	Queue q; //�����ඨ�� 
	Stack s; //ջ�ඨ�� 
	string car_number; //���ƶ��� 
	int money; //Ӧ����� 
	int purpose; //Ŀ�공����� 
	string judge; //�Ƿ�������в��� 
	
	cout<< "\t\t|--------------------------------------------------------------------------|\n";
    cout<< "\t\t|                       1.�������                                         |\n";
    cout<< "\t\t|                       2.�����뿪����                                     |\n";
    cout<< "\t\t|                       3.�鿴�����и�����                                 |\n";
    cout<< "\t\t|                       4.�鿴�Ⱥ���������                                 |\n";
    cout<< "\t\t|                       5.�˳�ϵͳ                                         |\n";
    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	cout<<"��ѡ����Ҫ���еĲ�����";
	cin>>operation;cin.sync(); 
	while(1){
		switch(operation)
		{
			case '1':{ //�����복�� 
				if(q.IsFull()){
					cout<<"�Ⱥ����������뵽���������������ͣ��"<<endl; 
				}
				else{
					cout<<"�������������ƺţ�";
					cin>>car_number;cin.sync();
					q.EnQueue(car_number);
					
					if(s.IsFull()){
						cout<<"ͣ�������������ڵȺ������еȺ�"<<endl;
					}
					else{
						car_number=q.OutQueue();
						s.Push(car_number);
					}
				}
				break;
			}
			case '2':{ //���������� 
				cout<<"�������ջ��������ţ�";
				cin>>purpose;cin.sync();
				if(s.num < purpose) 
				cout<<"�������ݴ���"<<endl; 
				else{
				   money = s.Money(purpose);
				   s.Pop(purpose);
				   cout<<endl<<"��������Ҫ���"<<money<<"Ԫ"<<endl; 
			    
				   car_number=q.OutQueue();
				   s.Push(car_number);
			    }
				break;
			}
			case '3':{ //չʾջ��Ԫ�� 
				s.show();
				break;
			}
			case '4':{ //չʾ������Ԫ�� 
				q.show();
				break;
			}
			case '5':{ //�˳�ϵͳ 
				return 0;
			}
			default:{
				cout<<"����������������룺";
				cin>>operation;cin.sync();
				continue;
			}
		}
		
		cout<<endl;
	    cout<<"------------------------------------------------------------------------------------------"; 
	    cout<<endl<<"�Ƿ�������в�������Y/N����";
	    cin>>judge;cin.sync();
	    while(1)
			{
	            if(judge == "Y" || judge == "y" )
				{
	             cout<< "\t\t|--------------------------------------------------------------------------|\n";
                 cout<< "\t\t|                       1.�������                                         |\n";
                 cout<< "\t\t|                       2.�����뿪����                                     |\n";
                 cout<< "\t\t|                       3.�鿴�����и�����                                 |\n";
                 cout<< "\t\t|                       4.�鿴�Ⱥ���������                                 |\n";
                 cout<< "\t\t|                       5.�˳�ϵͳ                                         |\n";
                 cout<< "\t\t|--------------------------------------------------------------------------|\n";
	            	cout<< "��������Ҫִ�еĲ�����Ӧ�ı��:";
					cin>>operation;cin.sync();
					break;
	            }
	            else if(judge == "N" || judge == "n" )
				{
	        	    cout<< endl<< "    [�����˳�]    ";
	        	    return 0;
	            }
	            else
				{
	            	cout<< "�����������������:";
	            	cin>>judge;cin.sync();
	            }
	        }
	}
	return 0;
}
