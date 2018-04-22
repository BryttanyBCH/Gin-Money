#ifndef PLAYER_H
#define PLAYER_H
#include "container.h"

class Player: public Container {        // Players: They get to choose which cards to exchange
    
    public:
        
        Player(std::string nameIn);     // token constructor
        Card sendCard();                // deletes a chosen card, but returns it
        void recieveCard(Card cardIn);  // adds card to possession, presumably from sendCard()
        void displayDebug();            // couts possession of cards, is actually used outside of debug
        std::string getName();          
        
    
    private:
        
        std::vector<Card> cardsPosessed;
        std::string name;
    
};
#endif