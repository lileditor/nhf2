#include "Tests.hpp"

void Test() {
  TEST(loadFile, "no file") { EXPECT_ANY_THROW(loadFile()); }
  END;
  TEST(loadFile, "file included") { EXPECT_NO_THROW(loadFile("state.txt")); }
  END;
  TEST(Hand, "Konstuction") {
    Hand hand;
    EXPECT_EQ(hand.getScore(), 0);
    Card *card = new Card(Spades, Jack);
    hand.addCard(card);
    EXPECT_EQ(hand.getScore(), 10);
  }
  END;
  TEST(Card, "Score") END;
  TEST(Card, "Konstuction") END;
  // és akkor itt lesz a többi teszt is
}
