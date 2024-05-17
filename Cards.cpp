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

std::vector <Card*> shuffleCards(Card **c) {
  std::vector<Card*> Cards;
  for (int i = 0; i < 52; i++) {
    Cards.push_back(c[i]);
  }
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(Cards.begin(), Cards.end(), g);
  delete[] c;
  return Cards;
}

const char* Clubs::printLn(int line) {
  if (line == 1 && getRank() == Ten) {
    return str[9];
  } else if (line == 7 && getRank() == Ten) {
    return str[10];
  }
  return str[line];
}
const char* Diamonds::printLn(int line) {
  if (line == 1 && getRank() == Ten) {
    return str[9];
  } else if (line == 7 && getRank() == Ten) {
    return str[10];
  }
  return str[line];
}

const char* Hearts::printLn(int line) {
  if (line == 1 && getRank() == Ten) {
    return str[9];
  } else if (line == 7 && getRank() == Ten) {
    return str[10];
  }
  return str[line];
}
const char* Spades::printLn(int line) {
  if (line == 1 && getRank() == Ten) {
    return str[9];
  } else if (line == 7 && getRank() == Ten) {
    return str[10];
  }
  return str[line];
}
