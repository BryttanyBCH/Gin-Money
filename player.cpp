#include "player.h"
#include<vector>

// for sorting player hands
bool comp(Card c1, Card c2)
{
    return c1.getIndex() < c2.getIndex();
}

// token constructor
Player::Player(std::string nameIn)
{
    name = nameIn;
}

// deletes a chosen card, but returns it
Card Player::sendCard()
{
    int select;
    std::cin >> select;
    
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
    std::vector<int> deadwood = {};
    //std::cout << "Let's find what isn't a run\n";
        for(int j=0;j<cardsPosessed.size()-1;j++) { //The last card of the vector should not be called in this loop
            //std::cout << "j is " << j << std::endl;
            int k=0;
            //std::cout << "k is " << k << std::endl;
            while((cardsPosessed.at(k+1).getIndex() == cardsPosessed.at(k).getIndex()+1) && (cardsPosessed.at(k+1).getSuit() == cardsPosessed.at(k).getSuit()) && (k+1<cardsPosessed.size()-1)) {
                //std::cout << "cardsPosessed.at(k+1).getIndex(): " << cardsPosessed.at(k+1).getIndex() << std::endl;
                //std::cout << "cardsPosessed.at(k).getIndex()+1): " << cardsPosessed.at(k).getIndex()+1 << std::endl;
                //std::cout << "cardsPosessed.at(k+1).getSuit(): " << cardsPosessed.at(k+1).getSuit() << std::endl;
                //std::cout << "cardsPosessed.at(k).getSuit(): " << cardsPosessed.at(k).getSuit() << std::endl;
                k++;
            }
            //std::cout << "j is " << j << std::endl;std::cout << "k is " << k << std::endl;
            if((j+k)>=cardsPosessed.size()-1) {j=cardsPosessed.size()-2;} //minus 2, so that the loop incriments j to size-1 (which is the index of the final card in the thingy)
            
            if(k!=0 && ((j-k)>=2 || (j-k)<=-2)) {j+=k;/*std::cout << "j has jumped, now" << j << "(not yet incrimented, will be incrimented next)\n";*/}
            else {deadwood.push_back(j);} //deadwood.push_back(cardsPosessed[j].getIndex());
            
            //else {deadwood.push_back(cardsPosessed[j]);}
            
        }
        
        //if(deadwood[deadwood.size()-1].getIndex()/*most recent deadwood*/==cardsPosessed[cardsPosessed.size()-2].getIndex()/*Second to last player card*/) {deadwood.push_back(cardsPosessed[cardsPosessed.size()-1]);} //If the card that was just added to the deadwood vector is the same as the second-to-last card in the main deck, then the final card in the deck is deadwood (run-wise)
        if(deadwood.size()-1/*most recent deadwood*/==cardsPosessed[cardsPosessed.size()-2].getIndex()/*Second to last player card*/) {deadwood.push_back(cardsPosessed.size()-1);} //If the card that was just added to the deadwood vector is the same as the second-to-last card in the main deck, then the final card in the deck is deadwood (run-wise)
        else if (!(cardsPosessed[cardsPosessed.size()-2].getIndex()/*Second to last player card's index*/==cardsPosessed[cardsPosessed.size()-1].getIndex()-1/*last card*/)) {deadwood.push_back(cardsPosessed.size()-1);} //If the card in the hand of the player that is 1 from the end (second-to-last) is NOT one index number beneath the final card in the deck, then the last card is deadwood (run-wise)
        //else if (!(cardsPosessed[cardsPosessed.size()-2].getIndex()/*Second to last player card*/==cardsPosessed[cardsPosessed.size()-1].getIndex()-1/*last card*/)) {deadwood.push_back(cardsPosessed[cardsPosessed.size()-1]);} //If the card in the hand of the player that is 1 from the end (second-to-last) is NOT one index number beneath the final card in the deck, then the last card is deadwood (run-wise)
        
        return deadwood;
        /*
            if((deadwood[deadwood.size()-1].getIndex()==cardsPosessed[cardsPosessed.size()-2].getIndex()) || (!(cardsPosessed[cardsPosessed.size()-2].getIndex()==cardsPosessed[cardsPosessed.end()].getIndex()-1))) {
                deadwood.push_back(cardsPosessed.end());
                This conditional doesn't work, because the first condition prevents the second one from being true if it is true*/
        }

std::vector<int> Player::anySets(void) { //need to put in header file
    std::vector<int> deadwood = {};
        for(int i=0;i<cardsPosessed.size();i++) {
            int matches=0;
            for(int j=0;j<cardsPosessed.size();j++) {
                if((cardsPosessed[j].getIndex())%13-(cardsPosessed[i].getIndex())%13==0) {matches++;} //If the mods of the indexes have no difference between them, then indicate that there was a match in the hand
            }
            //if(matches<3) {deadwood.push_back(cardsPosessed[i]);}
            if(matches<3) {deadwood.push_back(i);}
        }
        return deadwood;
}

//REMEMBER, DEADWOODINDEXES DOES NOT STORE THE INDEX THAT A CARD HAS (A CARD INDEX) BUT RATHER STORES THE INDEX OF THE LOCATION OF THE DEADWOOD IN THE DECK ARRAY
void Player::findDeadwood(void) {
    std::vector<int> deadwood = {};
    std::vector<int> runs = anyRuns();
    std::vector<int> sets = anySets();
    for(int i=0;i<sets.size();i++) {            //the vector used to get the size may need to be exchanged (originally runs, but problematic)
        bool match=false;
        for(int j=0;j<runs.size();j++) {
            if(runs[i] == sets[j]) {
                deadwood.push_back(i);
            }
        }
    }
    deadWoodIndexes = deadwood;
    /*
    std::cout << "runs size is " << runs.size() << ", rets size is " << sets.size() << "\n";
    std::cout << "runs\n";
    for(int i=0;i<runs.size();i++) {
        std::cout << runs[i] << " ";
    }
    std::cout << "\nsets\n";
    for(int i=0;i<sets.size();i++) {
        std::cout << sets[i] << " ";
    }
    std::cout << "\ndeadwood\n";
    for(int i=0;i<deadWoodIndexes.size();i++) {
        std::cout << deadWoodIndexes[i] << " ";
    }
    std::cout << "\n";
    */
}

int Player::countDeadWood() {
    //vector<int> deadwood= findDeadwood(); //findDeadwood will already be called before this function
    int points = 0;
    //using an iterator was causing fits so I changed it to an int
    for(int i = 0; i < deadWoodIndexes.size(); i++) {
        points += cardsPosessed.at(deadWoodIndexes.at(i)).getCardPoints();
    }
    return points;
}

int Player::getHandSize(void)
{
    return cardsPosessed.size();
}

// during the knocking phase, the non-knocking player calls this to attempt to send
//  any card over which count towards another player's melds, thus decreasing the
//  non-knocking player's deadwood count. Returns true if the card sent
bool Player::knockSend(Player target, int cardOutIndex)
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