#include<iostream>

using namespace std;
const int defalutSize=100;
template <typename numtype>
class LinearList{
	protected:
		numtype *Data; //存放初始化元素 
		numtype *List; //存放数组 
		int maxSize; //最大可容纳表项数 
		int Size; //定义顺序表容纳个数 
		int orSize; //保存最初定义顺序表长度 
		int addsize; //扩展顺序表时增加位数
		int site; //处理顺序表时目标位置 
		numtype purpose; //处理顺序表时目标 
		void reSize(); //扩展顺序表 
		
	public:
		LinearList(); //构造函数，用于建立数组
		void Initialize(); //初始化
		void Local(); //定位(知道位置查找元素)
		void Search(); //查找（知道元素查位置） 
		void Insert(); //插入
		void Delete(); //删除 
		void Insert_show(); //插入步骤显示
		void Search_show(); //搜索步骤显示 
		void Delete_show(); //删除步骤显示 
};

template <typename numtype> //建立数组 
LinearList<numtype>::LinearList(){
	maxSize=defalutSize;
	Data=new numtype[maxSize];
	List=new numtype[maxSize];
	cout<<"请输入你想要定义的元素个数:";
	cin>>Size;
	orSize=Size;
	cin.sync();
	
	if(Size<=maxSize){ //直接定义 
		cout<<"请输入"<<Size<<"个元素："; 
			for(int i=0;i<Size;i++){
				cin>>Data[i];
				List[i]=Data[i];
			}
		cin.sync();
	}
	
	else{
		string Judge="wrong"; //判断用户输入是否错误
		string judge; //判断用户是否选择扩展顺序表 
		cout<<endl<<"您希望输入的元素个数大于顺序表长度，是否需要扩展顺序表？（Y/N）：";
		cin>>judge;
		
		if(judge=="Y" || judge=="y"){
			Judge="correct";
			reSize();
			cout<<"现在顺序表的长度为"<<maxSize<<endl<<endl;
			while(maxSize<Size){
				cout<<"您希望输入的元素个数大于顺序表长度，是否需要扩展顺序表？（Y/N）：";
				cin>>judge;
				if(judge=="Y" || judge=="y"){
					Judge="correct"; 
					reSize();
					cout<<"现在顺序表的长度为"<<maxSize<<endl<<endl;
				}
				else if(judge=="N" || judge=="n"){
					Judge="correct";
			        Size=maxSize;
			        cout<<"请输入"<<Size<<"个元素："<<endl; 
			        for(int i=0;i<Size;i++){
				       cin>>List[i];
				       Data[i]=List[i];
				       cin.clear();
			        }
			    cin.sync();
				}
				else{
					Judge="wrong";
					cout<<"[输入错误，请重新输入]"<<endl<<endl;
				}
			}
		}
		else if(judge=="N" || judge=="n"){
			Judge="correct";
			Size=maxSize;
			cout<<"请输入"<<Size<<"个元素："<<endl; 
			for(int i=0;i<Size;i++){
				cin>>List[i];
				Data[i]=List[i];
			}
		cin.sync();
		}
		else{
			Judge="wrong";
			cout<<"输入错误，请按提示重新输入"<<endl;
		}
	}
}

template <typename numtype>//扩展顺序表长度 
void LinearList<numtype>::reSize(){
	cout<<endl<<"请输入您希望增加的长度：";
	cin>>addsize;
	cin.sync();
	string Judge="wrong";
	if(addsize<=0)
	cout<<"[输入数据有误，请重新输入]"<<endl<<endl;
	else{
		maxSize=maxSize+addsize;
		List=new numtype[maxSize];
		Data=new numtype[maxSize];
	}
}

template <typename numtype> //初始化顺序表 
void LinearList<numtype>::Initialize(){
	Size=orSize;
	for(int i=0;i<Size;i++)
	List[i]=Data[i];
	cout<<endl<<"    [已完成初始化]   "<<endl<<endl; 
	cout<<endl<<"*******************************************************************************************************************"<<endl;
}

