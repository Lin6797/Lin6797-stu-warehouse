#include"Student_class.h"


//��������ʵ��

BST::BST(){;} //�޲ι��캯��

BST::~BST(){//�������� 
	delete[] root;
}

bool BST::Build(int num,int* Key, Data** DA){//����������������numΪԪ�ظ���
	BSTNode* newNode=new BSTNode[1];//�����½�� 
	newNode->lchild=NULL; newNode->rchild=NULL;
	newNode->key=Key[0]; newNode->data=DA[0];
    root=newNode;//��ø����
    
	for(int i=1; i<num; i++){
    	Insert(Key[i], DA[i]);//����Insert[�ǵݹ����]
    }
    return true;
}

bool BST::Insert(int Key, Data* DA){//���뺯�����ǵݹ飩 
	BSTNode* newNode = new BSTNode[1];//�����½�� 
	newNode->lchild=NULL; newNode->rchild=NULL;//��ʼ�� 
	newNode->key=Key; newNode->data=DA;
	
	BSTNode* current=root;//������ڱȽϵĵ�
	
	while(current!=NULL){
		if( (current->key)==Key) return false;
		//Ŀ�����λ�����
		if( Key<(current->key) ){
			if( (current->lchild) ==NULL){
				current->lchild=newNode;
				return true;
			}
			else{current=current->lchild;}
		}
		//Ŀ�����λ���ұ� 
		else{
			if( (current->rchild) ==NULL){
				current->rchild=newNode;
				return true;
			}
			else{current=current->rchild;}
		}
	}
}

//�ݹ�����Ѿ�ɾ�� 

//�ǵݹ�����Ѿ�ɾ�� 


BSTNode* BST::Search(int Key){//�����������ݹ���ڣ� 
	BSTNode* purpose;
	purpose=Search(Key,root);
	if(purpose==NULL) {return NULL;}
	else return purpose;
}


BSTNode* BST::Search(const int Key, BSTNode* current){//�����������ݹ��壩 
	BSTNode* pur=NULL;
	if(current==NULL) {return NULL;}
	if(Key==(current->key)) {return current;}
	
	if(Key<(current->key)) pur=Search(Key, current->lchild);
	else if(Key>(current->key)) pur=Search(Key, current->rchild);
	
	return pur;
}

BSTNode* BST::Delete(int Key){//ɾ��������������ڣ�
	BSTNode* purpose=Search(Key);//ȷ��Ŀ�����Ƿ���� 
	if(purpose!=NULL) {Delete(Key, root); return purpose;}
	else { return NULL;}
}

bool BST::Delete(int Key, BSTNode* link){//ɾ���������ݹ��壩 
	if(link==NULL) return false;//Ŀ��ɾ����㲻����
	
	BSTNode* temp;//�滻��� 
	if(Key<link->key) Delete(Key, link->lchild);
	else if(Key>link->key) Delete(Key, link->rchild);
	else{
		if(link->lchild!=NULL && link->rchild!=NULL){//���Ҿ���Ϊ�� 
			temp=link->rchild;
			//�����������һ���
			//Ҫȷ����������ȫ��Ԫ�ؾ�С�ڸý�㣬��������ȫ��Ԫ�ؾ����ڸõ� 
			while(temp->lchild!=NULL)
			{temp=temp->lchild;}
			link->data=temp->data;//�滻����
			link->key=temp->key;
			Delete(temp->key, link->rchild);//���滻������ɾ�� 
		}
		else{//������һ��Ϊ�� 
			temp=link;
			if(link->lchild==NULL){//���ҽ����д���
				/*������ɾ��Ҷ�ӡ�ɾ����յĽ�㡢�Լ���������[���Ҿ��ǿյĽ��]�Ľ�� 
				*��������[���Ҿ��ǿյĽ��]�Ľ��ʱ����߱ض�Ϊ��[�ڸ÷�����] 
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
			else{//��������д���
				//��������ɾ���Ұ�Ϊ�յĽ�� 
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


bool BST::Show(){//��ʾ���� 
	Show(root);
}

bool BST::Show(BSTNode* current){//��ʾ���� 
	if(current==NULL) return false;
	Show(current->lchild); 
	if(current!=NULL){//������ݵ���Ļ 
		cout<<current->key<<" ";
		cout<<current->data->name<<" ";
		cout<<current->data->birthday<<" ";
		cout<<current->data->sex<<" ";
		cout<<current->data->phone<<" ";
		cout<<current->data->adver<<endl;
	}
	Show(current->rchild);
}


bool BST::Outfile(){//д���ļ�������� 
	 Outfile(root);
}

bool BST::Outfile(BSTNode* current){//д���ļ��������� 
	if(current==NULL) return false;
	
	Outfile(current->lchild);
	//������ݵ��ļ� 
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
	//�ر��ļ� 
	Outfile(current->rchild);
	return true;
}
