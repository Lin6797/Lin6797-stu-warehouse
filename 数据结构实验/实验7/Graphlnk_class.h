//Graphlnk class

#include"Queue_detail.cpp"
#include"Stack_detail.cpp"
#include<iostream>
#include<fstream>
using namespace std;

#ifndef Graphlnk_class_H
#define Graphlnk_class_H

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
class Graphlnk{
	public:
		Graphlnk(int content);//构造函数 
		~Graphlnk(){;}//析构函数 
		bool Build(int num, T* content);//建表
		bool Link(int v1,int v2,int weight);//连接点 
		bool Show();//展示
		void DFS(int start);//深度遍历入口
		void WFS(int start);//广度遍历
		void TolplogicalSort();//拓扑排序 
	private:
		Vetice<T>* Vetices;//点列表
		int Max;//最大值 
		int nowVetices;//目前点数 
		int nowEdges;//目前边数 
		int maxVetices;//目前最大容量 
		bool IsEmpty();//判空 
		bool IsFull();//判满 
		bool AddVetice(T content);//添加内容为content的点 
		bool DelVetice(int v);//删除编号为v的点
		bool AddEdge(int v1, int v2, int weight);//添加v1到v2的权值为weight的边
		bool DelEdge(int v1, int v2);//删除v1到v2的边
		int getFirst(int v);//获得点v的第一个邻接点
		int getNext(int v1, int v2);//获得点v1的邻接点v2的下一个邻接点 
		int getWeight(int v1, int v2);//获得点v1到v2的边的权值
		void DFS(int now, bool* visited);//深度遍历
		int getDegree(int v);//获得v的的度(若是入度表则为入度，反之亦然)
		void Sortshow(int* sort);//输出拓扑排序结果 
};

#endif
