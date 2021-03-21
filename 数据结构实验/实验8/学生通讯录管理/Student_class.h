//class

#ifndef BST_class_H
#define BST_class_H

#include<iostream>
#include<fstream>
using namespace std; 

//��Ϣ�� 
class Data{
	public:
	string name;//����
	string birthday;//��������
	char sex;//�Ա�
	string phone;//�绰����
	string adver;//��ַ 
};

//������� 
class BSTNode{
	friend class BST;//��Ԫ������ 
	public:
	int key;//ѧ�ţ��ؼ��룩
	Data* data;//����
	BSTNode* lchild,* rchild;//���Һ��ӵ�ַ 
};

//���� 
class BST{
	public:
		BST();//���캯��
		~BST();//�������� 
		bool Build(int num,int* Key, Data** Data);//���캯����� 
		bool Insert(int key,Data* data);//���뺯��
		BSTNode* Search(int key);//(�ݹ�)����������� 
		BSTNode* Delete(int key);//ɾ��������������ڣ�
		bool Show();//չʾ�������
		bool Outfile();//д���ļ�������� 
		bool Infile();//���ļ��ж�ȡ���� 
		
	private:
		 int content;//�ļ��ڲ��������� 
	     BSTNode* root;//������ַ 
		 bool insert(BSTNode* data, BSTNode* link);//(�ݹ�)���뺯��[�ȽϹؼ���] 
		 BSTNode* Search(int key, BSTNode* link);//(�ݹ�)��������[�ȽϹؼ���] 
		 bool Delete(int key, BSTNode* link);//ɾ�������ݹ��� 
		 bool Show(BSTNode* current);//չʾ�������� 
		 bool Outfile(BSTNode* current);//д���ļ��������� 
		 string** Apart();//��ֶ�ȡ����
};

#endif
