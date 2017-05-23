#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class scan//用户交流类 
{
	private:
		float input;
		int t;
		int f;
	public:
		scan()
		{
			t=0;input=0;f=0;
		}
		void scanf(float a);//输入答案 
		void result();//显示结果 
		void record(float answer);//记录正确题数
};
