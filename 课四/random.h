#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class random//��������� 
{
	private:
		int num;
		char symbol;
		char brack;
		
	public:
			char creat_symbol();// �������
			string bracket(string n); //�������
			int random_num();
};
