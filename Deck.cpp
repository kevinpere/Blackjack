#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include "Deck.h"
using namespace std;

// int A = 1;
// int J = 10;
// int Q = 10;
// int K = 10;
string A = "A";
string J = "J";
string Q = "Q";
string K = "K";

Deck::Deck() 
    : next(0) {
        deck = { A, "2", "3", "4", "5", "6", "7", "8", "9", "10", J, Q, K,
                 A, "2", "3", "4", "5", "6", "7", "8", "9", "10", J, Q, K,
                 A, "2", "3", "4", "5", "6", "7", "8", "9", "10", J, Q, K,
                 A, "2", "3", "4", "5", "6", "7", "8", "9", "10", J, Q, K };
    }

bool Deck::empty() const {
    if (next == 52) {
        return true;
    }
    else {
        return false;
    }
}

void Deck::shuffle() {
    srand( time(NULL) );

    for (int i = 51; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(deck.at(i), deck.at(j));
    }
}

string Deck::dealOne() {
    assert(Deck::empty() == false);
    string nextCard;
    nextCard = deck.at(next);
    ++next;
    return nextCard;
}

void printDeck() {
    cout << "DECK:" << endl;
    int i = 0;
    for (int j = 0; j < 52; ++j) {
        cout << j << " ,";
        ++i;
        if (i % 13 == 0) {
            cout << endl;
        }
    }
}