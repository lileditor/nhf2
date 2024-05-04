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
        break;
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
        std::cout << i << ". " << players[i].getName() << " " << players[i].getBalance() << std::endl;
    }
    std::string op;
    std::cin >> op;
    try {
        int option = std::stoi(op);
        if (option >= 0 && option < players.GetSize() && players[option].getBalance() > 0) {
            GameMenu(players, players[option]);
        } else {
            std::cout << "Invalid option or not enough money" << std::endl;
            ChoosePlayer(players);
        }
    } catch (...) {
        std::cout << "Invalid option" << std::endl;
        ChoosePlayer(players);
    }
}

void GameMenu(Players &players, Player &player) {
    std::cout << player.getName() << " balance: " << player.getBalance() << std::endl;
    std::cout << "Q - Quit" << " " << "B - Bet" << " " << "P - Hold"<< std::endl;
    saveFile(players, "state.txt");
    /*
        TODO
        Pack
        Sorting
        Hands management
        Printing
    */
}