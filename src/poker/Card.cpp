#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <string>
#include <sstream>
#include <cassert>

#include "Card.hpp"

Card::Card(Card::Rank r, Card::Suit s)
  : rank(r), suit(s) {
}

Card::Card(const Card& other) {
  rank = other.rank;
  suit = other.suit;
}

Card& Card::operator=(const Card& other) {
  if (this != &other) {
    rank = other.rank;
    suit = other.suit;
  }

  return *this;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
  static const std::string rankNames[] = {
    " 2", " 3", " 4", " 5",
    " 6", " 7", " 8", " 9", "10",
    " J", " Q", " K", " A"
  };
  static const std::string suitNames[] = {
    "❤", "♣", "♦", "♠︎"
  };
  os << rankNames[card.rank] << " " << suitNames[card.suit];
  return os;
}
