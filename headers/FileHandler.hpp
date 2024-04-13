#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include "Players.hpp"

Players& loadFile(const char* fileName = nullptr);
void saveFile(const char* fileName = nullptr, Players& players);

#endif