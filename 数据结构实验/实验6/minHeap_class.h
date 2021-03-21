//��С���ඨ��

class TreeNode{ //����ඨ�� 
	friend class minHeap;
	friend class Huffman;
	private:
		TreeNode* lchild,* rchild;
	    char data;
	    int weight;
};

class  minHeap{
	public:
		minHeap(int n); //���캯��(������õ�nΪ�ܵ�Ԫ�ظ���)
		~minHeap(){;} //��������
		bool IsEmpty(); //�ж϶��Ƿ�Ϊ��
		bool IsFull(); //�ж϶��Ƿ�Ϊ��
		bool Build(TreeNode* t_data, int e_data); //�����(�����Ԫ��Ϊdata)
		TreeNode* Out(); //�������Ԫ��(�����ɾ��)
		TreeNode* Get(); //��ö�����СԪ�أ������ɾ���� 
	private:
		int Capacity; //������ 
		int Num; //����Ԫ�ظ���
		TreeNode** tHeap; //T���Ͷѿռ�
		int* eHeap; //E���Ͷѿռ�  
		TreeNode* Delete(); //ɾ������Ԫ��
		bool Insert(TreeNode* t_data, int e_data); // ����Ԫ��(�����Ԫ��Ϊdata) 
		bool SiftUp(int start); //�ϻ���������Ԫ�أ�����ڲ�Ԫ��ʱ�ã�
		bool SiftDown(int start, int end); //�»�����Ԫ�أ�ɾ������Ԫ��ʱ�ã� 
};
