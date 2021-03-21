//����ʵ��
#include "Tree_class.h"
#include "Queue_detail.cpp"
#include <math.h>
#include <fstream>
#include <iostream>

Tree::Tree(){//���캯�������ļ��ж�ȡ���ݲ��������飩 
	string r; Num = 0;
	R = new string[100];
	Root = new TreeNode[1];
	
	ifstream in("abc.txt",ios::in);
	while(getline(in,r))
	{R[Num]=r, Num++;}
	in.close();
}

Tree::~Tree(){//�������� 
	delete Root;
}

bool Tree::Build(){
	Queue<TreeNode*> q(Num);
	string last,now;
	TreeNode* newNode;
	
	for(int t=0; t<R[1].length(); t++){
		if(R[1][t] == ' ')
		Root->data = R[1].substr(0,t);	
	}//��ȡ������data
	for(int l=0; l<3; l++){
		Root->sons[l]=NULL;
	} //������ʼ�� 
	q.EnQueue(Root);//��������
	
	for(int i=1; i<Num; i++){//ɨ������R 
		for(int t=0; t<R[i].length(); t++){
			if(R[i][t]==' '){
				last = R[i].substr(0,t);
				now = R[i].substr(t+1,R[i].length()-t-1);
			}
		}//��ȡ�½��洢������
		
		newNode = new TreeNode[1]; //�����½�� 
		newNode->data = now; //��Ŀ�����ݷ����½�� 
		for(int l=0; l<3; l++){ //��ʼ���½�� 
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
		}//��Ϊ�ý����ӽ�㣬��ֱ���������ҽ������ 
		else{
			q.OutQueue();
			i--; delete newNode;
		}//����Ϊ�ý����ӽ�㣬��ͷ�ڵ��˳����ٽ��бȶ� 
	}
	return true;
}

bool Tree::output(){ //��� 
	cout<<"�����Ϊ��"<<endl;
	num = 0;
	Out = new string[100];
	output(Root);
	
	for(int i=0; i<num; i++){
		cout<<Out[i];
	}
	return true;
}

bool Tree::output(TreeNode* current){ //����� 
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

void Tree::Interlize(){ //����רҵ�����༶����ʼ������ 
	root = Root; 
	major_number = 0;
	class_number = 0;
	student_number = 0; 
}

int Tree::Major_number(TreeNode* current){//ͳ��רҵ��Ŀ���� 
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
