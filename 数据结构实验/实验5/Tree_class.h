//树类声明

#include<iostream>
using namespace std;

struct TreeNode{
	string data;//结点存储内容 
	TreeNode* sons[3];//结点存储指针
};

class Tree{
	public://构造函数（从文件中读取数据并放入数组)
		TreeNode* root;//用于与外界进行沟通的根结点 
		Tree();//读取文件数据 
		~Tree();//析构函数（销毁)
		bool Build();//创建树 
		bool output();//输出函数入口
		void Interlize();//计算专业数目和班级数目初始化 
		int Major_number(TreeNode* current); //统计专业数(current为学院以上结点地址)
		int Class_number(TreeNode* current);//计算班级数入口(curretn为专业以上结点入口)
		int Student_number(TreeNode* current);//计算学生数 
		bool Delete();//销毁树
	private:
		string* R;//文件数据存储数组R
		int Num;//数组有效数据共Num位 
		TreeNode* Root;//树的根结点
		string* Out; //输出数组的头指针
		int num; //输出数组内有效元素个数
		int major_number;//专业数
		int class_number;//班级数
		int student_number;//学生数 
		bool output(TreeNode* tree); //输出函数 	 
};  
