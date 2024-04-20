#include <iostream>
#include "Hands.hpp"
#include "Cards.hpp"

void Hand::addCard(Card c) {
    cards[size++] = c;
    score += c.getValue();
}