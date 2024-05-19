#include "Players.hpp"
#include "Menu.hpp"
#include <iostream>

Player::Player() {
    name = new char[8];
    strcpy(name, "Default");
    hand = new Hand();
    balance = DEFAULT_BALANCE;
}

Player::Player(const char* n, int b) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    hand = new Hand();
    balance = b;
}

Player::Player(const char* n) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    hand = new Hand();
    balance = DEFAULT_BALANCE;
}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        delete[] name;
        delete hand;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        hand = other.hand;
        balance = other.balance;
    }
    return *this;
}

void Player::win(int bet) {
    std::cout << "Player " << name << " won " << bet << "!" << std::endl;
    balance += 2 * bet;
}

void Player::lose(int bet) {
    std::cout << "Player " << name << " lost " << bet << "!" << std::endl;
}

void Player::draw(int bet) {
    std::cout << "Player " << name << " played draw " << bet << "!" << std::endl;
    balance += bet;
}

void Players::createPlayer(const char* name) {
    Player *player = new Player(name);
    size++;
    players[size - 1] = player;
    std::cout << "Player created!" << std::endl;
}

Players::Players(const char **names, int count) {
    players = new Player*[count];
    for (int i = 0; i < count; i++) {
        Player *player = new Player(names[i]);
        players++;
        *players[i] = *player;
    }
    size = count;
}

Players::Players()  {
    players = new Player*[35];
    size = 0;
}

void CreateNewPlayer(Players &players) {
    std::cout << "Enter player name: ";
    std::string name;
    std::cin >> name;
    players.createPlayer(name.c_str());
}