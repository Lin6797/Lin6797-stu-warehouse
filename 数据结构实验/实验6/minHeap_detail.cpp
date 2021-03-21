//��С�ѵľ���ʵ��
#include "minHeap_class.h" 
#include <iostream>
using namespace std;

minHeap::minHeap(int n){ //���캯�� 
	Num=0; Capacity=n; //��ʼ�� 
	tHeap=new TreeNode*[n]; //���ٿռ� 
	eHeap=new int[n];
}

bool minHeap::IsEmpty(){//�ж϶��Ƿ�Ϊ�� 
	if(Num==0) return true;
	else return false;
}

bool minHeap::IsFull(){//�ж϶��Ƿ�Ϊ�� 
	if(Num==Capacity) return true;
	else return false;
}

bool minHeap::SiftUp(int start){//�ϻ������ѣ�Ĭ��start=Num-1�� 
	int j=start, i=(j-1)/2; //jΪ��ʼ�㣬iΪ��ʼ��ĸ�ĸ��
	TreeNode* ttemp=tHeap[start]; int etemp=eHeap[start]; //�������͵��м��� 
	while(j>0){
		if(eHeap[i]<=etemp) break; //�ӽڵ��Ȩֵ�ȸ�ĸ�ڵ�Ĵ�(�������) 
		else{ //�ӽڵ��Ȩֵ�ȸ�ĸ�ڵ��С
			eHeap[j]=eHeap[i]; tHeap[j]=tHeap[i];
			j=i; i=(j-1)/2;
		}
	}
	eHeap[j]=etemp; tHeap[j]=ttemp;
	return true;
}

bool minHeap::SiftDown(int start, int end){//�»������ѣ�Ĭ��start=0,end=Num-1�� 
	int i=start, j=(2*i)+1; //iΪ���,jΪ������½ǵĽ�� 
	TreeNode* ttemp=tHeap[i]; int etemp=eHeap[i]; //�������͵���ʼ�� 
	while(j<=end){
		if ( j<end && eHeap[j]>eHeap[j+1] ) j++; //ѡ���С����Ů���
		
		if(eHeap[j]>=etemp) break; //��ĸ����Ȩֵ����Ů���ȨֵС
		else{ //��ĸ���Ȩֵ����Ů���Ȩֵ�� 
			tHeap[i]=tHeap[j]; eHeap[i]=eHeap[j];
			i=j; j=2*i+1;
		}
	}
	eHeap[i]=etemp; tHeap[i]=ttemp;
	return true;
}

bool minHeap::Insert(TreeNode* t_data, int e_data){ //���� 
	if(IsFull()){
		cout<<"�����������ɲ���"<<endl;
		return false;
	}
	Num++;
	tHeap[Num-1]=t_data;
	eHeap[Num-1]=e_data;
	SiftUp(Num-1);
	return true;
}

bool minHeap::Build(TreeNode* t_data, int e_data){ //���� 
	Insert(t_data, e_data);
	return false;
}

TreeNode* minHeap::Delete(){//ɾ�������� 
	if(IsEmpty()){
		cout<<"��Ϊ��,���ɽ���ɾ��"<<endl;
	}
	else{
		TreeNode* ttemp=tHeap[0]; int etemp=eHeap[0];
	    tHeap[0]=tHeap[Num-1];
	    eHeap[0]=eHeap[Num-1];
	    Num--;
	    SiftDown(0,Num-1);
	    return ttemp;
	}
}

TreeNode* minHeap::Out(){
	TreeNode* temp=Delete();
	return temp;
}

TreeNode* minHeap::Get(){
	return tHeap[0];
}
