//HuffmanTree_class
#include"minHeap_class.h" 
#include<iostream>
using namespace std;

class Huffman{
	public:
		Huffman();//构造函数
		bool Interlize();//初始化
		bool Encoding();//编码
		bool Decoding();//译码
		bool Print();//打印代码文件
		bool TreePrint();//打印哈夫曼树 
	private:
		TreeNode* Root;//哈夫曼树的根
		string code;//编码
		bool TreePrint(TreeNode* current,string s);//凹入表输出树
		bool Print(TreeNode* current,string s);//凹入表树写入文件 
		bool Scan(TreeNode* current,char pu);//遍历哈夫曼树 
};
