//�ļ���ȡ���� 
#include"BST_class.h"
#include<sstream>
#include<vector>
 
string** BST::Apart(){
	ifstream in("BST.txt",ios::in);
	if(!in) return NULL;
	
	string** purpose;//Ŀ�귵������ 
	string str, judge;//�м��־���жϱ�־ 
	int start;//��ʼ�� 
	content=0;//�ļ��ڲ��������� 
	int No=0;
	
	vector<string> Messages;//���� 
	while(getline(in,str)){
		content++; Messages.push_back(str);//������ 
	}
	
	//��������ռ�
	purpose=new string*[content]; 
	for(int i=0;i<content;i++){
		purpose[i]=new string[2]; 
	}
	//�����ؼ��롢���� 
	
	vector<string>::iterator it=Messages.begin();
	for(; it!=Messages.end(); it++){
		string judge="key";
		int start=0;//�и���ʼλ�� 
		for(int i=0; i<(*it).length(); i++){
			if((*it)[i]==' ' && judge=="key"){
				purpose[No][0]=(*it).substr(start,i-start);
				i=i+1; start=i;
				judge="content"; 
			}
			if((*it)[i]==' ' && judge=="content"){
				purpose[No][1]=(*it).substr(start,i-start);
				break;
			}
		}
		No++; 
	}
	return purpose;
}

bool BST::Infile(){//���ļ��������� 
	string** purpose=Apart();
	//���ؼ��� 
	int* key=new int[content];
	for(int i=0;i<content;i++){
		int Num; stringstream ss(purpose[i][0]);
	    ss>>Num;
	    key[i]=Num;
	}
	
	//������
	char* data=new char[content];
	for(int i=0;i<content;i++){
		data[i]=purpose[i][1][0];
	}
	delete[] root;
	Build(content,key,data);
} 
