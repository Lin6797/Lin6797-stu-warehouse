//Graphlnk_detail
#include"Graphlnk_class.h"

//���캯�� 
template<class T>
Graphlnk<T>::Graphlnk(int content){
	maxVetices=content; Max=1000;
	nowVetices=0; nowEdges=0;
	Vetices=new Vetice<T>[maxVetices];//���ٵ�ռ� 
}

//����
template<class T>
bool Graphlnk<T>::IsFull(){ 
	if(nowVetices==maxVetices || nowEdges==(nowVetices-1)*nowVetices) return true;//�����ͱ��� 
	else return false;
}

//�п� 
template<class T>
bool Graphlnk<T>::IsEmpty(){ 
	if(nowEdges==0) return true;
	else return false; 
}

//������������� 
template<class T>
bool Graphlnk<T>::Build(int num, T* content){
	if(num>maxVetices || num<=0) return false;
	
	nowVetices=num;
	for(int i=0;i<num;i++){
		Vetices[i].data=content[i];//�������� 
		Vetices[i].link=NULL;//��ʼ�� 
	}
	return true;
}

//�����������
template<class T>
bool Graphlnk<T>::Link(int v1,int v2, int weight){
	AddEdge(v1,v2,weight);
	nowEdges++;
}

//�������Ϊcontent�ĵ�
template<class T>
bool Graphlnk<T>::AddVetice(T content){
	if(IsFull()) return false;
	
	Vetices[nowVetices].data=content;
	nowVetices++;
}

//ɾ�����Ϊcode�ĵ�
template<class T>
bool Graphlnk<T>::DelVetice(int code){
	if(code>=nowVetices) return false;//��Ŵ�0��ʼ 
	if(nowVetices==1) return false;
	
	if(code<nowVetices-1) Vetices[code]=Vetices[nowVetices-1];
	
	Edge* current, *now;
	for(int i=0;i<maxVetices;i++){
		current=Vetices[i]->link;
		if(current->no==code){//��һ���㼴ΪҪɾ���ĵ� 
			Vetices[i]->link=current->link;
			current->link=NULL;
			delete current;
			continue;//�涨������֮�䲻����ƽ���� 
		}
		while(current!=NULL){
			if(current->link->no==code){
				now=current->link;
				current->link=now->link;
				now->link=NULL;
				delete now;
			}
			current=current->link;
		}
	}
	nowVetices--;
	return true;
}

//���v1��v2��ȨֵΪweight�ı�
template<class T>
bool Graphlnk<T>::AddEdge(int v1, int v2, int weight){
	if(v1<0 || v1>=nowVetices) return false;
	if(v2<0 || v2>=nowVetices) return false;
	if(weight<0) return false;
	
	Edge* newEdge=new Edge[1];
	newEdge->link=NULL;newEdge->no=v2; newEdge->weight=weight;//��ʼ��
	 
	Edge* current=Vetices[v1].link;
	if(current==NULL){
	    Vetices[v1].link=newEdge;
	    return true;
	}
	
	while(current->link!=NULL){
		current=current->link;
	}
	current->link=newEdge;
	
	return true;
}

//ɾ��v1��v2�ı�
template<class T>
bool Graphlnk<T>::DelEdge(int v1, int v2){
	if(v1<0 || v1>=nowVetices) return false;
	if(v2<0 || v2>=nowVetices) return false;
	Edge* current=Vetices[v1]->link;
	Edge* now;
	if(current->no==v2){//��һ���㼴ΪҪɾ����Ŀ�� 
		Vetices[v1]->link=current->link;
		current->link=NULL;
		delete current;
		return true;//�涨����֮�䲻�ܴ���ƽ���� 
	}
	while(current!=NULL){
		if(current->link->no==v2){
			now=current->link;
			current=now->link;
			now->link=NULL;
			delete now;
			break;
		}
		current=current->link;
	}
}

//��õ�v�ĵ�һ���ڽӵ�
template<class T>
int Graphlnk<T>::getFirst(int v){
	if(v>=nowVetices || v<0) return 0;
	if(Vetices[v].link==NULL) return -1;
	else return (Vetices[v].link->no);
}

//��õ�v1���ڽӵ�v2����һ���ڽӵ� 
template<class T>
int Graphlnk<T>::getNext(int v1, int v2){
	if(v1>=nowVetices || v1<0) return -1;
	if(v2>=nowVetices || v2<0) return -1;
	
	Edge* current=Vetices[v1].link;
	while(current!=NULL){
		if(current->no==v2){
			break;
		}
		current=current->link;
	}
	if(current->link==NULL || current==NULL ) return -1;
	else return (current->link->no);
} 

