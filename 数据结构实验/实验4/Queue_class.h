//队列类 

using namespace std;

template<class T> 
class Queue{
	private:
		int rear; //指向队列的末端
		int front; //指向队列的前端
		int Capacity; //队列容量 
	    T *in_queue; //队列头指针 
	public:
		Queue(int Capacity); //构造函数
		~Queue();
		bool IsEmpty(); //判断是否为空
		bool IsFull(); //判断是否满
		bool EnQueue(T elements); //入队
		T OutQueue(); //出队
};

