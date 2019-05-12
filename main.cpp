#include"accounts.cpp"
#define delay(x) for(int i=0;i<x;i++);
int main()
{   int ch;
    int ch1;
    int flag_loop = 1;
	accounts a;
do{
    cout<<"----------- DASHBOARD -------------\n";
    cout<<"0. Exit\n1. Basic Account operation\n2. Extra Features\n";
    cin>>ch1;

    if(ch1==0)
    {   flag_loop = 0;
        exit(0);
    }
    else if(ch1==1)
    {   int flag_loop=0;

    system("cls");
        cout<<"\n\n ------------- BASIC ACCOUNT OPERATION --------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t TO go back press any key other than the option\n";
        cout<<"\n0. Exit\n1.Create ac\n2.Show all accounts\n3.Show account by Ac number\n4. Delete account\n";
        cin>>ch;
        switch(ch)
        {
        case 0:
                exit(0);
                break;
            case 1:
                    a.accounts_write();
                    break;
            case 2:
                    a.accounts_show_all();
                    break;
            case 3:
                    a.accounts_show();
                    break;
            case 4:
                    a.accounts_delete();
                    break;
        }
    }
    else if(ch1==2)
    {   flag_loop = 0;
    }
    else
    {   flag_loop = 1;
        cout<<"\nEnter valid choice\n";
    }
}while(flag_loop==1);
	return 0;
}
