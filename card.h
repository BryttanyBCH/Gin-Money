#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

class Card 
{
    public:
       
        Card(int cardNumIn, int suitNumIn);     // card constructor
        std::string getCardDisplay();           // displays the card
        int getIndex();                         // for sorting, gets where the card was in the original deck
        int getSuit();                          // for sorting. Example: if c1.getSuit() != c3.getSuit() != c3.getSuit() and the indexes of the cards are each 13 apart, then there is a meld
        int getCardPoints();                    // Returns the point value of the card    
        Card& operator=(const Card& cardIn);    // for setting cards equal to each other
        
    private:
       
        //std::string cardSuit; Instead of storing these, we can just combine them to make the cardDisplay when the card gets constructed
        //std::string cardNum;
        int cardIndex;                          // The ace of clubs is the first card in the deck so this int would be 1 for it, the king of spades is the last card so it would be number 52 (this makes sorting cards easier)
        int cardPoints;                         // how many points is the card worth (if cardNum>10 then this is 10)
        int cardSuit;                           // we still need to store the card suit, so that we can make sure that ascending cards are all in the same suit when counting points
        std::string cardDisplay;
};
#endif