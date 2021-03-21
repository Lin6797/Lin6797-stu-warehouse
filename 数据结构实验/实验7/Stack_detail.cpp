//栈具体实现文件
#include"Stack_class.h"
#include<iostream>
using namespace std;
 
template <class T> 
Stack<T>::Stack(int capacity){ //构造栈 
	top = -1;
	Top = top;
	Capacity = capacity;
	in_stack = new T[capacity];
}

template <class T> 
Stack<T>::~Stack(){ //析构函数 
	delete in_stack;
}

template <class T> 
bool Stack<T>::IsEmpty(){ //判空 
	if(top == -1) return true;
	return false;
}

template <class T> 
bool Stack<T>::IsFull(){ //判满 
	if(top == Capacity-1) return true;
	return false;
}

template <class T> 
bool Stack<T>::Push(T elements){ //入栈 
	top++;
	Top = top;
	in_stack[top] = elements;
	return true;
}

template <class T> 
T Stack<T>::Pop(){ //出栈 
	top--;
	Top = top;
	return in_stack[top+1];
}
