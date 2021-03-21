//ͷ�ļ�
#include<iostream>
using namespace std;

struct TreeNode{
	TreeNode *leftchild;//����Ů 
	char data;//������� 
	TreeNode *parent;//��ĸ 
	TreeNode *rightchild;//����Ů 
};

class Tree{
	private:
		int lheight, rheight;//���������߶� 
		int Leaves;//Ҷ������ 
		string purpose; //Ŀ����������ַ���������ʽ 
		TreeNode *root;//�����
		int TreeHeight(TreeNode *tree);//�����ߺ��� 
		void TreeLeaves(TreeNode *root);//����Ҷ��������
	public:
		Tree();//���캯�� 
		~Tree(){delete root;}//��������
		TreeNode *Build();//����
		bool aheadscan(TreeNode *tree,void (*visit)(TreeNode*));//ǰ��ɨ��(�ݹ�)
		bool aheadscan_s(void (*visit)(TreeNode*));//ǰ��ɨ�裨�ǵݹ飩 
		bool midscan(TreeNode *tree,void (*visit)(TreeNode*));//����ɨ�裨�ݹ飩 
		bool midscan_s(void (*visit)(TreeNode*));//����ɨ�裨�ǵݹ飩 
		bool tailscan(TreeNode *tree,void (*visit)(TreeNode*));//����ɨ�� (�ݹ�)
		bool tailscan_s(void (*visit)(TreeNode*));//����ɨ�裨�ǵݹ飩 
		int TreeHeight();//�����ߺ������ 
		int TreeLeaves();//����Ҷ����������� 
		bool Output();//���������
};
