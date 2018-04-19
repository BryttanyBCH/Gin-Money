#include "deck.h"
#include <cstdlib>
#include <ctime>

int randomgen (int i) {return std::rand()%i;}

Deck::Deck(void) {
    
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            allCards.push_back(Card(j,i));
        }
    }
    
    std::srand(std::time(0));
    std::random_shuffle(allCards.begin(), allCards.end(), randomgen);
}

void Deck::setAsDiscard(void) { allCards.clear();}

//methods to take a card from the stock and get its count
Card Deck::takeCard(void) {
    Card temp = allCards.back();
    allCards.pop_back();
    return temp;
}
int Deck::getCount(void) const {return allCards.size();}
void Deck::addCard(Card c) {allCards.push_back(c);}
Card Deck::viewCard(void) const {return allCards.back();}