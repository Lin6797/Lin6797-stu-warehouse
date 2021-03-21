//ʵ����
#include<iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

//���ȶ��������
int board[100][100];
int xstart,ystart; //��� 

//��x,y��ʾλ�� 
//���������շ����а��ֿ����ߵķ�ʽ 
int fx[]= {2,1,-1,-2,-2,-1,1,2};
int fy[]= {-1,-2,-2,-1,1,2,2,1};

bool check(int n, int x, int y);
void outputResult(int n);
void runTable(int n,int a,int b,int number);
void horseRun(int n,int x,int y);
bool returnStart(int n,int x,int y);

int main(){
	int n; //���̴�С
    cout<<"�������̴�Сn(С��100):"; cin>>n;
    int x,y;
    cout<<"������������ʼλ��x(0-"<<n-1<<"):";cin>>x;
    cout<<"������������ʼλ��y(0-"<<n-1<<"):";cin>>y;
    xstart=x;  ystart=y; 
	horseRun(n,x,y);
    return 0;
}

//���(x,y)λ�����������Ƿ�Ϸ�
//�Ƿ��������ڲ������Ƿ��Լ����߹� 
bool check(int n, int x, int y){
    if(x<0 || y<0 || x>=n || y>=n || board[x][y]!=0)
        return false;
    return true;
}

//��������
void outputResult(int n){
	cout<<"�õ������������ţ�"; 
    for(int i=0; i<n; i++){
        cout<<endl<<endl;
        for(int j=0; j<n; j++){
            cout<<setw(3)<<board[i][j]<<" ";
        }
    }
    cout<<endl<<endl;
}

//�Ƿ��ܹ��ص���� 
bool returnStart(int n,int x,int y){
	for(int i=0;i<8;i++)
		if(check(n,x+fx[i],y+fy[i]))
			if(x+fx[i]==xstart && y+fy[i]==ystart)
			       return true;
	
	return false;
} 

//������
void runTable(int n,int a,int b,int number){
//	//�Ѿ��������������еĵ㲢�Ҹõ���Իص���ʼ�� 
//    if(number==n*n && returnStart(n,a,b)){ 
//        outputResult(n); //���
//        exit(1); //�˳����� 
//    }

	//�Ѿ��������������еĵ� 
    if(number==n*n){ 
        outputResult(n); //���
        exit(1); //�˳����� 
    }

    for(int i=0; i<8; i++){ //���Ը����߷� 
        if(check(n, a+fx[i], b+fy[i])){//���������߷��Ƿ�������� 
            int x=a+fx[i];
            int y=b+fy[i];
            board[x][y]=number+1; //�ߵ���һ��λ�ã����������Ϊnumber+1������¼ 
            runTable(n,x, y,number+1);
            board[x][y]=0;//����
        }
    }
}

//�ݹ�
void horseRun(int n,int x,int y){
    int number=1; 
    board[x][y]=number; //����ȷ����ʼλ������������Ϊ1
    runTable(n, x, y,number);
    
}
