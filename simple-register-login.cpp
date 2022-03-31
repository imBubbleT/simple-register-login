#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void create();
void login();

string user;
string pass;

string luser;
string lpass;

ofstream wdata;
ifstream rdata;

string menuSelect;


int main()
{
	do{
		cout << "Type your selection(create/login/exit): ";
		getline(cin, menuSelect);


		if(menuSelect == "create"){
			create();
		}
		else if(menuSelect == "login"){
			login();
		}
		else if(menuSelect == "exit"){
			cout << "Exiting session...\n\n";
		}
		else{
			cout << "Invalid selection\n\n";
		}
	}
	while(menuSelect != "exit");
    return 0;
}

// Create a username and password session
void create()
{
	wdata.open("Data.txt");

    cout << "Create username: ";
	getline(cin, user);

    wdata << user << endl;

    cout << "Create password: ";
    getline(cin, pass);

    wdata << pass << endl;

    wdata.close();

    cout << "Username and password created!\n\n";
}

// Login session
void login()
{
    rdata.open("Data.txt");

    cout << "Enter username: ";
    getline(cin, luser);

    cout << "Enter password: ";
    getline(cin, lpass);

    rdata >> user;
    rdata >> pass;

    rdata.close();


    if((user == luser) && (pass == lpass)){
		cout << "Login succesful!\n\n";
    }else{
		cout << "Invalid username or password...\n\n";
    }

}
