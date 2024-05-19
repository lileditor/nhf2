#ifndef MAIN_GAME_HPP
#define MAIN_GAME_HPP
#include "Players.hpp"
#include "FileHandler.hpp"
#include "CardsRender.hpp"
#include <vector>
#include <algorithm>
#include "memtrace.h"

/**
 * @brief 
 * Ez a játékot kezeli és innen tudjuk elindítani a játékot.
 * @param players 
 * @param player 
 */
void GameMenu(Players& players, Player& player);

int placeBet(Player& player);

Card* setupHands(Player& player, Hand& dealerHand, std::vector <Card*> *deck);

void calculateWinner(Player& player, int bet, Hand* dealerHand);

void gameLoop(Players& players,Player& player, int bet, Hand* dealerHand, Card* heldCard, std::vector <Card*> *deck);

void GameMenu(Players& players, Player& player);
#endif // MAIN_GAME_HPP
