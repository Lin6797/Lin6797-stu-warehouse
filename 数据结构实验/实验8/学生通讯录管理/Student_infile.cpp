//���ļ��ж���ѧ�����ݺ�Ҫ���еĲ��� 
#include"Student_class.h"
#include<sstream>
#include<vector>
 
string** BST::Apart(){
	ifstream in("Student.txt",ios::in);
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
		purpose[i]=new string[6]; 
	}
	//����ѧ�š��������������ڡ��Ա𡢵绰���롢��ַ
	
	vector<string>::iterator it=Messages.begin();
	for(; it!=Messages.end(); it++){
		string judge="number";
		int start=0;//�и���ʼλ�� 
		for(int i=0; i<(*it).length(); i++){
			if((*it)[i]==' ' && judge=="number"){
				purpose[No][0]=(*it).substr(start,i-start);
				i=i+1; start=i;
				judge="name"; 
			}
			if((*it)[i]==' ' && judge=="name"){
				purpose[No][1]=(*it).substr(start,i-start);
				i=i+1; start=i;
				judge="birth"; 
			}
			if((*it)[i]==' ' && judge=="birth"){
				purpose[No][2]=(*it).substr(start,i-start);
				i=i+1; start=i;
				judge="sex"; 
			}
			if((*it)[i]==' ' && judge=="sex"){
				purpose[No][3]=(*it).substr(start,i-start);
				i=i+1; start=i;
				judge="phone"; 
			}
			if((*it)[i]==' ' && judge=="phone"){
				purpose[No][4]=(*it).substr(start,i-start);
				i=i+1; start=i;
				judge="adver"; 
			}
			if((*it)[i]==' ' && judge=="adver"){
				purpose[No][5]=(*it).substr(start,i-start);
				break;
			}
		}
		No++; 
	}
	return purpose;
}

bool BST::Infile(){//���ļ��������� 
	string** purpose=Apart();
	cout<<purpose[0][0]<<endl;
	//���ؼ��� 
	int* key=new int[content];
	for(int i=0;i<content;i++){
		int Num; stringstream ss(purpose[i][0]);
	    ss>>Num;
	    key[i]=Num;
	}
	
	//������
	Data** data=new Data*[content];
	for(int i=0;i<content;i++){
		data[i]=new Data[1];
	}
	for(int i=0;i<content;i++){
		data[i]->name=purpose[i][1];
		data[i]->birthday=purpose[i][2];
		data[i]->sex=purpose[i][3][0];
		data[i]->phone=purpose[i][4];
		data[i]->adver=purpose[i][5];
	}
	delete[] root;
	Build(content,key,data);
}
