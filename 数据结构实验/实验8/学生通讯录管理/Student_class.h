//class

#ifndef BST_class_H
#define BST_class_H

#include<iostream>
#include<fstream>
using namespace std; 

//信息类 
class Data{
	public:
	string name;//姓名
	string birthday;//出生日期
	char sex;//性别
	string phone;//电话号码
	string adver;//地址 
};

//树结点类 
class BSTNode{
	friend class BST;//友元类声明 
	public:
	int key;//学号（关键码）
	Data* data;//内容
	BSTNode* lchild,* rchild;//左右孩子地址 
};

//树类 
class BST{
	public:
		BST();//构造函数
		~BST();//析构函数 
		bool Build(int num,int* Key, Data** Data);//建造函数入口 
		bool Insert(int key,Data* data);//插入函数
		BSTNode* Search(int key);//(递归)搜索函数入口 
		BSTNode* Delete(int key);//删除函数（函数入口）
		bool Show();//展示函数入口
		bool Outfile();//写入文件函数入口 
		bool Infile();//从文件中读取函数 
		
	private:
		 int content;//文件内部数据数量 
	     BSTNode* root;//根结点地址 
		 bool insert(BSTNode* data, BSTNode* link);//(递归)插入函数[比较关键码] 
		 BSTNode* Search(int key, BSTNode* link);//(递归)搜索函数[比较关键码] 
		 bool Delete(int key, BSTNode* link);//删除函数递归体 
		 bool Show(BSTNode* current);//展示函数主体 
		 bool Outfile(BSTNode* current);//写入文件函数主体 
		 string** Apart();//拆分读取内容
};

#endif
