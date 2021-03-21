//栈头文件 

using namespace std;

template <class T> 
class Stack{
	private:
		int Capacity; //栈容量
		int top; //栈顶指针   
	public:
		int Top;
		T *in_stack; //栈
	    Stack(int capacity); //构造函数
	    ~Stack();//析构函数 
		bool IsEmpty(); //判空 
		bool IsFull(); //判满
		bool Push(T elements); //入栈
		T Pop(); //出栈
};
