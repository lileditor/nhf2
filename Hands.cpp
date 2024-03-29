#include <iostream>
#include "headers/Hands.hpp"
#include "headers/Cards.hpp"

void Hand::addCard(Card c) {
    cards[size++] = c;
    score += c.getValue();
}