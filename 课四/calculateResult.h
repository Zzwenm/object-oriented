#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class  calculateResult// 计算答案类 
{
	private:
		int num;
		float anwser;
	public:
		string InfixToPostfix(string infix);// 将中缀表达式转换成后缀表达式
		float posfixCompute(string s);// 计算后缀表达式
		float expressionCalculate(string s);//计算表达式 
};
