#include"scan.h"
void scan::result()
{
	char end;
	cin>>end;
    if(end=='Q'||end=='q')
	{
		cout<<"��ϲ������"<<t<<"�⣡"<<endl;
		cout<<"���ź�������"<<f<<"�⣡"; 
	}
}
void scan::scanf(float a)
{
	input=a;
}
void scan::record(float answer) //��¼��ȷ����
{
	if(answer==input)
        t++;
	else
		f++;
}
