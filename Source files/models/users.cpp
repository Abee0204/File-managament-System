#include"models/User.h"
#include<sstream>

namespace models
{
    //constructor
    user::user()
    {
        id = 0;
        Username = "";
        password = "";
        role = Role::User;
    };
    user::user(int id, const std::string& username,const std::string& password, Role role)
    {
        this->id = id;
        this->Username = username;
        this->password = password;
        this->role = role;
    }

    //getters
    int user::getId() const
    {
        return id;
    }
    std::string user::getUsername() const
    {
        return Username;
    }
    std::string user::getPassword() const
    {
        return password;
    }
    Role user::getRole() const
    {
        return role;
    }

    //setters
    void user::setUsername(const std::string& username)
    {
        this->Username = username ;
    }
    void user::setPassword(const std::string& password)
    {
        this->password = password ;
    }
    void user::setRole(Role role)
    {
        this->role = role ;
    }

    //utility
    std::string user::roleToString() const
    {
        return (role == Role::Admin) ? "Admin" : "User";
    }

    //converting user obj to string 
    std::string user::serialize() const
    {
        std::ostringstream oss;
        oss << id << "," << Username <<"," <<password <<","<< roleToString();
        return oss.str();
    }

    //converting string back to user obj
    user user::deserialize(const std::string& data)
    {
        std::istringstream iss(data);
        std::string token;

        int id;
        std::string Username, password , roleStr;

        std::getline(iss, token, ',');
        id = std::stoi(token);

        std::getline(iss, Username , ',');
        std::getline(iss, password , ',');
        std::getline(iss, roleStr , ',');

        Role role = (roleStr == "Admin") ? Role::Admin : Role::User;

        return user(id, Username, password , role);
    }
}