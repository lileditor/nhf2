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
    Player(const char* n){
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        hand = new Hand();
        balance = DEFAULT_BALANCE;
    }
    Player(const char* n, int b);

    char* getName() const { return name; }
    int getBalance() const { return balance; }

    Player& operator=(const Player& other);

    void freePlayer(Player* player);

    Hand* getHand() const { return hand; }

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
    Players(const char **names, int count) {
        players = new Player*[count];
        for (int i = 0; i < count; i++) {
            Player *player = new Player(names[i]);
            players++;
            *players[i] = *player;
        }
        size = count;
    }
    void CreatePlayer(const char* name);
    int GetSize() const { return size; }
    void addPlayer(Player* player) {
        players[size++] = player;
    }

    ~Players() {
        if (players == nullptr) return;
        /*for (int i = 0; i < size; i++) {
            if (players[i].getHand() != nullptr)
                //Player::freePlayer(&players[i]);
        }*/
        delete[] players;
    }

    Player& operator[](int index) {
        return *players[index];
    }
};

void CreateNewPlayer(Players &players);

#endif