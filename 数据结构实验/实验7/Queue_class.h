//队列类声明
using namespace std;

#ifndef Queue_class_H
#define Queue_class_H

template<class T> 
class Queue{
	private:
		int Capacity; //队列容量  
	public:
		int rear; //指向队列的末端
		int front; //指向队列的前端
		T *in_queue; //队列头指针
		Queue(int Capacity); //构造函数
		~Queue();//析构函数 
		bool IsEmpty(); //判断是否为空
		bool IsFull(); //判断是否满
		bool EnQueue(T elements); //入队
		T OutQueue(); //出队
};

#endif 
