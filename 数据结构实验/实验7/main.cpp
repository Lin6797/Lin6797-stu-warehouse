#include "Graphmtx_detail.cpp"
#include "Graphlnk_detail.cpp"
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//最小生成树 
void Weight(){
	system("cls"); 
	cout<<"请建立带权图："<<endl;
	char operation; int num, max, link, v1, v2, weight; char *pu;
	
	cout<<"请输入目标建立图的容量："; cin>>max; cin.sync();
	Graphmtx<char> WMT(max);//带权矩阵图
	Graphlnk<char> WLN(max);//带权邻接表 
	
    cout<<"请输入目标建立图的元素个数："; cin>>num; cin.sync();pu=new char[num];
	
	cout<<"请输入目标建立图的元素内容(字符类型)：";
    for(int i=0; i<num; i++) {cin>>pu[i];}
    cin.sync();
    
	WMT.Build(num,pu);
    WLN.Build(num,pu);
	
	cout<<"请输入图内边数："; cin>>link; cin.sync();
	
	cout<<"请按照[起始点 终止点 权重]的格式确定各点联系情况(起点编号为0)"<<endl;
	for(int i=0;i<num;i++) cout<<i<<"."<<pu[i]<<"   ";//输出目前元素内容和编号
	cout<<endl;
	
	for(int i=0;i<link;i++){//连接 
		cin>>v1; cin>>v2; cin>>weight;
		WMT.Link(v1,v2,weight);
		WMT.Link(v2,v1,weight);
		WLN.Link(v1,v2,weight);
	}

	while(1){
		cout<< "\t\t|-------------------------------------------------------------------|\n";
        cout<< "\t\t|                       1.Prim                                      |\n";
        cout<< "\t\t|                       2.Kruskal                                   |\n";
        cout<< "\t\t|                       3.拓扑排序                                  |\n";
        cout<< "\t\t|                       4.最短路径                                  |\n";
        cout<< "\t\t|                       5.退出对带权图进行操作                      |\n";
        cout<< "\t\t|                       6.退出程序                                  |\n";
	    cout<< "\t\t|-------------------------------------------------------------------|\n";
	    cout<<"请选择要进行的操作：";
	    cin>>operation;cin.sync();
	    switch(operation){
	    	case'1':{
	    		cout<<"得到的可以保留的树枝有："<<endl; 
	    		WMT.Prim();
	    		cout<<endl;
	    		ofstream out("Graph.txt",ios::app);
				out<<endl<<endl;
				out.close(); 
	    		break;
	    	}
	    	case'2':{
	    		cout<<"得到的可以保留的树枝有："<<endl;
	    		WMT.Kruskal();
				cout<<endl;
	    		ofstream out("Graph.txt",ios::app);
				out<<endl<<endl;
				out.close();
	    		break;
	    	}
	    	case'3':{
	    		cout<<"得到的拓扑序列之一为："<<endl;
	    		WLN.TolplogicalSort();
	    		cout<<endl;
	    		ofstream out("Graph.txt",ios::app);
				out<<endl<<endl;
				out.close();
	    		break;
	    	}
	    	case'4':{
	    		int start;
	            for(int i=0;i<num;i++) cout<<i<<"."<<pu[i]<<"   ";//输出目前元素内容和编号
	            cout<<endl;
				cout<<"请输入作为起点的元素编号："; cin>>start; cin.sync(); 
	            cout<<"各点的最短路径为："<<endl;
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
				cout<<"输入错误，请重新输入"<<endl;
				continue;
			}
	    }
	    char con;//是否继续输入标志 
		while(1){
		    cout<<"是否继续进行该操作？（Y/N）："; cin>>con; cin.sync();
		    system("cls");
			switch(con){
			   case'y':
			   case'Y': break;
			   case'n':
			   case'N': return ;
			   default:{ system("cls"); cout<<"输入错误，请重新输入"<<endl;}
		    }
		    if(con=='y'||con=='Y') break;
		}
		continue;
	}
}

//上面为带权图 

