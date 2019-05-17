#include<iostream>
#include<fstream>
#include<time.h>
#include<limits.h>
#include<cstdlib>
#include<cstdio>
using namespace std;
class accounts
{
	protected:
		string cname,pno,nat;
		float bal=0;
		int atype;
		bool visibility = 1;
		long ac;
	public:
		void accounts_input();
		void accounts_output();
		void dep(float);
		void withd();
		void accounts_write();
		void accounts_show_all();
		void accounts_read();
		void accounts_show();
		long retac()
		{
			return ac;
		}
		void accounts_delete();
		string ret_name()
		{
		    return cname;
		}
		int exist(long);
};

int accounts::exist(long temp_ac)
{
    ifstream f1;
    accounts a;
    f1.open("accounts_db.dat",ios::binary);
    while(f1.read((char*)&a,sizeof(a)))
    {
        if(a.retac()==temp_ac)
            return 1;
    }
    return 0;
}

void accounts::accounts_delete()
{
    accounts a;
    long temp_ac;
    system("cls");
    cout<<"\nEnter account number to delete\n";
    cin>>temp_ac;
    ifstream f1;
    ofstream f2;
    bool found = 0;
    f1.open("accounts_db.dat",ios::binary);
    f2.open("acc_temp.dat",ios::binary|ios::app);
   /* while(f1.read((char*)&a,sizeof(a)))
    {
        if(a.retac()==temp_ac)
            found = 1;
    }*/
   if(exist(temp_ac)==1)
    {

     while(f1.read((char*)&a,sizeof(a)))
        {
            if(a.retac()!=temp_ac)
            {
                f2.write((char*)&a,sizeof(a));
            }

        }
        f1.close();
        f2.close();
        char a[] = "accounts_db.dat";
        string b = "acc_temp.dat";
        remove(a);
        rename(b.c_str(),a);

        cout<<"\nDeleted Successfully!\n";

   }
    else
        cout<<"\n No account found with this account number\n";

}

void accounts::accounts_show_all()
{
	accounts a;
	ifstream f1;
	f1.open("accounts_db.dat",ios::binary);
	while(f1.read((char*)&a,sizeof(a)))
	{
		a.accounts_output();
	}
	f1.close();
}
long account_number_generator()
{
	srand(time(0));
	return(rand()%LONG_MAX);
}
void accounts::accounts_input()
{
	cout<<"\n Enter name of the customer\n";
	cin>>cname;
	fflush(stdin);
	cout<<"\n Enter phone no. of the customer\n";
	cin>>pno;
	fflush(stdin);
	cout<<"\n Enter nationality of the customer\n";
	cin>>nat;
	fflush(stdin);
        bool flag_loop_out=0;

        cout<<"\n Enter account type - 1. Savings \t 2. Current\n";
        cin>>atype;
             /*   if(atype==1||atype==2)
                {
                    flag_loop_out=1;
                    system("cls");
                    cout<<"\nEnter valid account type\n";
                    system("pause");
                }
        }while(flag_loop_out = 0);*/



	do{

        cout<<"\n Enter opening balance (more than 1500)\n";
        cin>>bal;

        }while(bal<1500);
	ac = account_number_generator();

}
void accounts::accounts_output()
{
	cout<<"\n----- CUSTOMER DETAILS ------\n";
	cout<<"Name: "<<this->ret_name()<<endl;
	cout<<"phone: "<<pno<<endl;
	cout<<"Nationality: "<<nat<<endl;
	cout<<"Account Type: ";
	atype==1?cout<<"Savings"<<endl:cout<<"Current"<<endl;
	cout<<"Current balance: "<<bal<<endl;
	cout<<"Account number : "<<this->retac()<<endl;
}
void accounts::dep(float deposit_var)
{
	if(deposit_var<=0)
		bal+=deposit_var;
	else
		{
			cout<<"Invalid amount input\n";
		}
}
void accounts::withd()
{
		float temp_withd;
		do{
		cout<<"Enter amount to withdraw (less than or equal to current balance)\n";
		cin>>temp_withd;

		}while(temp_withd<=bal);
		bal-=temp_withd;
}
void accounts::accounts_write()
{

accounts b;

ofstream f1;

f1.open("accounts_db.dat",ios::binary|ios::app);

char ch;

do{

	cout<<"\nEnter The Data Correctly -\n";

	b.accounts_input();

	f1.write((char*)&b,sizeof(b));

	cout<<"\n\nRecord Successfully Entered\n";

	cout<<"\nEnter Y to enter & N to exit\n";

	cin>>ch;

}while(ch=='y'||ch=='Y');

	f1.close();

}
void accounts::accounts_show()
{
    cout<<"Enter account number\n";
    long temp_ac;
    cin>>temp_ac;
    accounts a;
	ifstream f1;
	bool flag =0;
	f1.open("accounts_db.dat",ios::binary);
	while(f1.read((char*)&a,sizeof(a)))
	{
		if(temp_ac == a.retac())
		{
			a.accounts_output();
			flag =1;
		}
	}
	if(!flag)
	{
		cout<<"No account with this account number found\n";
	}
}
