//树类实现
#include "Tree_class.h"
#include "Queue_detail.cpp"
#include <math.h>
#include <fstream>
#include <iostream>

Tree::Tree(){//构造函数（从文件中读取数据并放入数组） 
	string r; Num = 0;
	R = new string[100];
	Root = new TreeNode[1];
	
	ifstream in("abc.txt",ios::in);
	while(getline(in,r))
	{R[Num]=r, Num++;}
	in.close();
}

Tree::~Tree(){//析构函数 
	delete Root;
}

bool Tree::Build(){
	Queue<TreeNode*> q(Num);
	string last,now;
	TreeNode* newNode;
	
	for(int t=0; t<R[1].length(); t++){
		if(R[1][t] == ' ')
		Root->data = R[1].substr(0,t);	
	}//获取根结点的data
	for(int l=0; l<3; l++){
		Root->sons[l]=NULL;
	} //根结点初始化 
	q.EnQueue(Root);//根结点入队
	
	for(int i=1; i<Num; i++){//扫描数组R 
		for(int t=0; t<R[i].length(); t++){
			if(R[i][t]==' '){
				last = R[i].substr(0,t);
				now = R[i].substr(t+1,R[i].length()-t-1);
			}
		}//获取新结点存储的数据
		
		newNode = new TreeNode[1]; //开辟新结点 
		newNode->data = now; //将目标数据放入新结点 
		for(int l=0; l<3; l++){ //初始化新结点 
			newNode->sons[l] = NULL;
		}
		
		if((q.in_queue[q.front])->data == last){
			for(int l=0; l<3; l++){
				if((q.in_queue[q.front])->sons[l] == NULL){
					(q.in_queue[q.front])->sons[l] = newNode;
					break;
				}
			}
			q.EnQueue(newNode);
		}//若为该结点的子结点，则直接相连并且将其入队 
		else{
			q.OutQueue();
			i--; delete newNode;
		}//若不为该结点的子结点，则将头节点退出后再进行比对 
	}
	return true;
}

bool Tree::output(){ //入口 
	cout<<"输出树为："<<endl;
	num = 0;
	Out = new string[100];
	output(Root);
	
	for(int i=0; i<num; i++){
		cout<<Out[i];
	}
	return true;
}

bool Tree::output(TreeNode* current){ //输出树 
	Out[num] = current->data; num++;
	for(int l=0; l<3; l++){
		if(current->sons[l] == NULL)
		{Out[num]=')'; num++; break;}
		else{
			if(l==0){
				Out[num] = '('; num++;
				output(current->sons[l]);
			}
			else{
				Out[num] = ','; num++;
				output(current->sons[l]);
			}
		}
	}
}

void Tree::Interlize(){ //计算专业数、班级数初始化函数 
	root = Root; 
	major_number = 0;
	class_number = 0;
	student_number = 0; 
}

int Tree::Major_number(TreeNode* current){//统计专业数目函数 
	for(int l=0; l<3; l++){
		if(current->sons[l] == NULL) break;
		else{
			if(current->sons[0]->sons[0]->sons[0] == NULL){
				major_number++; break;
			}
			else Major_number(current->sons[l]);
		}
	}
	return major_number;
}

int Tree::Class_number(TreeNode* current){
	for(int l=0; l<3; l++){
		if(current->sons[l] == NULL) break;
		else{
			if(current->sons[0]->sons[0] == NULL){
				class_number++; break;
			}
			else Class_number(current->sons[l]);
		}
	}
	return class_number;
} 

int Tree::Student_number(TreeNode* current){
	for(int l=0; l<3; l++){
		if(l!=0 && current->sons[l]==NULL) break;
		else{
			if(current->sons[0] == NULL){
				string text = current->data; int pu=0,i=0;
				do{
				   pu = (text[text.length()-1]-('1'-1))*pow(10,i)+pu;
				   i++; text = text.substr(0,text.length()-1);
				}while(text.length()!=0);
				student_number = student_number+pu;
				break;
			}
			else Student_number(current->sons[l]);
		}
	}
	return student_number;
}
