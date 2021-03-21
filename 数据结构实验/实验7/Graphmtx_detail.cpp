//Graphmtx_detail
#include "Graphmtx_class.h" 
#include"minHeap_detail.cpp"

//构造函数 
template<class T>
Graphmtx<T>::Graphmtx(int content){
	Max=1000; 
	nowVetices=0; nowEdges=0;
	maxVetices=content;
	Vetices=new T[maxVetices];
	Edges=new int*[maxVetices];
	for(int i=0;i<maxVetices;i++){ 
		Edges[i]=new int[maxVetices];
	}
	for(int i=0; i<maxVetices; i++){//初始化 
		for(int t=0; t<maxVetices; t++){
			if(t!=i) Edges[i][t]=Max;
			else Edges[i][t]=0;
		}
	}
}

//判满
template<class T>
bool Graphmtx<T>::IsFull(){ 
	if(nowVetices==maxVetices || nowEdges==(nowVetices-1)*nowVetices) return true;//点满和边满 
	else return false;
}

//判空 
template<class T>
bool Graphmtx<T>::IsEmpty(){ 
	if(nowEdges==0) return true;
	else return false; 
}

//将点加入点列表
template<class T>
bool Graphmtx<T>::Build(int num, T* content){
	if(num>maxVetices || num<=0) return false;
	
	nowVetices=num;
	for(int i=0;i<num;i++){
		Vetices[i]=content[i];
	}
	return true; 
}

//将点进行连接
template<class T>
bool Graphmtx<T>::Link(int v1,int v2, int weight){
	AddEdge(v1,v2,weight);
	nowEdges++; 
}

//添加内容为content的点
template<class T>
bool Graphmtx<T>::AddVetice(T content){
	if(IsFull()) return false;
	
	Vetices[nowVetices]=content;
	nowVetices++;
}

//删除编号为code的点
template<class T>
bool Graphmtx<T>::DelVetice(int code){
	if(code>=nowVetices) return false;//编号从0开始 
	if(nowVetices==1) return false;
	
	if(code<nowVetices-1) Vetices[code]=Vetices[nowVetices-1];
	for(int i=0;i<nowVetices && code<nowVetices-1 ;i++){
		Edges[i][code]=Edges[i][nowVetices-1];
	}
	for(int i=0;i<nowVetices && code<nowVetices-1 ;i++){
		Edges[code][i]=Edges[nowVetices-1][i];
	}
	nowVetices--;
	return true;
}

//添加v1到v2的权值为weight的边
template<class T>
bool Graphmtx<T>::AddEdge(int v1, int v2, int weight){
	if(v1<0 || v1>=nowVetices) return false;
	if(v2<0 || v2>=nowVetices) return false;
	if(weight<0) return false;
	
	Edges[v1][v2]=weight;
	nowEdges++;
	return true;
}

//删除v1到v2的边
template<class T>
bool Graphmtx<T>::DelEdge(int v1, int v2){
	if(v1<0 || v1>=nowVetices) return false;
	if(v2<0 || v2>=nowVetices) return false;
	
	nowEdges--;
	Edges[v1][v2]=0;
	return true;
}

//获得点v的第一个邻接点
template<class T>
int Graphmtx<T>::getFirst(int v){
	if(v>=nowVetices || v<0) return 0;
	
	for(int i=0;i<nowVetices;i++){
		if(Edges[v][i]!=0) return i;
	}
	return -1;//若该点孤立则回-1 
}

//获得点v1的邻接点v2的下一个邻接点 
template<class T>
int Graphmtx<T>::getNext(int v1, int v2){
	if(v1>=nowVetices || v1<0) return -1;
	if(v2>=nowVetices || v2<0) return -1;
	
	for(int i=v2+1; i<nowVetices; i++){
		if(Edges[v1][i]!=0) return i;
	}
	return -1;
}

//获得点v1到v2的边的权值
template<class T>
int Graphmtx<T>::getWeight(int v1, int v2){
	if(v1>=nowVetices || v1<0) return -1;
	if(v2>=nowVetices || v2<0) return -1;
	if(v1==v2) return 0;
	
	return Edges[v1][v2];
}

//显示 
template<class T>
bool Graphmtx<T>::Show(){
	cout<<"  ";
	for(int i=0; i<nowVetices; i++){
		cout<<Vetices[i]<<" ";
	}
	cout<<endl;
	
	for(int i=0; i<nowVetices; i++){
		cout<<Vetices[i]<<" ";
		for(int t=0; t<nowVetices; t++){
			if(Edges[i][t]==Max) cout<<"∞"<<" ";
			else cout<<Edges[i][t]<<" ";
		}
		cout<<endl;
	}
	return true;
}

//深度遍历入口 
template<class T>
void Graphmtx<T>::DFS(int start){//入口 
	bool* visited=new bool[maxVetices];
	for(int i=0;i<maxVetices;i++){
		visited[i]=false;//初始化 
	}
	DFS(start,visited);
	delete visited;
}

