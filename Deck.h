#ifndef DECK_H
#define DECK_H

#include <string>
#include <array>
#include <vector>

class Deck {
public:
    Deck();
    std::string dealOne();
    void shuffle();
    bool empty() const;
    void printDeck();

private:
    static const int DECK_SIZE = 52;
    std::vector<std::string> deck;
    int next;
};

#endif