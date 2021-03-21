//队列的类定义
#include<iostream>
using namespace std;

class Queue{
	private:
		int Capacity; //队列容量 
		int rear; //指向队列的末端
		int front; //指向队列的前端
		string *Car_number; //车牌号码 
	public:
		Queue(); //构造函数
		bool IsEmpty(); //判断是否为空
		bool IsFull(); //判断是否满
		bool EnQueue(string car_number); //入队(参数为车牌号)
		string OutQueue(); //出队(返回车牌号) 
		void show(); //展示等候区中的汽车 
};

Queue::Queue(){ //构造函数，给Capacity，front和rear赋值，开辟空间 
	rear = 0;
	front = 0;
	
	cout<<"请输入等候区容量；";
	cin>>Capacity;cin.sync();
	Car_number = new string[Capacity+1]; //队列判满的时候会有一个区域浪费，在这里补上 
}

bool Queue::IsEmpty(){ //判空 
	if (front == rear) return true;
	else return false; 
}
bool Queue::IsFull(){ //判满 
	if( (rear+1)%(Capacity+1) == front) return true;
	else return false;
}
bool Queue::EnQueue(string car_number){ //入队 
	rear = rear%(Capacity+1);
	Car_number[rear] = car_number;
	rear++;
	cout<<endl; 
	cout<<"车牌号为"<<car_number<<"的车辆已经成功进入等候区"<<endl; 
	return true;
}
string Queue::OutQueue(){ //出队 
	string car_number;
	
	front = front%(Capacity+1);
	car_number = Car_number[front];
	front++;
	return car_number;
}
void Queue::show(){
	int t = 1;
	if(IsEmpty()) cout<<"此时等候区中没有车辆"<<endl;
	else{
		for(int i=front; i != rear; i++)
	    {
		   i = i%(Capacity+1);
		   cout<<"等候区内第"<<t<<"辆汽车车牌号为:"<<Car_number[i]<<endl;
		   t++;
	    }
	}
} 
