#include <iostream>

#include "Tree_class.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Read(TreeNode *tree){
	cout<<tree->data<<"   ";
}

int main(int argc, char** argv) {
	cout<<"************[������Ŀǰ��֧���ַ���]************"<<endl; 
	cout<<"�밴�չ�������ʽ���ж������ı�ʾ(ע��������ȥ����)"<<endl; 
	cout<<"  A(B,C(,D))  "<<"�õ��Ķ�����Ϊ��"<<endl;
	cout<<"     A"<<endl;
	cout<<"   B   C"<<endl;
	cout<<"         D"<<endl;
	
	Tree t;
	TreeNode *Root;
	Root = t.Build();
	
	char operation; //����  
	string judge; //�Ƿ�������в��� 
	
	cout<< "\t\t|--------------------------------------------------------------------------|\n";
    cout<< "\t\t|                       1.ǰ��������������ݹ飩                           |\n";
    cout<< "\t\t|                       2.����������������ݹ飩                           |\n";
    cout<< "\t\t|                       3.����������������ݹ飩                           |\n";
    cout<< "\t\t|                       4.ǰ��������������ǵݹ飩                         |\n";
    cout<< "\t\t|                       5.����������������ǵݹ飩                         |\n";
    cout<< "\t\t|                       6.����������������ǵݹ飩                         |\n";
    cout<< "\t\t|                       7.��������߶�                                     |\n";
    cout<< "\t\t|                       8.�������Ҷ������                                 |\n";
    cout<< "\t\t|                       9.���������                                       |\n";
    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	cout<<"��ѡ����Ҫ���еĲ�����";
	cin>>operation;cin.sync(); 
	while(1){
		switch(operation)
		{
			case '1':{
				cout<<"ǰ��������������ݹ飩�õ����Ϊ:"<<endl; 
				t.aheadscan(Root,Read);//ǰ�� 
				cout<<endl;
				break;
			}
			case '2':{
				cout<<"����������������ݹ飩�õ����Ϊ:"<<endl;
			    t.midscan(Root,Read);//���� 
	            cout<<endl;
				break;
			}
			case '3':{
				cout<<"����������������ݹ飩�õ����Ϊ:"<<endl;
				t.tailscan(Root,Read);//����
				cout<<endl; 
				break;
			}
			case '4':{
				cout<<"ǰ��������������ǵݹ飩�õ����Ϊ:"<<endl;
				t.aheadscan_s(Read); //ǰ�� 
	            cout<<endl;
	            break;
			}
			case '5':{
				cout<<"ǰ��������������ǵݹ飩�õ����Ϊ:"<<endl;
				t.midscan_s(Read); //���� 
	            cout<<endl;
	            break;
			}
			case '6':{//���� 
				cout<<"ǰ��������������ǵݹ飩�õ����Ϊ:"<<endl;
				t.tailscan_s(Read);
				cout<<endl;
				break;
			} 
			case '7':{ //����Ҷ������ 
				int leaves;
	            leaves = t.TreeLeaves();
	            cout<<"Ҷ������Ϊ��"<<leaves<<endl;
				break;
			}
			case '8':{ //����������߶� 
				int height;
	            height = t.TreeHeight();
	            cout<<"�ö������ĸ߶�Ϊ��"<<height<<endl; 
				break;
			} 
			case '9':{
				cout<<"���������Ϊ��"<<endl;
	            t.Output();
				break;
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
                    cout<< "\t\t|                       1.ǰ��������������ݹ飩                           |\n";
               	    cout<< "\t\t|                       2.����������������ݹ飩                           |\n";
              	    cout<< "\t\t|                       3.����������������ݹ飩                           |\n";
             	    cout<< "\t\t|                       4.ǰ��������������ǵݹ飩                         |\n";
               	    cout<< "\t\t|                       5.����������������ǵݹ飩                         |\n";
              	    cout<< "\t\t|                       6.����������������ǵݹ飩                         |\n";
              	    cout<< "\t\t|                       7.��������߶�                                     |\n";
               	    cout<< "\t\t|                       8.�������Ҷ������                                 |\n";
              	    cout<< "\t\t|                       9.���������                                       |\n";
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