template <typename numtype> //定位查找（已知位置查元素） 
void LinearList<numtype>::Local(){
	cout<<"请输入您需要查找的元素为在顺序表中位置：";
	cin>>site;
	string Judge="wrong"; //判断输入是否正确 
	
	while(Judge=="wrong"){
		if(site<=0 || site>Size){
			cout<<"输入的数不在已顺序表范围内，请重新输入：";
			cin>>site;
		}
		else if(site>0 && site<=Size){
			Judge="correct"; 
			cout<<"您所查找的元素为："<<List[site-1]<<endl;
		}
		else{
			cout<<"输入有误，请重新输入"<<endl;
		}
	}
	cout<<endl<<"*******************************************************************************************************************"<<endl;
}

template <typename numtype>//查找（知道元素找位置） 
void LinearList<numtype>::Search(){
	string Judge="wrong";
	string judge;
	string search_judge="inexist";
	cout<<"请输入您要查找的元素：";
	cin>>purpose;
	
	while(Judge=="wrong"){
		cout<<"是否显示搜索过程？（Y/N）：";
		cin>>judge;
		
		if(judge=="Y" || judge=="y")
		{
		string Judge="correct";
		Search_show();
		break;
	    }
		else if (judge=="N" || judge=="n")
		{
			string Judge="correct";
			string search_judge="inexist";
	        int purpose_site[Size],T=0;
	
	        for(int i=0;i<Size;i++)
	        if(List[i]==purpose) 
			{
		       search_judge="exist";
		       purpose_site[T]=i+1;
		       T++;
	        } 
	
	        if(search_judge=="inexist")
	          cout<<"顺序表中不存在该元素"<<endl;
	        else
			{
		      cout<<"符合条件的元素有：";
		      for(int i=0;i<T;i++)
		      cout<<"第"<<purpose_site[i]<<"位  "; 
		    }
		}
		
		else
		{
			cout<<"输入错误，请重新输入：";
			cin>>judge;
		}
	}

	cout<<endl<<"*******************************************************************************************************************"<<endl;
} 

template <typename numtype> //查找步骤显示
void LinearList<numtype>::Search_show(){
	string Judge="wrong";
	string judge;
	string search_judge="inexist";
	int purpose_site[Size],T=0;
	
	for(int i=0;i<Size;i++)
	if(List[i]==purpose) 
	{
		search_judge="exist";
		purpose_site[T]=i+1;
		T++;
	}
	
	cout<<endl<<"搜索步骤如下："<<endl;
	cout<<"--------------------------------------------------------------------------------"; 
	cout<<endl<<"step 1：遍历顺序表，并将符合要求的元素的位置记录下来："<<endl;
	cout<<"本次搜索中可以检测到的符合要求的元素有：";
	if(search_judge=="exist")
	{
       for(int i=0;i<T;i++)
	   { 
		   cout<<"第"<<purpose_site[i]<<"位  ";
	   } 
   }
   else
   {
   	cout<<"无";
   }
	cout<<endl<<endl<<"step 2：如果有符合条件的元素则获取其位置，否则输出其‘不存在’的信息"<<endl;
	if(search_judge=="inexist")
	cout<<"顺序表中不存在该元素"<<endl;
	else{
		cout<<"本次搜索中符合条件的元素有：";
		for(int i=0;i<T;i++)
		cout<<"第"<<purpose_site[i]<<"位  "; 
	}
	cout<<endl<<"--------------------------------------------------------------------------------"; 
} 

template <typename numtype> //顺序表插入 
void LinearList<numtype>::Insert(){
		cout<<endl<<"初始顺序表为："<<endl;
	    for(int i=0;i<Size;i++)
	    cout<<List[i]<<"  ";
	 
		cout<<endl<<"请输入您想要插入的元素：";
	    cin>>purpose;
	    cout<<"请输入您希望元素插入的位置(插入成为第i个元素)：";
	    cin>>site;
	    
	if(Size + 1 > maxSize){
		cout<<"顺序表容量不足，无法插入"<<endl;
	}
	else if (site <= 0 || site > Size+1)
	cout<<"输入数据错误";
	else{
		string Judge="wrong";
		string judge;
		cout<<"是否需要展示插入过程？（Y/N）：";
		cin>>judge;
		while(Judge=="wrong"){
			if (judge=="Y" || judge=="y"){
				Judge="correct";
			    Insert_show();
			}
			else if(judge=="N" || judge=="n"){
				Judge="correct";
				Size=Size+1;
		        for(int i=Size-1;i>=site;i--)
		           {List[i]=List[i-1];}
		           List[site-1]=purpose;
		
		           cout<<endl<<"插入元素后得到顺序表为："<<endl;
		           for(int i=0;i<Size;i++){
			          cout<<List[i]<<"  ";
		           }
			}
			else{
				cout<<"输入错误，请重新输入：";
				cin>>judge;
			}
		}
	}
	cout<<endl<<endl<<"*******************************************************************************************************************"<<endl;
}

