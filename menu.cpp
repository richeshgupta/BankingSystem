#include"login/login.cpp"
void menu()
{
	cout<<"\n-----**** WELCOME TO SBI USER PORTAL ****-----\n";
	cout<<endl;
	cout<<"\n \t\t *** DASHBOARD *** \n";
	cout<<"\t\t\n0.Register\n\t\t1.Login\n";
	int ch;
	cin>>ch;
	credentials c;
	switch(ch)
	{
		case 0:c.credentials_register();
				break;
		case 1:
				if(login_status==0)
				{
					c.credentials_login();
				}
				else
				{
					c.credentials_logout();
				}break;
		default:
				cout<<"\nplease enter valid choice\n";
				menu();

	}
}