//������ 

using namespace std;

template<class T> 
class Queue{
	private:
		int rear; //ָ����е�ĩ��
		int front; //ָ����е�ǰ��
		int Capacity; //�������� 
	    T *in_queue; //����ͷָ�� 
	public:
		Queue(int Capacity); //���캯��
		~Queue();
		bool IsEmpty(); //�ж��Ƿ�Ϊ��
		bool IsFull(); //�ж��Ƿ���
		bool EnQueue(T elements); //���
		T OutQueue(); //����
};

