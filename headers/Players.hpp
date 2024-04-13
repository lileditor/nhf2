#ifndef PLAYERS_HPP
#define PLAYERS_HPP
#define DEFAULT_BALANCE 5000
#include <cstring>

class Player {
    char* name;
    int balance;
    public:
    Player(const char* name) {
        name = new char[strlen(name) + 1];
        balance = DEFAULT_BALANCE;
    }

    Player& operator=(const Player& other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            balance = other.balance;
        }
        return *this;
    }

    ~Player() {
        delete[] name;
    }
};

class Players {
    Player* players;
    int size;
    public:
    Players() {
        players = new Player[0];
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
        delete[] players;
    }
};


#endif