//��õ�v1��v2�ıߵ�Ȩֵ
template<class T>
int Graphlnk<T>::getWeight(int v1, int v2){
	if(v1>=nowVetices || v1<0) return 0;
	if(v2>=nowVetices || v2<0) return 0;
	if(v1==v2) return 0;
	
	Edge* current=Vetices[v1].link;
	while(current!=NULL){
		if(current->no==v2) return current->weight;
		current=current->link;
	}
	return Max;//���㲻���� 
}

//��ʾ 
template<class T>
bool Graphlnk<T>::Show(){
	cout<<"  ";
	for(int i=0; i<nowVetices; i++){
		cout<<Vetices[i].data<<" ";
	}
	cout<<endl;
	
	Edge* current;
	for(int i=0; i<nowVetices; i++){
		current=Vetices[i].link;
		cout<<Vetices[i].data<<":";
		while(current!=NULL){
			cout<<Vetices[current->no].data<<" ";
			current=current->link;
		}
		cout<<endl;
	}
	return true;
}

//��ȱ������ 
template<class T>
void Graphlnk<T>::DFS(int start){//��� 
	bool* visited=new bool[maxVetices];
	for(int i=0;i<maxVetices;i++){
		visited[i]=false;//��ʼ�� 
	}
	DFS(start,visited);
	delete visited;
}

//��ȱ��� 
template<class T>
void Graphlnk<T>::DFS(int now, bool* visited){
	ofstream out("Graph.txt",ios::app);
	cout<<Vetices[now].data<<"  ";
	out<<Vetices[now].data<<"  ";
	visited[now]=true;
	int next=getFirst(now);
	if(next!=-1 && visited[next]!=true) DFS(next,visited);
	//�����������ʼ���� 
	next=getNext(now,next);
	while(next!=-1){
		if(visited[next]!=true){
			DFS(next,visited);
		}
		next=getNext(now,next);//Ѱ����һ��������̽�ĵ� 
	}
	out.close();
}

//��ȱ��� 
template<class T>
void Graphlnk<T>::WFS(int start){
	ofstream out("Graph.txt",ios::app);
	Queue<int> Q(nowVetices+1); int now,next;
	bool* visited=new bool[nowVetices];
	
	for(int i=0;i<nowVetices;i++){//��ʼ�� 
		visited[i]=false;
	}
	
	Q.EnQueue(start);//���
	visited[start]=true;//��־
	while(Q.IsEmpty()==false){
		now=Q.OutQueue();
		cout<<Vetices[now].data<<"  ";
		out<<Vetices[now].data<<"  ";	
		next=getFirst(now); 
		while(next!=-1){
			if(visited[next]!=true){
				Q.EnQueue(next);
				visited[next]=true;//��־
			}
			next=getNext(now,next);
		}
	}
	out.close(); 
}

//��ö��� 
template<class T>
int Graphlnk<T>::getDegree(int v){
	Edge* current=Vetices[v].link;
	int degree=0;
	while(current!=NULL){
		degree++;
		current=current->link;
	}
	return degree;
}

//��������
template<class T> 
void Graphlnk<T>::TolplogicalSort(){
	Stack<int> Count(nowVetices);
	int* Degree=new int[nowVetices];//�洢������� 
	int* Sort=new int[nowVetices];//�洢����(������)
	bool* Judge=new bool[nowVetices];//�жϸõ��Ƿ��Ѿ�����ȡ 
	int count=0;//�Ѿ�����������������У��ĸ���
	
	for(int i=0;i<nowVetices;i++){//��ʼ��
		Degree[i]=getDegree(i);
		Judge[i]=false;
	}
	
	for(int i=0;i<nowVetices;i++){
		if(Degree[i]==0)//ѡ�����Ϊ0�ģ�Ȼ����ջ 
		   {Count.Push(i); Judge[i]=true; break;} 
	}

	while(Count.IsEmpty()==false){
		Sort[count]=Count.Pop();//��ջ,�������㣨����ţ����д洢 
		count++;
		
		for(int t=0;t<nowVetices;t++){
			if(Judge[t]==true) continue;//�Ѿ�����ջ������Ҫ���бȽ� 
			 
			Edge* current=Vetices[t].link;
			while(current!=NULL){
				if(current->no==Sort[count-1]){
					Degree[t]=Degree[t]-1;
					break;
				}
				current=current->link;
			}
		}//��ʣ�µĵ�Ķ����������
		
		
		for(int i=0;i<nowVetices;i++){
			if(Degree[i]==0 && Judge[i]==false){
				Count.Push(i); Judge[i]=true;
			}
		}
	}
	Sortshow(Sort);
}
//�������������
template<class T>
void Graphlnk<T>::Sortshow(int* sort){
	ofstream out("Graph.txt",ios::app);
	int t;
	for(int i=0;i<nowVetices;i++){
		t=sort[i];
		cout<<Vetices[t].data<<"  ";
		out<<Vetices[t].data<<"  ";
	}
	out.close();
} 
