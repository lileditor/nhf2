#include <iostream>
#include "StartMenu.hpp"

void StartMenu(Players &players) {
    int option = 0;
    std::cin >> option;
    std::cout << "Option: " << option << std::endl;
    switch (option)
    {
    case 0:
        std::cout << "Bye!" << std::endl;
        break;
    
    default:
        break;
    }
}