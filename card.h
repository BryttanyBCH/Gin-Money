#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

class Card 
{
    public:
       
        Card(int cardNumIn, int suitNumIn);     // card constructor
        std::string cardDisplay();              // returns card icon
        int getIndex();                         // for sorting
        Card& operator=(const Card& cardIn);
        
    private:
       
        std::string cardSuit;
        std::string cardNum;                    // 'T' is for 10!
        int cardIndex;
};
#endif