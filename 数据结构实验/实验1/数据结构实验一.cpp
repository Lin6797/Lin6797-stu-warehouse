#include<iostream>

using namespace std;
const int defalutSize=100;
template <typename numtype>
class LinearList{
	protected:
		numtype *Data; //��ų�ʼ��Ԫ�� 
		numtype *List; //������� 
		int maxSize; //�������ɱ����� 
		int Size; //����˳������ɸ��� 
		int orSize; //�����������˳����� 
		int addsize; //��չ˳���ʱ����λ��
		int site; //����˳���ʱĿ��λ�� 
		numtype purpose; //����˳���ʱĿ�� 
		void reSize(); //��չ˳��� 
		
	public:
		LinearList(); //���캯�������ڽ�������
		void Initialize(); //��ʼ��
		void Local(); //��λ(֪��λ�ò���Ԫ��)
		void Search(); //���ң�֪��Ԫ�ز�λ�ã� 
		void Insert(); //����
		void Delete(); //ɾ�� 
		void Insert_show(); //���벽����ʾ
		void Search_show(); //����������ʾ 
		void Delete_show(); //ɾ��������ʾ 
};

template <typename numtype> //�������� 
LinearList<numtype>::LinearList(){
	maxSize=defalutSize;
	Data=new numtype[maxSize];
	List=new numtype[maxSize];
	cout<<"����������Ҫ�����Ԫ�ظ���:";
	cin>>Size;
	orSize=Size;
	cin.sync();
	
	if(Size<=maxSize){ //ֱ�Ӷ��� 
		cout<<"������"<<Size<<"��Ԫ�أ�"; 
			for(int i=0;i<Size;i++){
				cin>>Data[i];
				List[i]=Data[i];
			}
		cin.sync();
	}
	
	else{
		string Judge="wrong"; //�ж��û������Ƿ����
		string judge; //�ж��û��Ƿ�ѡ����չ˳��� 
		cout<<endl<<"��ϣ�������Ԫ�ظ�������˳����ȣ��Ƿ���Ҫ��չ˳�����Y/N����";
		cin>>judge;
		
		if(judge=="Y" || judge=="y"){
			Judge="correct";
			reSize();
			cout<<"����˳���ĳ���Ϊ"<<maxSize<<endl<<endl;
			while(maxSize<Size){
				cout<<"��ϣ�������Ԫ�ظ�������˳����ȣ��Ƿ���Ҫ��չ˳�����Y/N����";
				cin>>judge;
				if(judge=="Y" || judge=="y"){
					Judge="correct"; 
					reSize();
					cout<<"����˳���ĳ���Ϊ"<<maxSize<<endl<<endl;
				}
				else if(judge=="N" || judge=="n"){
					Judge="correct";
			        Size=maxSize;
			        cout<<"������"<<Size<<"��Ԫ�أ�"<<endl; 
			        for(int i=0;i<Size;i++){
				       cin>>List[i];
				       Data[i]=List[i];
				       cin.clear();
			        }
			    cin.sync();
				}
				else{
					Judge="wrong";
					cout<<"[�����������������]"<<endl<<endl;
				}
			}
		}
		else if(judge=="N" || judge=="n"){
			Judge="correct";
			Size=maxSize;
			cout<<"������"<<Size<<"��Ԫ�أ�"<<endl; 
			for(int i=0;i<Size;i++){
				cin>>List[i];
				Data[i]=List[i];
			}
		cin.sync();
		}
		else{
			Judge="wrong";
			cout<<"��������밴��ʾ��������"<<endl;
		}
	}
}

template <typename numtype>//��չ˳����� 
void LinearList<numtype>::reSize(){
	cout<<endl<<"��������ϣ�����ӵĳ��ȣ�";
	cin>>addsize;
	cin.sync();
	string Judge="wrong";
	if(addsize<=0)
	cout<<"[����������������������]"<<endl<<endl;
	else{
		maxSize=maxSize+addsize;
		List=new numtype[maxSize];
		Data=new numtype[maxSize];
	}
}

template <typename numtype> //��ʼ��˳��� 
void LinearList<numtype>::Initialize(){
	Size=orSize;
	for(int i=0;i<Size;i++)
	List[i]=Data[i];
	cout<<endl<<"    [����ɳ�ʼ��]   "<<endl<<endl; 
	cout<<endl<<"*******************************************************************************************************************"<<endl;
}

template <typename numtype> //��λ���ң���֪λ�ò�Ԫ�أ� 
void LinearList<numtype>::Local(){
	cout<<"����������Ҫ���ҵ�Ԫ��Ϊ��˳�����λ�ã�";
	cin>>site;
	string Judge="wrong"; //�ж������Ƿ���ȷ 
	
	while(Judge=="wrong"){
		if(site<=0 || site>Size){
			cout<<"�������������˳���Χ�ڣ����������룺";
			cin>>site;
		}
		else if(site>0 && site<=Size){
			Judge="correct"; 
			cout<<"�������ҵ�Ԫ��Ϊ��"<<List[site-1]<<endl;
		}
		else{
			cout<<"������������������"<<endl;
		}
	}
	cout<<endl<<"*******************************************************************************************************************"<<endl;
}

