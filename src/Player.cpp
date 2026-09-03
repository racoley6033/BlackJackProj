/**
 * @file Player.cpp
 * @brief
 * @version 0.1
 * @date 2024-10-29
 */

#include "Player.h"

Player::Player(const std::string& name)
    : name(name) {}

const std::string& Player::getName() const { return name; }

void Player::addCardToHand(const Card& card) { hand.push_back(card); }

void Player::clearHand() { hand.clear(); }

int Player::calculateHandValue() const {
    int totalValue = 0;
    int aces = 0;

    for (const Card& card : hand) {
        int value = card.getValue();
        if (value > 10) value = 10;
        if (value == 1) aces++;
        totalValue += value;
    }

    while (aces > 0 && totalValue + 10 <= 21) {
        totalValue += 10;
        aces--;
    }

    return totalValue;
}

int Player::getHandValue() const { return calculateHandValue(); }

bool Player::isBusted() const { return getHandValue() > 21; }

bool Player::hasBlackjack() const { return getHandValue() == 21 && hand.size() == 2; }
