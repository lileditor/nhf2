#ifndef CARDS_HPP
#define CARDS_HPP
#include <map>
#include <cstddef>
#include <vector>
#include "memtrace.h"


enum Suit { Clubs, Diamonds, Hearts, Spades };

enum Rank {
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Ace
};

static std::map<Rank, const char*> RANKS = {{Two, "2"}, {Three, "3"}, {Four, "4"}, {Five, "5"}, {Six, "6"}, {Seven, "7"}, {Eight, "8"}, {Nine, "9"}, {Ten, "10"}, {Jack, "J"}, {Queen, "Q"}, {King, "K"}, {Ace, "A"}};

/**
 * @brief
 * Ez a kártyák funkciósit tartalmazza.
 */
class Card {
protected:
  Suit suit;
  Rank rank;

public:
  Card(){};
  Card(Suit s, Rank r) : suit(s), rank(r) {}
  void setSuit(Suit s) { suit = s; };
  void setRank(Rank r) { rank = r; };
  Suit getSuit() const { return suit; }
  Rank getRank() const { return rank; }
  int getValue() const {
    return rank > 8 ? rank == Ace ? 11 : 10 : static_cast<int>(rank) + 2;
  }
  void setCard(Suit s, Rank r) {
    suit = s;
    rank = r;
  }
  virtual const char* printLn(int line) = 0;
  virtual ~Card() {}
};

class Clubs: public Card {
  const char* str[11] = {
    "----------", 
    "| %s      |", 
    "|    #   |", 
    "|   ###  |", 
    "|  ##### |", 
    "|  # # # |", 
    "|    #   |", 
    "|      %s |", 
    "----------", 
    "| %s     |", 
    "|     %s |",
};
public:
  Clubs(Rank r) : Card(static_cast<Suit>(0), r) {}
  const char* printLn(int line);
  ~Clubs() {}
};

class Diamonds: public Card {
  const char* str[11] = {
    "----------", 
    "| %s      |", 
    "|    #   |", 
    "|   ###  |", 
    "|  ##### |", 
    "|   ###  |", 
    "|    #   |", 
    "|      %s |", 
    "----------", 
    "| %s     |", 
    "|     %s |"
};
public:
  Diamonds(Rank r) : Card(static_cast<Suit>(1), r) {}
  const char* printLn(int line);
  ~Diamonds() {}
};


class Hearts: public Card {
  const char* str[11] = {
    "----------", 
    "| %s      |", 
    "|  #   # |", 
    "| ##  ## |", 
    "| ###### |", 
    "|  ####  |", 
    "|   ##   |", 
    "|      %s |", 
    "----------", 
    "| %s     |", 
    "|     %s |"
};
public:
  Hearts(Rank r) : Card(static_cast<Suit>(2), r) {}
  const char* printLn(int line);
  ~Hearts() {}
};

class Spades: public Card {
  const char* str[11] = {
    "----------", 
    "| %s      |", 
    "|    #   |", 
    "|  ##### |", 
    "|  ##### |", 
    "|  ##### |", 
    "|    #   |", 
    "|      %s |", 
    "----------", 
    "| %s     |", 
    "|     %s |"
};
public:
  Spades(Rank r) : Card(static_cast<Suit>(3), r) {}
  const char* printLn(int line);
  ~Spades() {}
};

Card **generateCards();

std::vector <Card*>  shuffleCards(Card **cards);

#endif
