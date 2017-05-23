#include"generateExpression.h" 
string generateExpression::connect(string str1,string str2,char a)
{
    string equ = str1+a+str2;
	return equ;
}
string generateExpression::int_str(int number)
{
    char str[1];
    itoa(number,str,10);
    string i_s = str;
	return i_s;
}
void generateExpression::set(string s1,string s2,char s)
{
	str1=s1;
	str2=s2;
	a=s;
}
