#include "MainGame.hpp"

//LEHET VECTOR JIPIIII

int placeBet(Player& player) {
  std::string op;
  int bet = 0;
  std::cout << "place your bets" << std::endl;
  std::cin >> op;
  bet = std::stoi(op) ? std::stoi(op) : -1;
  player.placeBet(bet);
  return bet;
}

Card* setupHands(Player& player, Hand& dealerHand, std::vector <Card*> deck) {
  std::cout << "dealerHand: " << deck[deck.size() - 1]->getRank() << "\n";
  dealerHand.addCard(deck[deck.size() - 1]);
  deck.pop_back();
  player.getHand()->addCard(deck[deck.size() - 1]);
  deck.pop_back();
  Card* heldCard = deck[deck.size() - 1];
  deck.pop_back();
  deck.pop_back();
  player.getHand()->addCard(deck[deck.size() - 1]);
  deck.pop_back();
  return heldCard;
}

void gameLoop(Players& players, Player& player, int bet, Hand& dealerHand, Card* heldCard) {
  //TODO
  std::cout << players.GetSize() << player.getBalance() << bet << dealerHand.getScore() << heldCard->getValue() << "\n";
}

void GameMenu(Players& players, Player& player) {
  std::vector <Card*> deck = shuffleCards(generateCards());
  int bet = placeBet(player);
  Hand *dealerHand = new Hand;
  Card* heldCard = setupHands(player, *dealerHand, deck);
  Renderer::renderCards(dealerHand);
  Renderer::renderCards(player.getHand());
  gameLoop(players, player, bet, *dealerHand, heldCard);
  delete dealerHand;
  for (size_t i = 0; i < deck.size(); i++) {
    delete deck[i];
  }
  saveFile(players, "state.txt");
}