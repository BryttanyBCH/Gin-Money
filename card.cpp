// ♣ ♦ ♥ ♠
#include "card.h"

Card::Card(int cardNumIn, int suitNumIn)            // card constructor
{
    cardIndex = cardNumIn + (suitNumIn*13-13);      // for sorting: records the card's initial position in the deck
    
    cardSuit = suitNumIn;                           // also for sorting: for making sure that ascending melds and same-card melds are valid 
    
    if(cardNumIn > 10) {cardPoints=10;}             // sets the card's point value
    else {cardPoints=cardNumIn;}
   
    switch(suitNumIn) {                             // Sets the pretty suit character depending on the value of the suit
        case 1:
        cardDisplay="♣";
        break;
        case 2:
        cardDisplay="♦";
        break;
        case 3:
        cardDisplay="♥";
        break;
        default:                                    // I made spades the default case instead of case 4 to omit an unneeded comparison
        cardDisplay="♠";
        break;
    }
    
    std::string brace = "[";                        // I LOVE C++! (You cannot add two literal strings, the leftmost string must be a string variable)
    
    if(!(cardNumIn < 10 && cardNumIn > 1)) {        // The card class has been updated so that it can now print a 10 without having to resort to printing a 'T'
        if(cardNumIn == 13) {cardDisplay = brace + " K" + cardDisplay + "]";}
        else if(cardNumIn == 12) {cardDisplay = brace + " Q" + cardDisplay + "]";}
        else if(cardNumIn == 11) {cardDisplay = brace + " J" + cardDisplay + "]";}
        else if(cardNumIn == 1) {cardDisplay = brace + " A" + cardDisplay + "]";}
        else {cardDisplay = brace + "10" + cardDisplay + "]";}
    }
    else {cardDisplay = brace + " " + std::to_string(cardNumIn) + cardDisplay + "]";}
    
}

int Card::getIndex() {return cardIndex;}            // Returns the index of the card, useful for sorting and checking melds

int Card::getCardPoints() {return cardPoints;}      // Returns the point value of the card, for scoring

int Card::getSuit() {return cardSuit;}              // Returns the suit of the card, useful for checking melds

std::string Card::getCardDisplay() {return cardDisplay;}

Card& Card::operator=(const Card& cardIn)           // Overloaded equal operator
{
    cardPoints = cardIn.cardPoints;
    cardDisplay = cardIn.cardDisplay;
    cardIndex = cardIn.cardIndex;
}