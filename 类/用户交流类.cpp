class scan//�û������� 
{
	private:
		int input;
	public:
		void scanf();//����� 
		void result(int t,int f);//��ʾ��� 
};
void scan::result(int t,int f)
{
	char end;
    cout<<LanguageRead[4]<<endl;
	cin>>end;
    if(end=='Q'||end=='q')
	{
		cout<<LanguageRead[5]<<t<<LanguageRead[7]<<endl;
		cout<<LanguageRead[6]<<f<<LanguageRead[7]; 
	}		   
	return ;
}
void scan::scanf()
{
	cin>>input;
}
