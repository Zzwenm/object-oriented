#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map> 
#include <fstream>
#include"scan.h" 
#include"generateExpression.h" 
#include"random.h" 
#include"calculateResult.h" 
using namespace std;

int main()
{
    srand(unsigned(time(0)));
    scan a;
    generateExpression b;
    calculateResult c;
    random d;
    int count,i,j,n1,n2,exchange,temp2;
    string str_n1,str_n2,temp;
    char symbol,end;
    cout<<"============================================================================"<<endl;
    cin>>count;
    string equation[count];
    float *answer = new float[count];
    float *input = new float[count];
    for (i = 0; i < count; i++)
    {
        n1=d.random_num();
        n2=d.random_num();
        symbol=d.creat_symbol();
        str_n1=b.int_str(n1);
        str_n2=b.int_str(n2);
        equation[i]=b.connect(str_n1,str_n2,symbol);
        for (j = 0; j < 2; j++)
        {           
            str_n1=equation[i];
            str_n1=d.bracket(str_n1);
            n2=d.random_num();
            str_n2=b.int_str(n2);
            // 对字符串位置进行随机交换
            exchange=rand()%2;
            if (exchange==1)
            {
                temp=str_n1;
                str_n1=str_n2;
                str_n2=temp;
            }
            symbol=d.creat_symbol();
            equation[i]=b.connect(str_n1,str_n2,symbol);
        }
        cout<<'<'<<i+1<<">. "<<equation[i]<<'=';
        cin>>input[i];    a.scanf(input[i]);
        answer[i]=c.expressionCalculate(equation[i]);//四舍五入保留两位小数
        
        temp2=(int)(answer[i]*100+0.5f);
        answer[i]=(float)temp2/100;//正确题目数量和是否正确的提示
        
        a.record(answer[i]);//错误题目数量 
        
		if(i==count-1)
		a.result();
    }
    delete [] answer;
    delete [] input;
return 0;
}
