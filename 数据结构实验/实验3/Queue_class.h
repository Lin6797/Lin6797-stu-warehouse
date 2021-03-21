//���е��ඨ��
#include<iostream>
using namespace std;

class Queue{
	private:
		int Capacity; //�������� 
		int rear; //ָ����е�ĩ��
		int front; //ָ����е�ǰ��
		string *Car_number; //���ƺ��� 
	public:
		Queue(); //���캯��
		bool IsEmpty(); //�ж��Ƿ�Ϊ��
		bool IsFull(); //�ж��Ƿ���
		bool EnQueue(string car_number); //���(����Ϊ���ƺ�)
		string OutQueue(); //����(���س��ƺ�) 
		void show(); //չʾ�Ⱥ����е����� 
};

Queue::Queue(){ //���캯������Capacity��front��rear��ֵ�����ٿռ� 
	rear = 0;
	front = 0;
	
	cout<<"������Ⱥ���������";
	cin>>Capacity;cin.sync();
	Car_number = new string[Capacity+1]; //����������ʱ�����һ�������˷ѣ������ﲹ�� 
}

bool Queue::IsEmpty(){ //�п� 
	if (front == rear) return true;
	else return false; 
}
bool Queue::IsFull(){ //���� 
	if( (rear+1)%(Capacity+1) == front) return true;
	else return false;
}
bool Queue::EnQueue(string car_number){ //��� 
	rear = rear%(Capacity+1);
	Car_number[rear] = car_number;
	rear++;
	cout<<endl; 
	cout<<"���ƺ�Ϊ"<<car_number<<"�ĳ����Ѿ��ɹ�����Ⱥ���"<<endl; 
	return true;
}
string Queue::OutQueue(){ //���� 
	string car_number;
	
	front = front%(Capacity+1);
	car_number = Car_number[front];
	front++;
	return car_number;
}
void Queue::show(){
	int t = 1;
	if(IsEmpty()) cout<<"��ʱ�Ⱥ�����û�г���"<<endl;
	else{
		for(int i=front; i != rear; i++)
	    {
		   i = i%(Capacity+1);
		   cout<<"�Ⱥ����ڵ�"<<t<<"���������ƺ�Ϊ:"<<Car_number[i]<<endl;
		   t++;
	    }
	}
} 
