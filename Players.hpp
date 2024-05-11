#ifndef PLAYERS_HPP
#define PLAYERS_HPP
#define DEFAULT_BALANCE 5000
#include <cstring>
#include <iostream>

#include "Hands.hpp"

/**
 * @brief 
 * Ez a játékos adatait tartalmazza.
 */
class Player {
    char* name = nullptr;
    int balance;
    Hand* hand = nullptr;
    public:
    Player(const char* n);
    Player(const char* n, int b);

    char* getName() const { return name; }
    int getBalance() const { return balance; }
    void placeBet(int bet) { balance -= bet; }

    Player& operator=(const Player& other);

    void freePlayer(Player* player);

    Hand* getHand() const { return hand; }

    void win(int bet);
    void lose(int bet);
    void draw(int bet);

    ~Player() {
        if (name != nullptr) {
            delete[] name;
            delete hand;
        }
    }
};

/**
 * @brief 
 * Ez az összes játékost kezeli és ebbe történik a beolvasás. 
 */
class Players {
    Player** players = nullptr;
    int size;
    public:
    Players();
    Players(const char **names, int count);
    void CreatePlayer(const char* name);
    int GetSize() const { return size; }
    void addPlayer(Player* player) {
        players[size++] = player;
    }

    ~Players() {
        for (int i = 0; i < size; i++) {
            players[i]->freePlayer();
        }
        delete[] players;
    }

    Player& operator[](int index) {
        return *players[index];
    }
};

void CreateNewPlayer(Players &players);

#endif