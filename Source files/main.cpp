#include "auth/AuthManager.h"
#include <iostream>

int main()
{
    AuthService auth;

    int choice;
    std::cout << "Enter choice :\n 1.Register\n 2.Login\n 3.Exit\n"
              << std::endl;
    std::cin >> choice;
    std::string username, password;
    while (1)
    {
        
        if (choice == 1)
        {
            std::cout << "Enter Username:" << std::endl;
            std::cin >> username;

            std::cout << "Enter Password:" << std::endl;
            std::cin >> password;

            if (auth.registerUser(username, password))
                std::cout << "Registration successful.\n";
            else
                std::cout << "User already exists.\n";
        }
        else if (choice == 2)
        {
            std::cout << "Enter Username:" << std::endl;
            std::cin >> username;

            std::cout << "Enter Password:" << std::endl;
            std::cin >> password;

            auto user = auth.loginUser(username, password);
            if (user != nullptr)
            {
                std::cout << "Login successful.\n";
                break;
            }
            else
                std::cout << "Login failed.\n";
        }
        else if (choice == 3)
            return 0;
    }

    return 0;
}