template <typename numtype>//���ң�֪��Ԫ����λ�ã� 
void LinearList<numtype>::Search(){
	string Judge="wrong";
	string judge;
	string search_judge="inexist";
	cout<<"��������Ҫ���ҵ�Ԫ�أ�";
	cin>>purpose;
	
	while(Judge=="wrong"){
		cout<<"�Ƿ���ʾ�������̣���Y/N����";
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
	          cout<<"˳����в����ڸ�Ԫ��"<<endl;
	        else
			{
		      cout<<"����������Ԫ���У�";
		      for(int i=0;i<T;i++)
		      cout<<"��"<<purpose_site[i]<<"λ  "; 
		    }
		}
		
		else
		{
			cout<<"����������������룺";
			cin>>judge;
		}
	}

	cout<<endl<<"*******************************************************************************************************************"<<endl;
} 

template <typename numtype> //���Ҳ�����ʾ
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
	
	cout<<endl<<"�����������£�"<<endl;
	cout<<"--------------------------------------------------------------------------------"; 
	cout<<endl<<"step 1������˳�����������Ҫ���Ԫ�ص�λ�ü�¼������"<<endl;
	cout<<"���������п��Լ�⵽�ķ���Ҫ���Ԫ���У�";
	if(search_judge=="exist")
	{
       for(int i=0;i<T;i++)
	   { 
		   cout<<"��"<<purpose_site[i]<<"λ  ";
	   } 
   }
   else
   {
   	cout<<"��";
   }
	cout<<endl<<endl<<"step 2������з���������Ԫ�����ȡ��λ�ã���������䡮�����ڡ�����Ϣ"<<endl;
	if(search_judge=="inexist")
	cout<<"˳����в����ڸ�Ԫ��"<<endl;
	else{
		cout<<"���������з���������Ԫ���У�";
		for(int i=0;i<T;i++)
		cout<<"��"<<purpose_site[i]<<"λ  "; 
	}
	cout<<endl<<"--------------------------------------------------------------------------------"; 
} 

template <typename numtype> //˳������ 
void LinearList<numtype>::Insert(){
		cout<<endl<<"��ʼ˳���Ϊ��"<<endl;
	    for(int i=0;i<Size;i++)
	    cout<<List[i]<<"  ";
	 
		cout<<endl<<"����������Ҫ�����Ԫ�أ�";
	    cin>>purpose;
	    cout<<"��������ϣ��Ԫ�ز����λ��(�����Ϊ��i��Ԫ��)��";
	    cin>>site;
	    
	if(Size + 1 > maxSize){
		cout<<"˳����������㣬�޷�����"<<endl;
	}
	else if (site <= 0 || site > Size+1)
	cout<<"�������ݴ���";
	else{
		string Judge="wrong";
		string judge;
		cout<<"�Ƿ���Ҫչʾ������̣���Y/N����";
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
		
		           cout<<endl<<"����Ԫ�غ�õ�˳���Ϊ��"<<endl;
		           for(int i=0;i<Size;i++){
			          cout<<List[i]<<"  ";
		           }
			}
			else{
				cout<<"����������������룺";
				cin>>judge;
			}
		}
	}
	cout<<endl<<endl<<"*******************************************************************************************************************"<<endl;
}

template <typename numtype> //�������չʾ
void LinearList<numtype>::Insert_show(){
	    cout<<endl<<endl<<"���벽����ʾ���£�";
		cout<<endl<<"------------------------------------------------------------";
		Size=Size+1;
		cout<<endl<<"step 1:��չ˳����巶ΧΪ"<<Size<<"��ԭ��Ϊ"<<Size-1<<")";
		
		for(int i=Size-1;i>=site;i--)
		{List[i]=List[i-1];
		List[i-1]=0;}
		cout<<endl<<endl<<"step 2:��Ŀ��λ�ú��Ԫ�ؾ������ƶ���"; 
		for(int i=0;i<Size;i++){
			cout<<List[i]<<"  ";
		}
		
		List[site-1]=purpose;
		cout<<endl<<endl<<"step 3:��Ŀ��Ԫ������Ŀ��λ�ã�";
		for(int i=0;i<Size;i++){
			cout<<List[i]<<"  ";
		}
		
		cout<<endl<<endl<<"���ɵõ�����Ԫ�غ�õ�˳���Ϊ��";
		for(int i=0;i<Size;i++){
			cout<<List[i]<<"  ";
		}
		cout<<endl<<"------------------------------------------------------------"<<endl;
} 

