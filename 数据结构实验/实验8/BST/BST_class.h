//��������

#ifndef BST_class_H
#define BST_class_H

#include <iostream>
#include<fstream>
using namespace std;
 
class BSTNode{//����������� 
	friend class BST;//������Ԫ�� 
	public:
		int key;//�ؼ��� 
	    char data;//����
	    BSTNode* lchild,* rchild;//���ҽ�� 
};

class BST{
	public:
		BST();//���캯��
		BST(int key, char data);//���캯�� 
		~BST();//��������
		bool Build(int num,int* Key, char* Data);//���캯����� 
		bool Insert(int key,char data);//���뺯��
		bool insert(int key,char data);//(�ݹ�)���뺯����� 
		BSTNode* Search(int key);//�������� 
		BSTNode* search(int key);//(�ݹ�)����������� 
		BSTNode* Delete(int key);//ɾ��������������ڣ�
		bool Show();//չʾ�������
		bool show();//�������չʾ��� 
		bool Outfile();//д���ļ�������� 
		bool Infile();//���ļ��ж�ȡ���� 
	private:
		 int content; 
	     BSTNode* root;//������ַ 
		 bool insert(BSTNode* data, BSTNode* link);//(�ݹ�)���뺯��[�ȽϹؼ���] 
		 BSTNode* search(int key, BSTNode* link);//(�ݹ�)��������[�ȽϹؼ���] 
		 bool Delete(int key, BSTNode* link);//ɾ�������ݹ��� 
		 bool Show(string str, BSTNode* current);//չʾ���� 
		 bool show(BSTNode* current);//�������չʾ�� 
		 bool Outfile(BSTNode* current);//д���ļ��������� 
		 string** Apart();//��ֶ�ȡ����
};

#endif
