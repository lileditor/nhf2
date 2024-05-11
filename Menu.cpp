#include "Menu.hpp"
#include "FileHandler.hpp"
#include "MainGame.hpp"
#include "Players.hpp"
#include <iostream>

void StartMenu(Players &players) {
  std::cout << "0. Exit" << std::endl << "1. Players" << std::endl;
  int option = 0;
  std::cin >> option;
  std::cout << "Option: " << option << std::endl;
  switch (option) {
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
  std::cout << "0. Create player" << std::endl
            << "1. Choose player" << std::endl
            << "2. Back" << std::endl;
  int option = 0;
  std::cin >> option;
  switch (option) {
  case 0:
    CreateNewPlayer(players);
    PlayersMenu(players);
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
  for (int i = 0; i < players.getSize(); i++) {
    std::cout << i << ". " << players[i].getName() << " " << players[i].getBalance() << std::endl;
  }
  std::string op;
  std::cin >> op;
  int option = std::stoi(op) ? std::stoi(op) : -1;
  if (option >= 0 && option < players.getSize() && players[option].getBalance() > 0) {
    GameMenu(players, players[option]);
    return;
  } else {
    std::cout << "Invalid option or not enough money" << std::endl;
    ChoosePlayer(players);
    return;
  }
}
