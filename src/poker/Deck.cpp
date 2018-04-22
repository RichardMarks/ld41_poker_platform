#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <string>
#include <sstream>
#include <cassert>

#include "Deck.hpp"

Deck::Deck(Type t) {
  if (t == Deck::Type::Standard) {
    for (int r = 0; r < 13; r += 1) {
      for (int s = 0; s < 4; s += 1) {
        Card::Rank rank = static_cast<Card::Rank>(r);
        Card::Suit suit = static_cast<Card::Suit>(s);
        add(rank, suit);
      }
    }
  }
}

void Deck::add(Card::Rank rank, Card::Suit suit) {
  cards.push_back(Card(rank, suit));
}

void Deck::shuffle(int count) {
  if (cards.size()) {
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i < count; i += 1) {
      std::shuffle(cards.begin(), cards.end(), g);
    }
  }
}

void Deck::sort() {
  std::stable_sort(cards.begin(), cards.end(), Card::compare);
}
