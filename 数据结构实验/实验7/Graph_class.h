//Graph class

#include<iostream>
using namespace std;

#ifndef Graph_class_H
#define Graph_class_H

class Edge{//边结点定义 
	public:
	Edge* link;//下一条边
	int weight;//权值 
	int no;//边连接的另一个点 
};

template <class T>
class Vetice{//点定义 
	public:
	T data;//内容
	Edge* link;//边结点指针 
};

template<class T>
class Graph{
	public:
		Graph();//构造函数
		~Graph(){;}//析构函数 
		virtual void DFS(int start);//深度遍历入口 
		void WFS(int start);//广度遍历 
	protected:
		int maxVetices;//最大容量 
		virtual void DFS(int now, bool* visited);//深度遍历
};

#endif
