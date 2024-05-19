#include "Tests.hpp"

void Test() {
  TEST(loadFile, "no file") {
    EXPECT_ANY_THROW(Players players = loadFile(); std::invalid_argument(""));
  } END;
  TEST(loadFile, "invalid file") {
    EXPECT_ANY_THROW(Players players = loadFile("asd.txt"); std::invalid_argument(""));
  } END;
  TEST(loadFile, "file included") { //valamiert ketszer hivodik meg a destruktor
    EXPECT_NO_THROW(Players players = loadFile("state.txt"));
  } END;
  TEST(saveFile, "no file") {
    Players players = Players();
    EXPECT_ANY_THROW(saveFile(players); std::invalid_argument(""));
  } END;
  TEST(saveFile, "invalid file") {
    Players players = Players();
    EXPECT_ANY_THROW(saveFile(players, ""); std::runtime_error(""));
  } END;
  TEST(saveFile, "file included") {
    Players players = loadFile("state.txt");
    EXPECT_NO_THROW(saveFile(players, "state.txt"));
  } END;
  TEST(Hand, "Konstuction") {
    Hand hand;
    EXPECT_EQ(hand.getScore(), 0);
    Card *card = new class Spades(Jack);
    hand.addCard(card);
    EXPECT_EQ(hand.getScore(), 10);
    hand.deleteCards();
  } END;
  TEST(Hand, "AddCard") {
    Hand hand;
    Card *card = new class Hearts(Five);
    EXPECT_NO_THROW(hand.addCard(card));
    hand.deleteCards();
  } END;
  TEST(Hand, "GetSize") {
    Hand hand;
    Card *card = new class Diamonds(Ace);
    Card *card2 = new class Clubs(King);
    hand.addCard(card);
    EXPECT_EQ(hand.getSize(), 1);
    hand.addCard(card2); 
    EXPECT_EQ(hand.getSize(), 2);
    hand.deleteCards();
  } END;
  TEST(Hand, "GetScore") {
    Hand hand;
    Card *card = new class Diamonds(Ace);
    hand.addCard(card);
    EXPECT_EQ(hand.getScore(), 11);
    hand.deleteCards();
  } END;
  TEST(Hand, "DeleteCard") {
    Hand hand;
    Card *card = new class Spades(Ace);
    hand.addCard(card);
    hand.deleteCards();
    EXPECT_EQ(hand.getSize(), 0);
    EXPECT_EQ(hand.getScore(), 0);
  } END;
  TEST(Card, "Score") {
    Card *card = new class Spades(Ten);
    EXPECT_EQ(card->getValue(), 10);
    delete card;
  } END;
  TEST(Card, "Konstuction") { //itt nem jo
    Card *card = new class Spades(Ten);
    EXPECT_EQ(card->getValue(), 10);
    EXPECT_EQ(card->getSuit(), Spades);
    EXPECT_EQ(card->getRank(), Ten);
    delete card;
  } END;
  TEST(Card, "Print") {
    Card* card = new class Diamonds(Ten);
    EXPECT_STREQ(card->printLn(0), "----------");
    EXPECT_STREQ(Renderer::format(card->printLn(1), RANKS[card->getRank()]).c_str(), "| 10     |");
    delete card;
  } END;
  TEST(Cards, "Generate") {
    Card** cards = generateCards();
    EXPECT_EQ(cards[0]->getSuit(), Clubs);
    EXPECT_EQ(cards[0]->getRank(), Two);
    for (int i = 0; i < 52; i++) { delete cards[i]; }
    delete[] cards;
  } END;
  TEST(Player, "Konstuction") {
    Player player;
    EXPECT_STREQ(player.getName(), "Default");
    EXPECT_EQ(player.getBalance(), 5000);
  } END;
  TEST(Player, "Name") {
    Player player("John");
    EXPECT_STREQ(player.getName(), "John");
  } END;
  TEST(Player, "Balance") {
    Player player("Michael", 69420);
    EXPECT_EQ(player.getBalance(), 69420);
    EXPECT_STREQ(player.getName(), "Michael");
  } END;
  TEST(Player, "Bet") {
    Player player("Jonathan", 1337);
    player.placeBet(69);
    EXPECT_EQ(player.getBalance(), 1268);
  } END;
  TEST(Player, "Win") {
    Player player("Josh");
    player.placeBet(100);
    player.win(100);
    EXPECT_EQ(player.getBalance(), 5100);
  } END;
  TEST(Player, "Lose") {
    Player player("Sheldon");
    player.placeBet(100);
    player.lose(100);
    EXPECT_EQ(player.getBalance(), 4900);
  } END;
  TEST(Player, "Draw") {
    Player player("Penny");
    player.placeBet(100);
    player.draw(100);
    EXPECT_EQ(player.getBalance(), 5000);
  } END;
  TEST(Players, "Konstuction") {
    Players *players = new Players();
    EXPECT_EQ(players->getSize(), 0);
    delete players;
  } END;
  TEST(Players, "createPlayer") {
    Players *players = new Players();
    players->createPlayer("Howard");
    EXPECT_EQ(players->getSize(), 1);
    EXPECT_STREQ(players->operator[](0).getName(), "Howard");
    delete players;
  } END;
  TEST(Players, "CreateNewPlayer") {
    Players players = Players();
    CreateNewPlayer(players);
    EXPECT_EQ(players.getSize(), 1);
    EXPECT_STREQ(players[0].getName(), "John");
  } END;
  TEST(CardsRender, "Format") {
    EXPECT_STREQ(Renderer::format("%s", "Hello World").c_str(), "Hello World");
  } END;
  TEST(CardsRender, "RenderCards") {
    Hand hand;
    Card* card = new class Spades(Jack);
    hand.addCard(card);
    std::stringstream ss;
    Renderer::renderCards(&hand, ss);
    EXPECT_STREQ("---------- \n| J      | \n|    #   | \n|  ##### | \n|  ##### | \n|  ##### | \n|    #   | \n|      J | \n---------- \nScore: 10\n", ss.str().c_str());
    hand.deleteCards();
  } END;
  TEST(placeBet, "PlaceBet") {
    Player player("John", 5000);
    placeBet(player); // input 100
    EXPECT_EQ(player.getBalance(), 4900);
  } END;
  TEST(setupHands, "SetupHands") {
    Player player("John", 5000);
    Hand dealerHand;
    std::vector <Card*> deck = shuffleCards(generateCards());
    Card* heldCard = setupHands(player, dealerHand, &deck);
    EXPECT_STREQ(heldCard->printLn(0), "----------");
    for (size_t i = 0; i < deck.size(); i++) {
      if (deck[i] != nullptr)
        delete deck[i];
      deck[i] = nullptr;
    }
    deck.clear();
    delete heldCard;
  } END;
  TEST(calculateWinner, "CalculateWinner") {
    Player player("John", 5000);
    player.placeBet(100);
    int bet = 100;
    Hand dealerHand;
    dealerHand.addCard(new class Clubs(Ace));
    dealerHand.addCard(new class Diamonds(Ace));
    player.getHand()->addCard(new class Clubs(Ace));
    player.getHand()->addCard(new class Diamonds(King));
    calculateWinner(player, bet, &dealerHand);
    EXPECT_EQ(player.getBalance(), 5100);
    dealerHand.deleteCards();
    player.getHand()->deleteCards();
  } END;
}
