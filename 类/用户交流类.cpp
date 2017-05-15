class scan//用户交流类 
{
	private:
		int input;
	public:
		void scanf();//输入答案 
		void result(int t,int f);//显示结果 
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
