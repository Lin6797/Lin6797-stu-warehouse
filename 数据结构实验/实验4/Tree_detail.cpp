#include "Stack_detail.cpp"
#include "Queue_detail.cpp"
#include "Tree_class.h"
#include <iostream>
using namespace std;


Tree::Tree(){ //构造函数 
	root = NULL;
	cout<<"请输入需要进行处理的二叉树(请按照广义表形式输入)：";
	cin>>purpose;
	cin.sync(); 
}
TreeNode *Tree::Build(){ //建立 
	Stack<TreeNode*> TN_s(purpose.length());//构造建立二叉树时需要的栈 
	TreeNode *Root=NULL, *newTree;
	int k;//作为左右子女连接标志
	
	for(int i=0; i<purpose.length(); i++){
		
		switch(purpose[i]){
			case '(':{ //按照符号对符号前的数进行处理 
				k = 1;
				TN_s.Push(newTree);
				break;
			}
			case ',':{//按照符号对符号前的数进行处理 
				k = 2;
				break;
			}
			case ')':{//按照符号对符号前的数进行处理 
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
	
	return Root; //返回根 
}
bool Tree::aheadscan(TreeNode *tree,void (*visit)(TreeNode*)){ //前序遍历（递归） 
	if(root == NULL){
		cout<<"根节点为空，此树为空树"<<endl;
		return true;
	}
	
	if(tree != NULL){
		(*visit)(tree);
		aheadscan(tree->leftchild,visit);
		aheadscan(tree->rightchild,visit);
	}
	return true;
}

bool Tree::aheadscan_s(void (*visit)(TreeNode*)){ //前序遍历（非递归） 
	Stack<TreeNode*> TN(100); //建立栈 
	
	TreeNode *current = root;
	while(current != NULL){
		(*visit)(current);
	 	
	 	if(current->rightchild != NULL) TN.Push(current->rightchild); //若存在右子树，则右子树入栈 
		if(current->leftchild == NULL && TN.Top == -1) //判断栈内为空和左子树为空（及最后一个点）是否同时成立 
	 	break;
		
		if(current->leftchild != NULL) current = current->leftchild; //若存在左子树，则指针向下指向下一个左子树 
	 	else current = TN.Pop(); //若不存在左子树，则出栈，到达最近的右子树的根结点 
	}
}

bool Tree::midscan(TreeNode *tree,void (*visit)(TreeNode*)){//中序扫描（递归） 
	if(root == NULL){
		cout<<"根节点为空，此树为空树"<<endl;
		return false;
	}
	
	if(tree != NULL){
		midscan(tree->leftchild,visit);
		(*visit)(tree);
		midscan(tree->rightchild,visit);
	}
	return true;
}

bool Tree::midscan_s(void (*visit)(TreeNode*)){//中序扫描（非递归） 
	Stack<TreeNode*> TN(100); //建立栈
	
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
bool Tree::tailscan(TreeNode *tree,void (*visit)(TreeNode*)){ //后序扫描（递归） 
	if(root == NULL){
		cout<<"根节点为空，此树为空树"<<endl;
		return true;
	}
	
	if(tree != NULL){
		tailscan(tree->leftchild,visit);
		tailscan(tree->rightchild,visit);
		(*visit)(tree);
	}
	return true;
}

bool Tree::tailscan_s(void (*visit)(TreeNode *)){//后续扫描（非递归） 
	Stack<TreeNode*> TN(100); //建立结点栈
	Stack<char> JU(100);//建立判断符号栈 
	
	TreeNode *current = root;
	char Judge = 'L';//判断右字数是否被访问了 
	int loop;//判断是否要进行入栈循环 
	
	do{
		while(current != NULL){
			TN.Push(current); JU.Push('L');
			current = current->leftchild;
		}//入栈循环 
		
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

int Tree::TreeLeaves(){//计算树的叶子数函数入口 
	Leaves = 0; 
	TreeLeaves(root);
	return Leaves;
}

void Tree::TreeLeaves(TreeNode *tree){ //计算二叉树叶子数函数 
	if(tree != NULL){
		if(tree->leftchild == NULL && tree->rightchild == NULL){
			Leaves++;
		}
		TreeLeaves(tree->leftchild);
		TreeLeaves(tree->rightchild);
	}
}

int Tree::TreeHeight(){ //计算二叉树高度函数入口 
	int Height = 0;
	lheight = 0;
	rheight = 0;
	Height = Tree::TreeHeight(root);
	return Height+1;
}

int Tree::TreeHeight(TreeNode *tree){ //计算二叉树高度 
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

bool Tree::Output(){//输出 
	Queue<TreeNode*> TN(100);
	
	TreeNode *current = root;
	cout<<"根结点为："<<current->data<<endl;
	 
	TN.EnQueue(current);
	do{
		current = TN.OutQueue();
		if(current->leftchild != NULL)
		cout<<(current->data)<<"的左结点为"<<((current->leftchild)->data)<<",";
		else cout<<(current->data)<<"的左结点为"<<"空"<<",";
		if(current->rightchild != NULL)
		cout<<"右结点为"<<((current->rightchild)->data)<<endl;
		else cout<<"右结点为"<<"空"<<endl;
		
		if(current->leftchild != NULL){
			TN.EnQueue(current->leftchild);
		}
		
		if(current->rightchild != NULL){
			TN.EnQueue(current->rightchild);
		}
	
	}while(!TN.IsEmpty());
}
