#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include "Players.hpp"
#include "memtrace.h"

/**
 * @brief 
 * Innen fogja tudni hogy melyik játékosnak mennyi pontja van.
 * @param fileName 
 * @return Players& 
 */
Players loadFile(const char* fileName = nullptr);

/**
 * @brief 
 * Ez fogja elmenteni, hogy a következő indításnál tudjuk folytatni ugyan onnan.
 * @param players 
 * @param fileName 
 */
void saveFile(Players& players, const char* fileName = nullptr);

#endif