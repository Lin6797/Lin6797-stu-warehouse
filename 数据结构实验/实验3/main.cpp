/*************第三版****************/
/**********作者：林颖钰************/
/*********2019年10月21日终版*******/ 

#include <iostream>
#include"Stack_class.h"
#include"Queue_class.h"
using namespace std;

int main() {
	char operation; //操作 
	Queue q; //队列类定义 
	Stack s; //栈类定义 
	string car_number; //车牌定义 
	int money; //应付款定义 
	int purpose; //目标车辆序号 
	string judge; //是否继续进行操作 
	
	cout<< "\t\t|--------------------------------------------------------------------------|\n";
    cout<< "\t\t|                       1.车辆入库                                         |\n";
    cout<< "\t\t|                       2.车辆离开车库                                     |\n";
    cout<< "\t\t|                       3.查看车库中各车辆                                 |\n";
    cout<< "\t\t|                       4.查看等候区各车辆                                 |\n";
    cout<< "\t\t|                       5.退出系统                                         |\n";
    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	cout<<"请选择你要进行的操作：";
	cin>>operation;cin.sync(); 
	while(1){
		switch(operation)
		{
			case '1':{ //车辆入车库 
				if(q.IsFull()){
					cout<<"等候区已满，请到其他车库进行汽车停放"<<endl; 
				}
				else{
					cout<<"请输入汽车车牌号：";
					cin>>car_number;cin.sync();
					q.EnQueue(car_number);
					
					if(s.IsFull()){
						cout<<"停车场已满，请在等候区进行等候"<<endl;
					}
					else{
						car_number=q.OutQueue();
						s.Push(car_number);
					}
				}
				break;
			}
			case '2':{ //车辆出车库 
				cout<<"请输入出栈的汽车序号：";
				cin>>purpose;cin.sync();
				if(s.num < purpose) 
				cout<<"输入数据错误"<<endl; 
				else{
				   money = s.Money(purpose);
				   s.Pop(purpose);
				   cout<<endl<<"该汽车需要付款："<<money<<"元"<<endl; 
			    
				   car_number=q.OutQueue();
				   s.Push(car_number);
			    }
				break;
			}
			case '3':{ //展示栈内元素 
				s.show();
				break;
			}
			case '4':{ //展示队列内元素 
				q.show();
				break;
			}
			case '5':{ //退出系统 
				return 0;
			}
			default:{
				cout<<"输入错误，请重新输入：";
				cin>>operation;cin.sync();
				continue;
			}
		}
		
		cout<<endl;
	    cout<<"------------------------------------------------------------------------------------------"; 
	    cout<<endl<<"是否继续进行操作？（Y/N）：";
	    cin>>judge;cin.sync();
	    while(1)
			{
	            if(judge == "Y" || judge == "y" )
				{
	             cout<< "\t\t|--------------------------------------------------------------------------|\n";
                 cout<< "\t\t|                       1.车辆入库                                         |\n";
                 cout<< "\t\t|                       2.车辆离开车库                                     |\n";
                 cout<< "\t\t|                       3.查看车库中各车辆                                 |\n";
                 cout<< "\t\t|                       4.查看等候区各车辆                                 |\n";
                 cout<< "\t\t|                       5.退出系统                                         |\n";
                 cout<< "\t\t|--------------------------------------------------------------------------|\n";
	            	cout<< "请输入您要执行的操作对应的编号:";
					cin>>operation;cin.sync();
					break;
	            }
	            else if(judge == "N" || judge == "n" )
				{
	        	    cout<< endl<< "    [正在退出]    ";
	        	    return 0;
	            }
	            else
				{
	            	cout<< "输入错误，请重新输入:";
	            	cin>>judge;cin.sync();
	            }
	        }
	}
	return 0;
}
