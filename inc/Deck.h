/**
 * @file Deck.h
 * @brief
 * @version 0.1
 * @date 2024-10-29
 */

#pragma once

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    void shuffle();
    Card dealCard();
    int size() const;

private:
    std::vector<Card> deck;
    void buildDeck();
};
