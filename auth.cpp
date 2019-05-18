#include<fstream>
#include<iostream>
using namespace std;
class user
{
protected:
    long username,password;
public:
    void get_auth()
    {
        cout<<"\n Enter Username\n";
        cin>>username;
        fflush(stdin);
        cout<<"\n Enter password\n";
        cin>>password;
    }
    void cauth();
    int login();
    long ret_username()
    {
        return username;
    }
    long ret_password()
    {
        return password;
    }
};
int login_status=0;
long active_ac=0;
void user::cauth()
{
    user u;
    ofstream f1;
        f1.open("users_db.dat",ios::binary);
        u.get_auth();
    f1.write((char*)&u,sizeof(u));
    cout<<"\nSign Up successfully!\n";
    f1.close();
}
int user::login()
{   user u;
    long temp_u,temp_p;
    cout<<"\n Enter Username\n";
    cin>>temp_u;
    fflush(stdin);
    ifstream f1;
    f1.open("users_db.dat",ios::binary);
    while(f1.read((char*)&u,sizeof(u)))
    {
        if(u.ret_username()==temp_u)
        {
            cout<<"Enter password\n";
                cin>>temp_p;
            if(u.ret_password()==temp_p)
            {
              login_status = 1;
                return 1;
            }
            else
                {
                    return 0;
                }
        }
        else
        {
            return 0;
        }
    }
    f1.close();

}
