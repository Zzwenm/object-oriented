#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class  calculateResult// ������� 
{
	private:
		int num;
		float anwser;
	public:
		string InfixToPostfix(string infix);// ����׺���ʽת���ɺ�׺���ʽ
		float posfixCompute(string s);// �����׺���ʽ
		float expressionCalculate(string s);//������ʽ 
};
