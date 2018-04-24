#include "ai.h"

/*AI::AI(std::string nameIn, int x) : Player(nameIn)                     // Not sure if I am doing this right but we can fix it later
{
    for(int i=0;i<10;i++) {
        priority[i]=0;
    }
}
/*

//Not sure if I have properly imported the other stuff but we can fix it later
// for sorting player hands

// token constructor
AI::Player::AI(std::string nameIn)                      // Not sure if I am doing this right but we can fix it later
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
}*/