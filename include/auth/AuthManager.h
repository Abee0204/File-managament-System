#pragma once

#include<vector>
#include<string>
#include"models\User.h"

class AuthService
{
    private:
    std::vector <models::user> Users; //store all users
    void loadUsers();
    void saveUser(const models::user& user);
    bool userExists(const std::string& username);

    public:
    AuthService(); //constructor
    //register user
    bool registerUser(const std::string& username ,const std::string& password , models::Role role);
    //login 
    models::user loginUser(const std::string& username , const std::string& password);

};