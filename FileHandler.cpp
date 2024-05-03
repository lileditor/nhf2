#include <iostream>
#include <fstream>
#include <cmath>
#include "FileHandler.hpp"
#include "Players.hpp"
#include "Cards.hpp"

void saveFile(Players& players, const char* fileName) {
    if (fileName == nullptr) {
        throw std::invalid_argument("File name cannot be null");
    }
    std::ofstream file(fileName, std::ios::binary);
    file.open(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
    for (int i = 0; i < players.GetSize(); i++) {
        file.write(players[i].getName(), strlen(players[i].getName()) + 1);
        file << " " << players[i].getBalance() << " " << players[i].getHand()->getSize();
        for (int j = 0; j < players[i].getHand()->getSize(); j++) {
            file << SUITS[players[i].getHand()->getCards()[j].getSuit()] << " " << RANKS[players[i].getHand()->getCards()[j].getRank()] << "\n";
        }
    }
    file.close();
}

Players& loadFile(const char* fileName) {
    if (fileName == nullptr) {
        throw std::invalid_argument("File name cannot be null");
    }
    std::ifstream file(fileName, std::ios::binary);
    file.open(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
    Players *players = new Players();
    return *players;
}