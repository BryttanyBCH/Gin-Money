#ifndef PILE_H
#define PILE_H
#include "container.h"

class Pile: public Container {          // Piles: They can only exchange their top (back) cards
    
    public:
        
        Pile(std::string nameIn);       // token constructor
        Card sendCard();                // deletes card from posscession, but returns it
        void recieveCard(Card cardIn);  // adds card to possession, presumably from sendCard()
        void displayDebug();            // couts the possessed cards, for debugging
        void makeDeck();                // generates a deck of 52 cards
        std::string getName();           
        std::string getTopCard();       // returns top card, rename?
    
    private:
        
        std::vector<Card> cardsPosessed;
        std::string name;
    
};
#endif