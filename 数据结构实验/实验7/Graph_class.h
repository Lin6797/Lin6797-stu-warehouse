//Graph class

#include<iostream>
using namespace std;

#ifndef Graph_class_H
#define Graph_class_H

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
class Graph{
	public:
		Graph();//���캯��
		~Graph(){;}//�������� 
		virtual void DFS(int start);//��ȱ������ 
		void WFS(int start);//��ȱ��� 
	protected:
		int maxVetices;//������� 
		virtual void DFS(int now, bool* visited);//��ȱ���
};

#endif
