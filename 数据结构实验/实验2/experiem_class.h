/*************第四版****************/
/**********作者：林颖钰************/
/*********2019年10月10日终版*******/ 

//类以及类函数定义 

#include <iostream>
using namespace std;
class LinkNode{
	friend class LinearList;
	private:
		int data;
		LinkNode *link;
}; 
class LinearList{
	private:
		LinkNode *head; //头结点 
		int Number; //最初元素个数（初始化用）
		int *Elements; //数组，存储最初元素（初始化用） 
	public:
		int Num; //表中的元素个数
	    LinearList(); //最开始赋值 
	    void Interlize();//初始化 
	    void head_Build(int num); //头插法 
	    void behind_Build(int num);  //尾插法 
	    void Insert(int site, int& purpose); //插入元素purpose到site 
	    void Delete(int& site); //删除第site位元素
		bool Search(int& purpose); //查找元素purpose
		void reLink(); //逆置链表
		void Part(); //分解链表 
		void output(); //输出
		void output(LinkNode *head);//新链表输出 
};

LinearList::LinearList(){
	head = new LinkNode[4];
	
	int num; //表内元素个数 
	char build_judge; //判断建表方法 
	string Build_judge="unBuilded";
	cout<<"请输入你要建立的链表内元素个数：";
	cin>>num;cin.sync();
	
	cout<< "\t\t|--------------------------------------------------------------------------|\n";
    cout<< "\t\t|                       1.头插法建立（得到逆序）                           |\n";
    cout<< "\t\t|                       2.后插法建立（得到正序）                           |\n";
    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	cout<<"请选择建立链表的方法（1/2）："; //1-头插法；2-尾插法 
	cin>>build_judge;cin.sync();	
	   
	while(1)//判断建表方法
	{ 
		if(build_judge == '1'){
			head_Build(num);
			Number=num;
			cout<<"利用前插法得到链表为："<<endl;
			output();
			cout<<endl;
			break;
		}
		if(build_judge == '2'){
			behind_Build(num);
			Number=num;
			cout<<"利用后插法得到链表为："<<endl;
			output();
			cout<<endl;
			break;
		}
		else{
			cout<<"输入数据错误，请重新输入：";
			cin>>build_judge;cin.sync();
		} 
	}
	
	LinkNode *current;
	current = head->link;
	Elements = new int[Number];
	for(int i=0; i<Number; i++)
	{
		Elements[i] = current->data;
		current = current->link;
	}
}

void LinearList::Interlize(){ //初始化 
	int i=0;
	LinkNode *current;
	LinkNode *newNode;
	current = head;
	
	if( Num < Number){ //目前链表内元素个数小于初始个数，需要进行扩增空间 
		do{	
		    current = current->link;
			current->data = Elements[i];
			i++; 
		}while(current->link != NULL);
		
		for(; i<Number; i++)
		{
			newNode = new LinkNode[4];
			newNode->data = Elements[i];
			
			newNode -> link = NULL;
			current -> link = newNode;
			
			current = current -> link;
		}
	}
	
	else{
		do{
		    current = current->link;
			current->data = Elements[i];
			i++;
		}while(i < Number );
		current->link = NULL;
	}
}
void LinearList::behind_Build(int num){ //后插（结果顺序）
	LinkNode *current;
	LinkNode *newNode;
	current = head;
	
	cout<<"请输入你要进行处理的数据：";
	for (int i=0; i<num; i++)
	{
		newNode = new LinkNode[4];
		cin>> (newNode -> data);
		
		newNode -> link = NULL;
		current -> link = newNode;
		
		current = current -> link;
	}
	cin.sync();
	Num = num; 
}
void LinearList::head_Build(int num){ //前插（结果逆序)
	LinkNode *current;
	LinkNode *newNode;
	
	head->link = NULL;
	
	cout<<"请输入你要进行处理的数据：";
	for (int i=0; i<num; i++)
	{
		newNode = new LinkNode[4];
		cin>> (newNode->data);
		
		newNode->link = head->link;
		head->link = newNode;
	}
	cin.sync();
	Num = num;
}
void LinearList::Insert(int site, int& purpose){ //插入 
	
	int count=1;
	LinkNode *newNode;
	LinkNode *current;
	
	current = head;
	newNode = new LinkNode[4];
	newNode->data = purpose;
	
	while(current != NULL)
	{
		if(count==site)
		{
			newNode->link = current->link;
			current->link = newNode;
			break;
		}
		else
		{
			current = current->link;
			count++;
		} 
	}
	Num++;
}

void LinearList::Delete(int& site){//删除
	int count = 1;
	LinkNode *current;
	LinkNode *del;
	
	current = head;
	while(current->link != NULL)
	{
		if(count == site)
		{
			del = current->link;
			current->link = del->link;
			delete del;
			
			break;
		}
		else
		{
			current = current->link;
			count++;
		}
	}
	Num--;
}
bool LinearList::Search(int& purpose){ //查找
	int count=0;
	string Search_judge="unexist";
	LinkNode *current;
	
	current = head->link;
	while(current != NULL){
		count++;
		
		if(current->data == purpose)
		{
			Search_judge = "exist";
			cout<<"第"<<count<<"位  ";
		}
		current = current->link;
	}
	
	if(Search_judge == "unexist")
	return false;
	else
	return true;
}
void LinearList::reLink(){ //逆置 
	LinkNode *current;
	LinkNode *pur_current;
	
	current = head->link;
	while((current->link) != NULL)
	{
		pur_current = current->link;
		current->link = pur_current->link;
		
		pur_current->link = head->link;
		head->link = pur_current;
	}
}
void LinearList::Part(){ //分割 
	LinkNode *current;
	LinkNode *del; //删除存储偶数的存储单元 
	LinkNode *new_head; //新建结点来作为新链表(存储偶数)的头结点
	LinkNode *new_current; //新建链表（存储偶数）的标志 
	int even = 0; //偶数链表元素个数 
	int uneven = Num; // 奇数链表元素个数 
	new_head = new LinkNode[4];
	new_current = new_head; 
	
	current = head;
	while(current->link != NULL)
	{
		del = current->link;
		if((del->data)%2 == 0)
		{
			current->link = del->link;
			del->link = NULL;
			new_current->link = del;
			new_current = new_current->link;
			even++;uneven--;
		}
		else current = current->link;
	}
	Num = uneven;
	
	if(uneven != 0){
	   cout<<"这是奇数的链表：";
	   output();
	} 
	else{
		cout<<endl<<"链表中不存在奇数"<<endl; 
	}
	
	if(even != 0){
	   cout<<"这是偶数的链表：";
	   output(new_head);
	} 
	else{
		cout<<endl<<"链表中不存在偶数"<<endl; 
	}
}
void LinearList::output(){ //输出
	LinkNode *current;
	current = head->link;
	while(current != NULL)
	{
		cout<<current->data<<"  ";
		current = current->link;
	}
} 
void LinearList::output(LinkNode *head){ //新定义头结点输出
	LinkNode *current;
	current = head->link;
	while(current != NULL)
	{
		cout<<current->data<<"  ";
		current = current->link;
	}
}
