#include <iostream>
#include <string>

using namespace std;

string username;
string password;

string login;
string passCheck;

string lineBuffer;

int loginAttempt = 0;
int i = loginAttempt;

void loginSession();

int main()
{
    cout << "Create a username: ";
    getline(cin, username);
    cout << "Create a password: ";
    getline(cin, password);

    loginSession();

    if(i >= 5){
        cout << "Too many login attempts...\n";
    }

    return 0;
}

void loginSession()
{
    do
    {
        system("cls");

        cout << "Enter username: ";
      //  cin >> login;
        getline(cin, login);
        cout << "Enter password: ";
        //cin >> passCheck;
        getline(cin, passCheck);

        i++;

        if(username != login || password != passCheck){
            cout << "\nIncorrect username or password...\n";
        }
        if((username == login) && (password == passCheck)){
            cout << "\nLogin successful...\n";
        }
        getline(cin, lineBuffer); //Curent solution to avoid Username be skipped at certain occasion
    }
    while((username != login || password != passCheck) && i < 5);

}

