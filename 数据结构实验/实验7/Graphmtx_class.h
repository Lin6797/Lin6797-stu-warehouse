//Graphmtx_class

#include"Queue_detail.cpp"
#include<iostream>
#include<fstream>
using namespace std;

#ifndef Graphmtx_class_H
#define Graphmtx_class_H

class MTEdge{//最小生成树边结点类定义 
	public:
		int tail, head;
		int weight;
};

template<class T>
class Graphmtx{
	public:
		 Graphmtx(int content);//构造函数 
		 ~Graphmtx(){}//析构函数 
		 bool Build(int num, T* content);//建表
		 bool Link(int v1,int v2,int weight);//连接点 
		 bool Show();//展示
		 void DFS(int start);//深度遍历入口
		 void WFS(int start);//广度遍历
		 void Prim();//找最小生成树
		 void Kruskal();//找最小生成树
		 void Dijstrate(int start);//找最短路径 
	protected:
		T* Vetices;//点列表
		int Max;//最大值 
		int** Edges;//边列表 
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
		void Treeshow(MTEdge* edge);//输出最小树
		void Pathshow(int* path);//输出最短路径 
};

#endif
