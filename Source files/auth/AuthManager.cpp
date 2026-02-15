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

/*
void AuthService::saveUser(const models::user& user)
{
    std::ofstream file("data/users.db" , std::ios::app);

    if(!file.is_open()) return;

    file << user.getId() <<","<<user.getUsername() <<","<<user.getPassword() <<","<<(user.getRole() == models::Role::Admin ? "Admin" : "User")<< "\n";
    file.close();
}
*/

void AuthService::saveUsers()
{
    std::ofstream file("data/users.db");

    if(!file.is_open()) return;

    for(const auto& user: Users)
    {
        file << user.getId() <<","<<user.getUsername() <<","<<user.getPassword() <<","<<(user.getRole() == models::Role::Admin ? "Admin" : "User")<< "\n";
    }
    file.close();
}

bool AuthService::userExists(const std::string& username) const
{
    for(const auto& user : Users)
    {
        if(user.getUsername() == username)
        return true;
    }

    return false;
}

bool AuthService::registerUser(const std::string& username , const std::string& password , models::Role role)
{
    if(userExists(username)) return false;

    // models::user newUser;
    // newUser.setUsername(username);
    // newUser.setPassword(password);
    // newUser.setRole(role);

    int newID = Users.size()+1;

    models::user newUser(newID , username , password , role);
    
    Users.push_back(newUser);

    saveUsers();
    return true;
}

models::user* AuthService::loginUser(const std::string& username , const std::string& password)
{
    for(auto& user :Users)
    {
        if(user.getUsername() == username && user.getPassword() == password)
        return &user;

        return nullptr;
    }
}

AuthService::AuthService()
{
    loadUsers();
}