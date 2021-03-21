//最小堆的具体实现
#include "minHeap_class.h" 
#include <iostream>
using namespace std;

template<class T>
minHeap<T>::minHeap(int n){ //构造函数 
	Num=0; Capacity=n; //初始化 
	tHeap=new T[n]; //开辟空间 
	eHeap=new int[n];
}

template<class T>
bool minHeap<T>::IsEmpty(){//判断堆是否为空 
	if(Num==0) return true;
	else return false;
}

template<class T>
bool minHeap<T>::IsFull(){//判断堆是否为满 
	if(Num==Capacity) return true;
	else return false;
}

template<class T>
bool minHeap<T>::SiftUp(int start){//上滑调整堆（默认start=Num-1） 
	int j=start, i=(j-1)/2; //j为起始点，i为起始点的父母点
	T ttemp=tHeap[start]; int etemp=eHeap[start]; //两种类型的中间量 
	while(j>0){
		if(eHeap[i]<=etemp) break; //子节点的权值比父母节点的大(或者相等) 
		else{ //子节点的权值比父母节点的小
			eHeap[j]=eHeap[i]; tHeap[j]=tHeap[i];
			j=i; i=(j-1)/2;
		}
	}
	eHeap[j]=etemp; tHeap[j]=ttemp;
	return true;
}

template<class T>
bool minHeap<T>::SiftDown(int start, int end){//下滑调整堆（默认start=0,end=Num-1） 
	int i=start, j=(2*i)+1; //i为起点,j为起点左下角的结点 
	T ttemp=tHeap[i]; int etemp=eHeap[i]; //两种类型的起始量 
	while(j<=end){
		if ( j<end && eHeap[j]>eHeap[j+1] ) j++; //选择较小的子女结点
		
		if(eHeap[j]>=etemp) break; //父母结点的权值比子女结点权值小
		else{ //父母结点权值比子女结点权值大 
			tHeap[i]=tHeap[j]; eHeap[i]=eHeap[j];
			i=j; j=2*i+1;
		}
	}
	eHeap[i]=etemp; tHeap[i]=ttemp;
	return true;
}

template<class T>
bool minHeap<T>::Insert(T t_data, int e_data){ //插入 
	if(IsFull()){
		cout<<"堆已满，不可插入"<<endl;
		return false;
	}
	Num++;
	tHeap[Num-1]=t_data;
	eHeap[Num-1]=e_data;
	SiftUp(Num-1);
	return true;
}

template<class T>
bool minHeap<T>::Build(T t_data, int e_data){ //建表 
	Insert(t_data, e_data);
	return false;
}

template<class T>
T minHeap<T>::Delete(){//删除并返回 
	if(IsEmpty()){
		cout<<"堆为空,不可进行删除"<<endl;
	}
	else{
		T ttemp=tHeap[0]; int etemp=eHeap[0];
	    tHeap[0]=tHeap[Num-1];
	    eHeap[0]=eHeap[Num-1];
	    Num--;
	    SiftDown(0,Num-1);
	    return ttemp;
	}
}

template<class T>
T minHeap<T>::Out(){
	T temp=Delete();
	return temp;
}

template<class T>
T minHeap<T>::Get(){
	return tHeap[0];
}
