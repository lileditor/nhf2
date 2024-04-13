#include <iostream>
#include "headers/Cards.hpp"
#include "headers/Hands.hpp"
#include "headers/CardsRender.hpp"
#include "headers/FileHandler.hpp"
#include "headers/Players.hpp"

int main() {
    /*
        loadfile();
        menu();
        game();
    */
    Players *players = loadFile("state.txt");
    StartMenu(players);
    /*Card* cards = new Card[52];
    generateCards(cards);
    shuffeCards(cards);
    
    Hand* player = new Hand();
    Hand* dealer = new Hand();
    
    dealer->addCard(cards[0]);
    player->addCard(cards[1]);
    
    CardsRender::renderCards(dealer);
    CardsRender::renderCards(player);

    delete[] cards;
    */
} 
