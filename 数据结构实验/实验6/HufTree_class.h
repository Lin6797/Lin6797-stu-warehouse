//HuffmanTree_class
#include"minHeap_class.h" 
#include<iostream>
using namespace std;

class Huffman{
	public:
		Huffman();//���캯��
		bool Interlize();//��ʼ��
		bool Encoding();//����
		bool Decoding();//����
		bool Print();//��ӡ�����ļ�
		bool TreePrint();//��ӡ�������� 
	private:
		TreeNode* Root;//���������ĸ�
		string code;//����
		bool TreePrint(TreeNode* current,string s);//����������
		bool Print(TreeNode* current,string s);//�������д���ļ� 
		bool Scan(TreeNode* current,char pu);//������������ 
};
