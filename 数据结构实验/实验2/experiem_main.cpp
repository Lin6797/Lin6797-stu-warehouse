/*************���İ�****************/
/**********���ߣ���ӱ��************/
/*********2019��10��10���հ�*******/ 

//������ 

#include <iostream>
#include "experiem_class.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	LinearList t;
	char operation_judge;
	string judge;
	
	cout<< "\t\t|--------------------------------------------------------------------------|\n";
    cout<< "\t\t|                  1.��ʼ������                                            |\n";
    cout<< "\t\t|                  2.�½�����                                              |\n";
    cout<< "\t\t|                  3.�������в���ĳԪ��                                    |\n";
    cout<< "\t\t|                  4.��������ɾ��ĳλ�õ�ĳԪ��                            |\n";
    cout<< "\t\t|                  5.�������в���ĳԪ��                                    |\n";
    cout<< "\t\t|                  6.���������                                          |\n";
    cout<< "\t\t|                  7.ʵ������Ԫ�ص�����                                    |\n";
    cout<< "\t\t|                  8.�ֽ������ֽ�Ϊż���������������������������    |\n";
    cout<< "\t\t|                  9.�˳�����                                              |\n";
    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	cout<< "������Ҫִ�еĲ�����Ӧ�ı��:";
	cin>>operation_judge;cin.sync();
	cout<<endl;
	 
	while(1)
	{
		   switch(operation_judge)
		  {
		    case '1':{
			  t.Interlize();
			  cout<<"��ʼ���õ���Ϊ��"<<endl;
			  t.output(); 
			  break;
		    }
		    case '2':{
			  int num; //����Ԫ�� 
			  char build_judge; //�жϽ����� 
			  cout<<"��������Ҫ������������Ԫ�ظ�����";
			  cin>>num;cin.sync();
			
			  cout<< "\t\t|--------------------------------------------------------------------------|\n";
              cout<< "\t\t|                       1.ͷ�巨�������õ�����                           |\n";
              cout<< "\t\t|                       2.��巨�������õ�����                           |\n";
              cout<< "\t\t|--------------------------------------------------------------------------|\n";
			  cout<<"��ѡ��������ķ�����1/2����"; //1-ͷ�巨��2-β�巨 
			  cin>>build_judge;cin.sync();
			
			
			  while(1)//�жϽ�����
	          { 
		        if(build_judge == '1'){
			        t.head_Build(num);
			        cout<<"����ǰ�巨�õ�����Ϊ��"<<endl;
			        t.output();
			        cout<<endl; 
			        break;
		        }
		        if(build_judge == '2'){
			        t.behind_Build(num);
			        cout<<"���ú�巨�õ�����Ϊ��"<<endl;
			        t.output();
			        cout<<endl; 
			        break;
		        }
		        else{
			        cout<<"�������ݴ������������룺";
			        cin>>build_judge;cin.sync();
		        } 
	          }
			  break; //����opera��switch 
		    }
		    case '3':{ //������� 
			  int site; //Ԫ�ز���λ�� 
			  int purpose; //Ԫ�� 
			
			  cout<<"ԭʼ����Ϊ��"<<endl;
			  t.output();
			  cout<<endl;
			
			  cout<<"��������Ҫ�����Ԫ�ص�λ��(Ŀ��Ԫ�س�Ϊ��iλ)��";
			  cin>>site; cin.sync();
			  cout<<"��������Ҫ�����Ŀ��Ԫ�أ�";
			  cin>>purpose;cin.sync();
			
			  while(1)
			  {
			    if(site>0 && site<=t.Num+1){
				   t.Insert(site, purpose);
				   cout<<"����Ԫ�غ�õ���Ϊ��"<<endl;
				   t.output();
				   break;
			    }
			    else{
				    cout<<"�����ɲ���Ԫ�صķ�Χ������������Ҫ�����λ��(Ŀ��Ԫ�س�Ϊ��iλ)��";
				    cin>>site;cin.sync(); 
			    }
			  }
			  break;
		    }
		    case '4':{ //ɾ������ 
		 	  int site;
		 	
		 	  cout<<"ɾ��ǰ��Ϊ��"<<endl;
		 	  t.output();
		 	  cout<<endl;
		 	
		 	  cout<<"������Ҫɾ����Ԫ��λ�ã�ɾ����iλԪ�أ���";
			  cin>>site;cin.sync();
		 	
		 	  while(1)
			  {
			    if(site>0 && site<=t.Num){
				  t.Delete(site);
				  cout<<"ɾ�����Ϊ��"<<endl;
				  t.output();
				  break;
			    }
			    else{
				  cout<<"��������Ԫ�ط�Χ������������Ҫɾ����Ԫ��λ��(ɾ����iλԪ��)��";
				  cin>>site;cin.sync(); 
			    }
			  }
		 	  break;
		    }
		    case '5':{//���Ҳ��� (�ĳɲ�����)
		 	   int purpose;
			   cout<<"������Ҫ���ҵ�Ԫ�أ�";
			   cin>>purpose;cin.sync();
			 
			   if(t.Search(purpose))
			   cout<<endl<<"[�������]";
			   else
			   cout<<"���в����ڸ�Ԫ��";
			  
		 	   break;
		    }
		    case '6':{ //����� 
		 	  cout<<"Ŀǰ��Ϊ��"<<t.Num; 
		 	  break;
		    }
		    case '7':{ //�������� 
			  t.reLink();
			  cout<<"���ú�õ���Ϊ��"<<endl;
			  t.output();
		 	  break;
		    }
		    case '8':{ //�ֽ� 
		 	  t.Part();
		 	  break;
		    }
		    case '9':{ //�˳� 
		 	  cout<<"    [�����˳�]    ";
		 	  return 0;
		    }
		    default:
		    {
	          cout<< endl<< "�����������������:";
	          cin>>operation_judge; cin.sync();
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
                 cout<< "\t\t|                       1.��ʼ������                                       |\n";
                 cout<< "\t\t|                       2.�½�����                                         |\n";
                 cout<< "\t\t|                       3.�������в���ĳԪ��                               |\n";
                 cout<< "\t\t|                       4.��������ɾ��ĳλ�õ�ĳԪ��                       |\n";
                 cout<< "\t\t|                       5.�������в���ĳԪ��                               |\n";
                 cout<< "\t\t|                       6.���������                                     |\n";
                 cout<< "\t\t|                       7.ʵ������Ԫ�ص�����                               |\n";
                 cout<< "\t\t|                       8.�ֽ������ֽ�Ϊż���������������             |\n";
                 cout<< "\t\t|                       9.�˳�����                                         |\n";
                 cout<< "\t\t|--------------------------------------------------------------------------|\n";
	            	cout<< "��������Ҫִ�еĲ�����Ӧ�ı��:";
					cin>>operation_judge;cin.sync();
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
