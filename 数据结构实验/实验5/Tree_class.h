//��������

#include<iostream>
using namespace std;

struct TreeNode{
	string data;//���洢���� 
	TreeNode* sons[3];//���洢ָ��
};

class Tree{
	public://���캯�������ļ��ж�ȡ���ݲ���������)
		TreeNode* root;//�����������й�ͨ�ĸ���� 
		Tree();//��ȡ�ļ����� 
		~Tree();//��������������)
		bool Build();//������ 
		bool output();//����������
		void Interlize();//����רҵ��Ŀ�Ͱ༶��Ŀ��ʼ�� 
		int Major_number(TreeNode* current); //ͳ��רҵ��(currentΪѧԺ���Ͻ���ַ)
		int Class_number(TreeNode* current);//����༶�����(curretnΪרҵ���Ͻ�����)
		int Student_number(TreeNode* current);//����ѧ���� 
		bool Delete();//������
	private:
		string* R;//�ļ����ݴ洢����R
		int Num;//������Ч���ݹ�Numλ 
		TreeNode* Root;//���ĸ����
		string* Out; //��������ͷָ��
		int num; //�����������ЧԪ�ظ���
		int major_number;//רҵ��
		int class_number;//�༶��
		int student_number;//ѧ���� 
		bool output(TreeNode* tree); //������� 	 
};  