void UnWeight(){
	system("cls"); 
	cout<<"请建立不带权图："<<endl;
	char operation; int num, max, link, v1, v2, weight; char *pu;
	
	cout<<"请输入目标建立图的容量："; cin>>max; cin.sync(); Graphlnk<char> LN(max);//带权邻接表 
	
    cout<<"请输入目标建立图的元素个数："; cin>>num; cin.sync();
	
	cout<<"请输入目标建立图的元素内容(字符类型)：";
    for(int i=0; i<num; i++){cin>>pu[i];}
    cin.sync();
    
    if(LN.Build(num,pu) ==false){ cout<<"输入数据错误";}
	cout<<"请输入图内边数："; cin>>link; cin.sync();
	
	cout<<"请按照[起始点 终止点]的格式确定各点联系情况(起点编号为0)"<<endl;
	for(int i=0;i<num;i++) cout<<i<<"."<<pu[i]<<"   ";//输出目前元素内容和编号
	cout<<endl; 
	for(int i=0;i<link;i++){//连接 
		cin>>v1; cin>>v2;
		LN.Link(v1,v2,1);
		LN.Link(v2,v1,1);
	}
	
	
	while(1){
		cout<< "\t\t|-------------------------------------------------------------------|\n";
        cout<< "\t\t|                       1.DFS                                       |\n";
        cout<< "\t\t|                       2.WFS                                       |\n";
        cout<< "\t\t|                       3.退出对带权图进行操作                      |\n";
        cout<< "\t\t|                       4.退出程序                                  |\n";
	    cout<< "\t\t|-------------------------------------------------------------------|\n";
	    cout<<"请选择要进行的操作：";
	    cin>>operation;cin.sync();
	    switch(operation){
	    	case'1':{
	    		int start;
	            for(int i=0;i<num;i++) cout<<i<<"."<<pu[i]<<"   ";//输出目前元素内容和编号
	            cout<<endl;
				cout<<"请输入作为起点的元素编号："; cin>>start; cin.sync(); 
	            cout<<"深度遍历得到序列为："<<endl;
				LN.DFS(start);
				cout<<endl;
	    		ofstream out("Graph.txt",ios::app);
				out<<endl<<endl;
				out.close();
	    		break;
	    	}
	    	case'2':{
	    		int start;
	            for(int i=0;i<num;i++) cout<<i<<"."<<pu[i]<<"   ";//输出目前元素内容和编号
	            cout<<endl;
				cout<<"请输入作为起点的元素编号："; cin>>start; cin.sync(); 
	            cout<<"广度遍历得到序列为："<<endl;
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
				cout<<"输入错误，请重新输入"<<endl;
				continue;
			}
	    }
	    char con;//是否继续输入标志 
		while(1){
		    cout<<"是否继续对无权图进行操作？（Y/N）："; cin>>con; cin.sync();
		    system("cls");
			switch(con){
			   case'y':
			   case'Y': break;
			   case'n':
			   case'N': return ;
			   default:{ system("cls"); cout<<"输入错误，请重新输入"<<endl;}
		    }
		    if(con=='y'||con=='Y') break;
		}
		continue;
	}
}
//以上为无权图操作 

int main(int argc, char** argv) {
	char operation;
	while(1){
		cout<< "\t\t|-------------------------------------------------------------------|\n";
        cout<< "\t\t|                       1.不带权图操作                              |\n";
        cout<< "\t\t|                       2.带权图操作                                |\n";
        cout<< "\t\t|                       3.退出程序                                  |\n";
	    cout<< "\t\t|-------------------------------------------------------------------|\n";
	    cout<<"请选择你要进行的操作：";
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
				cout<<"输入错误，请重新输入"<<endl;
				continue;
			}
	    }
	    char con;//是否继续输入标志 
		while(1){
		    cout<<"是否继续对其他图进行操作？（Y/N）："; cin>>con; cin.sync();
		    switch(con){
			   case'y':
			   case'Y': break;
			   case'n':
			   case'N': exit(1);
			   default:{ system("cls"); cout<<"输入错误，请重新输入"<<endl;}
		    }
		    if(con=='y'||con=='Y') break;
		}
		continue;
	}
	char e; cin>>e;
	return 0;
}
