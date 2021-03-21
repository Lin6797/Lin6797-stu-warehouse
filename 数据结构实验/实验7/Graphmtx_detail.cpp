//Graphmtx_detail
#include "Graphmtx_class.h" 
#include"minHeap_detail.cpp"

//���캯�� 
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
	for(int i=0; i<maxVetices; i++){//��ʼ�� 
		for(int t=0; t<maxVetices; t++){
			if(t!=i) Edges[i][t]=Max;
			else Edges[i][t]=0;
		}
	}
}

//����
template<class T>
bool Graphmtx<T>::IsFull(){ 
	if(nowVetices==maxVetices || nowEdges==(nowVetices-1)*nowVetices) return true;//�����ͱ��� 
	else return false;
}

//�п� 
template<class T>
bool Graphmtx<T>::IsEmpty(){ 
	if(nowEdges==0) return true;
	else return false; 
}

//���������б�
template<class T>
bool Graphmtx<T>::Build(int num, T* content){
	if(num>maxVetices || num<=0) return false;
	
	nowVetices=num;
	for(int i=0;i<num;i++){
		Vetices[i]=content[i];
	}
	return true; 
}

//�����������
template<class T>
bool Graphmtx<T>::Link(int v1,int v2, int weight){
	AddEdge(v1,v2,weight);
	nowEdges++; 
}

//�������Ϊcontent�ĵ�
template<class T>
bool Graphmtx<T>::AddVetice(T content){
	if(IsFull()) return false;
	
	Vetices[nowVetices]=content;
	nowVetices++;
}

//ɾ�����Ϊcode�ĵ�
template<class T>
bool Graphmtx<T>::DelVetice(int code){
	if(code>=nowVetices) return false;//��Ŵ�0��ʼ 
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

//���v1��v2��ȨֵΪweight�ı�
template<class T>
bool Graphmtx<T>::AddEdge(int v1, int v2, int weight){
	if(v1<0 || v1>=nowVetices) return false;
	if(v2<0 || v2>=nowVetices) return false;
	if(weight<0) return false;
	
	Edges[v1][v2]=weight;
	nowEdges++;
	return true;
}

//ɾ��v1��v2�ı�
template<class T>
bool Graphmtx<T>::DelEdge(int v1, int v2){
	if(v1<0 || v1>=nowVetices) return false;
	if(v2<0 || v2>=nowVetices) return false;
	
	nowEdges--;
	Edges[v1][v2]=0;
	return true;
}

//��õ�v�ĵ�һ���ڽӵ�
template<class T>
int Graphmtx<T>::getFirst(int v){
	if(v>=nowVetices || v<0) return 0;
	
	for(int i=0;i<nowVetices;i++){
		if(Edges[v][i]!=0) return i;
	}
	return -1;//���õ�������-1 
}

//��õ�v1���ڽӵ�v2����һ���ڽӵ� 
template<class T>
int Graphmtx<T>::getNext(int v1, int v2){
	if(v1>=nowVetices || v1<0) return -1;
	if(v2>=nowVetices || v2<0) return -1;
	
	for(int i=v2+1; i<nowVetices; i++){
		if(Edges[v1][i]!=0) return i;
	}
	return -1;
}

//��õ�v1��v2�ıߵ�Ȩֵ
template<class T>
int Graphmtx<T>::getWeight(int v1, int v2){
	if(v1>=nowVetices || v1<0) return -1;
	if(v2>=nowVetices || v2<0) return -1;
	if(v1==v2) return 0;
	
	return Edges[v1][v2];
}

//��ʾ 
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
			if(Edges[i][t]==Max) cout<<"��"<<" ";
			else cout<<Edges[i][t]<<" ";
		}
		cout<<endl;
	}
	return true;
}

//��ȱ������ 
template<class T>
void Graphmtx<T>::DFS(int start){//��� 
	bool* visited=new bool[maxVetices];
	for(int i=0;i<maxVetices;i++){
		visited[i]=false;//��ʼ�� 
	}
	DFS(start,visited);
	delete visited;
}

