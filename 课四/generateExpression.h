#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;

class generateExpression//���ɱ��ʽ�� 
{
	private:
		char a;
		string equ;
		string str1;
		string str2;
	public:
		void set(string s1,string s2,char s);
		string int_str(int number);//����ת�ַ��� 
		string connect(string str1,string str2,char a);//���ӱ��ʽ 
};
