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

		//Extras vars
		int hloan = 0;
		int edloan = 0;
		int fd= 0;
		int insurance = 0;
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

		// Extras fn

		int rethloan()
		{
		    return hloan;
		}
		int sethloan(int a)
		{
		    hloan = a;
		}
		int retedloan()
		{
		    return edloan;
		}
		int setedloan(int a)
		{
		    edloan = a;
		}
		int retfd()
		{
		    return fd;
		}
		int setfd(int a)
		{
		    fd = a;
		}int retinsurance()
		{
		    return insurance;
		}
		int setinsurance(int a)
		{
		    insurance = a;
		}
		string ret_name()
		{
		    return cname;
		}
		int exist(long);
		void subinput();
		void suboutput();
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
void hloan_view()
{
    cout<<"\n \n -- ABOUT HOME LOAN -- \n \n";
    cout<<"-- Features\n";
    cout<<"* Low Interest rates\n* Low Processing Fees\n* No Hidden Charges\n * Repayment up to 30 yrs\n\n";
    cout<<"\n-- Eligibility\n";
    cout<<"* Indian Resident\n* Min age: 18 yrs\n * Max Age: 70yrs\n";
    cout<<"\nInterest rate: 15% p.a \n\n";
}
void insurance_view()
{
    cout<<"\n\n -- ABOUT INSURANCE SCHEME \n";
    cout<<"\n -- FEATURES\n";
    cout<<"Security – to ensure your family is financially protected\n";
    cout<<"Flexibility – Choose between two benefit structures and two rider options\n";
    cout<<"Affordability – through reasonable premiums\n";
    cout<<"\n\n -- Benefits\n";
    cout<<"\n In case of Death - 105% of all the premiums paid as on date of death\n";
    cout<<"\n Maturity Benefit is there in this Scheme\n";
}
void edloan_view()
{
    cout<<"\n\n -- ABOUT EDUCATION LOAN --\n\n";
    cout<<" A term loan granted to Indian Nationals for pursuing higher education in India or abroad where admission has been secured.";
    cout<<"\n -- Eligibility \n";
    cout<<"* Indian Citizens can apply only\n";
    cout<<"\n -- Security \n";
    cout<<" * Upto 7.5L -  Only Parent/ Guardian as co-borrower. No Collateral Security or third party guarantee\n";
    cout<<" * Above 7.5L -   Parent/ Guardian as co-borrower and tangible collateral security\n";
    cout<<"\n -- Repayment\n";
    cout<<" * Repayment will commence one year after completion of course.\n";
    cout<<" * Loan to be repaid in 15 years after the commencement of repayment\n";
    cout<<"\n\n --- R.O.I\n";
    cout<<" * 11.25% p.a\n\n";
}
void fd_view()
{
    cout<<"\n\n-- About Fixed Deposit Scheme\n";
    cout<<"-- R.O.I \n";
    cout<<" * 7 days to 45 days - 5.75% p.a\n * 46 days to 179 days - 6.25% p.a\n";
    cout<<" * 180 days to 210 days - 6.40% p.a\n * above 211 days - 6.50% p.a\n";
    cout<<"\n\n Minimum Investment : Rs. 1000\n";
    cout<<"Tenure : 7days - 10 years\n";
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


	do{

        cout<<"\n Enter opening balance (more than 1500)\n";
        cin>>bal;

        }while(bal<1500);
	ac = account_number_generator();
    cout<<"do you want to opt services[0/1] \n";
    int q;
    cin>>q;
    if(q==1)
    {
        subinput();
    }
}
void accounts::subinput()
{
    int extras_choice = 0;
        system("cls");
        cout<<"\n\n ________________ Services ______________\n\n";

        cout<<" 1. Home Loan\n 2. Education Loan\n 3. FD\n 4. Insurance\n\n";
        cin>>extras_choice;
        if(extras_choice ==1)
        {

            hloan_view();
            cout<<"do you want to apply [0/1] \n";
            int choice;
            cin>>choice;
            if(choice==1)
            {
                sethloan(1);
            }
        }
        else if(extras_choice == 2)
        {
            edloan_view();
            cout<<"do you want to apply [0/1] \n";
            int choice;
            cin>>choice;
            if(choice==1)
            {
                setedloan(1);
            }
        }
        else if(extras_choice == 3)
        {
            fd_view();
            cout<<"do you want to apply [0/1] \n";
            int choice;
            cin>>choice;
            if(choice==1)
            {
                setfd(1);
            }
        }
        else if(extras_choice = 4)
        {
            insurance_view();
            cout<<"do you want to apply [0/1] \n";
            int choice;
            cin>>choice;
            if(choice==1)
            {
                setinsurance(1);
            }

        }
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
    suboutput();
}
void accounts::suboutput()
{
    cout<<endl;cout<<endl;
	cout<<"Home loan :";
	if(rethloan()==1)
            cout<<"Active\n";
    else
            cout<<"Not active\n";
            cout<<endl;cout<<endl;
    cout<<"Education loan :";
	if(retedloan()==1)
            cout<<"Active\n";
    else
            cout<<"Not active\n";
            cout<<endl;
            cout<<endl;
    cout<<"FD : ";
    if(retfd()==1)
            cout<<"Active\n";
    else
            cout<<"Not active\n";
    cout<<endl;cout<<endl;
            cout<<"Insurance :";
    if(retinsurance()==1)
            cout<<"Active\n";
    else
            cout<<"Not Active\n";
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
