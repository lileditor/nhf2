#include <iostream>
#include "CardsRender.hpp"
#include "Cards.hpp"


void Renderer::renderCards(Hand* hand) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < hand->getSize(); j++) {
            std::cout << Renderer::format(hand->getCards()[j]->printLn(i), RANKS[hand->getCards()[j]->getRank()]) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Score: " <<hand->getScore() << "\n";
}
