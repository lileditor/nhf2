#include <iostream>
#include "Cards.hpp"
#include "Hands.hpp"
#include "CardsRender.hpp"
#include "FileHandler.hpp"
#include "Players.hpp"
#include "Menu.hpp"
//1#include "Tests.hpp"

int main() {
    /*
        loadfile(); write tests
        menu(); write tests
        game(); work in progress
    */
    Players players = loadFile("state.txt");
    StartMenu(players);
} 
