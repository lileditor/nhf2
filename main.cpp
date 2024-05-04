#include <iostream>
#include "Cards.hpp"
#include "Hands.hpp"
#include "CardsRender.hpp"
#include "FileHandler.hpp"
#include "Players.hpp"
#include "Menu.hpp"
#include "Tests.hpp"

int main() {
    /*
        loadfile();
        menu();
        game();
    */
    /*Players players = loadFile("state.txt");
    StartMenu(players);*/
    Hand *hand = new Hand();
    Card *card = new Card(Clubs, Jack);
    Card *card2 = new Card(Hearts, Ten);
    hand->addCard(card);
    hand->addCard(card2);
    Renderer::renderCards(hand);
    delete hand;
    delete card;
    delete card2;
} 
