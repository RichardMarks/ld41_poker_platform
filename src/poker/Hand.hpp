#ifndef HAND_H

#include <iostream>
#include "Deck.hpp"

class Hand {
  public:
    enum Rank {
      HighCard,
      Pair,
      TwoPair,
      ThreeOfAKind,
      Straight,
      Flush,
      FullHouse,
      FourOfAKind,
      StraightFlush,
      RoyalFlush
    };

    Hand ();

    inline bool operator<(const Hand& other) {
      return rank < other.rank;
    }

    inline bool operator>(const Hand& other) {
      return rank > other.rank;
    }

    void add(Card card);

    Deck deck;
    Rank rank;

  private:
    Rank determineRanking();
};

extern std::ostream& operator<<(std::ostream& os, const Hand& hand);

#endif // !HAND_H
