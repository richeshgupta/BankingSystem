#include<iostream>
#include<fstream>
using namespace std;
class account
{
	string user_name,address,nationality;
	double bal=0;
	int account_type,user_age;
	int pno[12];
public:
	void acc_input();
	void acc_output();
	void create_acc();
	void show_acc_all();
	void del_acc();
	void withdraw();
	void deposit();
	void search();
};
void account::acc_input()
{
	cout<<"\nEnter Customer's Name\n";
	cin>>user_name;
	cout<<"\nEnter Customer's Age\n";
	cin>>user_age;
	cout<<"\nEnter Customer's nationality \n";
	cin>>nationality;
	cout<<"\nEnter Customer's address \n";
	cin>>address;
}
void account::acc_output()
{
	cout<<"Name :"<<user_name<<endl;
	cout<<"Age :"<<user_age<<endl;
	cout<<"Nationality :"<<nationality<<endl;
	cout<<"Address :"<<address<<endl;
}
void account::create_acc()
{
	ofstream f1;
	f1.open("accounts_db.dat",ios::binary|ios::app);
	account b;
	b.acc_input();
	f1.write((char*)&b,sizeof(b));
	cout<<"\n Account Created!\n";
	f1.close();
}
void account::show_acc_all()
{
	account b;
	ifstream f1;
	f1.open("accounts_db.dat",ios::binary);
	cout<<"\n Displaying all of the accounts in the database\n";
	while(f1.read((char*)&b,sizeof(b)))
	{
		b.acc_output();
	}
	f1.close();
}
void account_menu()
{
	cout<<"------------- Account ----------\n";
	cout<<"1. Create Account\n2. Show Account\n3.Delete Account\n4. Deposit\n5. Withdraw\n6. Search Account\n7. Show all accounts\n";
	int ch;
	cin<<ch;
	if(ch==1)
	{
		this->create_acc();
	}
	else if(ch==2)
	{
		
	}
	else if(ch==3)
	{
		this->del_acc();
	}
	else if(ch==4)
	{
		this->deposit();
	}
	else if(ch==5)
	{
		this->withdraw();
	}
	else if(ch==6)
	{
		this->search();
	}
	else if(ch==7)
	{
		this->show_acc_all();
	}
	else
	{
		cout<<"\n Please enter from the given choices\n";
	}
}