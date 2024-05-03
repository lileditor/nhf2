#ifndef MENU_HPP
#define MENU_HPP

#include "Players.hpp"

/**
 * @brief 
 * Ezzel találkozik a játékos mikor elindítja a programot.
 * @param players 
 */
void StartMenu(Players &players);

void PlayersMenu(Players &players);

void ChoosePlayer(Players &players);

void GameMenu(Player &player);

void EndMenu(Players &players);

#endif