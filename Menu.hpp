#ifndef MENU_HPP
#define MENU_HPP

#include "Cards.hpp"
#include "Players.hpp"

/**
 * @brief 
 * Ezzel találkozik a játékos mikor elindítja a programot.
 * @param players 
 */
void StartMenu(Players &players);

void PlayersMenu(Players &players);

void ChoosePlayer(Players &players);

//void EndMenu(Players &players);

#endif