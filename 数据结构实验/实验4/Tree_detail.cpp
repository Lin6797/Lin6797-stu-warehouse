#include "Stack_detail.cpp"
#include "Queue_detail.cpp"
#include "Tree_class.h"
#include <iostream>
using namespace std;


Tree::Tree(){ //���캯�� 
	root = NULL;
	cout<<"��������Ҫ���д���Ķ�����(�밴�չ������ʽ����)��";
	cin>>purpose;
	cin.sync(); 
}
TreeNode *Tree::Build(){ //���� 
	Stack<TreeNode*> TN_s(purpose.length());//���콨��������ʱ��Ҫ��ջ 
	TreeNode *Root=NULL, *newTree;
	int k;//��Ϊ������Ů���ӱ�־
	
	for(int i=0; i<purpose.length(); i++){
		
		switch(purpose[i]){
			case '(':{ //���շ��ŶԷ���ǰ�������д��� 
				k = 1;
				TN_s.Push(newTree);
				break;
			}
			case ',':{//���շ��ŶԷ���ǰ�������д��� 
				k = 2;
				break;
			}
			case ')':{//���շ��ŶԷ���ǰ�������д��� 
				TN_s.Pop();
				break;
			}
			default:{
				newTree = new TreeNode[1];
				newTree->data = purpose[i];
				newTree->leftchild = NULL;
				newTree->rightchild = NULL;
				
				if(Root == NULL) 
				{Root = newTree; root = Root;}
				
				else{
				  if(k==1){
						TN_s.in_stack[TN_s.Top]->leftchild = newTree;
					}
					if(k==2){
						TN_s.in_stack[TN_s.Top]->rightchild = newTree;
					}
				  
			    }
			}
		}
	}
	
	return Root; //���ظ� 
}
bool Tree::aheadscan(TreeNode *tree,void (*visit)(TreeNode*)){ //ǰ��������ݹ飩 
	if(root == NULL){
		cout<<"���ڵ�Ϊ�գ�����Ϊ����"<<endl;
		return true;
	}
	
	if(tree != NULL){
		(*visit)(tree);
		aheadscan(tree->leftchild,visit);
		aheadscan(tree->rightchild,visit);
	}
	return true;
}

bool Tree::aheadscan_s(void (*visit)(TreeNode*)){ //ǰ��������ǵݹ飩 
	Stack<TreeNode*> TN(100); //����ջ 
	
	TreeNode *current = root;
	while(current != NULL){
		(*visit)(current);
	 	
	 	if(current->rightchild != NULL) TN.Push(current->rightchild); //������������������������ջ 
		if(current->leftchild == NULL && TN.Top == -1) //�ж�ջ��Ϊ�պ�������Ϊ�գ������һ���㣩�Ƿ�ͬʱ���� 
	 	break;
		
		if(current->leftchild != NULL) current = current->leftchild; //����������������ָ������ָ����һ�������� 
	 	else current = TN.Pop(); //�������������������ջ������������������ĸ���� 
	}
}

bool Tree::midscan(TreeNode *tree,void (*visit)(TreeNode*)){//����ɨ�裨�ݹ飩 
	if(root == NULL){
		cout<<"���ڵ�Ϊ�գ�����Ϊ����"<<endl;
		return false;
	}
	
	if(tree != NULL){
		midscan(tree->leftchild,visit);
		(*visit)(tree);
		midscan(tree->rightchild,visit);
	}
	return true;
}

bool Tree::midscan_s(void (*visit)(TreeNode*)){//����ɨ�裨�ǵݹ飩 
	Stack<TreeNode*> TN(100); //����ջ
	
	TreeNode *current = root;
	while(current != NULL || TN.Top != -1){
		while(current != NULL){
			TN.Push(current);
			current = current->leftchild;
		}
		
		current = TN.Pop();
		(*visit)(current);
		current = current->rightchild;
	}
	return true;
}
bool Tree::tailscan(TreeNode *tree,void (*visit)(TreeNode*)){ //����ɨ�裨�ݹ飩 
	if(root == NULL){
		cout<<"���ڵ�Ϊ�գ�����Ϊ����"<<endl;
		return true;
	}
	
	if(tree != NULL){
		tailscan(tree->leftchild,visit);
		tailscan(tree->rightchild,visit);
		(*visit)(tree);
	}
	return true;
}

bool Tree::tailscan_s(void (*visit)(TreeNode *)){//����ɨ�裨�ǵݹ飩 
	Stack<TreeNode*> TN(100); //�������ջ
	Stack<char> JU(100);//�����жϷ���ջ 
	
	TreeNode *current = root;
	char Judge = 'L';//�ж��������Ƿ񱻷����� 
	int loop;//�ж��Ƿ�Ҫ������ջѭ�� 
	
	do{
		while(current != NULL){
			TN.Push(current); JU.Push('L');
			current = current->leftchild;
		}//��ջѭ�� 
		
		loop = 0;
		while(loop==0 && TN.Top!=-1){
			current = TN.Pop(); Judge = JU.Pop();
			switch(Judge){
				case 'L':{
					if(current->rightchild != NULL){
						TN.Push(current); JU.Push('R');
						loop = 1; current = current->rightchild;
					}
					else (*visit)(current);
					break;
				}
				case 'R':{
					(*visit)(current);
					break;
				}
			}
		}
	}while(TN.Top != -1);
}

int Tree::TreeLeaves(){//��������Ҷ����������� 
	Leaves = 0; 
	TreeLeaves(root);
	return Leaves;
}

void Tree::TreeLeaves(TreeNode *tree){ //���������Ҷ�������� 
	if(tree != NULL){
		if(tree->leftchild == NULL && tree->rightchild == NULL){
			Leaves++;
		}
		TreeLeaves(tree->leftchild);
		TreeLeaves(tree->rightchild);
	}
}

int Tree::TreeHeight(){ //����������߶Ⱥ������ 
	int Height = 0;
	lheight = 0;
	rheight = 0;
	Height = Tree::TreeHeight(root);
	return Height+1;
}

int Tree::TreeHeight(TreeNode *tree){ //����������߶� 
	if(tree != NULL){
		if(tree->leftchild != NULL)
		lheight += 1;
		if(tree->rightchild != NULL)
		rheight += 1;
		
		lheight = TreeHeight(tree->leftchild);
		rheight = TreeHeight(tree->rightchild);
	}
	return ( lheight>rheight ? lheight : rheight);
}

bool Tree::Output(){//��� 
	Queue<TreeNode*> TN(100);
	
	TreeNode *current = root;
	cout<<"�����Ϊ��"<<current->data<<endl;
	 
	TN.EnQueue(current);
	do{
		current = TN.OutQueue();
		if(current->leftchild != NULL)
		cout<<(current->data)<<"������Ϊ"<<((current->leftchild)->data)<<",";
		else cout<<(current->data)<<"������Ϊ"<<"��"<<",";
		if(current->rightchild != NULL)
		cout<<"�ҽ��Ϊ"<<((current->rightchild)->data)<<endl;
		else cout<<"�ҽ��Ϊ"<<"��"<<endl;
		
		if(current->leftchild != NULL){
			TN.EnQueue(current->leftchild);
		}
		
		if(current->rightchild != NULL){
			TN.EnQueue(current->rightchild);
		}
	
	}while(!TN.IsEmpty());
}
