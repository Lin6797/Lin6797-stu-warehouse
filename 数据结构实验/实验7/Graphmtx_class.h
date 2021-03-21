//Graphmtx_class

#include"Queue_detail.cpp"
#include<iostream>
#include<fstream>
using namespace std;

#ifndef Graphmtx_class_H
#define Graphmtx_class_H

class MTEdge{//��С�������߽���ඨ�� 
	public:
		int tail, head;
		int weight;
};

template<class T>
class Graphmtx{
	public:
		 Graphmtx(int content);//���캯�� 
		 ~Graphmtx(){}//�������� 
		 bool Build(int num, T* content);//����
		 bool Link(int v1,int v2,int weight);//���ӵ� 
		 bool Show();//չʾ
		 void DFS(int start);//��ȱ������
		 void WFS(int start);//��ȱ���
		 void Prim();//����С������
		 void Kruskal();//����С������
		 void Dijstrate(int start);//�����·�� 
	protected:
		T* Vetices;//���б�
		int Max;//���ֵ 
		int** Edges;//���б� 
		int nowVetices;//Ŀǰ���� 
		int nowEdges;//Ŀǰ���� 
		int maxVetices;//Ŀǰ������� 
		bool IsEmpty();//�п� 
		bool IsFull();//���� 
		bool AddVetice(T content);//�������Ϊcontent�ĵ� 
		bool DelVetice(int v);//ɾ�����Ϊv�ĵ�
		bool AddEdge(int v1, int v2, int weight);//���v1��v2��ȨֵΪweight�ı�
		bool DelEdge(int v1, int v2);//ɾ��v1��v2�ı�
		int getFirst(int v);//��õ�v�ĵ�һ���ڽӵ�
		int getNext(int v1, int v2);//��õ�v1���ڽӵ�v2����һ���ڽӵ� 
		int getWeight(int v1, int v2);//��õ�v1��v2�ıߵ�Ȩֵ
		void DFS(int now, bool* visited);//��ȱ���
		void Treeshow(MTEdge* edge);//�����С��
		void Pathshow(int* path);//������·�� 
};

#endif
