#include "Cards.hpp"
#include "FileHandler.hpp"
#include "gtest_lite.h"
#include <iostream>

void Test() {
  TEST(StartMenu, "no file") { EXPECT_ANY_THROW(loadFile()); }
  END;
  TEST(StartMenu, "file included") { EXPECT_NO_THROW(loadFile("state.txt")); }
  END;
  TEST(Hand, "Konstuction") {
    Hand hand;
    EXPECT_EQ(hand.getScore(), 0);
    Card card;
    card.setCard(Spades, Jack);
    hand.addCard(card);
    EXPECT_EQ(hand.getScore(), 10);
  }
  END;
  // és akkor itt lesz a többi teszt is
}
