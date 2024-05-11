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

Card* setupHands(Player& player, Hand& dealerHand, std::vector <Card*> deck) {
  std::cout << "dealerHand: " << deck[deck.size() - 1]->getRank() << "\n";
  dealerHand.addCard(deck[deck.size() - 1]);
  deck.pop_back();
  player.getHand()->addCard(deck[deck.size() - 1]);
  deck.pop_back();
  Card* heldCard = deck[deck.size() - 1];
  deck.pop_back();
  player.getHand()->addCard(deck[deck.size() - 1]);
  deck.pop_back();
  return heldCard;
}

void calculateWinner(Player& player, int bet, int score) {
  if (score < player.getHand()->getScore() && player.getHand()->getScore() <= 21) {
    player.win(bet);
  } else if (score > player.getHand()->getScore()) {
    player.lose(bet);
  } else {
    player.draw(bet);
  }
}

void gameLoop(Players& players,Player& player, int bet, Hand* dealerHand, Card* heldCard, std::vector <Card*> deck) {
  bool end = false;
  while (!end)
  {
    char option;
    std::cout << "k - hit, p - stand, q - quit\n";
    std::cin >> option;
    switch (option)
    {
      case 'k':
        player.getHand()->addCard(deck[deck.size() - 1]);
        deck.pop_back();
        Renderer::renderCards(dealerHand);
        Renderer::renderCards(player.getHand());
        if (player.getHand()->getScore() > 21) {
          calculateWinner(player, bet, dealerHand->getScore());
          end = true;
          GameMenu(players, player);
        }
        break;
      case 'p':
        dealerHand->addCard(heldCard);
        while (dealerHand->getScore() + deck[deck.size() - 1]->getValue() < 21) {
          dealerHand->addCard(deck[deck.size() - 1]);
          deck.pop_back();
          Renderer::renderCards(dealerHand);
          Renderer::renderCards(player.getHand());
        }
        calculateWinner(player, bet, dealerHand->getScore());
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
    for (size_t i = 0; i < deck.size(); i++) {
      delete deck[i];
    }
    saveFile(players, "state.txt");
    return;
  }
  Hand *dealerHand = new Hand;
  Card* heldCard = setupHands(player, *dealerHand, deck);
  Renderer::renderCards(dealerHand);
  Renderer::renderCards(player.getHand());
  gameLoop(players, player, bet, dealerHand, heldCard, deck);
  delete dealerHand;
  for (size_t i = 0; i < deck.size(); i++) {
    delete deck[i];
  }
  saveFile(players, "state.txt");
}