#include <iostream>
#include <format>
#include "CardsRender.hpp"
#include "Cards.hpp"

void Renderer::renderCards(Hand* hand) {
    for (int i = 0; i < hand->getSize(); i++) {
        switch (hand->getCards()[i].getSuit()) {
            case Spades: {
                if (hand->getCards()[i].getRank() == Ten) {
                    std::string card = "----------\n" + Renderer::format("| %s     |\n", RANKS[hand->getCards()[i].getRank()]) + "|    #   |\n" + "|   ###  |\n" + "|  ##### |\n" + "|  # # # |\n" + "|    #   |\n" + Renderer::format("|     %s |\n", RANKS[hand->getCards()[i].getRank()]) + "----------\n";
                    std::cout << card;
                } else {
                    std::string card = "----------\n" + Renderer::format("| %s      |\n", RANKS[hand->getCards()[i].getRank()]) + "|    #   |\n" + "|   ###  |\n" + "|  ##### |\n" + "|  # # # |\n" + "|    #   |\n" + Renderer::format("|      %s |\n", RANKS[hand->getCards()[i].getRank()]) + "----------\n";
                    std::cout << card;
                }
                break;
            }
            case Hearts: {
                std::cout << "♡" << hand->getCards()[i].getRank() << " ";
                break;
            }
            case Clubs: {
                std::cout << "♣" << hand->getCards()[i].getRank() << " ";
                break;
            }
            case Diamonds: {
                std::cout << "♢" << hand->getCards()[i].getRank() << " ";
                break;
            }
            default:
                break;
        }
    }
}

/*
"----------" "----------" "----------" "----------"
"| {}     |" "| {}     |" "| {}     |" "| {}     |"
"|    #   |" "|    #   |" "|  #   # |" "|    #   |"
"|   ###  |" "|   ###  |" "| ##  ## |" "|  ##### |"
"|  ##### |" "|  ##### |" "| ###### |" "|  ##### |"
"|   ###  |" "|  # # # |" "|  ####  |" "|  ##### |"
"|    #   |" "|    #   |" "|   ##   |" "|    #   |"
"|     {} |" "|     {} |" "|     {} |" "|     {} |"
"----------" "----------" "----------" "----------"
*/