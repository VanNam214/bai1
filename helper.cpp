#include <iostream>
#include "helper.h"
using namespace std;


void Database(Account* users[5]){
    
    users[0]->name = "Nam";
    users[0]->email = "vannam@gmail.com";
    users[0]->password = "123456";
    users[0]->role = 0;
    
    users[1]->name = "Van Tong";
    users[1]->email = "vantong@gmail.com";
    users[1]->password = "123456";
    users[1]->role = 0;
    
    users[2]->name = "Quang MinhMinh";
    users[2]->email = "quangminh@gmail.com";
    users[2]->password = "123456";
    users[2]->role = 0;
    
    users[3]->name = "Ngoc Han";
    users[3]->email = "ngochan@gmail.com";
    users[3]->password = "123456";
    users[3]->role = 0;


    users[4]->name = "admin";
    users[4]->email = "admin@gmail.com";
    users[4]->password = "admin";
    users[4]->role = 1;

    
}

void print_error(int option,Error* err){

    switch(option){
        case 1:
            if(err->email_error == "" && err->name_error == "" && err->password_error == ""){
            
                cout << "Register is successful"<<endl;
            }else{
                if (err->email_error != ""){
                    cout << err->email_error;
                }else{
                    if(err->password_error != ""){
                        cout << err->password_error;
                    }
                }
            }
            break;
        case 2:
            if(err->email_error != "" && err->name_error != ""){
                cout << err->email_error;
            }else{

                if(err->password_error != ""){
                    cout << err->password_error;
                }
                else{
                    cout << "forgot is successful"<<endl;
                }
            }

            
            break;
        case 3:

            if(err->email_error != "" && err->password_error == ""){
                cout << err->email_error;
            }
            else if(err->password_error != ""){
                cout << err->password_error;
            }
            else{
                cout << "Login is successful"<<endl;
            }
            
            break;
    }

    
    


}
void view_list_account(Account* users[20],int position,int size){
    cout << "| Stt | "<<"Username |"<<" Email |"<<" Password |"<<endl;
    for(int i=0;i<size;i++){
        cout << "|"<< i<<"| "<<users[i]->name<<"|"<<users[i]->email<<" |"<<users[i]->password<<" |"<<endl;
    }
}
void add_user(Account* account,Account* users[20],int currentSize){

    for (int i = currentSize; i > 0; --i) {
        users[i] = users[i - 1];  
    }
    users[0]->name = account->name;
    users[0]->email = account->email;
    users[0]->password = account->password;
    users[0]->role = 0;
    currentSize++;  

    view_list_account(users,1,currentSize);
}
void verify__create_user(Account* account,Account* users[5],Error* err,int size){
    int option = 1;
    bool check = false;
    for(int i=0;i<5;i++){
        if (account->email.find("@gmail.com") != string::npos ){
           if (account->email == users[i]->email){
                err->email_error = "Email exitst";
            }else{
                if(account->password.length() < 8){
                    err->password_error = "Password must be longer than 8 characters";
                }else{
                    for(char pass:account->password){
                        if(!isupper(pass) && !islower(pass) && !isdigit(pass) && isalnum(pass)){
                            err->password_error = "Password must be contains uppercase character,lower character,digit character and special charater!!!";
                        }else{
                            check = true;
                        }
                    }
                }
            }       
        }else{
            err->email_error = "Email must be contains @gmail.com";
        }    
            
    }
    print_error(option,err);


    if(check == true){
        add_user(account,users,size);
    }

}

void create_account(Account* account,Account* users[5],Error* err,int size){
    
    // account = new Account;
    cout << "Enter email: ";
    cin >> account->email;
    cout << "Enter username: ";
    cin >> account->name;
    cout << "Enter password: ";
    cin >> account->password;
    
    verify__create_user(account,users,err,size);
    
}

void verify__forgot_password(Account* account,Account* users[5],Error* err){

    string password_confirm = "";
    string new_password = "";
    bool check = false;
    int option = 2;
    int position = 0;
    for(int i=0;i<5;i++){
        if(account->email != users[i]->email || account->name != users[i]->name){
            err->email_error = "Email and username do not exists";
            err->name_error = "Email and username do not exists";
            check = false;
        }else{
            check = true;
            break;
        }
        position++;
    }

    if(check == true){
        cout << "Enter new password: ";
        cin >> new_password;
        cout << "Confirm new password: ";
        cin >> password_confirm;

        if (password_confirm != new_password){
            err->password_error = "Password confirm is incorrect";
        }else{

            users[position]->password = new_password;
            cout << users[position]->password;

        }
    }
    print_error(option,err);



}
void forgot_password(Account* account,Account* users[5],Error* err){

    cout << "Enter email: ";
    cin >> account->email;
    cout << "Enter username: ";
    cin >> account->name;

    verify__forgot_password(account,users,err);
    
    

   
}
void  notice_login_success(Account* users[5],int position){

    cout << "Hello, "<< users[position]->name<<endl;

}

void delete_list_account(Account* account,Account* users[5],int position,int size){
    int pos = 0;



    cout << "Enter email: ";
    cin >> account->email;
    cout << "Enter username: ";
    cin >> account->name;

    for(int i=0;i<5;i++){
        if(account->email == users[i]->email && account->name == users[i]->name){
            for(int j=i;i<5;++i){
                users[i] = users[i+1];
            }
            --size;
           
           
        }else{
            cout << "Account do not exists";
        }
    }
    view_list_account(users,position,size);
    


}

void Login(Account* account,Account* users[5],Error* err,int size){
    
    int run = 0;
    int option = 3;
    bool check = true;
    int position = 0;


    do{

        if(check != true){
            cout << endl;
            cout << "Please, Re-enter!!!!"<<endl; 
        }

        cout << "Enter email: ";
        cin >> account->email;
        cout << "Enter password: ";
        cin >> account->password;
        



        for(int i=0;i<size;i++){


            if(account->email == users[i]->email && account->password == users[i]->password){
                err->email_error.clear();
                err->password_error.clear();
                check = true;
                break;
            }else{
                if(account->email == users[i]->email){
                    if(account->password == users[i]->password){
                        err->email_error.clear();
                        err->password_error.clear();
                        check = true;
                        break;
                    }else{
                        err->password_error = "Password is incorrect";
                        err->email_error.clear();
                        check = false;
                    }
                }else{
                    err->email_error = "Email or password is incorrect";
                    err->password_error.clear();
                    check = false;
                }
            }
            position++;
        }
        print_error(option,err);
        if(check == true){
            if(users[position]->role == 1){
                int option_item = 0;
                cout<<"==========ADMIN=========="<<endl;
                cout << "1.View list account"<<endl;
                cout << "2.View delete account"<<endl;
                cout<<"========================"<<endl;
                cout<<"Choose an option: ";
                cin >> option_item;


                switch (option_item)
                {
                case 1:
                    view_list_account(users,position,size);
                    break;
                case 2:
                    delete_list_account(account,users,position,size);
                    break;
                default:
                    view_list_account(users,position,size);
                    break;
                }
                
                
            }else{
                notice_login_success(users,position);
            }
           
        }

        
        run++;

    }while(run < 3 && check != true);


    
    
}