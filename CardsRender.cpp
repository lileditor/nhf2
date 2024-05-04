#include <iostream>
#include <format>
#include "CardsRender.hpp"
#include "Cards.hpp"

void Renderer::renderCards(Hand* hand) {
    for (int i = 0; i < hand->getSize(); i++) {
        switch (hand->getCards()[i].getSuit()) {
            case Spades: {
                if (hand->getCards()[i].getRank() == Ten) {
                    std::string card = "----------\n";
                    card += Renderer::format("| %s     |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "|    #   |\n";
                    card += "|   ###  |\n";
                    card += "|  ##### |\n";
                    card += "|  # # # |\n";
                    card += "|    #   |\n";
                    card += Renderer::format("|     %s |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "----------\n";
                    std::cout << card;
                } else {
                    std::string card = "----------\n";
                    card += Renderer::format("| %s      |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "|    #   |\n";
                    card += "|   ###  |\n";
                    card += "|  ##### |\n";
                    card += "|  # # # |\n";
                    card += "|    #   |\n";
                    card += Renderer::format("|      %s |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "----------\n";
                    std::cout << card;
                }
                break;
            }
            case Hearts: {
                if (hand->getCards()[i].getRank() == Ten) {
                    std::string card = "----------\n";
                    card += Renderer::format("| %s     |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "|  #   # |\n";
                    card += "| ##  ## |\n";
                    card += "| ###### |\n";
                    card += "|  ####  |\n";
                    card += "|   ##   |\n";
                    card += Renderer::format("|     %s |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "----------\n";
                    std::cout << card;
                } else {
                    std::string card = "----------\n";
                    card += Renderer::format("| %s      |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "|  #   # |\n";
                    card += "| ##  ## |\n";
                    card += "| ###### |\n";
                    card += "|  ####  |\n";
                    card += "|   ##   |\n";
                    card += Renderer::format("|      %s |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "----------\n";
                    std::cout << card;
                }
                break;
            }
            case Clubs: {
                if (hand->getCards()[i].getRank() == Ten) {
                    std::string card = "----------\n";
                    card += Renderer::format("| %s     |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "|    #   |\n";
                    card += "|  ##### |\n";
                    card += "|  ##### |\n";
                    card += "|  ##### |\n";
                    card += "|    #   |\n";
                    card += Renderer::format("|     %s |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "----------\n";
                    std::cout << card;
                } else {
                    std::string card = "----------\n";
                    card += Renderer::format("| %s      |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "|    #   |\n";
                    card += "|  ##### |\n";
                    card += "|  ##### |\n";
                    card += "|  ##### |\n";
                    card += "|    #   |\n";
                    card += Renderer::format("|      %s |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "----------\n";
                    std::cout << card;
                }
                break;
            }
            case Diamonds: {
                if (hand->getCards()[i].getRank() == Ten) {
                    std::string card = "----------\n";
                    card += Renderer::format("| %s     |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "|    #   |\n";
                    card += "|   ###  |\n";
                    card += "|  ##### |\n";
                    card += "|   ###  |\n";
                    card += "|    #   |\n";
                    card += Renderer::format("|     %s |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "----------\n";
                    std::cout << card;
                } else {
                    std::string card = "----------\n";
                    card += Renderer::format("| %s      |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "|    #   |\n";
                    card += "|   ###  |\n";
                    card += "|  ##### |\n";
                    card += "|   ###  |\n";
                    card += "|    #   |\n";
                    card += Renderer::format("|      %s |\n", RANKS[hand->getCards()[i].getRank()]);
                    card += "----------\n";
                    std::cout << card;
                }
                break;
            }
            default:
                break;
        }
    }
}

/*
"----------" "----------" "----------" "----------"
"| %s     |" "| %s     |" "| %s     |" "| %s     |"
"|    #   |" "|    #   |" "|  #   # |" "|    #   |"
"|   ###  |" "|   ###  |" "| ##  ## |" "|  ##### |"
"|  ##### |" "|  ##### |" "| ###### |" "|  ##### |"
"|   ###  |" "|  # # # |" "|  ####  |" "|  ##### |"
"|    #   |" "|    #   |" "|   ##   |" "|    #   |"
"|     %s |" "|     %s |" "|     %s |" "|     %s |"
"----------" "----------" "----------" "----------"
*/