//ջͷ�ļ� 

using namespace std;

template <class T> 
class Stack{
	private:
		int Capacity; //ջ����
		int top; //ջ��ָ��   
	public:
		int Top;
		T *in_stack; //ջ
	    Stack(int capacity); //���캯��
	    ~Stack();//�������� 
		bool IsEmpty(); //�п� 
		bool IsFull(); //����
		bool Push(T elements); //��ջ
		T Pop(); //��ջ
};
