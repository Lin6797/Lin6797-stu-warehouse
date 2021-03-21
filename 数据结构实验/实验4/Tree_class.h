//头文件
#include<iostream>
using namespace std;

struct TreeNode{
	TreeNode *leftchild;//左子女 
	char data;//结点数据 
	TreeNode *parent;//父母 
	TreeNode *rightchild;//右子女 
};

class Tree{
	private:
		int lheight, rheight;//左右子树高度 
		int Leaves;//叶子总数 
		string purpose; //目标二叉树的字符串表现形式 
		TreeNode *root;//根结点
		int TreeHeight(TreeNode *tree);//求树高函数 
		void TreeLeaves(TreeNode *root);//求树叶总数函数
	public:
		Tree();//构造函数 
		~Tree(){delete root;}//析构函数
		TreeNode *Build();//建立
		bool aheadscan(TreeNode *tree,void (*visit)(TreeNode*));//前序扫描(递归)
		bool aheadscan_s(void (*visit)(TreeNode*));//前序扫描（非递归） 
		bool midscan(TreeNode *tree,void (*visit)(TreeNode*));//中序扫描（递归） 
		bool midscan_s(void (*visit)(TreeNode*));//中序扫描（非递归） 
		bool tailscan(TreeNode *tree,void (*visit)(TreeNode*));//后续扫描 (递归)
		bool tailscan_s(void (*visit)(TreeNode*));//后续扫描（非递归） 
		int TreeHeight();//求树高函数入口 
		int TreeLeaves();//求树叶总数函数入口 
		bool Output();//输出二叉树
};
