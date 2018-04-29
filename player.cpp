#include "player.h"
#include <vector>
#include <limits> //used to validate user input

// for sorting player hands
bool comp(Card c1, Card c2)
{
    return c1.getIndex() < c2.getIndex();
}

// token constructors
Player::Player()
{
    name = "Unknown";
}

Player::Player(std::string nameIn)
{
    name = nameIn;
}

void Player::clearHand()
{
    cardsPosessed.clear();
}

// deletes a chosen card, but returns it
Card Player::sendCard()
{
    int select;
    std::cin >> select;
    
    while(select < 0 || select >= cardsPosessed.size() || std::cin.fail()) {
        std::cin.clear(); //clears the .fail() error from buffer
        std::cin.ignore(100,'\n'); //ignores up to 100 characters in cin
        std::cout << "Invalid choice. Try again. ";
        std::cin >> select;
    }
    
    Card temp = cardsPosessed.at(select);
    cardsPosessed.erase(cardsPosessed.begin() + select); 
    return temp;
}

Card Player::sendCard(int index)
{
    Card temp = cardsPosessed.at(index);
    cardsPosessed.erase(cardsPosessed.begin() + index);
    return temp;
}

// adds card to possession, presumably from sendCard()
void Player::recieveCard(Card cardIn)
{
    cardsPosessed.push_back(cardIn);
    sort(cardsPosessed.begin(), cardsPosessed.end(), comp);
}

// couts possession of cards, is actually used outside of debug
void Player::displayDebug()
{
    for (auto e : cardsPosessed) {
        std::cout << e.getCardDisplay();
    }
    std::cout << std::endl;
}

std::string Player::getName()
{
    return name;
}

//anyRuns checks if the deck has any runs in it and returns a vector of the cards that DON'T MAKE UP RUNS
std::vector<int> Player::anyRuns(void) { //need to put in header file vector<Card> startPos=deckIn iterator dumb int good 
    std::vector<int> runs = {};
    
        for(int j=0;j<cardsPosessed.size()-1;j++) { //The last card of the vector should not be called in this loop
            
            int k=0;
            
            //this while loop used to check the card that was at k, but k was fixed so that it started at zero. That is why only the first few parts of the deck got checked
            while((j+k+1<cardsPosessed.size()-1) && (cardsPosessed.at(j+k+1).getIndex() == cardsPosessed.at(j+k).getIndex()+1) && (cardsPosessed.at(j+k+1).getSuit() == cardsPosessed.at(j+k).getSuit())) {
                k++;
            }
            if((j+k)>=cardsPosessed.size()-1) {j=cardsPosessed.size()-2;} //minus 2, so that the loop incriments j to size-1 (which is the index of the final card in the thingy)
            if(k>=2) {
                for(int x=j+k;x>=j;x--) {runs.push_back(x);}
                j+=k;
            }
            //else {runs.push_back(j);}
            
        }
        if(runs.size()>=2) {
            if((cardsPosessed.at(cardsPosessed.size()-1).getIndex() == cardsPosessed.at(runs.size()-1).getIndex()+1) && (cardsPosessed.at(cardsPosessed.size()-1)).getSuit() == cardsPosessed.at(runs.size()-1).getSuit()) {
                if((cardsPosessed.at(cardsPosessed.size()-1).getIndex() == cardsPosessed.at(runs.size()-2).getIndex()+2) && (cardsPosessed.at(cardsPosessed.size()-1).getSuit() == cardsPosessed.at(runs.size()-2).getSuit())) {
                    runs.push_back(cardsPosessed.size()-1);
                }
            }
        }
        return runs;
        
}

//need to check for intersecting melds
std::vector<int> Player::anySets(void) { //need to put in header file
    std::vector<int> sets = {};
        for(int i=0;i<cardsPosessed.size();i++) {
            int matches=0;
            for(int j=0;j<cardsPosessed.size();j++) {
                if(((cardsPosessed.at(j).getIndex())%13-(cardsPosessed.at(i).getIndex())%13)==0) {matches++;} //If the mods of the indexes have no difference between them, then indicate that there was a match in the hand
            }
            if(matches>=3) {sets.push_back(i);}
        }
        return sets;
}


