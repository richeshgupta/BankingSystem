#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int login_status  = 0;
class credentials
{
	string username;
	string password; 
public:
	void input_credentials();
	void write_credentials();
	void credentials_register();
	void credentials_login();
	void credentials_logout();
	string ret_username()
	{
		return username;
	}
};
void credentials::input_credentials()
{	
		fstream f1;
		f1.open("login/users_db.dat",ios::binary);
		cout<<"\n Enter Username\n";
		string temp_u;
		cin>>temp_u;
		username = temp_u;
		cout<<"\n Enter password\n";
		cin>>password;
	}

void credentials::write_credentials()
{
	fstream f1;
	f1.open("login/users_db.dat",ios::app|ios::binary);
	this->input_credentials();
	f1.write((char*)this,sizeof(this));
	cout<<"\nRegistered Successfully!\n";
	f1.close();
}
void credentials::credentials_register()
{
	this->write_credentials();
}
void credentials::credentials_login()
{	string temp_u,temp_p;
	cout<<"\n\t\t -- login --\n\n";
	cout<<"\nEnter username : ";cin>>temp_u;
	cout<<"\nEnter password : ";cin>>temp_p;
	credentials c;
	fstream f1;
	f1.open("login/users_db.dat",ios::binary);
	int flag_found = 0;
	while(f1.read((char*)&c,sizeof(c)))
	{
		if(ret_username() == temp_u)
		{	
			flag_found  = 1;

			if(this->password == temp_p)
			{
				cout<<"\n Logged in Successfully!\n";
				login_status = 1;
				break;
			}
			else
			{
				cout<<"Wrong password\n";

				//cout<<"status\n "<<login_status;
				this->credentials_login();
			}
		}
		
	}
	f1.close();
}
void credentials::credentials_logout()
{
	if(login_status)
	{
		login_status = 0;
	}
	else
	{
		cout<<"Not logged in!";
	}
}