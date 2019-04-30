#include"login/login.cpp"
void user_menu() 
{
    User b;
	cout<<"1.login\n2.Register\n";
	int ch;
	cin>>ch;
	if(ch==1)
	{

   if(b.authenticate()!=0)
   		cout<<"Success\n";
	}
	else if(ch==2)
	{
    b.write_cred();
	}
	else if(ch==3)
	b.print_data();
}
int main()
{
    user_menu();
    return 0;
}
