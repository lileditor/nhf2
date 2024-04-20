#include <iostream>
#include "Cards.hpp"
#include "Hands.hpp"
#include "CardsRender.hpp"
#include "FileHandler.hpp"
#include "Players.hpp"
#include "StartMenu.hpp"

int main() {
    /*
        loadfile();
        menu();
        game();
    */
    Players players = loadFile("state.txt");
    StartMenu(players);
} 
