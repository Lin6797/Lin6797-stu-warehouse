//ջ����ʵ���ļ�
#include"Stack_class.h"
#include<iostream>
using namespace std;
 
template <class T> 
Stack<T>::Stack(int capacity){ //����ջ 
	top = -1;
	Top = top;
	Capacity = capacity;
	in_stack = new T[capacity];
}

template <class T> 
Stack<T>::~Stack(){ //�������� 
	delete in_stack;
}

template <class T> 
bool Stack<T>::IsEmpty(){ //�п� 
	if(top == -1) return true;
	return false;
}

template <class T> 
bool Stack<T>::IsFull(){ //���� 
	if(top == Capacity-1) return true;
	return false;
}

template <class T> 
bool Stack<T>::Push(T elements){ //��ջ 
	top++;
	Top = top;
	in_stack[top] = elements;
	return true;
}

template <class T> 
T Stack<T>::Pop(){ //��ջ 
	top--;
	Top = top;
	return in_stack[top+1];
}
