//����������
using namespace std;

#ifndef Queue_class_H
#define Queue_class_H

template<class T> 
class Queue{
	private:
		int Capacity; //��������  
	public:
		int rear; //ָ����е�ĩ��
		int front; //ָ����е�ǰ��
		T *in_queue; //����ͷָ��
		Queue(int Capacity); //���캯��
		~Queue();//�������� 
		bool IsEmpty(); //�ж��Ƿ�Ϊ��
		bool IsFull(); //�ж��Ƿ���
		bool EnQueue(T elements); //���
		T OutQueue(); //����
};

#endif 
