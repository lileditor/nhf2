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

    ~Player() {
        delete[] name;
    }
}

class Players {
    Player* players;
    int size;
    public:
    Players(int count) {
        players = new Player[count];
        size = count;
    }

    void CreatePlayer(const char* name);

    ~Players() {
        for (int i = 0; i < size; i++) {
            delete[] name[i];
        }
        delete[] *name;
        delete[] balance;
    }
};


#endif