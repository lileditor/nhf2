#include "Cards.hpp"
#include <random>
#include <iostream>

Card** generateCards() {
  Card **cards = new Card*[52];
  for (int i = 0; i < 13; i++) {
    cards[i] = new class Clubs(static_cast<Rank>(i));
    cards[i + 13] = new class Diamonds(static_cast<Rank>(i));
    cards[i + 26] = new class Hearts(static_cast<Rank>(i));
    cards[i + 39] = new class Spades(static_cast<Rank>(i));
  }
  return cards;
}

std::vector <Card*> shuffleCards(Card **cards) {
  std::random_device generator;
  std::uniform_real_distribution<float> distribution(0, 51);
  std::vector<Card*> Cards;
  for (int i = 0; i < 52; i++) {
    int index = distribution(generator);
    Cards.push_back(cards[index]);
  }
  delete[] cards;
  return Cards;
}
