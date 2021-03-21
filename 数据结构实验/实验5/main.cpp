#include <iostream>
#include "Tree_class.h" 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Tree t;
	t.Build();
	
	char operation; //操作  
	char judge; //是否继续进行操作 
	
 
	while(1){
		cout<< "\t\t|--------------------------------------------------------------------------|\n";
        cout<< "\t\t|                       1.输出树                                           |\n";
        cout<< "\t\t|                       2.求专业数                                         |\n";
        cout<< "\t\t|                       3.求班级数                                         |\n";
        cout<< "\t\t|                       4.求学生数                                         |\n";
        cout<< "\t\t|                       5.退出程序                                         |\n";
	    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	    cout<<"请选择你要进行的操作：";
	    cin>>operation;cin.sync();
		switch(operation) //选择大操作 
		{
			case '1':{
				system("cls"); 
				cout<<"以括号表述输出树为:"<<endl; 
				t.output();
				cout<<endl;
				break;
			}
			case '2':{//求专业数 
				t.Interlize();
				char major_operation; int major;
				while(1){
					cout<< "\t\t|--------------------------------------------------------------------------|\n";
                    cout<< "\t\t|                       1.求学校专业数                                     |\n";
                    cout<< "\t\t|                       2.求计算机学院专业数                               |\n";
                    cout<< "\t\t|                       3.求电信学院专业数                                 |\n";
                    cout<< "\t\t|                       4.退出系统                                         |\n";
                    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	                cout<<"请选择你要进行的操作："; cin>>major_operation; cin.sync();
	                switch(major_operation){
	            	   case'1':{
	            	   	 system("cls");
	            		 major=t.Major_number(t.root);
	            		 cout<<"学校专业数为："<<major<<endl;
	            		 break;
	            	   }
	            	   case'2':{
	            	   	  system("cls");
	            		  major=t.Major_number(t.root->sons[0]);
	            		  cout<<"计算机学院专业数为："<<major<<endl; 
						  break;
	            	   }
	            	   case'3':{
	            	   	   system("cls");
	            		   major=t.Major_number(t.root->sons[1]);
	            		   cout<<"电信学院专业数为："<<major<<endl;
	            		   break;
	            	   }
	            	   case'4':{
	            	   	   return 0;
	            	   } 
	            	   default:{
	            	   	    system("cls");
	            	   	    cout<<"***********输入错误，请重新输入***********"<<endl;
	            	   	    continue;
	            	   }
	                }
	                break;
				}
				break;
			}
			case '3':{//求班级数目  
				t.Interlize();
				char class_operation;int class_num;
				while(1){
					cout<< "\t\t|--------------------------------------------------------------------------|\n";
                    cout<< "\t\t|                       1.求学校班级数                                     |\n";
                    cout<< "\t\t|                       2.求计算机学院班级数                               |\n";
                    cout<< "\t\t|                       3.求电信学院班级数                                 |\n";
                    cout<< "\t\t|                       4.求计算机科学专业班级数                           |\n";
                    cout<< "\t\t|                       5.求信息安全专业班级数                             |\n";
                    cout<< "\t\t|                       6.求物联网专业班级数                               |\n";
                    cout<< "\t\t|                       7.求电子信息类专业班级数                           |\n";
                    cout<< "\t\t|                       8.求信息工程专业班级数                             |\n";
                    cout<< "\t\t|                       9.退出系统                                         |\n";
                    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	                cout<<"请选择你要进行的操作："; cin>>class_operation; cin.sync();
	                switch(class_operation){
	            	   case'1':{
	            	   	 system("cls");
	            		 class_num=t.Class_number(t.root);
	            		 cout<<"学校班级数为："<<class_num<<endl; 
	            		 break;
	            	   }
	            	   case'2':{
	            	   	  system("cls");
	            		  class_num=t.Class_number(t.root->sons[0]);
	            		  cout<<"计算机学院班级数为："<<class_num<<endl;
	            		  break;
	            	   }
	            	   case'3':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[1]);
	            		   cout<<"电信学院班级数为："<<class_num<<endl; 
	            		   break;
	            	   }
	            	   case'4':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[0]->sons[0]);
	            		   cout<<"计算机科学专业班级数为："<<class_num<<endl;
						   break;
	            	   }
	            	   case'5':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[0]->sons[1]);
	            		   cout<<"信息安全专业班级数为："<<class_num; 
						   break;
	            	   }
	            	   case'6':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[0]->sons[2]);
	            		   cout<<"物联网专业班级数为："<<class_num<<endl; 
						   break;
	            	   }
	            	   case'7':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[1]->sons[0]);
	            		   cout<<"电子信息类专业班级数为："<<class_num<<endl; 
						   break;
	            	   }
	    	           case'8':{
	            	   	   system("cls");
	            		   class_num=t.Class_number(t.root->sons[1]->sons[1]);
	            		   cout<<"信息工程专业班级数为："<<class_num<<endl; 
						   break;
	            	   }
	            	   case'9':{
	            	   	   return 0;
	            	   }
	            	   default:{
	            	   	    system("cls");
	            	   	    cout<<"***********输入错误，请重新输入***********"<<endl;
	            	   	    continue;
	            	   }
	                }
	                break;
				}
				break;
			}
			case '4':{//求人数 
				t.Interlize();
				char class_operation;int student;
				while(1){
					cout<< "\t\t|--------------------------------------------------------------------------|\n";
                    cout<< "\t\t|                       1.求学校学生数                                     |\n";
                    cout<< "\t\t|                       2.求计算机学院学生数                               |\n";
                    cout<< "\t\t|                       3.求电信学院学生数                                 |\n";
                    cout<< "\t\t|                       4.求计算机科学专业学生数                           |\n";
                    cout<< "\t\t|                       5.求信息安全专业学生数                             |\n";
                    cout<< "\t\t|                       6.求物联网专业学生数                               |\n";
                    cout<< "\t\t|                       7.求电子信息类专业学生数                           |\n";
                    cout<< "\t\t|                       8.求信息工程专业学生数                             |\n";
                    cout<< "\t\t|                       9.退出系统                                         |\n";
                    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	                cout<<"请选择你要进行的操作："; cin>>class_operation; cin.sync();
	                switch(class_operation){
	            	   case'1':{
	            	   	 system("cls");
	            		 student=t.Student_number(t.root);
	            		 cout<<"学校学生数为："<<student<<endl; 
						 break;
	            	   }
	            	   case'2':{
	            	   	  system("cls");
	            		  student=t.Student_number(t.root->sons[0]);
	            		  cout<<"计算机学院学生数为："<<student<<endl; 
						  break;
	            	   }
	            	   case'3':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[1]);
	            		   cout<<"电信学院学生数为："<<student<<endl; 
						   break;
	            	   }
	            	   case'4':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[0]->sons[0]);
	            		   cout<<"计算机科学专业学生数为："<<student<<endl; 
						   break;
	            	   }
	            	   case'5':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[0]->sons[1]);
	            		   cout<<"信息安全专业学生数为："<<student<<endl; 
						   break;
	            	   }
	            	   case'6':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[0]->sons[2]);
	            		   cout<<"物联网专业学生数为："<<student<<endl; 
						   break;
	            	   }
	            	   case'7':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[1]->sons[0]);
	            		   cout<<"电子信息类专业学生数为："<<student<<endl; 
						   break;
	            	   }
	    	           case'8':{
	            	   	   system("cls");
	            		   student=t.Student_number(t.root->sons[1]->sons[1]);
	            		   cout<<"信息工程专业学生数为："<<student<<endl; 
						   break;
	            	   }
	            	   default:{
	            	   	    system("cls");
	            	   	    cout<<"***********输入错误，请重新输入***********"<<endl;
	            	   	    continue;
	            	   }
	                }
	                break;
				}
	            break;
			}
			case '5':{ //退出程序 
				return 0;
			}
			default:{
				cout<<cout<<"***********输入错误，请重新输入***********"<<endl;
				cin>>operation;cin.sync();
				continue;
			}
			break;
		}
		
		while(1){
			cout<<endl<<"是否继续进行操作？（Y/N）："; cin>>judge; cin.sync();
			if(judge=='y'||judge=='Y') break;
			else if(judge=='n'||judge=='N') return 0;
			else{
				cout<<"***********输入错误，请重新输入***********";
			}
		}
	}
	
	return 0;
}
