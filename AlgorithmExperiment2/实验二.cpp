//ʵ���

#include<iostream> 
#include<string.h>  
#include<stdlib.h>  
#include<time.h>  
#include<iomanip>  
using namespace std; 

#define N 30//�豸����  
#define M 10//��������  
#define T 10//ʵ������,��ĿҪ��10��

int main(){  
    int c[N+1][M+1];
	int V[M+1][N+1],D[M+1][N+1];   
	int t=T;
	char Judge; 

    srand((unsigned int)time(0));
    while(t--){  
		//��ʼ������
		memset(c,0,sizeof(c)); 
	    memset(V,0,sizeof(V));   
        memset(D,0,sizeof(D)); 

        //������������ʼ��    
        
        cout<<"�Ƿ��ֶ����룿(y/n):";cin>>Judge;
        cout<<"��"<<T-t<<"��ʵ��:"<<endl;
		if(Judge=='y' or Judge=='Y'){
			for(int i=0;i<=N;i++){  
                cout<<i<<setw(4);  
                for(int j=0;j<=M;j++){
			        if(i!=0&&j!=0) 
					    c[i][j]=rand()%1000; 
			        
					cout<<setw(4)<<c[i][j];  
		        }  
		        cout<<endl;  
            }
		}
		else{  
            cout<<"į���������j�ų���ɻ�õ�����"<<endl;  
            for(int i=0;i<=M;i++){  
                cout<<setw(4)<<i;
		    }  
            cout<<endl;
			for(int i=0;i<=N;i++){  
                cout<<i<<setw(4);  
                for(int j=0;j<=M;j++){
			        if(i!=0&&j!=0) 
					    c[i][j]=rand()%1000; 
			        
					cout<<setw(4)<<c[i][j];  
		        }  
		        cout<<endl;  
            } 
		} 

        //����˳�����ÿ���ӵ�j�ų�����ǰj-1��������������豸��D[i][j]�����į�豸���䵽j�ų�����������V[i][j];  
        for(int i=1;i<=M;i++){  
		    for(int j=1;j<=N;j++){  
			    for(int k=0;k<=j;k++){  
				    if(V[i][j]<V[i-1][j-k]+c[k][i]){    
					    V[i][j]=V[i-1][j-k]+c[k][i]; 
					    D[i][j]=k;  
                    } 
                }  
            }  
        } 
        
		cout<<"�������Ϊ��"<<V[M][N]<<endl;  
        //�����һ�����������豸����(N-D[i][j])���Ƶ���һ�ų��������豸������ 

	    int k=N;
        for(int i=M;i>0;i--){
		    cout<<"��"<<i<<"�ų������Ļ�������Ϊ"<<D[i][k]<<",����Ϊ"<<c[D[i][k]][i]<<endl;
		    k=k-D[i][k];
	    }

    }
    return 0;  
} 
