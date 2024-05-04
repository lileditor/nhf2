#include "Players.hpp"
#include "Menu.hpp"
#include <iostream>

void Player::freePlayer(Player* player) {
    delete[] player->name;
    delete player->hand;
}

Player::Player(const char* n, int b) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    hand = new Hand();
    balance = b;
}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        delete name;
        delete hand;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        hand = other.hand;
        balance = other.balance;
    }
    return *this;
}

void Players::CreatePlayer(const char* name) {
    Player *player = new Player(name);
    size++;
    players[size - 1] = player;
    std::cout << "Player created!" << std::endl;
}

Players::Players()  {
    players = new Player*[35];
    size = 0;
}

void CreateNewPlayer(Players &players) {
    std::cout << "Enter player name: ";
    std::string name;
    std::cin >> name;
    players.CreatePlayer(name.c_str());
    PlayersMenu(players);
}