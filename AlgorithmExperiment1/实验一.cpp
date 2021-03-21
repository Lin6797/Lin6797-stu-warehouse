//实验一
#include<time.h> 
#include<stdio.h>
#include<stdlib.h> 
#include<iostream>
using namespace std;

int Split(int a[],int low,int high);
void QuickSort(int a[],int low,int high);
void mergeSort(int a[],int low,int high,int c[]);


int main() {
    int random=5000,j=1; char Judge;
    int*merge_array,*quick_array,*c;
    clock_t start,end,start1,end1;

    while(j<=20) {
    	merge_array=new int[random*j];
        quick_array=new int[random*j];
        c=new int [random*j];
    	
		cout<<"是否手动输入(y/n):";cin>>Judge;
		if(Judge=='Y' or Judge=='y'){
           for(int i=0;i<random*j;i++) {
                cin>>merge_array[i]; 
                quick_array[i]=merge_array[i];
            }
		}
		else{
            for(int i=0;i<random*j;i++) {
                merge_array[i]=rand(); 
                quick_array[i]=merge_array[i];
            }
		}

        start=clock(); mergeSort(merge_array,0,random*j-1,c); end=clock();
        delete []merge_array;

		start1=clock(); QuickSort(quick_array,0,random*j-1); end1=clock();
        delete []quick_array;

        delete []c;
        
        cout<<"随机数数量\t归并排序时间\t快速排序算法时间"<<endl;
        cout<<random*j<<"\t\t"<<static_cast<double>(end-start)/CLOCKS_PER_SEC*1000<<"ms\t\t";
        cout<<static_cast<double>(end1-start1)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
        j++;
    }
    return 0;
}

//划分 
int Split(int a[],int low,int high) {
    int i=low,temp;
    
    //选择三个数的中位数 
     if(a[low]< a[(low+high)/2]) {
        if(a[low]<a[high]) {
            if(a[(low+high)/2]<a[high]) {
                temp= a[(low+high)/2];
                a[(low+high)/2]=a[low];
                a[low]=temp;
            }
            else {
                temp=a[high];
                a[high]=a[low];
                a[low]=temp;
            }
        }
    }
    else {
        if(a[(low+high)/2]<a[high]) {
            if(a[low]>a[high]) {
                temp=a[high];
                a[high]=a[low];
                a[low]=temp;
            }
        }
        else {
            temp=a[(low+high)/2];
            a[(low+high)/2]=a[low];
            a[low]=temp;
        }
    }
    
    //开始进行调整 
    for(int j=low+1;j<=high;j++) {
        if(a[j]<a[low]) {
            i++;
            if(i!=j){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    temp=a[i];
    a[i]=a[low];
    a[low]=temp;
    return i;
}

//快排 
void QuickSort(int a[],int low,int high) {
    if(low<high){
        int w=Split(a,low,high);
        //划分 
		QuickSort(a,low,w-1);
        QuickSort(a,w+1,high);
    }
}

//分 
void merge(int a[],int first,int mid,int end,int c[]) {
    int pbotton=first;
    int f=first,m=mid;
    while(f<mid && m<=end)
        if(a[f]<a[m]) c[pbotton++]=a[f++];
        else c[pbotton++]=a[m++];
    
	if(f==mid)
        while(m<=end)
		    c[pbotton++]=a[m++];
    else
        while(f<mid)
            c[pbotton++]=a[f++];

    for(int i=first;i<=end;i++)
        a[i]=c[i];
}

//归并排序 
void mergeSort(int a[],int low,int high,int c[]) {
    if(low<high) {
        mergeSort(a,low,(low+high)/2,c);
        mergeSort(a,(low+high)/2+1,high,c);
        merge(a,low,(low+high)/2+1,high,c);
    }
}
