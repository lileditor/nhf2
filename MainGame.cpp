#include "MainGame.hpp"

void GameMenu(Players& players, Player& player) {
  Card* c =  new Card[51];
  generateCards(c);
  shuffleCards(c);
  Cards deck(c);
  Hand *dealerHand = new Hand;
  Card first = deck[0];
  dealerHand->addCard(&first);
  deck.pop_front();
  first = deck[0];
  player.getHand()->addCard(&first);
  deck.pop_front();
  Card holdedCard = deck[0];
  deck.pop_front();
  first = deck [0];
  player.getHand()->addCard(&first);
  std::cout << holdedCard.getRank() << std::endl;
  Renderer::renderCards(player.getHand());
  saveFile(players);
}
