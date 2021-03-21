//栈类定义 
#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

class Stack{
	private:
		int Capacity; //栈容量
		int top; //栈顶指针 
		int number; //已入栈元素个数 
		string *Car_number; //车牌号 
		int *Time_hour; //停车时间(hour) 
		int *Time_min; //停车时间 (minute)
	public:
		int num; //已入栈元素个数 
	    Stack(); //构造函数
		bool IsEmpty(); //判空 
		bool IsFull(); //判满
		bool Push(string car_number); //入栈
		bool Pop(int purpose); //出栈（参数为出栈是第purpose位）
		int Money(int purpose); //计算应付款（参数为出栈是第purpose位） 
		void show();//展示栈中车辆以及入栈时间 
		void in_Stack(int top);//汽车入栈消息写入文档
		void out_Stack(int top);//汽车出栈消息写入文档 
};

Stack::Stack(){
	top = -1;
	number = top+1; 
	cout<<"请输入停车场容量；";
	cin>>Capacity;cin.sync();
	Car_number = new string[Capacity]; //开辟空间存储车牌号
	Time_hour = new int[Capacity]; //开辟空间存储入栈时间（hour） 
	Time_min = new int[Capacity];  //开辟空间存储入栈时间（minute）
}
bool Stack::IsEmpty(){
	if(top == -1) return true;
	else return false;
}
bool Stack::IsFull(){
	if (top == Capacity-1) return true;
	else return false;
}
bool Stack::Push(string car_number){ //入栈 
	top++;number++;num = number;
	Car_number[top] =car_number;
	
	struct tm *local; 
	time_t t; 
	t = time(NULL); 
	local = localtime(&t); 
	Time_hour[top] = local->tm_hour; //入库时间入栈（hour） 
	Time_min[top] = local->tm_min; //入库时间入栈（minute）
	
	in_Stack(top); 
	
	cout<<"车牌号为"<<Car_number[top]<<"的汽车已经于"<<Time_hour[top]<<":"<<Time_min[top]<<"进入车库"<<endl;
	return true; 
}
int Stack::Money(int purpose){ //计算应付金额 
	int money;
	struct tm *local;  //确定离开时间 
	time_t t; 
	t = time(NULL);  
	local = localtime(&t); 
	
	if(Time_min[purpose-1] < (local->tm_min))
	money = 3*( (local->tm_hour) - Time_hour[purpose-1] +1 );
	else money = 3*( (local->tm_hour) - Time_hour[purpose-1] );
	
	return money;
}
bool Stack::Pop(int purpose){ //出栈 
	string *temporary_Car_number = new string[number-purpose]; //临时栈 
	int *temporary_Time_hour = new int[number-purpose]; //临时栈 
	int *temporary_Time_min = new int[number-purpose]; //临时栈 
	int temporary_top = -1; //临时栈栈顶指针
	
	struct tm *local;//确定离开时间 
	time_t t;
	t = time(NULL);
	local = localtime(&t); 
	
	if(purpose == number){
		out_Stack(top);
	 	cout<<"车牌号为"<<Car_number[top]<<"的汽车已于"<<local->tm_hour<<":"<<local->tm_min<<"离开车库"<<endl;
	 	top--;number--; num=number;
	}
	 else{
	 		do{
		         temporary_top++;
		         temporary_Car_number[temporary_top] = Car_number[top];
		         temporary_Time_hour[temporary_top] = Time_hour[top];
		         temporary_Time_min[temporary_top] = Time_min[top];
		         top--;
	         }while(top != purpose-1);
	         
	         out_Stack(top);
	         
	         cout<<"车牌号为"<<Car_number[top]<<"的汽车已于"<<local->tm_hour<<":"<<local->tm_min<<"离开车库"<<endl;
	         top--;
	
	         for(int i = temporary_top; i>=0; i--)
	         {
			    Car_number[top+1] = temporary_Car_number[i];
		        Time_hour[top+1] = temporary_Time_hour[i];
		        Time_min[top+1] = temporary_Time_min[i];
		        top++;
	         }
	         number--; num=number;
	 }
	return true;
}
void Stack::show(){
	if(IsEmpty()) cout<<"此时车库中没有汽车"<<endl;
	else{
		for(int i = 0; i<=top; i++)
	    {
		   cout<<"车库内第"<<i+1<<"辆汽车车牌号为:"<<Car_number[i]<<"  进入车库时间为："<<Time_hour[i]<<":"<<Time_min[i]<<endl;
	    }
	}
}
void Stack::in_Stack(int top){ //向文件中写入车辆进入车库的消息 
	ofstream outfile("in_Stack",ios::app);
	outfile<<"汽车车牌号为:"<<Car_number[top]<<"  进入车库时间为："<<Time_hour[top]<<":"<<Time_min[top]<<endl;
	outfile.close();
}
void Stack::out_Stack(int top){ //向文件中写入车辆离开车库的消息
	struct tm *local;
	time_t t; 
	t = time(NULL);  
	local = localtime(&t); 
	
	ofstream outfile("out_Stack",ios::app);
	outfile<<"车牌号为"<<Car_number[top]<<"的汽车已于"<<local->tm_hour<<":"<<local->tm_min<<"离开车库"<<endl;
	outfile.close();
}
