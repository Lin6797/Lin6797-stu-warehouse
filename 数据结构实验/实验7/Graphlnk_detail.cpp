//Graphlnk_detail
#include"Graphlnk_class.h"

//构造函数 
template<class T>
Graphlnk<T>::Graphlnk(int content){
	maxVetices=content; Max=1000;
	nowVetices=0; nowEdges=0;
	Vetices=new Vetice<T>[maxVetices];//开辟点空间 
}

//判满
template<class T>
bool Graphlnk<T>::IsFull(){ 
	if(nowVetices==maxVetices || nowEdges==(nowVetices-1)*nowVetices) return true;//点满和边满 
	else return false;
}

//判空 
template<class T>
bool Graphlnk<T>::IsEmpty(){ 
	if(nowEdges==0) return true;
	else return false; 
}

//向点内输入数据 
template<class T>
bool Graphlnk<T>::Build(int num, T* content){
	if(num>maxVetices || num<=0) return false;
	
	nowVetices=num;
	for(int i=0;i<num;i++){
		Vetices[i].data=content[i];//输入内容 
		Vetices[i].link=NULL;//初始化 
	}
	return true;
}

//将点进行连接
template<class T>
bool Graphlnk<T>::Link(int v1,int v2, int weight){
	AddEdge(v1,v2,weight);
	nowEdges++;
}

//添加内容为content的点
template<class T>
bool Graphlnk<T>::AddVetice(T content){
	if(IsFull()) return false;
	
	Vetices[nowVetices].data=content;
	nowVetices++;
}

//删除编号为code的点
template<class T>
bool Graphlnk<T>::DelVetice(int code){
	if(code>=nowVetices) return false;//编号从0开始 
	if(nowVetices==1) return false;
	
	if(code<nowVetices-1) Vetices[code]=Vetices[nowVetices-1];
	
	Edge* current, *now;
	for(int i=0;i<maxVetices;i++){
		current=Vetices[i]->link;
		if(current->no==code){//第一个点即为要删除的点 
			Vetices[i]->link=current->link;
			current->link=NULL;
			delete current;
			continue;//规定两个点之间不能有平行线 
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

//添加v1到v2的权值为weight的边
template<class T>
bool Graphlnk<T>::AddEdge(int v1, int v2, int weight){
	if(v1<0 || v1>=nowVetices) return false;
	if(v2<0 || v2>=nowVetices) return false;
	if(weight<0) return false;
	
	Edge* newEdge=new Edge[1];
	newEdge->link=NULL;newEdge->no=v2; newEdge->weight=weight;//初始化
	 
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

//删除v1到v2的边
template<class T>
bool Graphlnk<T>::DelEdge(int v1, int v2){
	if(v1<0 || v1>=nowVetices) return false;
	if(v2<0 || v2>=nowVetices) return false;
	Edge* current=Vetices[v1]->link;
	Edge* now;
	if(current->no==v2){//第一个点即为要删除的目标 
		Vetices[v1]->link=current->link;
		current->link=NULL;
		delete current;
		return true;//规定两点之间不能存在平行线 
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

//获得点v的第一个邻接点
template<class T>
int Graphlnk<T>::getFirst(int v){
	if(v>=nowVetices || v<0) return 0;
	if(Vetices[v].link==NULL) return -1;
	else return (Vetices[v].link->no);
}

//获得点v1的邻接点v2的下一个邻接点 
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

//获得点v1到v2的边的权值
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
	return Max;//两点不相连 
}

//显示 
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

//深度遍历入口 
template<class T>
void Graphlnk<T>::DFS(int start){//入口 
	bool* visited=new bool[maxVetices];
	for(int i=0;i<maxVetices;i++){
		visited[i]=false;//初始化 
	}
	DFS(start,visited);
	delete visited;
}

//深度遍历 
template<class T>
void Graphlnk<T>::DFS(int now, bool* visited){
	ofstream out("Graph.txt",ios::app);
	cout<<Vetices[now].data<<"  ";
	out<<Vetices[now].data<<"  ";
	visited[now]=true;
	int next=getFirst(now);
	if(next!=-1 && visited[next]!=true) DFS(next,visited);
	//纵向结束，开始横向 
	next=getNext(now,next);
	while(next!=-1){
		if(visited[next]!=true){
			DFS(next,visited);
		}
		next=getNext(now,next);//寻找下一个进行试探的点 
	}
	out.close();
}

//广度遍历 
template<class T>
void Graphlnk<T>::WFS(int start){
	ofstream out("Graph.txt",ios::app);
	Queue<int> Q(nowVetices+1); int now,next;
	bool* visited=new bool[nowVetices];
	
	for(int i=0;i<nowVetices;i++){//初始化 
		visited[i]=false;
	}
	
	Q.EnQueue(start);//入队
	visited[start]=true;//标志
	while(Q.IsEmpty()==false){
		now=Q.OutQueue();
		cout<<Vetices[now].data<<"  ";
		out<<Vetices[now].data<<"  ";	
		next=getFirst(now); 
		while(next!=-1){
			if(visited[next]!=true){
				Q.EnQueue(next);
				visited[next]=true;//标志
			}
			next=getNext(now,next);
		}
	}
	out.close(); 
}

//获得度数 
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

//拓扑排序
template<class T> 
void Graphlnk<T>::TolplogicalSort(){
	Stack<int> Count(nowVetices);
	int* Degree=new int[nowVetices];//存储各点入度 
	int* Sort=new int[nowVetices];//存储排序(各点编号)
	bool* Judge=new bool[nowVetices];//判断该点是否已经被读取 
	int count=0;//已经输出（进入拓扑序列）的个数
	
	for(int i=0;i<nowVetices;i++){//初始化
		Degree[i]=getDegree(i);
		Judge[i]=false;
	}
	
	for(int i=0;i<nowVetices;i++){
		if(Degree[i]==0)//选出入度为0的，然后入栈 
		   {Count.Push(i); Judge[i]=true; break;} 
	}

	while(Count.IsEmpty()==false){
		Sort[count]=Count.Pop();//出栈,对整个点（的序号）进行存储 
		count++;
		
		for(int t=0;t<nowVetices;t++){
			if(Judge[t]==true) continue;//已经进入栈，不需要进行比较 
			 
			Edge* current=Vetices[t].link;
			while(current!=NULL){
				if(current->no==Sort[count-1]){
					Degree[t]=Degree[t]-1;
					break;
				}
				current=current->link;
			}
		}//对剩下的点的度数处理完毕
		
		
		for(int i=0;i<nowVetices;i++){
			if(Degree[i]==0 && Judge[i]==false){
				Count.Push(i); Judge[i]=true;
			}
		}
	}
	Sortshow(Sort);
}
//输出拓扑排序结果
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
