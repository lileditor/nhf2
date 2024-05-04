#include <iostream>
#include <fstream>
#include "FileHandler.hpp"
#include "Players.hpp"
#include "Cards.hpp"

void saveFile(Players& players, const char* fileName) {
    if (fileName == nullptr) {
        throw std::invalid_argument("File name cannot be null");
    }
    std::ofstream file (fileName);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
    file << "";
    for (int i = 0; i < players.GetSize(); i++) {
        std::cout << players[i].getName() << " " << players[i].getBalance() << " " << players[i].getHand()->getSize() << "\n";
        file << players[i].getName() << " " << players[i].getBalance() << " " << players[i].getHand()->getSize() << "\n";
        for (int j = 0; j < players[i].getHand()->getSize(); j++) {
            file << players[i].getHand()->getCards()[j]->getSuit() << " " << players[i].getHand()->getCards()[j]->getRank() << "\n";
        }
    }
    file.close();
}

Players& loadFile(const char* fileName) {
    if (fileName == nullptr) {
        throw std::invalid_argument("File name cannot be null");
    }
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
    Players *players = new Players();
    std::string line;
    while (file >> line) {
        const char *name = line.c_str();
        int balance;
        file >> balance;
        Player *player = new Player(name, balance);
        int cardsNumber;
        file >> cardsNumber;
        for (int i = 0; i < cardsNumber; i++) {
            int suit;
            int rank;
            file >> suit >> rank;
            player->getHand()->addCard(new Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
        }
        players->addPlayer(player);
    }
    return *players;
}