#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;

class generateExpression//生成表达式类 
{
	private:
		char a;
		string equ;
		string str1;
		string str2;
	public:
		void set(string s1,string s2,char s);
		string int_str(int number);//数字转字符串 
		string connect(string str1,string str2,char a);//连接表达式 
};
