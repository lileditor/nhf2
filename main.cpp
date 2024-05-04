#include <iostream>
#include "Cards.hpp"
#include "Hands.hpp"
#include "CardsRender.hpp"
#include "FileHandler.hpp"
#include "Players.hpp"
#include "Menu.hpp"

int main() {
    /*
        loadfile();
        menu();
        game();
    */
    /*Players players = loadFile("state.txt");
    StartMenu(players);*/
    Hand *hand = new Hand();
    Card *card = new Card(Spades, Ten);
    hand->addCard(card);
    Renderer::renderCards(hand);
    delete hand;
    delete card;
} 
