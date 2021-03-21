#include <iostream>

#include "Tree_class.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Read(TreeNode *tree){
	cout<<tree->data<<"   ";
}

int main(int argc, char** argv) {
	cout<<"************[本程序目前仅支持字符类]************"<<endl; 
	cout<<"请按照广义表的形式进行二叉树的表示(注：不可舍去逗号)"<<endl; 
	cout<<"  A(B,C(,D))  "<<"得到的二叉树为："<<endl;
	cout<<"     A"<<endl;
	cout<<"   B   C"<<endl;
	cout<<"         D"<<endl;
	
	Tree t;
	TreeNode *Root;
	Root = t.Build();
	
	char operation; //操作  
	string judge; //是否继续进行操作 
	
	cout<< "\t\t|--------------------------------------------------------------------------|\n";
    cout<< "\t\t|                       1.前序遍历二叉树（递归）                           |\n";
    cout<< "\t\t|                       2.中序遍历二叉树（递归）                           |\n";
    cout<< "\t\t|                       3.后序遍历二叉树（递归）                           |\n";
    cout<< "\t\t|                       4.前序遍历二叉树（非递归）                         |\n";
    cout<< "\t\t|                       5.中序遍历二叉树（非递归）                         |\n";
    cout<< "\t\t|                       6.后序遍历二叉树（非递归）                         |\n";
    cout<< "\t\t|                       7.求二叉树高度                                     |\n";
    cout<< "\t\t|                       8.求二叉树叶子总数                                 |\n";
    cout<< "\t\t|                       9.输出二叉树                                       |\n";
    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	cout<<"请选择你要进行的操作：";
	cin>>operation;cin.sync(); 
	while(1){
		switch(operation)
		{
			case '1':{
				cout<<"前序遍历二叉树（递归）得到结果为:"<<endl; 
				t.aheadscan(Root,Read);//前序 
				cout<<endl;
				break;
			}
			case '2':{
				cout<<"中序遍历二叉树（递归）得到结果为:"<<endl;
			    t.midscan(Root,Read);//中序 
	            cout<<endl;
				break;
			}
			case '3':{
				cout<<"后序遍历二叉树（递归）得到结果为:"<<endl;
				t.tailscan(Root,Read);//后序
				cout<<endl; 
				break;
			}
			case '4':{
				cout<<"前序遍历二叉树（非递归）得到结果为:"<<endl;
				t.aheadscan_s(Read); //前序 
	            cout<<endl;
	            break;
			}
			case '5':{
				cout<<"前序遍历二叉树（非递归）得到结果为:"<<endl;
				t.midscan_s(Read); //中序 
	            cout<<endl;
	            break;
			}
			case '6':{//后序 
				cout<<"前序遍历二叉树（非递归）得到结果为:"<<endl;
				t.tailscan_s(Read);
				cout<<endl;
				break;
			} 
			case '7':{ //计算叶子总数 
				int leaves;
	            leaves = t.TreeLeaves();
	            cout<<"叶子总数为："<<leaves<<endl;
				break;
			}
			case '8':{ //计算二叉树高度 
				int height;
	            height = t.TreeHeight();
	            cout<<"该二叉树的高度为："<<height<<endl; 
				break;
			} 
			case '9':{
				cout<<"输出二叉树为："<<endl;
	            t.Output();
				break;
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
                    cout<< "\t\t|                       1.前序遍历二叉树（递归）                           |\n";
               	    cout<< "\t\t|                       2.中序遍历二叉树（递归）                           |\n";
              	    cout<< "\t\t|                       3.后序遍历二叉树（递归）                           |\n";
             	    cout<< "\t\t|                       4.前序遍历二叉树（非递归）                         |\n";
               	    cout<< "\t\t|                       5.中序遍历二叉树（非递归）                         |\n";
              	    cout<< "\t\t|                       6.后序遍历二叉树（非递归）                         |\n";
              	    cout<< "\t\t|                       7.求二叉树高度                                     |\n";
               	    cout<< "\t\t|                       8.求二叉树叶子总数                                 |\n";
              	    cout<< "\t\t|                       9.输出二叉树                                       |\n";
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
