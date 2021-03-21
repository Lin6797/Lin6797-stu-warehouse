//ʵ����

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <queue>
using namespace std;

//�����տ���ִ�е��߷� 
typedef struct{
    int x; int y;
} Step;

//һ�������߷� 
Step step[8]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};

//���߷���������ѡ�� 
struct NextPos{
    int nextPosSteps; //��ʾ��һλ���ж������߷����߷��ٵ����ȿ���
    int nextPosDirection; //��һλ������ڵ�ǰλ�õķ�λ
    int nextPosToMidLength; //��ʾ��ǰλ�þ��м����룻�����м��Զ�����ȿ���
    //�ض��� 
	bool operator < (const NextPos &a) const
    { return nextPosSteps > a.nextPosSteps && nextPosToMidLength < a.nextPosToMidLength;}
}; 

//�������� 
int board[100][100];
int N; //���̴�С

bool check(int x, int y); //����Ƿ���������(�������ڻ����Ѿ������) 
int nextStepsNum(int x, int y); //��һ�����ж������߷� 
int posToMidLength(int x,int y);
int posToMidLength(int x,int y); 
bool returnStart(int x, int y);
void outputResult(int xstart,int ystart);
void BackTrace(int t, int x, int y,int xstart,int ystart);
void horseRun(int xstart,int ystart);

int main(){
    //��������ʼλ��
    int x, y;
    cout<<"���������̴�С:";cin>>N;
    cout<<"��������������ʼλ��x(0-"<<N-1<<"):"; cin>>x;
	cout<<"��������������ʼλ��y(0-"<<N-1<<"):"; cin>>y;

    horseRun(x,y); //ִ��������
    return 0;
}

//������λ���Ƿ������
bool check(int x, int y){
    if (x<0 || x>=N || y<0 || y>=N || board[x][y]!=0)
        return false;
    return true;
}

//��һλ���ж������߷�
int nextStepsNum(int x, int y){
    int steps=0;
    for (int i=0; i<8; i++){
    	//�ж��Ƿ�������� 
        if (check(x+step[i].x, y+step[i].y))
            steps++;
    }
    return steps;
}

//ĳһλ�þ����������ĵľ���
int posToMidLength(int x,int y){
    int midx=N/2-1;
    int midy=N/2-1;
    return (abs(x-midx) + abs(y-midy));
}

//�ж��Ƿ�ص����
bool returnStart(int x, int y){
    //У������Ƿ���Իص���㣬Ҳ�������̵��м�λ��
    int midx,midy;
    //��0Ϊ��ʼ 
	midx=N/2-1; midy=N/2-1;
	
    //�����߷������ԣ�ֻҪ�ܻ����
    for (int i=0; i<8; i++) 
        if (x+step[i].x==midx && y+step[i].y==midy)
            return true;
    return false;
}

//������
void outputResult(int xstart,int ystart){
    int num=N*N;
    int k=num-board[xstart][ystart];
    for (int i=0; i<N; i++){
        cout<<endl<<endl;
        for (int j=0; j<N; j++){
            board[i][j]=(board[i][j]+k)%num+1;
            cout<<setw(5)<<board[i][j];
        }
    }
    cout<<endl<<endl;
}

void BackTrace(int t, int x, int y,int xstart,int ystart){
    //�ҵ����,�����������̵�����λ�ã����������Իص���㣬�γɻ�· 
    if (t==N*N && returnStart(x,y)) {
        outputResult(xstart,ystart);
        exit(1); //�������� 
    }
    
    //������ 
    //����һ���ӽ����� 
    priority_queue<NextPos> nextPosQueue;
	for (int i=0; i<8; i++){
		//�������������� 
        if (check(x+step[i].x, y+step[i].y)){
            NextPos aNextPos;
            aNextPos.nextPosSteps=nextStepsNum(x+step[i].x, y+step[i].y);
            aNextPos.nextPosDirection=i;
            aNextPos.nextPosToMidLength=posToMidLength(x+step[i].x, y+step[i].y);
            nextPosQueue.push(aNextPos);
        }
    }
    
    //���ն��е���������һ��Ѱ�� 
    while(nextPosQueue.size()){
        int d=nextPosQueue.top().nextPosDirection;
        nextPosQueue.pop();
        x += step[d].x; y += step[d].y;
        
        board[x][y]=t+1;
        BackTrace(t+1, x, y,xstart,ystart);
            
		//����
        board[x][y]=0;
        x -= step[d].x; y -= step[d].y;
    }
}

//��ʼ�� 
void horseRun(int xstart,int ystart){
    //��ʼ������
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            board[i][j]=0;

    int midx=N/2-1;
    int midy=N/2-1;
    board[midx][midy]=1; //�����̵��м��λ�ÿ�ʼ������
    BackTrace(1, midx, midy,xstart,ystart);
}
