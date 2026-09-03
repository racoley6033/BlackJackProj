/**
 * @file game.cpp
 * @brief
 * @version 0.1
 * @date 2024-10-29
 */

#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

void playRound(Player& player, Player& dealer, Deck& deck);
void playerTurn(Player& player, Deck& deck);
void dealerTurn(Player& dealer, Deck& deck);

int main() {
    Deck deck;
    Player player("Player");
    Player dealer("Dealer");

    while (true) {
        deck.shuffle();
        player.clearHand();
        dealer.clearHand();

        playRound(player, dealer, deck);

        char choice;
        cout << "Play again? (y/n): ";
        cin >> choice;
        if (choice != 'y') break;
    }

    return 0;
}

void playRound(Player& player, Player& dealer, Deck& deck) {
    player.addCardToHand(deck.dealCard());
    player.addCardToHand(deck.dealCard());
    dealer.addCardToHand(deck.dealCard());
    dealer.addCardToHand(deck.dealCard());

    cout << "\nPlayer's hand:\n";
    for (const Card& card : player.getHand()) {
        cout << card.ToString() << endl;
    }

    playerTurn(player, deck);

    if (!player.isBusted()) {
        cout << "\nDealer's hand:\n";
        for (const Card& card : dealer.getHand()) {
            cout << card.ToString() << endl;
        }
        dealerTurn(dealer, deck);
    }

    if (player.isBusted()) {
        cout << "You busted! Dealer wins.\n";
    } else if (dealer.isBusted() || player.getHandValue() > dealer.getHandValue()) {
        cout << "You win!\n";
    } else if (player.getHandValue() < dealer.getHandValue()) {
        cout << "Dealer wins.\n";
    } else {
        cout << "It's a tie!\n";
    }
}

void playerTurn(Player& player, Deck& deck) {
    while (true) {
        cout << "\nYour hand value: " << player.getHandValue() << endl;
        char choice;
        cout << "Hit or stand? (h/s): ";
        cin >> choice;

        if (choice == 'h') {
            player.addCardToHand(deck.dealCard());
            if (player.isBusted()) {
                cout << "Busted! Final hand value: " << player.getHandValue() << endl;
                break;
            }
        } else if (choice == 's') {
            break;
        }
    }
}

void dealerTurn(Player& dealer, Deck& deck) {
    while (dealer.getHandValue() < 17) {
        dealer.addCardToHand(deck.dealCard());
    }

    cout << "Dealer's final hand value: " << dealer.getHandValue() << endl;
}
