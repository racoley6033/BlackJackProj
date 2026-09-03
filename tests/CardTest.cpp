#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

using namespace std;

// Creates 52 card deck with 4 suits and 13 cards each (1-10, J, Q, K)
void CreateDeckOfCard(vector<Card> &deck) {
    for (int suit = 1; suit <= 4; ++suit) {
        for (int value = 1; value <= 13; ++value) {
            Card card(value, suit, true);  // Face-up by default
            deck.push_back(card);
        }
    }
}

// drawn cards
void ToString(const vector<Card> &deck) {
    for (const auto &card : deck) {
        cout << card.ToString() << endl;
    }
}

// shuffling 
void Shuffle(vector<Card> &deck) {
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}

// draw 4 cards the remove from vector
void DealCards(vector<Card> &deck) {
    cout << "\nDealing 4 cards:" << endl;
    for (int i = 0; i < 4; ++i) {
        if (!deck.empty()) {
            cout << deck.back().ToString() << endl;
            deck.pop_back();  // Remove card
        }
    }
}

int main() {
    vector<Card> deck;

    // create deck class
    CreateDeckOfCard(deck);

    // show the deck
    cout << "Initial deck of cards:" << endl;
    ToString(deck);

    // shuffle the deck
    Shuffle(deck);

    // show shuffled deck
    cout << "\nShuffled deck of cards:" << endl;
    ToString(deck);

    // draw 4 cards
    DealCards(deck);

    // show all remaining cards
    cout << "\nRemaining deck after dealing:" << endl;
    ToString(deck);

    return 0;
}
