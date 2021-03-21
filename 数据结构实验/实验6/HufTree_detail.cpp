//��������������ʵ��
#include"HufTree_class.h"
#include<iostream>
#include<fstream>
using namespace std;

Huffman::Huffman(){
	code="";
	Interlize();
}

bool Huffman::Interlize(){//��ʼ��
	int n, m;
	cout<<"������Ŀ��Ԫ�ظ�����"; 
	cin>>n; cin.sync(); m=n/2+1;
	minHeap Node(n);//�洢��� 
	
	//��ʼ�ý����� 
	TreeNode* newnode;
	for(int i=0 ;i<n; i++){
		system("cls");
		newnode=new TreeNode[1];
		cout<<"�������"<<i+1<<"��������ݣ�"; 
		newnode->data=getchar();cin.sync(); 
		cout<<"�������"<<i+1<<"�����Ȩ�أ�";
		cin>>newnode->weight, cin.sync();
		newnode->lchild=NULL; newnode->rchild=NULL;
		
		Node.Build(newnode,newnode->weight);
	}//ȫ��������
	
	//��ʼ�����������
	while(1){
		TreeNode* Node1=Node.Out();
		TreeNode* Node2=Node.Out();
	    TreeNode* newNode=new TreeNode[1];
	    newNode->lchild=Node1; newNode->rchild=Node2; newNode->data='<';
	    newNode->weight=(Node1->weight) + (Node2->weight);
	    if(Node.IsEmpty()){Root=newNode; break;}//��������Ϊ��ʱ������ѭ�� 
		else Node.Build(newNode,newNode->weight);
	}
	//��������������ϣ��õ����ڵ�ΪRoot 
	
	//׼��д���ļ�
	system("cls");
	//���ҳ�� 
	ofstream out("hfmTree.txt",ios::out);
	out.close();
	//���ļ��ÿ�
	string s=""; Print(Root,s);
	//��������д���ļ���� 
}

bool Huffman::Print(TreeNode* current,string s){//�������д���ļ� 
	ofstream out("hfmTree.txt",ios::app);
	if(current==NULL) return true;
	s=s+"   ";
	Print(current->rchild,s); 
	out<<s<<current->data<<endl;
	Print(current->lchild,s);
	out.close();
}

bool Huffman::Encoding(){
	system("cls");//����
	ofstream out("CodeFile.txt",ios::out);//�ļ��ÿ�
	out.close();
	
	ifstream in("ToBeTran.txt",ios::in);//���ļ��ж�����Ҫ��������� 
	string s;
	while(getline(in,s)){
		for(int i=0; i<s.length(); i++){
			Scan(Root,s[i]);
		}
	}
}

bool Huffman::Scan(TreeNode* current,char pu){//���������������ҳ�pu�ı��� 
	if(current==NULL) return true;
	if(current->lchild==NULL && current->rchild==NULL && current->data==pu){
		ofstream out("CodeFile.txt",ios::app);
		out<<code;
	}
	
	code=code+"1";//������Ů�ƶ�
	Scan(current->lchild,pu);
	code=code.substr(0,code.length()-1);
	code=code+"0";
	Scan(current->rchild,pu);
	code=code.substr(0,code.length()-1);
}

bool Huffman::Decoding(){//���� 
	TreeNode* current=Root;
	string s;
	ifstream in("CodeFile.txt",ios::in);//���ļ���ȡ��Ҫ���б���ı��� 
	cout<<"���ڲ����ݿ��Եõ��ļ�������Ϊ��"<<endl;
	while(getline(in,s)){
		for(int i=0; i<s.length(); i++){
			switch(s[i]){
				case '1':{current=current->lchild; break;}
				case '0':{current=current->rchild; break;}
			}
			if(current->lchild==NULL && current->rchild==NULL){
				ofstream Out("TextFile.txt",ios::out); Out.close();//�ļ��ÿ�
				ofstream out("TextFile.txt",ios::app); out<<current->data; out.close();//��������д���ļ� 
				cout<<current->data; current=Root;
			}
		}
	} 
	in.close();
	cout<<endl; 
}

bool Huffman::Print(){//��ӡ�����ļ� 
	ifstream in("CodeFile.txt",ios::in);//���ļ��ж�������
	string s;
	while(getline(in,s)){
		while(s.length()>50){
			cout<<s.substr(0,50)<<endl;
			s=s.substr(51,s.length()-50);
		}
		cout<<s<<endl;
	}
}

bool Huffman::TreePrint(){//��ӡ�������� 
	cout<<"����������ݿ��Եõ���������£�"<<endl; 
	string s="";
	TreePrint(Root,s);
}

bool Huffman::TreePrint(TreeNode* current,string s){//���������� 
	if(current==NULL) return true;
	s=s+"   ";
	TreePrint(current->rchild,s); 
	cout<<s<<current->data<<endl;
	TreePrint(current->lchild,s);
}
