//二叉树类

#ifndef BST_class_H
#define BST_class_H

#include <iostream>
#include<fstream>
using namespace std;
 
class BSTNode{//二叉树结点类 
	friend class BST;//声明友元类 
	public:
		int key;//关键码 
	    char data;//内容
	    BSTNode* lchild,* rchild;//左右结点 
};

class BST{
	public:
		BST();//构造函数
		BST(int key, char data);//构造函数 
		~BST();//析构函数
		bool Build(int num,int* Key, char* Data);//建造函数入口 
		bool Insert(int key,char data);//插入函数
		bool insert(int key,char data);//(递归)插入函数入口 
		BSTNode* Search(int key);//搜索函数 
		BSTNode* search(int key);//(递归)搜索函数入口 
		BSTNode* Delete(int key);//删除函数（函数入口）
		bool Show();//展示函数入口
		bool show();//中序遍历展示入口 
		bool Outfile();//写入文件函数入口 
		bool Infile();//从文件中读取函数 
	private:
		 int content; 
	     BSTNode* root;//根结点地址 
		 bool insert(BSTNode* data, BSTNode* link);//(递归)插入函数[比较关键码] 
		 BSTNode* search(int key, BSTNode* link);//(递归)搜索函数[比较关键码] 
		 bool Delete(int key, BSTNode* link);//删除函数递归体 
		 bool Show(string str, BSTNode* current);//展示函数 
		 bool show(BSTNode* current);//中序遍历展示体 
		 bool Outfile(BSTNode* current);//写入文件函数主体 
		 string** Apart();//拆分读取内容
};

#endif
