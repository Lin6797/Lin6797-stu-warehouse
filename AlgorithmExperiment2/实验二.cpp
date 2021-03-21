//实验二

#include<iostream> 
#include<string.h>  
#include<stdlib.h>  
#include<time.h>  
#include<iomanip>  
using namespace std; 

#define N 30//设备数量  
#define M 10//车间数量  
#define T 10//实例个数,题目要求10个

int main(){  
    int c[N+1][M+1];
	int V[M+1][N+1],D[M+1][N+1];   
	int t=T;
	char Judge; 

    srand((unsigned int)time(0));
    while(t--){  
		//初始化数组
		memset(c,0,sizeof(c)); 
	    memset(V,0,sizeof(V));   
        memset(D,0,sizeof(D)); 

        //声明变量并初始化    
        
        cout<<"是否手动输入？(y/n):";cin>>Judge;
        cout<<"第"<<T-t<<"个实例:"<<endl;
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
            cout<<"i台机器分配给j号车间可获得的利润："<<endl;  
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

        //代码顺推算出每增加第j号车间其前j-1个车间所分配的设备数D[i][j]并算出i台设备分配到j号车间的最大利润V[i][j];  
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
        
		cout<<"最大利润为："<<V[M][N]<<endl;  
        //从最后一个车间分配的设备数量(N-D[i][j])逆推到第一号车间分配的设备数量。 

	    int k=N;
        for(int i=M;i>0;i--){
		    cout<<"第"<<i<<"号车间分配的机器数量为"<<D[i][k]<<",利润为"<<c[D[i][k]][i]<<endl;
		    k=k-D[i][k];
	    }

    }
    return 0;  
} 
