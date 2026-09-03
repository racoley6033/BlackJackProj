/**
 * @file Card.cpp
 * @brief
 * @version 0.1
 * @date 2024-10-29
 */

#include "Card.h"
#include <stdexcept>

Card::Card(int value, int suit, bool isFaceUp)
    : _value(value), _suit(suit), _isFaceUp(isFaceUp)
{
    if (value < 1 || value > 13)
        throw runtime_error("Card value out of range. Must be 1 - 13");

    if (suit < 1 || suit > 4)
        throw runtime_error("Suit value out of range. Must be 1 - 4");

    convertValueToString(value);
    convertSuitToString(suit);
}

void Card::convertValueToString(int val)
{
    switch (val)
    {
    case 1: _strValue = "ACE"; break;
    case 11: _strValue = "JACK"; break;
    case 12: _strValue = "QUEEN"; break;
    case 13: _strValue = "KING"; break;
    default: _strValue = to_string(val); break;
    }
}

void Card::convertSuitToString(int suit)
{
    switch (suit)
    {
    case 1: _strSuit = "HEARTS"; break;
    case 2: _strSuit = "DIAMONDS"; break;
    case 3: _strSuit = "CLUBS"; break;
    case 4: _strSuit = "SPADES"; break;
    default: throw runtime_error("Invalid suit value. Must be between 1 and 4.");
    }
}

string Card::ToString() const
{
    return _isFaceUp ? _strValue + " of " + _strSuit : "Face-down";
}
