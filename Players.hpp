#ifndef PLAYERS_HPP
#define PLAYERS_HPP
#define DEFAULT_BALANCE 5000
#include <cstring>
#include <iostream>

#include "Hands.hpp"
#include "memtrace.h"


/**
 * @brief 
 * Ez a játékos adatait tartalmazza.
 */
class Player {
    char* name = nullptr;
    int balance;
    Hand* hand = nullptr;
    public:
    Player();
    Player(const char* n);
    Player(const char* n, int b);

    char* getName() const { return name; }
    int getBalance() const { return balance; }
    void placeBet(int bet) { balance -= bet; }

    Player& operator=(const Player& other);

    void freePlayer();

    Hand* getHand() const { return hand; }

    void win(int bet);
    void lose(int bet);
    void draw(int bet);

    ~Player() {
        if (name == nullptr) return;
        delete[] name;
        delete hand;
        name = nullptr;
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
    void createPlayer(const char* name);
    int getSize() const { return size; }
    void addPlayer(Player* player) {
        players[size++] = player;
    }

    ~Players() {
        if (players == nullptr) return;
        for (int i = 0; i < size; i++) {
            delete players[i];
        }
        delete[] players;
        players = nullptr;
    }

    Player& operator[](int index) {
        return *players[index];
    }
};

/**
 * @brief Create a New Player object
 * Ez létrehoz egy uj játékost akinek a nevét stdin-ben adjuk meg.
 * @param players 
 */
void CreateNewPlayer(Players &players);

#endif