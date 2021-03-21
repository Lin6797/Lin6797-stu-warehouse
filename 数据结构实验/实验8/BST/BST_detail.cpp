//��������ʵ��

#include"BST_class.h"

BST::BST(){;} //�޲ι��캯��

BST::BST(int Key, char Data){//���ι��캯�� 
	BSTNode* newNode=new BSTNode[1];//�����½�� 
	newNode->lchild=NULL; newNode->rchild=NULL;
	newNode->key=Key; newNode->data=Data;
	root=newNode;//��ø����
}

BST::~BST(){//�������� 
	delete root;
}

bool BST::Build(int num,int* Key, char* Data){//����������������numΪԪ�ظ���
	BSTNode* newNode=new BSTNode[1];//�����½�� 
	newNode->lchild=NULL; newNode->rchild=NULL;
	newNode->key=Key[0]; newNode->data=Data[0];
    root=newNode;//��ø����
    
	for(int i=1; i<num; i++){
    	Insert(Key[i], Data[i]);//����Insert[�ǵݹ����]
    }
    return true;
}

bool BST::Insert(int Key, char Data){//���뺯�����ǵݹ飩 
	BSTNode* newNode = new BSTNode[1];//�����½�� 
	newNode->lchild=NULL; newNode->rchild=NULL;//��ʼ�� 
	newNode->key=Key; newNode->data=Data;
	
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

bool BST::insert(int Key, char Data){//�ݹ���� 
	BSTNode* newNode=new BSTNode[1];
	newNode->lchild=NULL; newNode->rchild=NULL;
	newNode->key=Key; newNode->data=Data;
	
	if( insert(newNode, root) ) return true;
	else return false;
}

bool BST::insert(BSTNode* data, BSTNode* link){
	int Key=data->key;
	
	if( (link->key)==Key) return false;
	//Ŀ�����λ����� 
	if( Key<(link->key) ){
		if( (link->lchild) ==NULL){
			link->lchild=data;
			return true;
		}
		else{insert(data,link->lchild);}
	}
	//Ŀ�����λ���ұ� 
	else{
		if( (link->rchild) ==NULL){
			link->rchild=data;
			return true;
		}
		else{insert(data,link->rchild);}
	}
	return true;
}


BSTNode* BST::Search(int Key){//�����������ǵݹ飩[�������������������ָ��] 
	BSTNode* current=root;
	
	while(current!=NULL){
		if( (current->key)==Key) return current;
		
		if( Key<(current->key) ) {current=current->lchild;}
		else if(Key>(current->key)) {current=current->rchild;}
	}
	return NULL;
}


BSTNode* BST::search(int Key){//�����������ݹ���ڣ� 
	BSTNode* purpose;
	purpose=search(Key,root);
	if(purpose==NULL) {return NULL;}
	else return purpose;
}


BSTNode* BST::search(const int Key, BSTNode* current){//�����������ݹ��壩 
	BSTNode* pur=NULL;
	if(current==NULL) {return NULL;}
	if(Key==(current->key)) {return current;}
	
	if(Key<(current->key)) pur=search(Key, current->lchild);
	else if(Key>(current->key)) pur=search(Key, current->rchild);
	
	return pur;
}


BSTNode* BST::Delete(int Key){//ɾ��������������ڣ�
	BSTNode* purpose=Search(Key);//ȷ��Ŀ�����Ƿ���� 
	if(purpose!=NULL) {Delete(Key, root); return purpose;}
	else {return NULL;}
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
			Delete(link->key, link->rchild);//���滻������ɾ�� 
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


bool BST::Show(){//��ʾ������ 
	string str="";
	Show(str,root);
}


bool BST::Show(string str, BSTNode* current){//��ʾ���� 
	if(current!=NULL){
	   str=str+"  ";
	   Show(str,current->rchild); 
	   cout<<str<<current->data<<" "<<current->key<<endl;
	   Show(str,current->lchild);
    }
}

bool BST::show(){
	show(root);
}

bool BST::show(BSTNode* current){
	if(current==NULL) return false;
	if(current!=NULL){
	   show(current->lchild);
	   cout<<current->data<<current->key<<endl;
	   show(current->rchild);
    }
}

bool BST::Outfile(){//д���ļ�������� 
	 ofstream out("BST.txt",ios::out);
	 out.close();//����ļ� 
	 Outfile(root);
}

bool BST::Outfile(BSTNode* current){//д���ļ��������� 
	if(current==NULL) return false;
	
	Outfile(current->lchild);
	//������ݵ��ļ� 
	ofstream out("BST.txt",ios::app);
	if(!out) {return false;}
	if(current!=NULL){
		out<<current->key<<" ";
		out<<current->data<<" "<<endl;
	}
	out.close();
	//�ر��ļ� 
	Outfile(current->rchild);
	return true;
}