template <typename numtype> //ɾ��(��֪Ԫ��ɾ��) 
void LinearList<numtype>::Delete()
{
	string Judge="wrong";
	string judge;
	string delete_judge="inexist";
	int purpose_site[Size],T=0;
	
	cout<<"��ʼ˳���Ϊ��"<<endl;
	for(int i=0;i<Size;i++)
	cout<<List[i]<<"  ";
	
	cout<<endl<<"����������Ҫɾ����Ԫ�أ�";
	cin>>purpose;
	
	while(Judge=="wrong")
	{
		cout<<"�Ƿ���ʾɾ�����裿��Y/N����";
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
	        cout<<"˳����в����ڸ�Ԫ�أ��޷�����ɾ��"<<endl;
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
		      cout<<"ɾ����õ���˳���Ϊ��"<<endl; 
		      for(int i=0;i<Size;i++)
		      cout<<List[i]<<"  ";
         	}
         	break;
	    }
	    
	    else{
	    	cout<<"����������������룺";
	    	cin>>judge;
	    }
	}
	cout<<endl<<"*******************************************************************************************************************"<<endl;
}

template <typename numtype>//ɾ��������ʾ 
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
	
	cout<<endl<<"ɾ���������£�"<<endl;
	cout<<"-----------------------------------------------------------------------------------------"<<endl; 
	cout<<"step 1���ȱ���˳����ҳ�Ҫɾ����Ԫ��"<<endl;
	if(delete_judge=="exist"){
	cout<<"����������Ҫɾ����Ԫ����:";
	for(int i=0;i<T;i++)
	cout<<"��"<<purpose_site[i]+1<<"λ  ";
	}
	else{
	cout<<"˳����в����ڷ���ɾ��������Ԫ��,������޷�ɾ������Ϣ"<<endl;
	cout<<"˳����в����ڸ�Ԫ�أ��޷�����ɾ��"<<endl;
	}
	
	if(delete_judge=="exist")
	cout<<endl<<endl<<"step 2����ǰ�濪ʼ�����ν�Ҫɾ����Ԫ��λ�ú��Ԫ��ǰ�Ƹ���,ͬʱ�ı�˳�����"<<endl;
		for(int t=0;t<T;t++){
			for(int i=purpose_site[t];i<Size-1;i++)
			{
				List[i]=List[i+1];
			}
			cout<<"����ɾ�������У���"<<t+1<<"�ָ���Ԫ�غ�õ���";
			for(int i=0;i<Size-1;i++)
			cout<<List[i]<<"  ";
			
			Size=Size-1;
			cout<<endl<<"����ɾ�������ı�˳�����Ϊ��"<<Size<<"(ԭ��˳�����Ϊ"<<Size+1<<")"<<endl;
		}
		cout<<endl<<"ɾ����õ���˳���Ϊ��"; 
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
 cout<<"\t\t|                       1.��ʼ��˳���                                     |\n";
 cout<<"\t\t|                       2.��˳����в�����Ԫ��                             |\n";
 cout<<"\t\t|                       3.ɾ��˳����е�ĳԪ��                             |\n";
 cout<<"\t\t|                       4.����˳����е�ĳԪ�أ���֪λ�ã�                 |\n";
 cout<<"\t\t|                       5.����˳����е�ĳԪ��λ�ã���֪Ԫ�أ�             |\n";
 cout<<"\t\t|                       6.�˳�����                                         |\n";
 cout<<"\t\t|--------------------------------------------------------------------------|\n";
	cout<<"��������Ҫִ�еĲ�����Ӧ�ı��:";
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
	            cout<<"    [�����˳�]    ";
	            return 0;
	          }
	          default:{
	            cout<<endl<<"�����������������:";
	            cin>>opration;
	            continue;
	          }
	        }
	        
	        while(Judge=="wrong"){
	        	cout<<endl<<"�Ƿ�������в�������Y/N����";
	            cin>>judge;
	            if(judge=="Y" || judge=="y"){
	             cout<<"\t\t|--------------------------------------------------------------------------|\n";
                 cout<<"\t\t|                       1.��ʼ��˳���                                     |\n";
                 cout<<"\t\t|                       2.��˳����в�����Ԫ��                             |\n";
                 cout<<"\t\t|                       3.ɾ��˳����е�ĳԪ��                             |\n";
                 cout<<"\t\t|                       4.����˳����е�ĳԪ�أ���֪λ�ã�                 |\n";
                 cout<<"\t\t|                       5.����˳����е�ĳԪ��λ�ã���֪Ԫ�أ�             |\n";
                 cout<<"\t\t|                       6.�˳�����                                         |\n";
                 cout<<"\t\t|--------------------------------------------------------------------------|\n";
	            	cout<<"��������Ҫִ�еĲ�����Ӧ�ı��:";
					cin>>opration;
					break;
	            }
	            else if(judge=="N" || judge=="n"){
	        	    cout<<endl<<"****************************�����˳�****************************";
	        	    return 0;
	            }
	            else{
	            	cout<<"�����������������";
	            }
	        }
	        
	}
	return 0;
}           
