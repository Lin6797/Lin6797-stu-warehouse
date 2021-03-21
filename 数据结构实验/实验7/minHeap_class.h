//Heap_class
//最小堆类定义

#ifndef minHeap_class_H
#define minHeap_class_H

template<class T>
class minHeap{
	public:
		minHeap(int n); //构造函数(从外界获得的n为总的元素个数)
		~minHeap(){;} //析构函数
		bool IsEmpty(); //判断堆是否为空
		bool IsFull(); //判断堆是否为满
		bool Build(T t_data, int e_data); //建造堆(进入的元素为data)
		T Out(); //输出堆内元素(输出并删除)
		T Get(); //获得堆内最小元素（输出不删除） 
	private:
		int Capacity; //堆容量 
		int Num; //堆内元素个数
		T* tHeap; //T类型堆空间
		int* eHeap; //E类型堆空间  
		T Delete(); //删除堆内元素
		bool Insert(T t_data, int e_data); // 插入元素(进入的元素为data) 
		bool SiftUp(int start); //上滑调整堆内元素（向堆内插元素时用）
		bool SiftDown(int start, int end); //下滑调整元素（删除堆内元素时用） 
};

#endif
