#include"Student_class.h"


//二叉树类实现

BST::BST(){;} //无参构造函数

BST::~BST(){//析构函数 
	delete[] root;
}

bool BST::Build(int num,int* Key, Data** DA){//建造搜索二叉树，num为元素个数
	BSTNode* newNode=new BSTNode[1];//开辟新结点 
	newNode->lchild=NULL; newNode->rchild=NULL;
	newNode->key=Key[0]; newNode->data=DA[0];
    root=newNode;//获得根结点
    
	for(int i=1; i<num; i++){
    	Insert(Key[i], DA[i]);//调用Insert[非递归插入]
    }
    return true;
}

bool BST::Insert(int Key, Data* DA){//插入函数（非递归） 
	BSTNode* newNode = new BSTNode[1];//开辟新结点 
	newNode->lchild=NULL; newNode->rchild=NULL;//初始化 
	newNode->key=Key; newNode->data=DA;
	
	BSTNode* current=root;//获得用于比较的点
	
	while(current!=NULL){
		if( (current->key)==Key) return false;
		//目标插入位在左边
		if( Key<(current->key) ){
			if( (current->lchild) ==NULL){
				current->lchild=newNode;
				return true;
			}
			else{current=current->lchild;}
		}
		//目标插入位在右边 
		else{
			if( (current->rchild) ==NULL){
				current->rchild=newNode;
				return true;
			}
			else{current=current->rchild;}
		}
	}
}

//递归插入已经删除 

//非递归查找已经删除 


BSTNode* BST::Search(int Key){//搜索函数（递归入口） 
	BSTNode* purpose;
	purpose=Search(Key,root);
	if(purpose==NULL) {return NULL;}
	else return purpose;
}


BSTNode* BST::Search(const int Key, BSTNode* current){//搜索函数（递归体） 
	BSTNode* pur=NULL;
	if(current==NULL) {return NULL;}
	if(Key==(current->key)) {return current;}
	
	if(Key<(current->key)) pur=Search(Key, current->lchild);
	else if(Key>(current->key)) pur=Search(Key, current->rchild);
	
	return pur;
}

BSTNode* BST::Delete(int Key){//删除函数（函数入口）
	BSTNode* purpose=Search(Key);//确定目标结点是否存在 
	if(purpose!=NULL) {Delete(Key, root); return purpose;}
	else { return NULL;}
}

bool BST::Delete(int Key, BSTNode* link){//删除函数（递归体） 
	if(link==NULL) return false;//目标删除结点不存在
	
	BSTNode* temp;//替换结点 
	if(Key<link->key) Delete(Key, link->lchild);
	else if(Key>link->key) Delete(Key, link->rchild);
	else{
		if(link->lchild!=NULL && link->rchild!=NULL){//左右均不为空 
			temp=link->rchild;
			//找中序遍历第一结点
			//要确保左子树的全部元素均小于该结点，右子树的全部元素均大于该点 
			while(temp->lchild!=NULL)
			{temp=temp->lchild;}
			link->data=temp->data;//替换内容
			link->key=temp->key;
			Delete(temp->key, link->rchild);//找替换结点进行删除 
		}
		else{//左右有一个为空 
			temp=link;
			if(link->lchild==NULL){//用右结点进行代替
				/*适用于删除叶子、删除左空的结点、以及用来代替[左右均非空的结点]的结点 
				*用来代替[左右均非空的结点]的结点时：左边必定为空[在该方法下] 
				*/
				if(link->rchild==NULL) { temp=link; link=NULL; }
				else{
					temp=link->rchild;
					link->data=link->rchild->data;
					link->key=link->rchild->key;
					link->lchild=link->rchild->lchild;
					link->rchild=link->rchild->rchild;
				}
			}
			else{//用左结点进行代替
				//仅适用于删除右半为空的结点 
				temp=link->lchild;
				link->data=link->lchild->data;
				link->key=link->lchild->key;
				link->rchild=link->lchild->rchild;
				link->lchild=link->lchild->lchild;
			}	 
			delete[] temp;
			return true;
		}
	}
}


bool BST::Show(){//显示数据 
	Show(root);
}

bool BST::Show(BSTNode* current){//显示主体 
	if(current==NULL) return false;
	Show(current->lchild); 
	if(current!=NULL){//输出数据到屏幕 
		cout<<current->key<<" ";
		cout<<current->data->name<<" ";
		cout<<current->data->birthday<<" ";
		cout<<current->data->sex<<" ";
		cout<<current->data->phone<<" ";
		cout<<current->data->adver<<endl;
	}
	Show(current->rchild);
}


bool BST::Outfile(){//写入文件函数入口 
	 Outfile(root);
}

bool BST::Outfile(BSTNode* current){//写入文件函数主体 
	if(current==NULL) return false;
	
	Outfile(current->lchild);
	//输出数据到文件 
	ofstream out("Student.txt",ios::app);
	if(!out) {return false;}
	if(current!=NULL){
		out<<current->key<<" ";
		out<<current->data->name<<" ";
		out<<current->data->birthday<<" ";
		out<<current->data->sex<<" ";
		out<<current->data->phone<<" ";
		out<<current->data->adver<<" "<<endl;
	}
	out.close();
	//关闭文件 
	Outfile(current->rchild);
	return true;
}
