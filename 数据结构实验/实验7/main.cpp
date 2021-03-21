#include "Graphmtx_detail.cpp"
#include "Graphlnk_detail.cpp"
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//��С������ 
void Weight(){
	system("cls"); 
	cout<<"�뽨����Ȩͼ��"<<endl;
	char operation; int num, max, link, v1, v2, weight; char *pu;
	
	cout<<"������Ŀ�꽨��ͼ��������"; cin>>max; cin.sync();
	Graphmtx<char> WMT(max);//��Ȩ����ͼ
	Graphlnk<char> WLN(max);//��Ȩ�ڽӱ� 
	
    cout<<"������Ŀ�꽨��ͼ��Ԫ�ظ�����"; cin>>num; cin.sync();pu=new char[num];
	
	cout<<"������Ŀ�꽨��ͼ��Ԫ������(�ַ�����)��";
    for(int i=0; i<num; i++) {cin>>pu[i];}
    cin.sync();
    
	WMT.Build(num,pu);
    WLN.Build(num,pu);
	
	cout<<"������ͼ�ڱ�����"; cin>>link; cin.sync();
	
	cout<<"�밴��[��ʼ�� ��ֹ�� Ȩ��]�ĸ�ʽȷ��������ϵ���(�����Ϊ0)"<<endl;
	for(int i=0;i<num;i++) cout<<i<<"."<<pu[i]<<"   ";//���ĿǰԪ�����ݺͱ��
	cout<<endl;
	
	for(int i=0;i<link;i++){//���� 
		cin>>v1; cin>>v2; cin>>weight;
		WMT.Link(v1,v2,weight);
		WMT.Link(v2,v1,weight);
		WLN.Link(v1,v2,weight);
	}

	while(1){
		cout<< "\t\t|-------------------------------------------------------------------|\n";
        cout<< "\t\t|                       1.Prim                                      |\n";
        cout<< "\t\t|                       2.Kruskal                                   |\n";
        cout<< "\t\t|                       3.��������                                  |\n";
        cout<< "\t\t|                       4.���·��                                  |\n";
        cout<< "\t\t|                       5.�˳��Դ�Ȩͼ���в���                      |\n";
        cout<< "\t\t|                       6.�˳�����                                  |\n";
	    cout<< "\t\t|-------------------------------------------------------------------|\n";
	    cout<<"��ѡ��Ҫ���еĲ�����";
	    cin>>operation;cin.sync();
	    switch(operation){
	    	case'1':{
	    		cout<<"�õ��Ŀ��Ա�������֦�У�"<<endl; 
	    		WMT.Prim();
	    		cout<<endl;
	    		ofstream out("Graph.txt",ios::app);
				out<<endl<<endl;
				out.close(); 
	    		break;
	    	}
	    	case'2':{
	    		cout<<"�õ��Ŀ��Ա�������֦�У�"<<endl;
	    		WMT.Kruskal();
				cout<<endl;
	    		ofstream out("Graph.txt",ios::app);
				out<<endl<<endl;
				out.close();
	    		break;
	    	}
	    	case'3':{
	    		cout<<"�õ�����������֮һΪ��"<<endl;
	    		WLN.TolplogicalSort();
	    		cout<<endl;
	    		ofstream out("Graph.txt",ios::app);
				out<<endl<<endl;
				out.close();
	    		break;
	    	}
	    	case'4':{
	    		int start;
	            for(int i=0;i<num;i++) cout<<i<<"."<<pu[i]<<"   ";//���ĿǰԪ�����ݺͱ��
	            cout<<endl;
				cout<<"��������Ϊ����Ԫ�ر�ţ�"; cin>>start; cin.sync(); 
	            cout<<"��������·��Ϊ��"<<endl;
	    		WMT.Dijstrate(start);
	    		cout<<endl;
	    		ofstream out("Graph.txt",ios::app);
				out<<endl<<endl;
				out.close();
	    		break;
	    	}
			case'5':return ;
			case'6':exit(1);
			default:{
				system("cls");
				cout<<"�����������������"<<endl;
				continue;
			}
	    }
	    char con;//�Ƿ���������־ 
		while(1){
		    cout<<"�Ƿ�������иò�������Y/N����"; cin>>con; cin.sync();
		    system("cls");
			switch(con){
			   case'y':
			   case'Y': break;
			   case'n':
			   case'N': return ;
			   default:{ system("cls"); cout<<"�����������������"<<endl;}
		    }
		    if(con=='y'||con=='Y') break;
		}
		continue;
	}
}

//����Ϊ��Ȩͼ 

