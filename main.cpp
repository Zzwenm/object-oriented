#include<iostream>
#include"circle.h"//头文件声明 
using namespace std;

int main()
{
	double r=0,area=0;//变量初始化 
	
	cin>>r; 
	
	area=calculate(r);//调用 函数 
	
	cout<<area;
	
	return 0;
}
