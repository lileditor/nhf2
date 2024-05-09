#include "Cards.hpp"
#include <random>
#include <iostream>

void generateCards(Card *cards) {
  for (int i = 0; i < 52; i++) {
    cards[i].setCard(static_cast<Suit>(i / 13), static_cast<Rank>(i % 13));
  }
}

void shuffleCards(Card *cards) {
  std::random_device generator;
  std::uniform_real_distribution<float> distribution(0, 51);
  for (int i = 0; i < 52; i++) {
    int index = distribution(generator);
    Card tmp = cards[i];
    cards[i] = cards[index];
    cards[index] = tmp;
  }
}
