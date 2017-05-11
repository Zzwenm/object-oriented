#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <stack>
#include <map> 
#include<fstream>
#include"calculate.h"

using namespace std;
char randomOperation()
{
	int n = rand() % 4;
	char sym;
	switch (n)
	{
	case 0: sym = '+';break;
	case 1: sym = '-';break;
	case 2: sym = '*';break;
	case 3: sym = '/';break;
	}
	return sym;
}

// 随机括号
string bracket(string n)
{
	int random = rand() % 2;
	if (random == 1)
	{
		n = '(' + n + ')';
	}
	return n;
}
string int_str(int number)
{
	char str[3];
	_itoa_s(number, str, 10);
	string i_s = str;
	return i_s;
}
// 连接数字运算符
string connect(string str1, string str2, char a)
{
	string equ = str1 + a + str2;
	return equ;
}

// 将中缀表达式转换成后缀表达式
string InfixToPostfix(string infix)
{
	char current = 0;
	string postfix;//后缀表达式

	stack<char> mark;//符号栈

	map<char, int> priority;//符号优先级
	priority['+'] = 0;
	priority['-'] = 0;
	priority['*'] = 1;
	priority['/'] = 1;

	for (int i = 0;i < infix.size(); ++i)
	{
		current = infix[i];
		switch (current)
		{
		case '0':case '1':case '2':case '3':case '4':case '5':
		case '6':case '7':case '8':case '9':case '.':
			postfix.push_back(current);//数字直接写入
			break;
		case '+':case '-':case '*':case '/':
			//如果运算符的前一项不是右括号即说明前一个数字输入完毕，用#标识
			if (infix[i - 1] != ')')
				postfix.push_back('#');
			//如果符号栈非空，即比较目前符号与栈顶符号优先级，低于等于出栈(并写入输出字符串)，
			//直至符号全部出栈或者遇到了'('或者大于栈顶符号的优先级
			if (!mark.empty())
			{
				char tempTop = mark.top();
				while (tempTop != '(' && priority[current] <= priority[tempTop])
				{
					postfix.push_back(tempTop);
					mark.pop();
					if (mark.empty())
						break;
					tempTop = mark.top();
				}
			}
			mark.push(current);//新符号入栈
			break;
		case '(':
			if (infix[i - 1] >= '0' && infix[i - 1] <= '9')// for expression 2-5*2(6/2)
			{
				postfix.push_back('#');
				mark.push('*');
			}
			mark.push(current);
			break;
		case ')':
			postfix.push_back('#');//右括号说明前方数字输入完成，标识一下
			while (mark.top() != '(')
			{
				postfix.push_back(mark.top());
				mark.pop();
			}
			mark.pop();//左括号出栈
			break;
		default:
			break;//忽略其他字符
		}
	}
	if (infix[infix.size() - 1] != ')')
		postfix.push_back('#');//中缀表达式最后一个是数字需要加上#。
	while (!mark.empty())//如果栈非空，全部出栈并写入输出字符串
	{
		postfix.push_back(mark.top());
		mark.pop();
	}
	return postfix;
}

// 计算后缀表达式
float posfixCompute(string s)
{
	stack<float> tempResult;

	string strNum;
	float currNum = 0;

	float tempNum = 0;
	for (string::const_iterator i = s.begin(); i != s.end(); ++i)
	{
		switch (*i)
		{
		case '0':case '1':case '2':case '3':case '4':case '5':
		case '6':case '7':case '8':case '9':case '.':
			strNum.push_back(*i);
			break;
		case '+':
			tempNum = tempResult.top();
			tempResult.pop();
			tempNum += tempResult.top();
			tempResult.pop();
			tempResult.push(tempNum);
			break;
		case '-':
			tempNum = tempResult.top();
			tempResult.pop();
			tempNum = tempResult.top() - tempNum;
			tempResult.pop();
			tempResult.push(tempNum);
			break;
		case '*':
			tempNum = tempResult.top();
			tempResult.pop();
			tempNum *= tempResult.top();
			tempResult.pop();
			tempResult.push(tempNum);
			break;
		case '/':
			tempNum = tempResult.top();
			tempResult.pop();
			tempNum = tempResult.top() / tempNum;
			tempResult.pop();
			tempResult.push(tempNum);
			break;
		case '#':
			currNum = atof(strNum.c_str());//in c++11, use currNum = std::stof(strNUm);
			strNum.clear();
			tempResult.push(currNum);
			break;
		}
	}
	return tempResult.top();
}


// 表达式计算
float calculateResult(string s)
{
	return posfixCompute(InfixToPostfix(s));
}
float record(int answer, int input)//记录正确题数 
{
	int t = 0;
	if (answer == input)
	{
		t++;
	}
	return t;
}
void print(int t, int f)//结果 
{
	char end;
	cout << "题已答完，输入Q显示测试结果" << endl;
	cin >> end;
	if (end == 'Q' || end == 'q')
	{
		cout << "恭喜你答对了：" << t << "题!" << endl;
		cout << "很遗憾你打错了：" << f << "题!" << endl;
	}
	return;
}
int readfile(string infilepath)
{
	int a;
	FILE * fp1 = fopen("in.txt", "r");//打开输入文件
	fscanf(fp1, "%d", &a);
	fclose(fp1);
	return a;
}
void writeFile(int t, int f)
{
	FILE * fp1 = fopen("out.txt", "w");
	char end;
	cout << "题已答完，输入Q显示测试结果" << endl;
	cin >> end;
	fprintf(fp1, "恭喜你答对了：%d 题", t);
	fprintf(fp1, "很遗憾答错了：%d 题", f);
	fclose(fp1);
}
