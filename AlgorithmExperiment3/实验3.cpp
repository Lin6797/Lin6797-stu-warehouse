//实验三

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <queue>
using namespace std;

//马跳日可以执行的走法 
typedef struct{
    int x; int y;
} Step;

//一共八种走法 
Step step[8]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};

//对走法进行排序选择 
struct NextPos{
    int nextPosSteps; //表示下一位置有多少种走法；走法少的优先考虑
    int nextPosDirection; //下一位置相对于当前位置的方位
    int nextPosToMidLength; //表示当前位置距中间点距离；距离中间点远的优先考虑
    //重定义 
	bool operator < (const NextPos &a) const
    { return nextPosSteps > a.nextPosSteps && nextPosToMidLength < a.nextPosToMidLength;}
}; 

//定义棋盘 
int board[100][100];
int N; //棋盘大小

bool check(int x, int y); //检查是否满足条件(在棋盘内或者已经被标记) 
int nextStepsNum(int x, int y); //下一步能有多少种走法 
int posToMidLength(int x,int y);
int posToMidLength(int x,int y); 
bool returnStart(int x, int y);
void outputResult(int xstart,int ystart);
void BackTrace(int t, int x, int y,int xstart,int ystart);
void horseRun(int xstart,int ystart);

int main(){
    //马周游起始位置
    int x, y;
    cout<<"请输入棋盘大小:";cin>>N;
    cout<<"请输入马周游起始位置x(0-"<<N-1<<"):"; cin>>x;
	cout<<"请输入马周游起始位置y(0-"<<N-1<<"):"; cin>>y;

    horseRun(x,y); //执行马周游
    return 0;
}

//检测这个位置是否可以走
bool check(int x, int y){
    if (x<0 || x>=N || y<0 || y>=N || board[x][y]!=0)
        return false;
    return true;
}

//下一位置有多少种走法
int nextStepsNum(int x, int y){
    int steps=0;
    for (int i=0; i<8; i++){
    	//判断是否符合条件 
        if (check(x+step[i].x, y+step[i].y))
            steps++;
    }
    return steps;
}

//某一位置距离棋盘中心的距离
int posToMidLength(int x,int y){
    int midx=N/2-1;
    int midy=N/2-1;
    return (abs(x-midx) + abs(y-midy));
}

//判断是否回到起点
bool returnStart(int x, int y){
    //校验最后是否可以回到起点，也就是棋盘的中间位置
    int midx,midy;
    //以0为起始 
	midx=N/2-1; midy=N/2-1;
	
    //八种走法都可以，只要能回起点
    for (int i=0; i<8; i++) 
        if (x+step[i].x==midx && y+step[i].y==midy)
            return true;
    return false;
}

//输出结果
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
    //找到结果,即遍历了棋盘的所以位置，并且最后可以回到起点，形成回路 
    if (t==N*N && returnStart(x,y)) {
        outputResult(xstart,ystart);
        exit(1); //结束程序 
    }
    
    //往后走 
    //将下一步加进队列 
    priority_queue<NextPos> nextPosQueue;
	for (int i=0; i<8; i++){
		//这是满足条件的 
        if (check(x+step[i].x, y+step[i].y)){
            NextPos aNextPos;
            aNextPos.nextPosSteps=nextStepsNum(x+step[i].x, y+step[i].y);
            aNextPos.nextPosDirection=i;
            aNextPos.nextPosToMidLength=posToMidLength(x+step[i].x, y+step[i].y);
            nextPosQueue.push(aNextPos);
        }
    }
    
    //按照队列迭代进行下一步寻找 
    while(nextPosQueue.size()){
        int d=nextPosQueue.top().nextPosDirection;
        nextPosQueue.pop();
        x += step[d].x; y += step[d].y;
        
        board[x][y]=t+1;
        BackTrace(t+1, x, y,xstart,ystart);
            
		//回溯
        board[x][y]=0;
        x -= step[d].x; y -= step[d].y;
    }
}

//开始走 
void horseRun(int xstart,int ystart){
    //初始化棋盘
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            board[i][j]=0;

    int midx=N/2-1;
    int midy=N/2-1;
    board[midx][midy]=1; //从棋盘的中间的位置开始马周游
    BackTrace(1, midx, midy,xstart,ystart);
}
