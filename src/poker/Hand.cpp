#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <string>
#include <sstream>
#include <cassert>

#include "Hand.hpp"

Hand::Hand()
  : rank(Hand::Rank::HighCard) {
}

void Hand::add(Card card) {
  deck.add(card.rank, card.suit);
  rank = determineRanking();
}

Hand::Rank Hand::determineRanking() {
  if (deck.cards.size() < 5) {
    return Hand::Rank::HighCard;
  }

  deck.sort();

  int ranks[13] = {
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0
  };

  int oak2[13] = {
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0
  };

  int oak3[13] = {
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0
  };

  int oak4[13] = {
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0
  };

  int suits[4] = { 0, 0, 0, 0 };

  bool has4 = false;
  bool has3 = false;
  bool has2 = false;
  int pairs = 0;

  bool inSequence = true;

  for (auto card : deck.cards) {
    ranks[card.rank] += 1;
    suits[card.suit] += 1;
  }

  for (int i = 0; i < 4; i += 1) {
    Card& a = deck.cards.at(i);
    Card& b = deck.cards.at(i + 1);
    int d = a.rank - b.rank;
    // std::cout << a << " <> " << b << std::endl << d << std::endl;
    if (d != 1) {
      inSequence = false;
      break;
    }
  }

  for (int i = 0; i < 13; i += 1) {
    pairs += ~~(ranks[i] / 2);
    if (ranks[i] == 4) {
      has4 = true;
      oak4[i] += 1;
    }
    else if (ranks[i] == 3) {
      has3 = true;
      oak3[i] += 1;
    }
    else if (ranks[i] == 2) {
      oak2[i] += 1;
      has2 = true;
    }
  }

#if 0
  {
    std::cout << std::endl;
    std::cout << "        2  3  4  5  6  7  8  9  T  J  Q  K  A" << std::endl;
    std::cout << "Ranks: ";
    for (int i = 0; i < 13; i += 1) {
      std::cout << "[" << ranks[i] << "]";
    }
    std::cout << std::endl << "       ";
    for (int i = 0; i < 13; i += 1) {
      std::cout << "[" << oak4[i] << "]";
    }
    std::cout << std::endl << "       ";
    for (int i = 0; i < 13; i += 1) {
      std::cout << "[" << oak3[i] << "]";
    }
    std::cout << std::endl << "       ";
    for (int i = 0; i < 13; i += 1) {
      std::cout << "[" << oak2[i] << "]";
    }

    std::cout << std::endl << std::endl;
    std::cout << "        ❤  ♣  ♦  ♠" << std::endl;
    std::cout << "Suits: ";
    for (int i = 0; i < 4; i += 1) {
      std::cout << "[" << suits[i] << "]";
    }
    std::cout << std::endl;
    std::cout << "Pairs: " << pairs << std::endl;
    std::cout << "4: " << (has4 ? "Yes" : "No") << std::endl;
    std::cout << "3: " << (has3 ? "Yes" : "No") << std::endl;
    std::cout << "Sequential: " << (inSequence ? "Yes" : "No") << std::endl;
    std::cout << std::endl;
  }
#endif

  // do we have a royal flush?
  // A K Q J 10 same suit
  if (suits[deck.cards.at(0).suit] == 5) {
    // all same suit
    if (
      ranks[Card::Rank::Ace] == 1 &&
      ranks[Card::Rank::King] == 1 &&
      ranks[Card::Rank::Queen] == 1 &&
      ranks[Card::Rank::Jack] == 1 &&
      ranks[Card::Rank::Ten] == 1) {
      // boom baby
      return Hand::Rank::RoyalFlush;
    }
  }

  // do we have a straight flush?
  if (inSequence && suits[deck.cards.at(0).suit] == 5) {
    return Hand::Rank::StraightFlush;
  }

  // do we have four of a kind?
  if (has4) {
    return Hand::Rank::FourOfAKind;
  }

  auto sumOf = [](int count, int* items) {
    int sum = 0;
    for (int i = 0; i < count; i += 1) {
      sum += items[i];
    }
    return sum;
  };

  // do we have a full house?
  if (has3 && sumOf(13, oak2) == 1) {
    return Hand::Rank::FullHouse;
  }

  // do we have a flush?
  if (!inSequence && suits[deck.cards.at(0).suit] == 5) {
    return Hand::Rank::Flush;
  }

  // do we have a straight?
  if (inSequence && suits[deck.cards.at(0).suit] != 5) {
    return Hand::Rank::Straight;
  }

  // do we have three of a kind?
  if (has3) {
    return Hand::Rank::ThreeOfAKind;
  }

  // do we have two pair?
  if (pairs == 2) {
    return Hand::Rank::TwoPair;
  }

  // do we have a pair?
  if (has2) {
    return Hand::Rank::Pair;
  }

  return Hand::Rank::HighCard;
}

static const char* handRankNames[] = {
  "High Card",
  "Pair",
  "Two Pairs",
  "Three Of A Kind",
  "Straight",
  "Flush",
  "Full House",
  "Four Of A Kind",
  "Straight Flush",
  "Royal Flush"
};

std::ostream& operator<<(std::ostream& os, const Hand& hand) {
  std::copy(
    hand.deck.cards.begin(),
    hand.deck.cards.end(),
    std::ostream_iterator<Card>(os, " ")
  );
  os << "(" << handRankNames[hand.rank] << ")";
  return os;
}
