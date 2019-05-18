#include"menu.cpp"

int main()
{
    user u;

    cout<<"\t\t\t _______________LOGIN MODULE _________________\n\n";
    int ch;
    cout<<"\n\n1. Register\n2. Login\n";
    cin>>ch;
    if(ch==1)
    {
        u.cauth();
        main();
    }
    else if(ch==2)
    {
        if(u.login()==1)
        {
            system("cls");
            menu();
        }
        else
        {
            cout<<"Wrong password or Username entered\n";
            main();
        }
    }
    else
    {
        cout<<"\n\n Enter valid choice\n";
        main();
    }
    return 0;
}
