#ifndef HANDS_HPP
#define HANDS_HPP
#include "Cards.hpp"

/**
 * @brief
 * Ez a kártyákat tudja kezelni ami éppen nálad van.
 */
class Hand {
  Card **cards;
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

  ~Hand() { delete[] cards; }
};

#endif
