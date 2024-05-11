#include <iostream>
#include "FileHandler.hpp"
#include "Players.hpp"
#include "Menu.hpp"
#include "Tests.hpp"
#define CPORTA

int main() {
    /*
        loadfile(); write tests
        menu(); write tests
        game(); write tests
    */
#ifdef CPORTA
    Test();
#else
    Players players = loadFile("state.txt");
    StartMenu(players);
#endif
} 