template <typename numtype> //插入过程展示
void LinearList<numtype>::Insert_show(){
	    cout<<endl<<endl<<"插入步骤显示如下：";
		cout<<endl<<"------------------------------------------------------------";
		Size=Size+1;
		cout<<endl<<"step 1:扩展顺序表定义范围为"<<Size<<"（原长为"<<Size-1<<")";
		
		for(int i=Size-1;i>=site;i--)
		{List[i]=List[i-1];
		List[i-1]=0;}
		cout<<endl<<endl<<"step 2:将目标位置后的元素均往后移动："; 
		for(int i=0;i<Size;i++){
			cout<<List[i]<<"  ";
		}
		
		List[site-1]=purpose;
		cout<<endl<<endl<<"step 3:将目标元素输入目标位置：";
		for(int i=0;i<Size;i++){
			cout<<List[i]<<"  ";
		}
		
		cout<<endl<<endl<<"最后可得到插入元素后得到顺序表为：";
		for(int i=0;i<Size;i++){
			cout<<List[i]<<"  ";
		}
		cout<<endl<<"------------------------------------------------------------"<<endl;
} 

template <typename numtype> //删除(已知元素删除) 
void LinearList<numtype>::Delete()
{
	string Judge="wrong";
	string judge;
	string delete_judge="inexist";
	int purpose_site[Size],T=0;
	
	cout<<"初始顺序表为："<<endl;
	for(int i=0;i<Size;i++)
	cout<<List[i]<<"  ";
	
	cout<<endl<<"请输入您想要删除的元素：";
	cin>>purpose;
	
	while(Judge=="wrong")
	{
		cout<<"是否显示删除步骤？（Y/N）：";
		cin>>judge;
		if(judge=="Y" || judge=="y")
		{
			Judge=="correct";
			Delete_show();
			break;
		}
		
		else if(judge=="N" || judge=="n")
		{
			Judge=="correct";
			
			for(int i=0;i<Size;i++)
	         if(List[i]==purpose)
			  {
		       delete_judge="exist";
		       purpose_site[T]=i;
		       T++;
	          } 
	
	        if(delete_judge=="inexist")
	        {
	        cout<<"顺序表中不存在该元素，无法进行删除"<<endl;
			}
			
	        else
			{
		       for(int t=0;t<T;t++)
			   {
			      for(int i=purpose_site[t];i<Size-1;i++)
				  {
				    List[i]=List[i+1];
			      }
			      Size=Size-1;
		       }
		      cout<<"删除后得到的顺序表为："<<endl; 
		      for(int i=0;i<Size;i++)
		      cout<<List[i]<<"  ";
         	}
         	break;
	    }
	    
	    else{
	    	cout<<"输入错误，请重新输入：";
	    	cin>>judge;
	    }
	}
	cout<<endl<<"*******************************************************************************************************************"<<endl;
}

