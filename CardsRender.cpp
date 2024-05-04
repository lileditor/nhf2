#include <iostream>
#include <format>
#include "CardsRender.hpp"
#include "Cards.hpp"

/*
"----------" "----------" "----------" "----------" "----------"
"| %s     |" "| %s     |" "| %s     |" "| %s     |" "|        |"
"|    #   |" "|    #   |" "|  #   # |" "|    #   |" "|        |"
"|   ###  |" "|   ###  |" "| ##  ## |" "|  ##### |" "|        |"
"|  ##### |" "|  ##### |" "| ###### |" "|  ##### |" "|        |"
"|   ###  |" "|  # # # |" "|  ####  |" "|  ##### |" "|        |"
"|    #   |" "|    #   |" "|   ##   |" "|    #   |" "|        |"
"|     %s |" "|     %s |" "|     %s |" "|     %s |" "|        |"
"----------" "----------" "----------" "----------" "----------"
*/

const char* ClubsString[11] = {
    "----------", 
    "| %s      |", 
    "|    #   |", 
    "|   ###  |", 
    "|  ##### |", 
    "|  # # # |", 
    "|    #   |", 
    "|      %s |", 
    "----------", 
    "| %s     |", 
    "|     %s |",
};
const char* DiamondsString[11] = {
    "----------", 
    "| %s      |", 
    "|    #   |", 
    "|   ###  |", 
    "|  ##### |", 
    "|   ###  |", 
    "|    #   |", 
    "|      %s |", 
    "----------", 
    "| %s     |", 
    "|     %s |"
};
const char* HeartsString[11] = {
    "----------", 
    "| %s      |", 
    "|  #   # |", 
    "| ##  ## |", 
    "| ###### |", 
    "|  ####  |", 
    "|   ##   |", 
    "|      %s |", 
    "----------", 
    "| %s     |", 
    "|     %s |"
};
const char* SpadesString[11] = {
    "----------", 
    "| %s      |", 
    "|    #   |", 
    "|  ##### |", 
    "|  ##### |", 
    "|  ##### |", 
    "|    #   |", 
    "|      %s |", 
    "----------", 
    "| %s     |", 
    "|     %s |"
};

void Renderer::renderCards(Hand* hand) {
    std::string cards = Renderer::getCardsString(hand);
    std::cout << cards;
    std::cout << "score: " << hand->getScore() << std::endl;
}

std::string Renderer::getCardsString(Hand *hand) {
    std::string cards = "";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < hand->getSize(); j++) {
            cards += getCardStringFormLine(hand->getCards()[j], i);
            cards += " ";
        }
        cards += "\n";
    }
    return cards;
}

std::string Renderer::getCardStringFormLine(Card *card, int line) {
    std::string cardString = "";
    switch (card->getSuit()) {
        case Clubs:
            if (line == 1 && card->getRank() == Ten) {
                cardString = Renderer::format(ClubsString[line + 8], RANKS[card->getRank()]);
            } else if (line == 7 && card->getRank() == Ten) {
                cardString = Renderer::format(ClubsString[line + 3], RANKS[card->getRank()]);
            } else {
                cardString = Renderer::format(ClubsString[line], RANKS[card->getRank()]);
            }
            break;
        case Diamonds:
            if (line == 1 && card->getRank() == Ten) {
                cardString = Renderer::format(DiamondsString[line + 8], RANKS[card->getRank()]);
            } else if (line == 7 && card->getRank() == Ten) {
                cardString = Renderer::format(DiamondsString[line + 3], RANKS[card->getRank()]);
            } else {
                cardString = Renderer::format(DiamondsString[line], RANKS[card->getRank()]);
            }
            break;
        case Hearts:
            if (line == 1 && card->getRank() == Ten) {
                cardString = Renderer::format(HeartsString[line + 8], RANKS[card->getRank()]);
            } else if (line == 7 && card->getRank() == Ten) {
                cardString = Renderer::format(HeartsString[line + 3], RANKS[card->getRank()]);
            } else {
                cardString = Renderer::format(HeartsString[line], RANKS[card->getRank()]);
            }
            break;
        case Spades:
            if (line == 1 && card->getRank() == Ten) {
                cardString = Renderer::format(SpadesString[line + 8], card->getRank());
            } else if (line == 7 && card->getRank() == Ten) {
                cardString = Renderer::format(SpadesString[line + 3], card->getRank());
            } else {
                cardString = Renderer::format(SpadesString[line], card->getRank());
            }
            break;
        default:
            break;
    }
    return cardString;
}