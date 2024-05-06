#include "MainGame.hpp"

void GameMenu(Players& players, Player& player) {
  Card* cards =  new Card[51];
  generateCards(cards);
  shuffleCards(cards);
  Cards deck(cards);
  Hand *dealerHand = new Hand;
  dealerHand->addCard(&deck[0]);
  deck->pop_front();
  player.getHand()->addCard(&deck[0]);
  deck->pop_front();
  Card holdedCard = deck[0];
  deck->pop_front();
  player.getHand()->addCard(&deck[0]);
  
  saveFIle(players);
}
