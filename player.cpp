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
    
        for(int j=0;j<cardsPosessed.size()-1;j++) { //The last card of the vector should not be called in this loop
            
            int k=0;
            //std::cout << "j is " << j << std::endl;std::cout << "k is " << k << std::endl;
            
            //this while loop used to check the card that was at k, but k was fixed so that it started at zero. That is why only the first few parts of the deck got checked
            while((j+k+1<cardsPosessed.size()-1) && (cardsPosessed.at(j+k+1).getIndex() == cardsPosessed.at(j+k).getIndex()+1) && (cardsPosessed.at(j+k+1).getSuit() == cardsPosessed.at(j+k).getSuit())) {
            //std::cout << " The card at j is " << cardsPosessed.at(j).getCardDisplay() << " and j is " << j << "\n";
            //std::cout << " The card at k is " << cardsPosessed.at(k).getCardDisplay() << " and k is " << k << "\n";
                k++;
            }
            if((j+k)>=cardsPosessed.size()-1) {j=cardsPosessed.size()-2;/*std::cout << "end reached, j reduced by 2, j is" << j << "\n";*/} //minus 2, so that the loop incriments j to size-1 (which is the index of the final card in the thingy)
            //std::cout << "j is " << j << std::endl;std::cout << "k is " << k << std::endl;
            if(k!=0 && k>=2) {j+=k;/*std::cout << "Condition 2 tripped, add j to k. J is " << j << " and k is " << k << "\n";*/}
            else {deadwood.push_back(j);/*std::cout << "Card bad, put its index into the deadwood deck. Index is (j) " << j << "\n";*/}
            //std::cout << "j is " << j << std::endl;std::cout << "k is " << k << std::endl;
            
        }
        //std::cout << "Time to check the last card of this deck and see if it is a run\n";
        //std::cout << "The last card is: " << cardsPosessed.at(deadwood.size()-1).getIndex() << "\n";
        //std::cout << "Alpha " << cardsPosessed.at(deadwood.size()-1).getIndex() << " " << cardsPosessed.at(cardsPosessed.size()-2).getIndex() << "\n";
        //std::cout << "Beta (negate) " << cardsPosessed.at(cardsPosessed.size()-2).getIndex() << " " << cardsPosessed.at(cardsPosessed.size()-1).getIndex()-1 << "\n";
        if(cardsPosessed.at(deadwood.at(deadwood.size()-1)).getIndex()==cardsPosessed.at(cardsPosessed.size()-2).getIndex()) {deadwood.push_back(cardsPosessed.size()-1);} //If the card that was just added to the deadwood vector is the same as the second-to-last card in the main deck, then the final card in the deck is deadwood (run-wise)
        else if (!(cardsPosessed.at(cardsPosessed.size()-2).getIndex()==cardsPosessed.at(cardsPosessed.size()-1).getIndex()-1)) {deadwood.push_back(cardsPosessed.size()-1);} //If the card in the hand of the player that is 1 from the end (second-to-last) is NOT one index number beneath the final card in the deck, then the last card is deadwood (run-wise)
        //std::cout << "No deadwood in last slot\n";
        return deadwood;
        
}

//need to check for intersecting melds
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

//FIXME
void Player::findDeadwood(void) {
    std::vector<int> deadwood = {};
    std::vector<int> runs = anyRuns();
    std::vector<int> sets = anySets();
    //std::cout << "runs size is " << runs.size() << ", sets size is " << sets.size() << "\n";
    for(int i=0;i<sets.size();i++) {            //the vector used to get the size may need to be exchanged (originally runs, but problematic)
        bool match=false;
        for(int j=0;j<runs.size();j++) {
            if(runs.at(j) == sets.at(i)) { //Originally an out of bounds unreported error with runs[i] == sets[j], the i and j are mixed up
                deadwood.push_back(runs.at(j));
                //std::cout << runs.at(j) << " equals " << sets.at(i) << " so I am putting it in deadwood vector\n";
                std::cout << "j is: " << j << "\n";
                std::cout << "i is: " << i << "\n";
            }
            //else {std::cout << runs[j] << " DNE " << sets[i] << " so I am not putting it in deadwood\n";}
        }
    }
    deadWoodIndexes = deadwood;
    
    
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
    
}

int Player::countDeadWood() {
    //vector<int> deadwood= findDeadwood(); //findDeadwood will already be called before this function
    int points = 0;
    //using an iterator was causing fits so I changed it to an int
    for(int i = 0; i < deadWoodIndexes.size(); i++) {
        points += cardsPosessed.at(deadWoodIndexes.at(i)).getCardPoints();
    }
    std::cout << "The deadwood total points for this hand: " << points << "\n";
    std::cout << "The deadwood in this hand: " << "\n";
    for(int i = 0; i < deadWoodIndexes.size(); i++) {
        std::cout << cardsPosessed.at(deadWoodIndexes.at(i)).getCardDisplay() << " ";
    }
    std::cout << "\nThe deadwood point vals in this hand are: \n";
    for(int i = 0; i < deadWoodIndexes.size(); i++) {
        std::cout << cardsPosessed.at(deadWoodIndexes.at(i)).getCardPoints() << " ";
    }
    std::cout << "\n";
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