/**
 * @file Player.h
 * @brief
 * @version 0.1
 * @date 2024-10-29
 */

#pragma once

#include <vector>
#include <string>
#include "Card.h"

class Player {
public:
    Player(const std::string& name);
    const std::string& getName() const;
    int getHandValue() const;
    bool isBusted() const;
    bool hasBlackjack() const;
    std::vector<Card> getHand() const { return hand; }
    void addCardToHand(const Card &card);
    void clearHand();

private:
    std::string name;
    std::vector<Card> hand;
    int calculateHandValue() const;
};
