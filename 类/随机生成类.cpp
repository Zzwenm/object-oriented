class random//��������� 
{
	private:
		int num;
		char symbol;
		char bracket;
		
	public:
			char creat_symbol();// �������
			string bracket(string n); 
			
};
char random::creat_symbol()
{
    int n = rand()%4;
    char sym;
    switch(n)
    {
        case 0: sym='+';break;
        case 1: sym='-';break;
        case 2: sym='*';break;
        case 3: sym='/';break;
    }
	return sym;
}
string random::bracket(string n)//������� 
{
    int random=rand()%2;
    if (random==1)
    {
        n='('+n+')';
    }
	return n; 
}
