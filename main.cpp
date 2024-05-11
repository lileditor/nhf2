#include <iostream>
#include "Cards.hpp"
#include "Hands.hpp"
#include "CardsRender.hpp"
#include "FileHandler.hpp"
#include "Players.hpp"
#include "Menu.hpp"
//#include "Tests.hpp"

int main() {
    /*
        loadfile(); write tests
        menu(); write tests
        game(); write tests
    */
    Players players = loadFile("state.txt");
    StartMenu(players);
} 
