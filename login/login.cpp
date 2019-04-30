#include<iostream>
#include<fstream>
using namespace std;
int login_flag;
class User
{
string user,pass;

public:
void get_input()
{
    cout<<"enter user-id!\n";
    cin>>user;
    cout<<"Enter password\n";
    cin>>pass;
}
string retuser()
{
    return user;
}
string retpass()
{
    return pass;
}
void write_cred()
{
    ofstream f1;
    f1.open("login/users_db.dat",ios::binary|ios::app);
    (*this).get_input();
    f1.write((char*)this,sizeof(this));
    f1.close();
}
int authenticate();
void print_data();
void output();
};
int User::authenticate()
{
    ifstream f1;
    string temp_u,temp_p;
    cout<<"Enter user id\n";
    cin>>temp_u;
    cout<<"Enter password\n";
    cin>>temp_p;
    f1.open("login/login.cpp",ios::binary);
    while(f1.read((char*)this,sizeof(this)))
    {
        if(this->retuser() == temp_u)
        {
            if(this->retpass() == temp_p)
            {
                login_flag=1;
            }
            else
            {
               login_flag = 0;
            }
        }
    }
    f1.close();
return login_flag;
}

void User::output()
{
    cout<<"\nUser id - "<<user;
    cout<<"\npass \n -"<<pass;
}
void User::print_data()
{
    ifstream f1;
    User b;
    f1.open("login/login.cpp",ios::binary);
    while(f1.read((char*)&b,sizeof(b)))
    {
        b.output();
    }
    f1.close();
}
