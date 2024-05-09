#include "MainGame.hpp"

//LEHET VECTOR JIPIIII

void GameMenu(Players& players, Player& player) {
  Card* c = new Card[51];
  generateCards(c);
  shuffleCards(c);
  Cards deck(&c);
  Hand *dealerHand = new Hand;
  Card* first = deck[0];
  std::cout << "First card: " << first->getSuit() << " " << first->getRank() << std::endl;
  dealerHand->addCard(first);
  deck.pop_front();
  std::cout << "igazam van"<< std::endl;
  first = deck[0];
  std::cout << "First card: " << first->getSuit() << " " << first->getRank() << std::endl;
  player.getHand()->addCard(first);
  deck.pop_front();
  Card* holdedCard = deck[0];
  std::cout << "Holded card: " << holdedCard->getSuit() << " " << holdedCard->getRank() << std::endl;
  deck.pop_front();
  first = deck[0];
  std::cout << "First card: " << first->getSuit() << " " << first->getRank() << std::endl;
  player.getHand()->addCard(first);
  dealerHand->addCard(holdedCard);
  Renderer::renderCards(dealerHand);
  Renderer::renderCards(player.getHand());
  saveFile(players);
}
