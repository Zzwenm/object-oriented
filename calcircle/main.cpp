#include<iostream>
#include"circle.h"//ͷ�ļ����� 
using namespace std;

int main()
{
	double r=0,area=0;//������ʼ�� 
	
	cin>>r; 
	
	area=calculate(r);//���� ���� 
	
	cout<<area;
	
	return 0;
}
