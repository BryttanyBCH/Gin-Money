#ifndef PLAYER_H
#define PLAYER_H
#include "container.h"
#include<vector>

class Player: public Container {        // Players: They get to choose which cards to exchange
    
    public:
        
        Player();
        Player(std::string nameIn);     // token constructor
        Card sendCard();                // deletes a chosen card, but returns it
        Card sendCard(int index);
        void recieveCard(Card cardIn);  // adds card to possession, presumably from sendCard()
        void displayHand();            // couts possession of cards, is actually used outside of debug
        void clearHand();               // Clear players hand after each round
        std::string getName();
        bool knockSend(Player& target, int cardOutIndex);
        int getHandSize(void);          //this will usually be 10, but is needed during knocking
        std::vector<int> getDWIndexes(void);
        std::vector<int> anyMelds(void);
        
        int countDeadWood();
        std::vector<int> anyRuns();
        std::vector<int> anySets();
        void findDeadwood();
        
        Player& operator=(const Player& playerIn);
    
    protected: //needs to be protected so that ai can inherit these variables
        std::vector<Card> cardsPosessed;
        std::string name;
        std::vector<int> deadWoodIndexes;
    
};
#endif