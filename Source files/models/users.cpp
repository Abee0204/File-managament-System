#include<models/User.h>
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
}