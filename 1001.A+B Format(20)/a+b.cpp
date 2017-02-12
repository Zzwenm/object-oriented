#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,e,sum;
    scanf("%d %d",&a,&b);
    sum=a+b;
    if(sum<1000&&sum>-1000)
    {
        printf("%d",sum);
    }
    else if(abs(sum)>999&&abs(sum)<1000000)
    {
        c=abs(sum%1000);
        d=(sum-sum%1000)/1000;
        printf("%d,%03d",d,c);
    }
    else if(abs(sum)>999999)
    {
        c=abs(sum%1000);
        sum=(sum-sum%1000)/1000;
        d=abs(d%1000);
        e=(sum-sum%1000)/1000;
        printf("%d,%03d,%03d",e,d,c);
    }
    return 0;
}
