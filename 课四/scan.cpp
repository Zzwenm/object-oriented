#include"scan.h"
void scan::result()
{
	char end;
	cin>>end;
    if(end=='Q'||end=='q')
	{
		cout<<"恭喜你答对了"<<t<<"题！"<<endl;
		cout<<"很遗憾你答错了"<<f<<"题！"; 
	}
}
void scan::scanf(float a)
{
	input=a;
}
void scan::record(float answer) //记录正确题数
{
	if(answer==input)
        t++;
	else
		f++;
}
