#include <iostream>
#include "Deck.h"

using namespace std;

int main() {
    Deck deck;
    cout << "Dealing 4 cards:" << endl;
    for (int i = 0; i < 4; ++i) {
        try {
            Card card = deck.Deal();
            cout << card.ToString() << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    return 0; // returns the cards drawn
}
