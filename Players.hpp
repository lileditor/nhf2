#ifndef PLAYERS_HPP
#define PLAYERS_HPP
#define DEFAULT_BALANCE 5000
#include <cstring>

#include "Hands.hpp"

/**
 * @brief 
 * Ez a játékos adatait tartalmazza.
 */
class Player {
    char* name = nullptr;
    int balance;
    Hand* hand;
    public:
    Player(const char* name) {
        name = new char[strlen(name) + 1];
        hand = new Hand();
        balance = DEFAULT_BALANCE;
    }

    Player& operator=(const Player& other) {
        if (this != &other) {
            delete[] name;
            delete hand;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            balance = other.balance;
            hand = other.hand;
        }
        return *this;
    }

    ~Player() {
        if (name != nullptr)
            delete[] name;
    }
};

/**
 * @brief 
 * Ez az összes játékost kezeli és ebbe történik a beolvasás. 
 */
class Players {
    Player* players = nullptr;
    int size;
    public:
    Players() {
        players = new Player("Default");
        size = 0;
    }
    Players(const char **names, int count) {
        for (int i = 0; i < count; i++) {
            players = new Player(names[i]);
            players++;
        }
        size = count;
    }

    void CreatePlayer(const char* name);

    ~Players() {
        if (players != nullptr)
            delete[] players;
    }
};


#endif