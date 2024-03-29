#include <iostream>
#include "headers/CardsRender.hpp"
#include "headers/Cards.hpp"

void CardsRender::renderCards(Hand* hand) {
    for (int i = 0; i < hand->getSize(); i++) {
        switch (hand->getCards()[i].getSuit()) {
            case Suit::Spades:
                std::cout << "♠" << hand->getCards()[i].getRank() << " ";
                break;
            case Suit::Hearts:
                std::cout << "♡" << hand->getCards()[i].getRank() << " ";
                break;
            case Suit::Clubs:
                std::cout << "♣" << hand->getCards()[i].getRank() << " ";
                break;
            case Suit::Diamonds:
                std::cout << "♢" << hand->getCards()[i].getRank() << " ";
                break;
            default:
                break;
        }
    }
}

/*
"----------" "----------" "----------" "----------"
"| 2      |" "| 2      |" "| 2      |" "| 2      |"
"|    #   |" "|    #   |" "|  #   # |" "|    #   |"
"|   ###  |" "|   ###  |" "| ##  ## |" "|  ##### |"
"|  ##### |" "|  ##### |" "| ###### |" "|  ##### |"
"|   ###  |" "|  # # # |" "|  ####  |" "|  ##### |"
"|    #   |" "|    #   |" "|   ##   |" "|    #   |"
"|      2 |" "|      2 |" "|      2 |" "|      2 |"
"----------" "----------" "----------" "----------"
*/