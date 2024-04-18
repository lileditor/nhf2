#include <iostream>
#include "headers/Cards.hpp"
#include "headers/Hands.hpp"
#include "headers/CardsRender.hpp"
#include "headers/FileHandler.hpp"
#include "headers/Players.hpp"
#include "headers/StartMenu.hpp"

int main() {
    /*
        loadfile();
        menu();
        game();
    */
    Players players = loadFile("state.txt");
    StartMenu(players);
} 
