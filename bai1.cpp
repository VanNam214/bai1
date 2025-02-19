#include <iostream>
#include <string>
#include "helper.h"
using namespace std;



int main()
{
    int option;
    int size = 20;
    int currentSize = 5;
    Account* users[size];
    Account* acc = new Account;
    Error* error = new Error;
    for (int i = 0; i < size; i++) {
        users[i] = new Account;  // Cấp phát bộ nhớ cho từng Account
    }
    Database(users);
    
    
    cout << "=============Chon Menu=================="<<endl;
    cout << "1.Create account"<<endl;
    cout << "2.Forgot password"<<endl;
    cout << "3.Login"<<endl;
    cout << "==============================="<<endl;
    cout <<"Choose an option: ";
    cin >> option;
    
    switch(option){
        case 1:
            create_account(acc,users,error,currentSize);
            break;
        case 2:
            forgot_password(acc,users,error);
            break;
        case 3:
            Login(acc,users,error,currentSize);
            break;
        
    }
    
    

    return 0;
}