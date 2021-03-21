/*************���İ�****************/
/**********���ߣ���ӱ��************/
/*********2019��10��10���հ�*******/ 

//���Լ��ຯ������ 

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
		LinkNode *head; //ͷ��� 
		int Number; //���Ԫ�ظ�������ʼ���ã�
		int *Elements; //���飬�洢���Ԫ�أ���ʼ���ã� 
	public:
		int Num; //���е�Ԫ�ظ���
	    LinearList(); //�ʼ��ֵ 
	    void Interlize();//��ʼ�� 
	    void head_Build(int num); //ͷ�巨 
	    void behind_Build(int num);  //β�巨 
	    void Insert(int site, int& purpose); //����Ԫ��purpose��site 
	    void Delete(int& site); //ɾ����siteλԪ��
		bool Search(int& purpose); //����Ԫ��purpose
		void reLink(); //��������
		void Part(); //�ֽ����� 
		void output(); //���
		void output(LinkNode *head);//��������� 
};

LinearList::LinearList(){
	head = new LinkNode[4];
	
	int num; //����Ԫ�ظ��� 
	char build_judge; //�жϽ����� 
	string Build_judge="unBuilded";
	cout<<"��������Ҫ������������Ԫ�ظ�����";
	cin>>num;cin.sync();
	
	cout<< "\t\t|--------------------------------------------------------------------------|\n";
    cout<< "\t\t|                       1.ͷ�巨�������õ�����                           |\n";
    cout<< "\t\t|                       2.��巨�������õ�����                           |\n";
    cout<< "\t\t|--------------------------------------------------------------------------|\n";
	cout<<"��ѡ��������ķ�����1/2����"; //1-ͷ�巨��2-β�巨 
	cin>>build_judge;cin.sync();	
	   
	while(1)//�жϽ�����
	{ 
		if(build_judge == '1'){
			head_Build(num);
			Number=num;
			cout<<"����ǰ�巨�õ�����Ϊ��"<<endl;
			output();
			cout<<endl;
			break;
		}
		if(build_judge == '2'){
			behind_Build(num);
			Number=num;
			cout<<"���ú�巨�õ�����Ϊ��"<<endl;
			output();
			cout<<endl;
			break;
		}
		else{
			cout<<"�������ݴ������������룺";
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

void LinearList::Interlize(){ //��ʼ�� 
	int i=0;
	LinkNode *current;
	LinkNode *newNode;
	current = head;
	
	if( Num < Number){ //Ŀǰ������Ԫ�ظ���С�ڳ�ʼ��������Ҫ���������ռ� 
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
void LinearList::behind_Build(int num){ //��壨���˳��
	LinkNode *current;
	LinkNode *newNode;
	current = head;
	
	cout<<"��������Ҫ���д�������ݣ�";
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
void LinearList::head_Build(int num){ //ǰ�壨�������)
	LinkNode *current;
	LinkNode *newNode;
	
	head->link = NULL;
	
	cout<<"��������Ҫ���д�������ݣ�";
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
void LinearList::Insert(int site, int& purpose){ //���� 
	
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

void LinearList::Delete(int& site){//ɾ��
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
bool LinearList::Search(int& purpose){ //����
	int count=0;
	string Search_judge="unexist";
	LinkNode *current;
	
	current = head->link;
	while(current != NULL){
		count++;
		
		if(current->data == purpose)
		{
			Search_judge = "exist";
			cout<<"��"<<count<<"λ  ";
		}
		current = current->link;
	}
	
	if(Search_judge == "unexist")
	return false;
	else
	return true;
}
void LinearList::reLink(){ //���� 
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
void LinearList::Part(){ //�ָ� 
	LinkNode *current;
	LinkNode *del; //ɾ���洢ż���Ĵ洢��Ԫ 
	LinkNode *new_head; //�½��������Ϊ������(�洢ż��)��ͷ���
	LinkNode *new_current; //�½������洢ż�����ı�־ 
	int even = 0; //ż������Ԫ�ظ��� 
	int uneven = Num; // ��������Ԫ�ظ��� 
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
	   cout<<"��������������";
	   output();
	} 
	else{
		cout<<endl<<"�����в���������"<<endl; 
	}
	
	if(even != 0){
	   cout<<"����ż��������";
	   output(new_head);
	} 
	else{
		cout<<endl<<"�����в�����ż��"<<endl; 
	}
}
void LinearList::output(){ //���
	LinkNode *current;
	current = head->link;
	while(current != NULL)
	{
		cout<<current->data<<"  ";
		current = current->link;
	}
} 
void LinearList::output(LinkNode *head){ //�¶���ͷ������
	LinkNode *current;
	current = head->link;
	while(current != NULL)
	{
		cout<<current->data<<"  ";
		current = current->link;
	}
}
