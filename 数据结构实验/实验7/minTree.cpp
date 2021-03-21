//minTree_class

#include"Graphmtx_class.h"
#include"minHeap_detail.cpp"

#ifndef minHeap_class_H
#define minHeap_class_H

class MTEdge{//最小生成树边结点类定义 
	public:
		int tail, head;
		int weight;
};

template<class T>
void Graphmtx<T>::Prim(){
	MTEdge* Edge=new MTEdge[nowVetices-1];//用边数组表示树
	int Max=nowVetices-1,now=0;//树枝的最大数和当前数
	
	MTEdge ed;//最小生成树边结点类定义
	int n,m,v,u,count; 
	n=nowVetices; m=nowEdges/2;
	u=0;//设置起点为0结点
	minHeap<MTEdge> H(m);//最小堆
	bool* Vmst=new bool[nowVetices];
	for(int i=0; i<nowVetices;i++){//初始化 
		Vmst[i]=false;
	}
	
	Vmst[u]=true; count=1;//集合内有一点u 
	
	do{
		v=getFirst(u);//得到int 
		while(v!=-1){//起始点不是孤立点 
			if(Vmst[v]!=true){//v点未被读取 
				ed.head=v; ed.tail=u;
				ed.weight=getWeight(v,u);
				H.Build(ed,ed.weight);//入堆 
			}
			v=getNext(u,v);
		}//把v周围的全部入堆 
		
		while(H.IsEmpty()==false && count<n){
			ed=H.Out();//退堆
			if(Vmst[ed.head]==false){
				Edge[now]=ed; now++;
				u=ed.head; Vmst[u]=true;
				count++; break;
			}
		}
	}while(count<n);
}

#endif
