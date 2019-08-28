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
#include "Deck.h"
using namespace std;


class Game{
private:
    Deck deck;
    vector<string> playerHand;
    vector<string> dealerHand;
    vector<int> playerNumHand;
    vector<int> dealerNumHand;

public:
    Game() { }

    void shuffleCards() {
        deck.shuffle();
    }

    void deal() {

        for (int i = 0; i < 2; ++i) {
            playerHand.push_back(deck.dealOne());
            if (playerHand[i] == "J" || playerHand[i] == "Q" || playerHand[i] == "K") {
                playerNumHand.push_back(10);
            }
            else if (playerHand[i] == "A") {
                playerNumHand.push_back(1);
            }
            else {
                playerNumHand.push_back(stoi(playerHand[i]));
            }

            dealerHand.push_back(deck.dealOne());
            if (dealerHand[i] == "J" || dealerHand[i] == "Q" || dealerHand[i] == "K") {
                dealerNumHand.push_back(10);
            }
            else if (dealerHand[i] == "A") {
                dealerNumHand.push_back(1);
            }
            else {
                dealerNumHand.push_back(stoi(dealerHand[i]));
            }
            
        }

        int playerSum = 0;
        for (size_t i = 0; i < playerNumHand.size(); ++i) {
            if (playerNumHand[i] == 1 && playerSum + 11 <= 21) {
                playerNumHand[i] = 11;
                //playerSum =+ playerNumHand[i];
            }
            playerSum += playerNumHand[i];
        }

        cout << "YOU WERE DEALT:" << endl;
        cout << playerHand.at(0) << endl;
        cout << playerHand.at(1) << endl;

        cout << "THE DEALER SHOWS:" << endl;
        cout << dealerHand.at(0) << endl;
        cout << "X" << endl;

        // int playerSum = 0;
        // for (auto i : this->playerNumHand) {
        //     if (i == 1 && playerSum + 11 <= 21) {
        //         i = 11;
        //     }
        // }
        // for (size_t i = 0; i < playerNumHand.size(); ++i) {
        //     playerSum += playerNumHand[i];
        // }
        cout << "Youre count is " << playerSum << endl;
    }
};



int main() {
    //Deck deck;
    Game bjack;

    bjack.shuffleCards();

    bjack.deal();
}