/*************第四版****************/
/**********作者：林颖钰************/
/*********2019年10月10日终版*******/ 

//主函数 

#include <iostream>
#include "experiem_class.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	LinearList t;
	char operation_judge;
	string judge;
	
	cout<< "\t\t|--------------------------------------------------------------------------|\n";
    cout<< "\t\t|                  1.初始化链表                                            |\n";
    cout<< "\t\t|                  2.新建链表                                              |\n";
    cout<< "\t\t|                  3.在链表中插入某元素                                    |\n";
    cout<< "\t\t|                  4.在链表中删除某位置的某元素                            |\n";
    cout<< "\t\t|                  5.在链表中查找某元素                                    |\n";
    cout<< "\t\t|                  6.输出链表长度                                          |\n";
    cout<< "\t\t|                  7.实现链表元素的逆置                                    |\n";
    cout<< "\t\t|                  8.分解链表（分解为偶数链表和奇数链表并返回奇数链表）    |\n";
    cout<< "\t\t|                  9.退出程序                                              |\n";
    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	cout<< "请输入要执行的操作对应的编号:";
	cin>>operation_judge;cin.sync();
	cout<<endl;
	 
	while(1)
	{
		   switch(operation_judge)
		  {
		    case '1':{
			  t.Interlize();
			  cout<<"初始化得到表为："<<endl;
			  t.output(); 
			  break;
		    }
		    case '2':{
			  int num; //表内元素 
			  char build_judge; //判断建表方法 
			  cout<<"请输入你要建立的链表内元素个数：";
			  cin>>num;cin.sync();
			
			  cout<< "\t\t|--------------------------------------------------------------------------|\n";
              cout<< "\t\t|                       1.头插法建立（得到逆序）                           |\n";
              cout<< "\t\t|                       2.后插法建立（得到正序）                           |\n";
              cout<< "\t\t|--------------------------------------------------------------------------|\n";
			  cout<<"请选择建立链表的方法（1/2）："; //1-头插法；2-尾插法 
			  cin>>build_judge;cin.sync();
			
			
			  while(1)//判断建表方法
	          { 
		        if(build_judge == '1'){
			        t.head_Build(num);
			        cout<<"利用前插法得到链表为："<<endl;
			        t.output();
			        cout<<endl; 
			        break;
		        }
		        if(build_judge == '2'){
			        t.behind_Build(num);
			        cout<<"利用后插法得到链表为："<<endl;
			        t.output();
			        cout<<endl; 
			        break;
		        }
		        else{
			        cout<<"输入数据错误，请重新输入：";
			        cin>>build_judge;cin.sync();
		        } 
	          }
			  break; //跳出opera的switch 
		    }
		    case '3':{ //插入操作 
			  int site; //元素插入位置 
			  int purpose; //元素 
			
			  cout<<"原始链表为："<<endl;
			  t.output();
			  cout<<endl;
			
			  cout<<"请输入你要插入的元素的位置(目标元素成为第i位)：";
			  cin>>site; cin.sync();
			  cout<<"请输入你要插入的目标元素：";
			  cin>>purpose;cin.sync();
			
			  while(1)
			  {
			    if(site>0 && site<=t.Num+1){
				   t.Insert(site, purpose);
				   cout<<"插入元素后得到表为："<<endl;
				   t.output();
				   break;
			    }
			    else{
				    cout<<"超出可插入元素的范围，请重新输入要插入的位置(目标元素成为第i位)：";
				    cin>>site;cin.sync(); 
			    }
			  }
			  break;
		    }
		    case '4':{ //删除操作 
		 	  int site;
		 	
		 	  cout<<"删除前表为："<<endl;
		 	  t.output();
		 	  cout<<endl;
		 	
		 	  cout<<"请输入要删除的元素位置（删除第i位元素）：";
			  cin>>site;cin.sync();
		 	
		 	  while(1)
			  {
			    if(site>0 && site<=t.Num){
				  t.Delete(site);
				  cout<<"删除后表为："<<endl;
				  t.output();
				  break;
			    }
			    else{
				  cout<<"超出已有元素范围，请重新输入要删除的元素位置(删除第i位元素)：";
				  cin>>site;cin.sync(); 
			    }
			  }
		 	  break;
		    }
		    case '5':{//查找操作 (改成布尔型)
		 	   int purpose;
			   cout<<"请输入要查找的元素：";
			   cin>>purpose;cin.sync();
			 
			   if(t.Search(purpose))
			   cout<<endl<<"[查找完成]";
			   else
			   cout<<"表中不存在该元素";
			  
		 	   break;
		    }
		    case '6':{ //输出表长 
		 	  cout<<"目前表长为："<<t.Num; 
		 	  break;
		    }
		    case '7':{ //链表逆置 
			  t.reLink();
			  cout<<"逆置后得到表为："<<endl;
			  t.output();
		 	  break;
		    }
		    case '8':{ //分解 
		 	  t.Part();
		 	  break;
		    }
		    case '9':{ //退出 
		 	  cout<<"    [正在退出]    ";
		 	  return 0;
		    }
		    default:
		    {
	          cout<< endl<< "输入错误，请重新输入:";
	          cin>>operation_judge; cin.sync();
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
                 cout<< "\t\t|                       1.初始化链表                                       |\n";
                 cout<< "\t\t|                       2.新建链表                                         |\n";
                 cout<< "\t\t|                       3.在链表中插入某元素                               |\n";
                 cout<< "\t\t|                       4.在链表中删除某位置的某元素                       |\n";
                 cout<< "\t\t|                       5.在链表中查找某元素                               |\n";
                 cout<< "\t\t|                       6.输出链表长度                                     |\n";
                 cout<< "\t\t|                       7.实现链表元素的逆置                               |\n";
                 cout<< "\t\t|                       8.分解链表（分解为偶数链表和奇数链表）             |\n";
                 cout<< "\t\t|                       9.退出程序                                         |\n";
                 cout<< "\t\t|--------------------------------------------------------------------------|\n";
	            	cout<< "请输入您要执行的操作对应的编号:";
					cin>>operation_judge;cin.sync();
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
