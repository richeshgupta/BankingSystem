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
};
void credentials::input_credentials()
{	
		fstream f1;
		f1.open("login/users_db.dat",ios::binary);
		cout<<"\n Enter Username\n";
		cin>>username;
		string temp_u = username;
		while(f1.read((char*)this,sizeof(this)))
		{
			if(this->username == temp_u)
				cout<<"Username already exists\n";
		}
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

	fstream f1;
	f1.open("login/users_db",ios::binary);
	while(f1.read((char*)this,sizeof(this)))
	{
		if(this->username == temp_u)
		{
			if(this->password == temp_p)
			{
				login_status = 1;
				break;
			}
		}
	}
	cout<<"\nLogin was Successfull\n";

}
void credentials::logout()
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