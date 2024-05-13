#include <iostream>
#include "CardsRender.hpp"
#include "Cards.hpp"


void Renderer::renderCards(Hand* hand, std::ostream &os) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < hand->getSize(); j++) {
            os << Renderer::format(hand->getCards()[j]->printLn(i), RANKS[hand->getCards()[j]->getRank()]) << " ";
        }
        os << "\n";
    }
    os << "Score: " <<hand->getScore() << "\n";
}
