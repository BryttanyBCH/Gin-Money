#include "player.h"

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
        std::cout << e.cardDisplay();
    }
    std::cout << std::endl;
}

std::string Player::getName()
{
    return name;
}