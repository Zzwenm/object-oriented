#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
using namespace std;
class scan//�û������� 
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
		void scanf(float a);//����� 
		void result();//��ʾ��� 
		void record(float answer);//��¼��ȷ����
};
