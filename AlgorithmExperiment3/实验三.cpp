//实验三
#include<iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

//事先定义的棋盘
int board[100][100];
int xstart,ystart; //起点 

//用x,y表示位置 
//按照马跳日法共有八种可能走的方式 
int fx[]= {2,1,-1,-2,-2,-1,1,2};
int fy[]= {-1,-2,-2,-1,1,2,2,1};

bool check(int n, int x, int y);
void outputResult(int n);
void runTable(int n,int a,int b,int number);
void horseRun(int n,int x,int y);
bool returnStart(int n,int x,int y);

int main(){
	int n; //棋盘大小
    cout<<"输入棋盘大小n(小于100):"; cin>>n;
    int x,y;
    cout<<"输入马周游起始位置x(0-"<<n-1<<"):";cin>>x;
    cout<<"输入马周游起始位置y(0-"<<n-1<<"):";cin>>y;
    xstart=x;  ystart=y; 
	horseRun(n,x,y);
    return 0;
}

//检测(x,y)位置在棋盘中是否合法
//是否在棋盘内部或者是否以及被走过 
bool check(int n, int x, int y){
    if(x<0 || y<0 || x>=n || y>=n || board[x][y]!=0)
        return false;
    return true;
}

//输出最后结果
void outputResult(int n){
	cout<<"得到各格遍历的序号："; 
    for(int i=0; i<n; i++){
        cout<<endl<<endl;
        for(int j=0; j<n; j++){
            cout<<setw(3)<<board[i][j]<<" ";
        }
    }
    cout<<endl<<endl;
}

//是否能够回到起点 
bool returnStart(int n,int x,int y){
	for(int i=0;i<8;i++)
		if(check(n,x+fx[i],y+fy[i]))
			if(x+fx[i]==xstart && y+fy[i]==ystart)
			       return true;
	
	return false;
} 

//试着走
void runTable(int n,int a,int b,int number){
//	//已经走完棋盘中所有的点并且该点可以回到起始点 
//    if(number==n*n && returnStart(n,a,b)){ 
//        outputResult(n); //输出
//        exit(1); //退出程序 
//    }

	//已经走完棋盘中所有的点 
    if(number==n*n){ 
        outputResult(n); //输出
        exit(1); //退出程序 
    }

    for(int i=0; i<8; i++){ //尝试各种走法 
        if(check(n, a+fx[i], b+fy[i])){//测试这种走法是否符合条件 
            int x=a+fx[i];
            int y=b+fy[i];
            board[x][y]=number+1; //走到下一个位置，设置其序号为number+1用来记录 
            runTable(n,x, y,number+1);
            board[x][y]=0;//回溯
        }
    }
}

//递归
void horseRun(int n,int x,int y){
    int number=1; 
    board[x][y]=number; //首先确定起始位置这个格是序号为1
    runTable(n, x, y,number);
    
}