//��ȱ��� 
template<class T>
void Graphmtx<T>::DFS(int now, bool* visited){
	ofstream out("Graph.txt",ios::app);
	
	out<<Vetices[now]<<"  ";
	cout<<Vetices[now]<<"  ";
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
void Graphmtx<T>::WFS(int start){
	ofstream out("Graph.txt",ios::app);
	Queue<int> Q(nowVetices+1); int now,next;
	bool* visited=new bool[nowVetices];
	
	for(int i=0;i<nowVetices;i++){//��ʼ�� 
		visited[i]=false;
	}
	
	Q.EnQueue(start);//���
	 
	while(Q.IsEmpty()==false){
		now=Q.OutQueue();
		out<<Vetices<<"  ";
		cout<<Vetices[now]<<"  ";
		visited[now]=true;//��־
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
	MTEdge* Edge=new MTEdge[nowVetices-1];//�ñ������ʾ��
	int max=nowVetices-1,now=0;//��֦��������͵�ǰ��
	
	MTEdge ed;//��С�������߽���ඨ��
	int n,m,v,u,count; 
	n=nowVetices; m=nowEdges/2;
	u=0;//�������Ϊ0���
	minHeap<MTEdge> H(m);//��С��
	bool* Vmst=new bool[nowVetices];
	for(int i=0; i<nowVetices;i++){//��ʼ�� 
		Vmst[i]=false;
	}
	
	Vmst[u]=true; count=1;//��������һ��u 
	
	do{
		v=getFirst(u);//�õ�int 
		while(v!=-1){//��ʼ�㲻�ǹ����� 
			if(Vmst[v]!=true){//v��δ����ȡ 
				ed.head=v; ed.tail=u;
				ed.weight=getWeight(v,u);
				H.Build(ed,ed.weight);//��� 
			}
			v=getNext(u,v);
		}//��v��Χ��ȫ����� 
		
		while(H.IsEmpty()==false && count<n){
			ed=H.Out();//�˶�
			if(Vmst[ed.head]==false){
				Edge[now]=ed; now++;
				u=ed.head; Vmst[u]=true;
				count++; break;
			}
		}
	}while(count<n);
	Treeshow(Edge);
}

//��С������ 
template<class T>
void Graphmtx<T>::Kruskal(){
	
	MTEdge* Edge=new MTEdge[nowVetices-1];//�ñ������ʾ��
	int max=nowVetices-1,now=0;//��֦��������͵�ǰ��
	
	MTEdge ed;//��С�������߽���ඨ��
	int n,m,v,u,count; 
	n=nowVetices; m=nowEdges/2;
	u=0;//�������Ϊ0���
	minHeap<MTEdge> H(m);//��С��
	bool* Vmst=new bool[nowVetices];
	for(int i=0; i<nowVetices;i++){//��ʼ�� 
		Vmst[i]=false;
	}
	
	Vmst[u]=true; count=1;//��������һ��u 
	
	do{
		v=getFirst(u);//�õ�int 
		while(v!=-1){//��ʼ�㲻�ǹ����� 
			if(Vmst[v]!=true){//v��δ����ȡ 
				ed.head=v; ed.tail=u;
				ed.weight=getWeight(v,u);
				H.Build(ed,ed.weight);//��� 
			}
			v=getNext(u,v);
		}//��v��Χ��ȫ����� 
		
		while(H.IsEmpty()==false && count<n){
			ed=H.Out();//�˶�
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

//��ʾ��С������ 
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

//�����·�� 
template<class T>
void Graphmtx<T>::Dijstrate(int start){
	int u;
	bool* S=new bool[nowVetices];//�жϸõ��Ƿ��Ѿ������˼�����
	int* dist=new int[nowVetices];//��ʼ��Strat���õ��·������
	int* path=new int[nowVetices];//��ʼ��Start���õ��·�� 
	for(int i=0; i<nowVetices; i++){//��ʼ�� 
		S[i]=false; dist[i]=getWeight(start,i);
		if(i!=start && dist[i]<Max) path[i]=start;//���
		else path[i]=-1;
	}
	
	S[start]=true; dist[start]=0;//��ʼ���뼯��  
	for(int i=0; i<nowVetices-1; i++){
		int minWeight=Max;
		int u=start;//��ʼ�� 
		for(int j=0;j<nowVetices;j++){//�ҵ���С·��ֵ 
			if(S[j]==false && dist[j]<minWeight){
			    u=j; minWeight=dist[j];
			}
	    }
		S[u]=true;
		for(int k=0; k<nowVetices; k++){//�޸� 
			int w=getWeight(u,k);
			if(S[k]==false && w<Max && dist[u]+w<dist[k]){
				dist[k]=dist[u]+w; path[k]=u;
			}
		}
	}
	Pathshow(path);
} 

//������·��
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
