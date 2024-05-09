#include "MainGame.hpp"

//LEHET VECTOR JIPIIII

void GameMenu(Players& players, Player& player) {
  std::vector <Card*> deck = shuffleCards(generateCards());
  Hand *dealerHand = new Hand;
  Card* first = deck[deck.size() - 1];
  std::cout << "First card: " << first->getSuit() << " " << first->getRank() << std::endl;
  dealerHand->addCard(first);
  deck.pop_back();
  std::cout << "igazam van"<< std::endl;
  first = deck[deck.size() - 1];
  std::cout << "First card: " << first->getSuit() << " " << first->getRank() << std::endl;
  player.getHand()->addCard(first);
  deck.pop_back();
  Card* holdedCard = deck[deck.size() - 1];
  std::cout << "Holded card: " << holdedCard->getSuit() << " " << holdedCard->getRank() << std::endl;
  deck.pop_back();
  first = deck[deck.size() - 1];
  std::cout << "First card: " << first->getSuit() << " " << first->getRank() << std::endl;
  deck.pop_back();
  player.getHand()->addCard(first);
  dealerHand->addCard(holdedCard);
  Renderer::renderCards(dealerHand);
  Renderer::renderCards(player.getHand());
  saveFile(players);
}
