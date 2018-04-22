#ifndef DECK_H

#include "Card.hpp"

#include <vector>

class Deck {
  public:
    enum Type { Empty, Standard };

    Deck (Type t = Empty);
    void add(Card::Rank rank, Card::Suit suit);
    void shuffle(int count);
    void sort();

    std::vector<Card> cards;
};

#endif // !DECK_H
