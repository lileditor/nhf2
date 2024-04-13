#include "headers/FileHandler.hpp"
#include <iostream>
#include <fstream>

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

    file >> 
}