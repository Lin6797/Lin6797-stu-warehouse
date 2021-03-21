//队列类实现

#ifndef Queue_detail_cpp
#define Queue_detail_cpp

#include"Queue_class.h"
#include<iostream>
using namespace std;

template<class T>
Queue<T>::Queue(int capacity){ //构造函数 
	front = 0;
	rear = front;
	Capacity = capacity;
	in_queue = new T[Capacity]; 
} 

template<class T>
Queue<T>::~Queue(){ //析构函数 
	delete in_queue;
}

template<class T>
bool Queue<T>::IsEmpty(){ //判空 
	if(front == rear)
	return true;
	return false;
}

template<class T>
bool Queue<T>::IsFull(){ //判满 
	if( (rear+1)% Capacity == front)
	return true;
	return false;
}

template<class T>
bool Queue<T>::EnQueue(T elements){ //入队 
	in_queue[rear] = elements;
	rear = (rear+1)%Capacity;
	return true;
}

template<class T>
T Queue<T>::OutQueue(){ //出队 
	T purpose;
	purpose = in_queue[front];
	front = (front+1)%Capacity;
	return (purpose);
}   

#endif
