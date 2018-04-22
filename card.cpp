// ♣ ♦ ♥ ♠
#include "card.h"

Card::Card(int cardNumIn, int suitNumIn)        // card constructor
{
    // if statement assigns card number, T is for ten!
    if (cardNumIn == 1) {
        cardNum = "A";
    } else if (cardNumIn <= 9) {
        cardNum = std::to_string(cardNumIn);
    } else if (cardNumIn == 10) {
        cardNum = "T";
    } else if (cardNumIn == 11) {
        cardNum = "J";
    } else if (cardNumIn == 12) {
        cardNum = "Q";
    } else if (cardNumIn == 13) {
        cardNum = "K";
    } else {
        cardNum = "?";  // for troubleshooting
    }
    
    // switch statement assigns cards with suit
    switch (suitNumIn) {
        case 1:
            cardSuit = "♣";
            break;
        case 2:
            cardSuit = "♦";
            break;
        case 3:
            cardSuit = "♥";
            break;
        case 4:
            cardSuit = "♠";
            break;
        default:
            cardSuit = "?";     // for troubleshooting
            break;
    }
    
    // unique index number (for sorting) is assigned to cards as they are defined
    cardIndex = cardNumIn + ((suitNumIn * 13) - 13);
}

std::string Card::cardDisplay()     // returns a string icon of a given card
{
    std::string cardOut = "[" + cardNum + cardSuit + "]";
    return cardOut;
}

int Card::getIndex()
{
    return cardIndex;
}

Card& Card::operator=(const Card& cardIn)
{
    cardSuit = cardIn.cardSuit;
    cardNum = cardIn.cardNum;
    cardIndex = cardIn.cardIndex;
}