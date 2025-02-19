#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>

struct Account{
public:
    std::string name;
    std::string email;
    std::string password;
    int role;

   
    
};
struct Error{
    std::string name_error;
    std::string email_error;
    std::string password_error;
};


void Database(Account* users[5]);
void create_account(Account* account,Account* users[5],Error* err,int size);
void forgot_password(Account* account,Account* users[5],Error* err);
void Login(Account* account,Account* users[5],Error* err,int size);

#endif // FUNCTIONS_H
