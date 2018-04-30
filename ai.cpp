#include "ai.h"
#include<stdlib.h> //needed for absolute value

void AI::takeTurn(Pile* stock, Pile* disc)
{
    findDeadwood();
    int initialDeadwood = countDeadWood();
    
    // consider taking from discard. If no card is taken from discard, take from stock
    if(!checkDiscard(disc, initialDeadwood))
    {
        //take from stock
        recieveCard(stock->sendCard());
    }
    
    //recalculate deadwood value
    findDeadwood();
    int newDeadwood = countDeadWood();
    
    //breaks and doesn't discard if the AI has Big Gin
    if(newDeadwood == 0)
        return;
    
    //find which index to discard from
    int discard = removeIndex(newDeadwood);
    
    //discard that one
    disc->recieveCard(sendCard(discard));
}

bool AI::willKnock(void)
{
    findDeadwood();
    if(countDeadWood() < 10)        
        return true;
    return false;
}

bool AI::checkDiscard(Pile* disc, int startVal)
{
    //store the first card from the discard pile
    Card temp = disc->sendCard();
    
    //add a copy of the card to the hand
    recieveCard(temp);
    
    //check if deadwood count increased
    findDeadwood();
    int newDeadwood = countDeadWood();
    
    //keep the card if dw didn't increase
    if(newDeadwood - startVal <= 0) {
        lastCardIndex = temp.getIndex();
        return true;
    }
    
    //iterate through all cards in index
    for(Card c : cardsPosessed) {
        //see if other cards in the hand are within r = 2, but areNOT the new card
        if(c != temp && c.getSuit() == temp.getSuit() && abs(c.getIndex()%13 - temp.getIndex()%13) < 2) {
            lastCardIndex = temp.getIndex();
            return true; //keep the card in this case
        }
    }
    
    //at this point, if the method is still running, we don't
    // want to keep this card so return it to the discard pile.
    // we must iterate through the hand again to find the original
    // card's location and then send it to discard
    for(int i = 0; i < cardsPosessed.size(); i++) {
        if(cardsPosessed.at(i) == temp) {
            disc->recieveCard(sendCard(i));
            break;
        }
    }
    
    return false;
}

int AI::removeIndex(int startVal)
{
    Card temp;
    //declare a val to keep track of minimum deadwood added by a card's absence and one to keep an index
    int minDiff = 1000;
    int output = 0;
    
    //iterate through the deck
    for(int i = 0; i < cardsPosessed.size(); i++) {
        //copy the current card into temp
        temp = sendCard(i);
        //recalculate deadwood
        findDeadwood();
        int newDeadwood = countDeadWood();
        
        //if the change in DW is less than min, change min and index
        // also, don't discard if it just came from discard
        if(newDeadwood - startVal < minDiff && temp.getIndex() != lastCardIndex) {
            minDiff = newDeadwood - startVal;
            output = i;
        }
        
        //readd the card to hand
        recieveCard(temp);
    }
    
    //return the index to remove
    return output;
}

AI& AI::operator=(const AI& aiIn)           // Overloaded equal operator
{
    cardsPosessed = aiIn.cardsPosessed;
    name = aiIn.name;
    deadWoodIndexes = aiIn.deadWoodIndexes;
    lastCardIndex = aiIn.lastCardIndex;
}
