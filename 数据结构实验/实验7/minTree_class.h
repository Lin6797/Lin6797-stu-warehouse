//minTree_class.h

#ifndef minTree_class_H
#define minTree_class_H
#include"minHeap_detail.cpp" 
#include"Graphmtx_class.h"
#include<iostream>
using namespace std;

class MTedge{//��С�������� 
	friend class Mintree;
	int tail,head;
	int weight;
};

template<class T>
class minTree:public Graphmtx<T>{
	public:
		minTree(int content){nowVetices=content;}//���캯�� 
		void Prim();
	private:
		int nowVetices;
};

#endif
