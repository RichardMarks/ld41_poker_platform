#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
  public:
    static bool compare(const Card& a, const Card& b) {
      return a.rank > b.rank;
    }

    enum Rank {
      Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King,
      Ace
    };

    enum Suit {
      Hearts, Clubs, Diamonds, Spades
    };

    Card(Rank r, Suit s);
    Card(const Card& other);
    Card& operator=(const Card& other);

    inline bool operator<(const Card& other) {
      return rank < other.rank;
    }

    inline bool operator>(const Card& other) {
      return rank > other.rank;
    }

    Rank rank;
    Suit suit;
};

extern std::ostream& operator<<(std::ostream& os, const Card& card);

#endif // !CARD_H
