//ջ�ඨ�� 
#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

class Stack{
	private:
		int Capacity; //ջ����
		int top; //ջ��ָ�� 
		int number; //����ջԪ�ظ��� 
		string *Car_number; //���ƺ� 
		int *Time_hour; //ͣ��ʱ��(hour) 
		int *Time_min; //ͣ��ʱ�� (minute)
	public:
		int num; //����ջԪ�ظ��� 
	    Stack(); //���캯��
		bool IsEmpty(); //�п� 
		bool IsFull(); //����
		bool Push(string car_number); //��ջ
		bool Pop(int purpose); //��ջ������Ϊ��ջ�ǵ�purposeλ��
		int Money(int purpose); //����Ӧ�������Ϊ��ջ�ǵ�purposeλ�� 
		void show();//չʾջ�г����Լ���ջʱ�� 
		void in_Stack(int top);//������ջ��Ϣд���ĵ�
		void out_Stack(int top);//������ջ��Ϣд���ĵ� 
};

Stack::Stack(){
	top = -1;
	number = top+1; 
	cout<<"������ͣ����������";
	cin>>Capacity;cin.sync();
	Car_number = new string[Capacity]; //���ٿռ�洢���ƺ�
	Time_hour = new int[Capacity]; //���ٿռ�洢��ջʱ�䣨hour�� 
	Time_min = new int[Capacity];  //���ٿռ�洢��ջʱ�䣨minute��
}
bool Stack::IsEmpty(){
	if(top == -1) return true;
	else return false;
}
bool Stack::IsFull(){
	if (top == Capacity-1) return true;
	else return false;
}
bool Stack::Push(string car_number){ //��ջ 
	top++;number++;num = number;
	Car_number[top] =car_number;
	
	struct tm *local; 
	time_t t; 
	t = time(NULL); 
	local = localtime(&t); 
	Time_hour[top] = local->tm_hour; //���ʱ����ջ��hour�� 
	Time_min[top] = local->tm_min; //���ʱ����ջ��minute��
	
	in_Stack(top); 
	
	cout<<"���ƺ�Ϊ"<<Car_number[top]<<"�������Ѿ���"<<Time_hour[top]<<":"<<Time_min[top]<<"���복��"<<endl;
	return true; 
}
int Stack::Money(int purpose){ //����Ӧ����� 
	int money;
	struct tm *local;  //ȷ���뿪ʱ�� 
	time_t t; 
	t = time(NULL);  
	local = localtime(&t); 
	
	if(Time_min[purpose-1] < (local->tm_min))
	money = 3*( (local->tm_hour) - Time_hour[purpose-1] +1 );
	else money = 3*( (local->tm_hour) - Time_hour[purpose-1] );
	
	return money;
}
bool Stack::Pop(int purpose){ //��ջ 
	string *temporary_Car_number = new string[number-purpose]; //��ʱջ 
	int *temporary_Time_hour = new int[number-purpose]; //��ʱջ 
	int *temporary_Time_min = new int[number-purpose]; //��ʱջ 
	int temporary_top = -1; //��ʱջջ��ָ��
	
	struct tm *local;//ȷ���뿪ʱ�� 
	time_t t;
	t = time(NULL);
	local = localtime(&t); 
	
	if(purpose == number){
		out_Stack(top);
	 	cout<<"���ƺ�Ϊ"<<Car_number[top]<<"����������"<<local->tm_hour<<":"<<local->tm_min<<"�뿪����"<<endl;
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
	         
	         cout<<"���ƺ�Ϊ"<<Car_number[top]<<"����������"<<local->tm_hour<<":"<<local->tm_min<<"�뿪����"<<endl;
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
	if(IsEmpty()) cout<<"��ʱ������û������"<<endl;
	else{
		for(int i = 0; i<=top; i++)
	    {
		   cout<<"�����ڵ�"<<i+1<<"���������ƺ�Ϊ:"<<Car_number[i]<<"  ���복��ʱ��Ϊ��"<<Time_hour[i]<<":"<<Time_min[i]<<endl;
	    }
	}
}
void Stack::in_Stack(int top){ //���ļ���д�복�����복�����Ϣ 
	ofstream outfile("in_Stack",ios::app);
	outfile<<"�������ƺ�Ϊ:"<<Car_number[top]<<"  ���복��ʱ��Ϊ��"<<Time_hour[top]<<":"<<Time_min[top]<<endl;
	outfile.close();
}
void Stack::out_Stack(int top){ //���ļ���д�복���뿪�������Ϣ
	struct tm *local;
	time_t t; 
	t = time(NULL);  
	local = localtime(&t); 
	
	ofstream outfile("out_Stack",ios::app);
	outfile<<"���ƺ�Ϊ"<<Car_number[top]<<"����������"<<local->tm_hour<<":"<<local->tm_min<<"�뿪����"<<endl;
	outfile.close();
}
