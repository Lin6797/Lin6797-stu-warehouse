//Heap_class
//��С���ඨ��

#ifndef minHeap_class_H
#define minHeap_class_H

template<class T>
class minHeap{
	public:
		minHeap(int n); //���캯��(������õ�nΪ�ܵ�Ԫ�ظ���)
		~minHeap(){;} //��������
		bool IsEmpty(); //�ж϶��Ƿ�Ϊ��
		bool IsFull(); //�ж϶��Ƿ�Ϊ��
		bool Build(T t_data, int e_data); //�����(�����Ԫ��Ϊdata)
		T Out(); //�������Ԫ��(�����ɾ��)
		T Get(); //��ö�����СԪ�أ������ɾ���� 
	private:
		int Capacity; //������ 
		int Num; //����Ԫ�ظ���
		T* tHeap; //T���Ͷѿռ�
		int* eHeap; //E���Ͷѿռ�  
		T Delete(); //ɾ������Ԫ��
		bool Insert(T t_data, int e_data); // ����Ԫ��(�����Ԫ��Ϊdata) 
		bool SiftUp(int start); //�ϻ���������Ԫ�أ�����ڲ�Ԫ��ʱ�ã�
		bool SiftDown(int start, int end); //�»�����Ԫ�أ�ɾ������Ԫ��ʱ�ã� 
};

#endif
