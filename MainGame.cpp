#include "MainGame.hpp"

int placeBet(Player& player) {
  std::string op;
  int bet = 0;
  std::cout << "place your bets or q to quit" << std::endl;
  std::cin >> op;
  if (op == "q") {
    return -1;
  }
  bet = std::stoi(op) ? std::stoi(op) : -1;
  player.placeBet(bet);
  return bet;
}

Card* setupHands(Player& player, Hand& dealerHand, std::vector <Card*> *deck) {
  dealerHand.addCard(deck->back());
  deck->pop_back();
  player.getHand()->addCard(deck->back());
  deck->pop_back();
  Card* heldCard = deck->back();
  deck->pop_back();
  player.getHand()->addCard(deck->back());
  deck->pop_back();
  return heldCard;
}

void calculateWinner(Player& player, int bet, Hand* dealerHand) {
  if ((dealerHand->getScore() < player.getHand()->getScore() && player.getHand()->getScore() <= 21) || dealerHand->getScore() > 21) {
    player.win(bet);
  } else if (dealerHand->getScore() == player.getHand()->getScore()) {
    player.draw(bet);
  } else {
    player.lose(bet);
  }
  std::cout << "Your balance: " << player.getBalance() << std::endl;
  player.getHand()->deleteCards();
  dealerHand->deleteCards();
}

void gameLoop(Players& players,Player& player, int bet, Hand* dealerHand, Card* heldCard, std::vector <Card*> *deck) {
  bool end = false;
  while (!end)
  {
    char option;
    std::cout << "k - hit, p - stand, q - quit\n";
    std::cin >> option;
    switch (option)
    {
      case 'k':
        deck->shrink_to_fit();
        player.getHand()->addCard(deck->back());
        deck->pop_back();
        Renderer::renderCards(dealerHand);
        Renderer::renderCards(player.getHand());
        if (player.getHand()->getScore() > 21) {
          Renderer::renderCards(dealerHand);
          Renderer::renderCards(player.getHand());
          calculateWinner(player, bet, dealerHand);
          end = true;
          GameMenu(players, player);
        }
        break;
      case 'p':
        dealerHand->addCard(heldCard);
        while ((dealerHand->getScore() + deck->back()->getValue()) < 21) {
          dealerHand->addCard(deck->back());
          deck->pop_back();
          Renderer::renderCards(dealerHand);
          Renderer::renderCards(player.getHand());
        }
        Renderer::renderCards(dealerHand);
        Renderer::renderCards(player.getHand());
        calculateWinner(player, bet, dealerHand);
        end = true;
        GameMenu(players, player);
        break;
      case 'q':
        std::cout << "Bye!" << std::endl;
        end = true;
        break;
    }
  }
}

void GameMenu(Players& players, Player& player) {
  std::vector <Card*> deck = shuffleCards(generateCards());
  int bet = placeBet(player);
  if (bet == -1) {
    deck.shrink_to_fit();
    for (size_t i = 0; i < deck.size(); i++) {
      if (deck[i] != nullptr)
        delete deck[i];
      deck[i] = nullptr;
    }
    deck.clear();
    saveFile(players, "state.txt");
    return;
  }
  Hand *dealerHand = new Hand();
  Card* heldCard = setupHands(player, *dealerHand, &deck);
  Renderer::renderCards(dealerHand);
  Renderer::renderCards(player.getHand());
  gameLoop(players, player, bet, dealerHand, heldCard, &deck);
  for (size_t i = 0; i < deck.size(); i++) {
      if (deck[i] != nullptr)
        delete deck[i];
      deck[i] = nullptr;
    }
  delete dealerHand;
    deck.clear();
  saveFile(players, "state.txt");
}