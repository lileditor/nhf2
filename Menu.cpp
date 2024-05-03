#include <iostream>
#include "Players.hpp"
#include "Menu.hpp"
#include "FileHandler.hpp"

void StartMenu(Players &players) {
    std::cout << "0. Exit" << std::endl << "1. Players" << std::endl;
    int option = 0;
    std::cin >> option;
    std::cout << "Option: " << option << std::endl;
    switch (option)
    {
    case 0:
        std::cout << "Bye!" << std::endl;
        saveFile(players, "state.txt");
        break;
    case 1:
        PlayersMenu(players);
    default:
        std::cout << "Not an option" << std::endl;
        break;
    }
}

void PlayersMenu(Players &players) {
    std::cout << "0. Create player" << std::endl << "1. Choose player" << std::endl << "2. Back" << std::endl;
    int option = 0;
    std::cin >> option;
    switch (option) {
        case 0:
            CreateNewPlayer(players);
            break;
        case 1:
            ChoosePlayer(players);
            break;
        case 2:
            StartMenu(players);
            break;
        default:
            std::cout << "Not an option" << std::endl;
            break;
    }
}

void ChoosePlayer(Players &players) {
    std::cout << "Choose player: " << std::endl;
    for (int i = 0; i < players.GetSize(); i++) {
        std::cout << i << ". " << players[i].getName() << std::endl;
    }
    int option = 0;
    std::cin >> option;
    if (option >= 0 && option < players.GetSize()) {
        GameMenu(players[option]);
    }
}

void GameMenu(Player &player) {
    std::cout << "0. Back" << std::endl;
    /*
        TODO
        Pack
        Sorting
        Hands management
        Printing
    */
}