void UnWeight(){
	system("cls"); 
	cout<<"�뽨������Ȩͼ��"<<endl;
	char operation; int num, max, link, v1, v2, weight; char *pu;
	
	cout<<"������Ŀ�꽨��ͼ��������"; cin>>max; cin.sync(); Graphlnk<char> LN(max);//��Ȩ�ڽӱ� 
	
    cout<<"������Ŀ�꽨��ͼ��Ԫ�ظ�����"; cin>>num; cin.sync();
	
	cout<<"������Ŀ�꽨��ͼ��Ԫ������(�ַ�����)��";
    for(int i=0; i<num; i++){cin>>pu[i];}
    cin.sync();
    
    if(LN.Build(num,pu) ==false){ cout<<"�������ݴ���";}
	cout<<"������ͼ�ڱ�����"; cin>>link; cin.sync();
	
	cout<<"�밴��[��ʼ�� ��ֹ��]�ĸ�ʽȷ��������ϵ���(�����Ϊ0)"<<endl;
	for(int i=0;i<num;i++) cout<<i<<"."<<pu[i]<<"   ";//���ĿǰԪ�����ݺͱ��
	cout<<endl; 
	for(int i=0;i<link;i++){//���� 
		cin>>v1; cin>>v2;
		LN.Link(v1,v2,1);
		LN.Link(v2,v1,1);
	}
	
	
	while(1){
		cout<< "\t\t|-------------------------------------------------------------------|\n";
        cout<< "\t\t|                       1.DFS                                       |\n";
        cout<< "\t\t|                       2.WFS                                       |\n";
        cout<< "\t\t|                       3.�˳��Դ�Ȩͼ���в���                      |\n";
        cout<< "\t\t|                       4.�˳�����                                  |\n";
	    cout<< "\t\t|-------------------------------------------------------------------|\n";
	    cout<<"��ѡ��Ҫ���еĲ�����";
	    cin>>operation;cin.sync();
	    switch(operation){
	    	case'1':{
	    		int start;
	            for(int i=0;i<num;i++) cout<<i<<"."<<pu[i]<<"   ";//���ĿǰԪ�����ݺͱ��
	            cout<<endl;
				cout<<"��������Ϊ����Ԫ�ر�ţ�"; cin>>start; cin.sync(); 
	            cout<<"��ȱ����õ�����Ϊ��"<<endl;
				LN.DFS(start);
				cout<<endl;
	    		ofstream out("Graph.txt",ios::app);
				out<<endl<<endl;
				out.close();
	    		break;
	    	}
	    	case'2':{
	    		int start;
	            for(int i=0;i<num;i++) cout<<i<<"."<<pu[i]<<"   ";//���ĿǰԪ�����ݺͱ��
	            cout<<endl;
				cout<<"��������Ϊ����Ԫ�ر�ţ�"; cin>>start; cin.sync(); 
	            cout<<"��ȱ����õ�����Ϊ��"<<endl;
				LN.WFS(start);
				cout<<endl;
	    		ofstream out("Graph.txt",ios::app);
				out<<endl<<endl;
				out.close();
	    		break;
	    	}
			case'3':return ;
			case'4':exit(1);
			default:{
				system("cls");
				cout<<"�����������������"<<endl;
				continue;
			}
	    }
	    char con;//�Ƿ���������־ 
		while(1){
		    cout<<"�Ƿ��������Ȩͼ���в�������Y/N����"; cin>>con; cin.sync();
		    system("cls");
			switch(con){
			   case'y':
			   case'Y': break;
			   case'n':
			   case'N': return ;
			   default:{ system("cls"); cout<<"�����������������"<<endl;}
		    }
		    if(con=='y'||con=='Y') break;
		}
		continue;
	}
}
//����Ϊ��Ȩͼ���� 

int main(int argc, char** argv) {
	char operation;
	while(1){
		cout<< "\t\t|-------------------------------------------------------------------|\n";
        cout<< "\t\t|                       1.����Ȩͼ����                              |\n";
        cout<< "\t\t|                       2.��Ȩͼ����                                |\n";
        cout<< "\t\t|                       3.�˳�����                                  |\n";
	    cout<< "\t\t|-------------------------------------------------------------------|\n";
	    cout<<"��ѡ����Ҫ���еĲ�����";
	    cin>>operation;cin.sync();
	    switch(operation){
	    	case'1':{
	    		UnWeight(); 
	    		break;
	    	}
	    	case'2':{
	    		Weight();
	    		break;
	    	}
			case'3':exit(1);
			default:{
				system("cls");
				cout<<"�����������������"<<endl;
				continue;
			}
	    }
	    char con;//�Ƿ���������־ 
		while(1){
		    cout<<"�Ƿ����������ͼ���в�������Y/N����"; cin>>con; cin.sync();
		    switch(con){
			   case'y':
			   case'Y': break;
			   case'n':
			   case'N': exit(1);
			   default:{ system("cls"); cout<<"�����������������"<<endl;}
		    }
		    if(con=='y'||con=='Y') break;
		}
		continue;
	}
	char e; cin>>e;
	return 0;
}
