//哈夫曼树操作类实现
#include"HufTree_class.h"
#include<iostream>
#include<fstream>
using namespace std;

Huffman::Huffman(){
	code="";
	Interlize();
}

bool Huffman::Interlize(){//初始化
	int n, m;
	cout<<"请输入目标元素个数："; 
	cin>>n; cin.sync(); m=n/2+1;
	minHeap Node(n);//存储结点 
	
	//开始让结点入堆 
	TreeNode* newnode;
	for(int i=0 ;i<n; i++){
		system("cls");
		newnode=new TreeNode[1];
		cout<<"请输入第"<<i+1<<"个结点内容："; 
		newnode->data=getchar();cin.sync(); 
		cout<<"请输入第"<<i+1<<"个结点权重：";
		cin>>newnode->weight, cin.sync();
		newnode->lchild=NULL; newnode->rchild=NULL;
		
		Node.Build(newnode,newnode->weight);
	}//全部入堆完毕
	
	//开始建造哈夫曼树
	while(1){
		TreeNode* Node1=Node.Out();
		TreeNode* Node2=Node.Out();
	    TreeNode* newNode=new TreeNode[1];
	    newNode->lchild=Node1; newNode->rchild=Node2; newNode->data='<';
	    newNode->weight=(Node1->weight) + (Node2->weight);
	    if(Node.IsEmpty()){Root=newNode; break;}//当结点堆内为空时，跳出循环 
		else Node.Build(newNode,newNode->weight);
	}
	//哈夫曼树建造完毕，得到根节点为Root 
	
	//准备写入文件
	system("cls");
	//清空页面 
	ofstream out("hfmTree.txt",ios::out);
	out.close();
	//将文件置空
	string s=""; Print(Root,s);
	//哈夫曼树写入文件完成 
}

bool Huffman::Print(TreeNode* current,string s){//凹入表树写入文件 
	ofstream out("hfmTree.txt",ios::app);
	if(current==NULL) return true;
	s=s+"   ";
	Print(current->rchild,s); 
	out<<s<<current->data<<endl;
	Print(current->lchild,s);
	out.close();
}

bool Huffman::Encoding(){
	system("cls");//清屏
	ofstream out("CodeFile.txt",ios::out);//文件置空
	out.close();
	
	ifstream in("ToBeTran.txt",ios::in);//从文件中读出需要编码的内容 
	string s;
	while(getline(in,s)){
		for(int i=0; i<s.length(); i++){
			Scan(Root,s[i]);
		}
	}
}

bool Huffman::Scan(TreeNode* current,char pu){//遍历哈夫曼树，找出pu的编码 
	if(current==NULL) return true;
	if(current->lchild==NULL && current->rchild==NULL && current->data==pu){
		ofstream out("CodeFile.txt",ios::app);
		out<<code;
	}
	
	code=code+"1";//向左子女移动
	Scan(current->lchild,pu);
	code=code.substr(0,code.length()-1);
	code=code+"0";
	Scan(current->rchild,pu);
	code=code.substr(0,code.length()-1);
}

bool Huffman::Decoding(){//译码 
	TreeNode* current=Root;
	string s;
	ifstream in("CodeFile.txt",ios::in);//从文件中取出要进行编译的编码 
	cout<<"由内部数据可以得到文件译码结果为："<<endl;
	while(getline(in,s)){
		for(int i=0; i<s.length(); i++){
			switch(s[i]){
				case '1':{current=current->lchild; break;}
				case '0':{current=current->rchild; break;}
			}
			if(current->lchild==NULL && current->rchild==NULL){
				ofstream Out("TextFile.txt",ios::out); Out.close();//文件置空
				ofstream out("TextFile.txt",ios::app); out<<current->data; out.close();//将译码结果写入文件 
				cout<<current->data; current=Root;
			}
		}
	} 
	in.close();
	cout<<endl; 
}

bool Huffman::Print(){//打印编码文件 
	ifstream in("CodeFile.txt",ios::in);//从文件中读入数据
	string s;
	while(getline(in,s)){
		while(s.length()>50){
			cout<<s.substr(0,50)<<endl;
			s=s.substr(51,s.length()-50);
		}
		cout<<s<<endl;
	}
}

bool Huffman::TreePrint(){//打印哈夫曼树 
	cout<<"由输入的数据可以得到凹入表如下："<<endl; 
	string s="";
	TreePrint(Root,s);
}

bool Huffman::TreePrint(TreeNode* current,string s){//凹入表输出树 
	if(current==NULL) return true;
	s=s+"   ";
	TreePrint(current->rchild,s); 
	cout<<s<<current->data<<endl;
	TreePrint(current->lchild,s);
}
