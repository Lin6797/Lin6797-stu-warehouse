//文件读取处理 
#include"BST_class.h"
#include<sstream>
#include<vector>
 
string** BST::Apart(){
	ifstream in("BST.txt",ios::in);
	if(!in) return NULL;
	
	string** purpose;//目标返回数组 
	string str, judge;//中间标志，判断标志 
	int start;//起始点 
	content=0;//文件内部数据数量 
	int No=0;
	
	vector<string> Messages;//容器 
	while(getline(in,str)){
		content++; Messages.push_back(str);//入容器 
	}
	
	//开辟数组空间
	purpose=new string*[content]; 
	for(int i=0;i<content;i++){
		purpose[i]=new string[2]; 
	}
	//包括关键码、内容 
	
	vector<string>::iterator it=Messages.begin();
	for(; it!=Messages.end(); it++){
		string judge="key";
		int start=0;//切割起始位置 
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

bool BST::Infile(){//从文件读出数据 
	string** purpose=Apart();
	//读关键字 
	int* key=new int[content];
	for(int i=0;i<content;i++){
		int Num; stringstream ss(purpose[i][0]);
	    ss>>Num;
	    key[i]=Num;
	}
	
	//读内容
	char* data=new char[content];
	for(int i=0;i<content;i++){
		data[i]=purpose[i][1][0];
	}
	delete[] root;
	Build(content,key,data);
} 