//FIXME add intersecting meld checker
void Player::findDeadwood(void) {
    std::vector<int> crossMelds = {};
    std::vector<int> deadwood = {};
    std::vector<int> runs = anyRuns();
    std::vector<int> sets = anySets();
    std::vector<int> intersection = {};
    
    
    //Looking for any shared meld components, and adding them to the vector intersection
    for(int runsIndex=0;runsIndex<runs.size();runsIndex++) {
        for(int setsIndex=0;setsIndex<sets.size();setsIndex++) {
            if(sets.at(setsIndex)==runs.at(runsIndex)) {
                intersection.push_back(runs.at(runsIndex));
            }
        }
    }
    
    for(std::vector<int>::iterator it=intersection.begin();it!=intersection.end();it++) {
    
    std::vector<int> tempRuns = {}; //all card indexes that don't intersect go here
    std::vector<int> tempSets = {}; //all card indexes that don't intersect go here too
    std::vector<int> tempRunsTest = {}; //The melds of a meld type go here to later be scored
    std::vector<int> tempSetsTest = {}; //The melds of a meld type go here to later be scored
    int runsPoints=0;
    int setsPoints=0;

                for(int runsIndexTemp=0;runsIndexTemp<runs.size();runsIndexTemp++) {
                    if(runs.at(runsIndexTemp) != *it) {
                        tempRuns.push_back(runs.at(runsIndexTemp));
                    }
                }
                
                for(int setsIndexTemp=0;setsIndexTemp<sets.size();setsIndexTemp++) {
                    if(sets.at(setsIndexTemp) != *it) {
                        //thanks gdb
                        tempSets.push_back(sets.at(setsIndexTemp));
                    }
                }
                
                //Preferably I would make an anyRuns/anySets function that would take in a vector argument but I don't have time so I won't
                
                //replaced cardsPosessed with tempRuns and runs with tempRunsTest
                if(tempRuns.size()!=0) {
                    for(int j=0;j<tempRuns.size()-1;j++) { //The last card of the vector should not be called in this loop
                        int k=0;
                        while((j+k+1<tempRuns.size()-1) && (cardsPosessed.at(tempRuns.at(j+k+1)).getIndex() == cardsPosessed.at(tempRuns.at(j+k)).getIndex()+1) && (cardsPosessed.at(tempRuns.at(j+k+1)).getSuit() == cardsPosessed.at(tempRuns.at(j+k)).getSuit())) {k++;}
                        if((j+k)>=tempRuns.size()-1) {j=tempRuns.size()-2;} 
                        if(k>=2) {
                            for(int x=j+k;x>=j;x--) {tempRunsTest.push_back(x);}
                        j+=k;
                        }
                    }
                    if(tempRunsTest.size()>=2) {
                        if((cardsPosessed.at(tempRuns.at(tempRuns.size()-1)).getIndex() == cardsPosessed.at(tempRuns.at(tempRunsTest.size()-1)).getIndex()+1) && (cardsPosessed.at(tempRuns.at(tempRuns.size()-1)).getSuit() == cardsPosessed.at(tempRuns.at(tempRunsTest.size()-1)).getSuit())) {
                            if((cardsPosessed.at(tempRuns.at(tempRuns.size()-1)).getIndex() == cardsPosessed.at(tempRuns.at(tempRunsTest.size()-2)).getIndex()+2) && (cardsPosessed.at(tempRuns.at(tempRuns.size()-1)).getSuit() == cardsPosessed.at(tempRuns.at(tempRunsTest.size()-2)).getSuit())) {
                                tempRunsTest.push_back(tempRuns.size()-1);
                            }
                         }
                    }
                }
                //replaced cardsPosessed with tempSets and sets with tempSetsTest
        
                for(int i=0;i<tempSets.size();i++) {
                    int matches=0;
                    for(int j=0;j<tempSets.size();j++) {
                        if(((cardsPosessed.at(tempSets.at(j)).getIndex())%13)==((cardsPosessed.at(tempSets.at(i)).getIndex())%13)) {matches++;} 
                    }
                    if(matches>=3) {tempSetsTest.push_back(i);}
                }
                
                //A deck that has a higher total point value lying inside melds will naturally have less deadwood than a deck with less points in melds
                //Therefore we don't need to convert the meld decks to deadwood for now
                
                //Find the point values for cards in the runs meld deck (tempRunsTest)
                
                for(int i = 0; i < tempRunsTest.size(); i++) {
                    runsPoints += cardsPosessed.at(tempRunsTest.at(i)).getCardPoints();
                }
                
                //Find the point values for cards in the sets meld deck (tempRunsTest)
                
                for(int i = 0; i < tempSetsTest.size(); i++) {
                    setsPoints += cardsPosessed.at(tempSetsTest.at(i)).getCardPoints();
                }
        
                //depending on which meld deck is worth more points, 
                //replace the other meld type vector with the vector that doesn't have the intersecting card,
                //and leave that formerly intersecting card in the other deck
        
                if(setsPoints>runsPoints) {runs=tempRunsTest;} //this conditional pair gives the ai a preference for sets
                else {sets=tempSetsTest;}
    
    }
    
    
    //Finding absent indexes, and putting them into a deadwood deck
    for(int i=0;i<cardsPosessed.size();i++) {
        
        bool isDeadwood=true; //if this is true then the index (i) isn't in a run, so put the index in the deadwood
        
        for(int runsIndex=0;runsIndex<runs.size();runsIndex++) {
            
            if(runs.at(runsIndex)==i) {isDeadwood=false;} //remove the mark if the card is in one of the runs
            
        }
        
        if(isDeadwood) {
                
                for(int setsIndex=0;setsIndex<sets.size();setsIndex++) {
                    
                    if(sets.at(setsIndex)==i) {isDeadwood=false;} //remove the mark if the card is in one of the sets
                    
                }
            }
            
        if(isDeadwood) {deadwood.push_back(i);} //put the integer that wasn't in either the runs meld set or the sets meld set into the deadwood vector
            
    }
    deadWoodIndexes = deadwood;
}

