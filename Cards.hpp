#ifndef CARDS_HPP
#define CARDS_HPP

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

class Card {
  protected:
  Suit suit;
  Rank rank;
public:
  Card() {};
  Card(Suit s, Rank r) : suit(s), rank(r) {}
  void setSuit(Suit s) { suit = s; };
  void setRank(Rank r) { rank = r; };
  Suit getSuit() const { return suit; }
  Rank getRank() const { return rank; }
  int getValue() const { return rank > 8 ? rank == Ace ? 11 : 10 : static_cast<int>(rank) + 2; }
  void setCard(Suit s, Rank r) { suit = s; rank = r; }
};

void generateCards(Card *cards);

void shuffeCards(Card *cards);

#endif