/**
 * @file Card.h
 * @brief
 * @version 0.1
 * @date 2024-10-29
 */

#pragma once
#include <string>

using namespace std;

class Card
{
private:
    int _value;
    string _strValue;
    int _suit;
    string _strSuit;
    bool _isFaceUp;

    void convertValueToString(int val);
    void convertSuitToString(int suit);

public:
    Card(int value, int suit, bool isFaceUp);
    int getValue() const { return _value; }
    string ToString() const;
};
