//Graphlnk class

#include"Queue_detail.cpp"
#include"Stack_detail.cpp"
#include<iostream>
#include<fstream>
using namespace std;

#ifndef Graphlnk_class_H
#define Graphlnk_class_H

class Edge{//�߽�㶨�� 
	public:
	Edge* link;//��һ����
	int weight;//Ȩֵ 
	int no;//�����ӵ���һ���� 
};

template <class T>
class Vetice{//�㶨�� 
	public:
	T data;//����
	Edge* link;//�߽��ָ�� 
};

template<class T> 
class Graphlnk{
	public:
		Graphlnk(int content);//���캯�� 
		~Graphlnk(){;}//�������� 
		bool Build(int num, T* content);//����
		bool Link(int v1,int v2,int weight);//���ӵ� 
		bool Show();//չʾ
		void DFS(int start);//��ȱ������
		void WFS(int start);//��ȱ���
		void TolplogicalSort();//�������� 
	private:
		Vetice<T>* Vetices;//���б�
		int Max;//���ֵ 
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
		int getDegree(int v);//���v�ĵĶ�(������ȱ���Ϊ��ȣ���֮��Ȼ)
		void Sortshow(int* sort);//������������� 
};

#endif
