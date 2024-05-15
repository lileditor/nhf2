#ifndef HANDS_HPP
#define HANDS_HPP
#include "Cards.hpp"
#include <iostream>
#include "memtrace.h"


/**
 * @brief
 * Ez a kártyákat tudja kezelni ami éppen nálad van.
 */
class Hand {
  Card **cards = nullptr;
  int size;
  int score;

public:
  Hand() {
    cards = new Card*[10];
    score = 0;
    size = 0;
  }
  void addCard(Card *c);

  int getScore() const { return score; }

  int getSize() const { return size; }

  Card **getCards() const { return cards; }

  void deleteCards();

  ~Hand() { 
  if (cards != nullptr) { 
    for (int i = 0; i < size; i++) {
      if (cards[i] != nullptr)
        delete cards[i];
      cards[i] = nullptr;
    } 
    delete[] cards;
    cards = nullptr; 
    } 
  }
};

#endif