int Player::countDeadWood() {

    int points = 0;
    //using an iterator was causing fits so I changed it to an int
    for(int i = 0; i < deadWoodIndexes.size(); i++) {
        points += cardsPosessed.at(deadWoodIndexes.at(i)).getCardPoints();
    }
    //std::cout << points << " points of deadwood.\n";
    return points;
}

int Player::getHandSize(void)
{
    return cardsPosessed.size();
}

// during the knocking phase, the non-knocking player calls this to attempt to send
//  any card over which count towards another player's melds, thus decreasing the
//  non-knocking player's deadwood count. Returns true if the card sent
bool Player::knockSend(Player& target, int cardOutIndex)
{
    //calculate initial deadwoods
    target.findDeadwood();
    int targetInitial = target.countDeadWood();
    findDeadwood();
    int selfInitial = countDeadWood();
    
    target.recieveCard(sendCard(cardOutIndex));
    
    //calculate new deadwoods
    target.findDeadwood();
    int targetDiff = target.countDeadWood() - targetInitial;
    findDeadwood();
    int selfDiff = countDeadWood() - selfInitial;
    
    //if this card was in a meld (self's deadwood count increased or stayed same)
    // or if the card didn't fit in the other player's melds (their dw increased)
    // then undo the trade
    if(selfDiff >= 0 || targetDiff > 0) {
        recieveCard(target.sendCard(target.getHandSize()-1));
        return false;
    }
    
    return true;
}

Player& Player::operator=(const Player& playerIn)           // Overloaded equal operator
{
    cardsPosessed = playerIn.cardsPosessed;
    name = playerIn.name;
    deadWoodIndexes = playerIn.deadWoodIndexes;
}