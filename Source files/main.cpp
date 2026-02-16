#include "auth/AuthManager.h"
#include <iostream>

int main()
{
    AuthService auth;
    auth.registerUser("Abee", "Ayu", models::Role::Admin );

    auto userTesting = auth.loginUser("Abee", "Ayu" );

    if(userTesting!=nullptr)
    std::cout<<"Testing successfull";
    else
    std::cout<<"something failed";
}
