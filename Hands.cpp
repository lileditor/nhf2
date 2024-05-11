#include <iostream>
#include "Hands.hpp"
#include "Cards.hpp"

void Hand::addCard(Card *c) {
    cards[size++] = c;
    score += c->getValue();
}

void Hand::deleteCards() {
    for (int i = 0; i < size; i++) {
        delete cards[i];
    }
    size = 0;
    score = 0;
}
