#include"include\auth\AuthManager.h"
#include<fstream>
#include<iostream>
#include<sstream>

void AuthService::loadUsers()
{
    std::ifstream file("data/users.db");

    if(!file.is_open())
    return;

    std::string line;
    while(std::getline(file , line))
    {
        std::stringstream ss(line);
        std::string idStr , username , password , roleStr;

        std::getline(ss,idStr,',' );
        std::getline(ss,username,',' );
        std::getline(ss,password,',' );
        std::getline(ss,roleStr,',' );

        int id = std::stoi(idStr);
        models::Role role = (roleStr == "Admin") ? models::Role::Admin : models::Role::User ;

        Users.emplace_back(id , username , password , role);
    }

    file.close();
}

AuthService::AuthService()
{
    loadUsers();
}