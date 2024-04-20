#include <iostream>
#include <string>
#include "Cards.hpp"

void generateCards(Card *cards) {
    for (int i = 0; i < 52; i++) {
        cards[i].setCard(static_cast<Suit>(i / 13), static_cast<Rank>(i % 13));
    }
}

void shuffeCards(Card *cards) {
    srand(time(nullptr));
    for (int i = 0; i < 52; i++) {
        int index = rand() % 52;
        Card tmp = cards[i];
        cards[i] = cards[index];
        cards[index] = tmp;
    }
}