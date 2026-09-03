/**
 * @file Deck.cpp
 * @brief
 * @version 0.1
 * @date 2024-10-29
 */

#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {
    buildDeck();
    shuffle();
}

void Deck::buildDeck() {
    deck.clear();
    for (int suit = 1; suit <= 4; ++suit) {
        for (int value = 1; value <= 13; ++value) {
            deck.push_back(Card(value, suit, true));
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

Card Deck::dealCard() {
    if (deck.empty()) throw std::runtime_error("No cards left in the deck.");
    Card card = deck.back();
    deck.pop_back();
    return card;
}

int Deck::size() const { return deck.size(); }
