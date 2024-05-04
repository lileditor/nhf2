#include <iostream>
#include "Hands.hpp"
#include "Cards.hpp"

void Hand::addCard(Card *c) {
    std::cout << "c1" << std::endl;
    size++;
    
    cards[size - 1] = c;
    std::cout << "c2" << std::endl;
    score += c->getValue();
}