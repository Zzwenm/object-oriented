#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <stack>
#include"calculate.h"
using namespace std;

int main(int argc, char *argv[])
{
	string infilepath, outfilepath;
	if (argc == 3)//判断主函数参数个数（避免直接打开报错）
	{
		infilepath = argv[1];
		outfilepath = argv[2];
	}
	else cin >> infilepath >> outfilepath;//从命令行中输入路径和输出路径
	srand(unsigned(time(0)));
	int count;
	cout << "一下为生成题目的数量:\n";
	int i, j, n1, n2, exchange, t = 0, f;
	string str_n1, str_n2, temp;
	char symbol, end;
	count = readfile(infilepath);
	string equation[100];
	float *answer = new float[count];
	float *input = new float[count];
	for (i = 0; i < count; i++)
	{
		n1 = rand() % 11;
		n2 = rand() % 11;
		symbol = randomOperation();
		str_n1 = int_str(n1);
		str_n2 = int_str(n2);
		equation[i] = connect(str_n1, str_n2, symbol);
		for (j = 0; j < 2; j++)
		{
			str_n1 = equation[i];
			str_n1 = bracket(equation[i]);
			n2 = rand() % 11;
			str_n2 = int_str(n2);
			// 对字符串位置进行随机交换
			exchange = rand() % 2;
			if (exchange == 1)
			{
				temp = str_n1;
				str_n1 = str_n2;
				str_n2 = temp;
			}
			symbol = randomOperation();
			equation[i] = connect(str_n1, str_n2, symbol);
		}
		cout << '(' << i + 1 << ')' << '\t' << equation[i] << '=';
		cin >> input[i];
		answer[i] = calculateResult(equation[i]);
		t += record(answer[i], input[i]);
		f = count - t;
		if (i == count - 1)
			void writeFile(int t, int f);
	}
	delete[] answer;
	delete[] input;
	return 0;
}