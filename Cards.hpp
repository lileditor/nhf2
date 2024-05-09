#ifndef CARDS_HPP
#define CARDS_HPP
#include <map>
#include <cstddef>

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
  virtual printLn(int line) = 0;
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
  Diamonds(Rank r) : Card(Diamonds, r) {}
  void printLn(int line);
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
  Clubs(Rank r) : Card(Clubs, r) {}
  void printLn(int line);
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
  Hearts(Rank r) : Card(Hearts, r) {}
  void printLn(int line);
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
  Spades(Rank r) : Card(Spades, r) {}
  void printLn(int line);
};

void generateCards(Card *cards);

void shuffleCards(Card *cards);

#endif