template <typename numtype>//删除步骤显示 
void LinearList<numtype>::Delete_show()
{
	string delete_judge="inexist";
	int purpose_site[Size],T=0;
	
	for(int i=0;i<Size;i++)
	if(List[i]==purpose)
	{
		delete_judge="exist";
		purpose_site[T]=i;
		T++;
	}
	
	cout<<endl<<"删除步骤如下："<<endl;
	cout<<"-----------------------------------------------------------------------------------------"<<endl; 
	cout<<"step 1：先遍历顺序表，找出要删除的元素"<<endl;
	if(delete_judge=="exist"){
	cout<<"符合条件需要删除的元素有:";
	for(int i=0;i<T;i++)
	cout<<"第"<<purpose_site[i]+1<<"位  ";
	}
	else{
	cout<<"顺序表中不存在符合删除条件的元素,输出‘无法删除’信息"<<endl;
	cout<<"顺序表中不存在该元素，无法进行删除"<<endl;
	}
	
	if(delete_judge=="exist")
	cout<<endl<<endl<<"step 2：从前面开始，依次将要删除的元素位置后的元素前移覆盖,同时改变顺序表长度"<<endl;
		for(int t=0;t<T;t++){
			for(int i=purpose_site[t];i<Size-1;i++)
			{
				List[i]=List[i+1];
			}
			cout<<"本次删除操作中，第"<<t+1<<"轮覆盖元素后得到：";
			for(int i=0;i<Size-1;i++)
			cout<<List[i]<<"  ";
			
			Size=Size-1;
			cout<<endl<<"本次删除操作改变顺序表长度为："<<Size<<"(原来顺序表长度为"<<Size+1<<")"<<endl;
		}
		cout<<endl<<"删除后得到的顺序表为："; 
		for(int i=0;i<Size;i++)
		cout<<List[i]<<"  ";
    	cout<<endl<<"-----------------------------------------------------------------------------------------"<<endl; 
}
	

int main(){
	LinearList<int> t;
	char opration;
	string Judge="wrong";
	string judge="y";
	
 cout<<endl<<endl;
 cout<<"\t\t|--------------------------------------------------------------------------|\n";
 cout<<"\t\t|                       1.初始化顺序表                                     |\n";
 cout<<"\t\t|                       2.在顺序表中插入新元素                             |\n";
 cout<<"\t\t|                       3.删除顺序表中的某元素                             |\n";
 cout<<"\t\t|                       4.查找顺序表中的某元素（已知位置）                 |\n";
 cout<<"\t\t|                       5.查找顺序表中的某元素位置（已知元素）             |\n";
 cout<<"\t\t|                       6.退出程序                                         |\n";
 cout<<"\t\t|--------------------------------------------------------------------------|\n";
	cout<<"请输入您要执行的操作对应的编号:";
	cin>>opration;
	cout<<endl<<"*******************************************************************************************************************"<<endl;
	
	while(Judge=="wrong"){
			switch(opration){
		      case '1':{
		        t.Initialize(); 
		        break;
	          } 
	          case '2':{
		        t.Insert();
		        break;
	          }
	          case '3':{
	            t.Delete();
		        break;
	          }
	          case '4':{
	            t.Local();
		        break;
	          }
	          case '5':{
		        t.Search();
		        break;
	          }
	          case '6':{
	            cout<<"    [正在退出]    ";
	            return 0;
	          }
	          default:{
	            cout<<endl<<"输入错误，请重新输入:";
	            cin>>opration;
	            continue;
	          }
	        }
	        
	        while(Judge=="wrong"){
	        	cout<<endl<<"是否继续进行操作？（Y/N）：";
	            cin>>judge;
	            if(judge=="Y" || judge=="y"){
	             cout<<"\t\t|--------------------------------------------------------------------------|\n";
                 cout<<"\t\t|                       1.初始化顺序表                                     |\n";
                 cout<<"\t\t|                       2.在顺序表中插入新元素                             |\n";
                 cout<<"\t\t|                       3.删除顺序表中的某元素                             |\n";
                 cout<<"\t\t|                       4.查找顺序表中的某元素（已知位置）                 |\n";
                 cout<<"\t\t|                       5.查找顺序表中的某元素位置（已知元素）             |\n";
                 cout<<"\t\t|                       6.退出程序                                         |\n";
                 cout<<"\t\t|--------------------------------------------------------------------------|\n";
	            	cout<<"请输入您要执行的操作对应的编号:";
					cin>>opration;
					break;
	            }
	            else if(judge=="N" || judge=="n"){
	        	    cout<<endl<<"****************************正在退出****************************";
	        	    return 0;
	            }
	            else{
	            	cout<<"输入错误，请重新输入";
	            }
	        }
	        
	}
	return 0;
}           
