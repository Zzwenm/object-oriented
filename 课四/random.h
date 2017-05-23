#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class random//随机生成类 
{
	private:
		int num;
		char symbol;
		char brack;
		
	public:
			char creat_symbol();// 随机符号
			string bracket(string n); //随机括号
			int random_num();
};