//深度遍历 
template<class T>
void Graphmtx<T>::DFS(int now, bool* visited){
	ofstream out("Graph.txt",ios::app);
	
	out<<Vetices[now]<<"  ";
	cout<<Vetices[now]<<"  ";
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
void Graphmtx<T>::WFS(int start){
	ofstream out("Graph.txt",ios::app);
	Queue<int> Q(nowVetices+1); int now,next;
	bool* visited=new bool[nowVetices];
	
	for(int i=0;i<nowVetices;i++){//初始化 
		visited[i]=false;
	}
	
	Q.EnQueue(start);//入队
	 
	while(Q.IsEmpty()==false){
		now=Q.OutQueue();
		out<<Vetices<<"  ";
		cout<<Vetices[now]<<"  ";
		visited[now]=true;//标志
		next=getFirst(now); 
		while(next!=-1){
			if(visited[next]!=true){
				Q.EnQueue(next);
				visited[next]=true;
			}
			next=getNext(now,next);
		}
	}
	out.close();
}

template<class T>
void Graphmtx<T>::Prim(){
	MTEdge* Edge=new MTEdge[nowVetices-1];//用边数组表示树
	int max=nowVetices-1,now=0;//树枝的最大数和当前数
	
	MTEdge ed;//最小生成树边结点类定义
	int n,m,v,u,count; 
	n=nowVetices; m=nowEdges/2;
	u=0;//设置起点为0结点
	minHeap<MTEdge> H(m);//最小堆
	bool* Vmst=new bool[nowVetices];
	for(int i=0; i<nowVetices;i++){//初始化 
		Vmst[i]=false;
	}
	
	Vmst[u]=true; count=1;//集合内有一点u 
	
	do{
		v=getFirst(u);//得到int 
		while(v!=-1){//起始点不是孤立点 
			if(Vmst[v]!=true){//v点未被读取 
				ed.head=v; ed.tail=u;
				ed.weight=getWeight(v,u);
				H.Build(ed,ed.weight);//入堆 
			}
			v=getNext(u,v);
		}//把v周围的全部入堆 
		
		while(H.IsEmpty()==false && count<n){
			ed=H.Out();//退堆
			if(Vmst[ed.head]==false){
				Edge[now]=ed; now++;
				u=ed.head; Vmst[u]=true;
				count++; break;
			}
		}
	}while(count<n);
	Treeshow(Edge);
}

//最小生成树 
template<class T>
void Graphmtx<T>::Kruskal(){
	
	MTEdge* Edge=new MTEdge[nowVetices-1];//用边数组表示树
	int max=nowVetices-1,now=0;//树枝的最大数和当前数
	
	MTEdge ed;//最小生成树边结点类定义
	int n,m,v,u,count; 
	n=nowVetices; m=nowEdges/2;
	u=0;//设置起点为0结点
	minHeap<MTEdge> H(m);//最小堆
	bool* Vmst=new bool[nowVetices];
	for(int i=0; i<nowVetices;i++){//初始化 
		Vmst[i]=false;
	}
	
	Vmst[u]=true; count=1;//集合内有一点u 
	
	do{
		v=getFirst(u);//得到int 
		while(v!=-1){//起始点不是孤立点 
			if(Vmst[v]!=true){//v点未被读取 
				ed.head=v; ed.tail=u;
				ed.weight=getWeight(v,u);
				H.Build(ed,ed.weight);//入堆 
			}
			v=getNext(u,v);
		}//把v周围的全部入堆 
		
		while(H.IsEmpty()==false && count<n){
			ed=H.Out();//退堆
			if(Vmst[ed.head]==false){
				Edge[now]=ed; now++;
				u=ed.head; Vmst[u]=true;
				count++; break;
			}
		}
	}while(count<n);
	Treeshow(Edge);
	return ;
}

//显示最小生成树 
template<class T>
void Graphmtx<T>::Treeshow(MTEdge* edge){
	ofstream out("Graph.txt",ios::app);
	int h,t;
	for(int i=0;i<nowEdges;i++){
		h=edge[i].head; t=edge[i].tail;  
		cout<<Vetices[h]<<"--"<<edge[i].weight<<"--"<<Vetices[t]<<endl;
		out<<Vetices[h]<<"--"<<edge[i].weight<<"--"<<Vetices[t]<<endl;
	}
	out.close();
	return ;
}

//找最短路径 
template<class T>
void Graphmtx<T>::Dijstrate(int start){
	int u;
	bool* S=new bool[nowVetices];//判断该点是否已经进入了集合中
	int* dist=new int[nowVetices];//起始点Strat到该点的路径长度
	int* path=new int[nowVetices];//起始点Start到该点的路径 
	for(int i=0; i<nowVetices; i++){//初始化 
		S[i]=false; dist[i]=getWeight(start,i);
		if(i!=start && dist[i]<Max) path[i]=start;//起点
		else path[i]=-1;
	}
	
	S[start]=true; dist[start]=0;//起始点入集合  
	for(int i=0; i<nowVetices-1; i++){
		int minWeight=Max;
		int u=start;//初始化 
		for(int j=0;j<nowVetices;j++){//找到最小路径值 
			if(S[j]==false && dist[j]<minWeight){
			    u=j; minWeight=dist[j];
			}
	    }
		S[u]=true;
		for(int k=0; k<nowVetices; k++){//修改 
			int w=getWeight(u,k);
			if(S[k]==false && w<Max && dist[u]+w<dist[k]){
				dist[k]=dist[u]+w; path[k]=u;
			}
		}
	}
	Pathshow(path);
} 

//输出最短路径
template<class T>
void  Graphmtx<T>::Pathshow(int* path){
	ofstream out("Graph.txt",ios::app);
	int t;
	for(int i=0;i<nowVetices;i++){
		cout<<Vetices[i]<<"  ";
		t=path[i];
		while(t!=-1){
			cout<<Vetices[t]<<"  ";
			out<<Vetices[t]<<"  ";
			t=path[t];
		}
		cout<<endl;
		out<<endl;
	}
	out.close();
}
