#pragma once

#include<string>

namespace models 
{
    //defines user role
    enum class Role
    {
        Admin,
        User
    };

    class user
    {
        private:
        int id;
        std::string Username;
        std::string password;
        Role role;

        public:
        //consturctor
        user();
        user(int id , const std::string& username , const std::string& password , Role role);

        //getters
        int getId() const;
        std::string getUsername() const;
        std::string getPassword() const;
        Role getRole() const;

        //setters
        void setUsername(const std::string& username);
        void setPassword(const std::string& password);
        void setRole(Role role);

        //utility
        std::string roleToString() const;

        //convert obj to string for storing in file
        std::string serialize() const;

        //create user from string in file
        static user deserialize(const std::string& data);
    };
    
}
