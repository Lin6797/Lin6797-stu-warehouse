//minTree_class

#include"Graphmtx_class.h"
#include"minHeap_detail.cpp"

#ifndef minHeap_class_H
#define minHeap_class_H

class MTEdge{//��С�������߽���ඨ�� 
	public:
		int tail, head;
		int weight;
};

template<class T>
void Graphmtx<T>::Prim(){
	MTEdge* Edge=new MTEdge[nowVetices-1];//�ñ������ʾ��
	int Max=nowVetices-1,now=0;//��֦��������͵�ǰ��
	
	MTEdge ed;//��С�������߽���ඨ��
	int n,m,v,u,count; 
	n=nowVetices; m=nowEdges/2;
	u=0;//�������Ϊ0���
	minHeap<MTEdge> H(m);//��С��
	bool* Vmst=new bool[nowVetices];
	for(int i=0; i<nowVetices;i++){//��ʼ�� 
		Vmst[i]=false;
	}
	
	Vmst[u]=true; count=1;//��������һ��u 
	
	do{
		v=getFirst(u);//�õ�int 
		while(v!=-1){//��ʼ�㲻�ǹ����� 
			if(Vmst[v]!=true){//v��δ����ȡ 
				ed.head=v; ed.tail=u;
				ed.weight=getWeight(v,u);
				H.Build(ed,ed.weight);//��� 
			}
			v=getNext(u,v);
		}//��v��Χ��ȫ����� 
		
		while(H.IsEmpty()==false && count<n){
			ed=H.Out();//�˶�
			if(Vmst[ed.head]==false){
				Edge[now]=ed; now++;
				u=ed.head; Vmst[u]=true;
				count++; break;
			}
		}
	}while(count<n);
}

#endif
