#include <iostream>
#include <fstream>
#include "headers/FileHandler.hpp"
#include "headers/Players.hpp"

void saveFile(const char* fileName, Players& players) {
    if (fileName == nullptr) {
        throw std::invalid_argument("File name cannot be null");
    }
    std::ofstream file(fileName, std::ios::binary);
    file.open(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
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