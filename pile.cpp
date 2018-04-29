#include "pile.h"

// for card shuffling
int randomgen(int i) 
{
    return std::rand() % i;
}

// token contructors

Pile::Pile()
{
    name = "Unknown";
}

Pile::Pile(std::string nameIn)
{
    name = nameIn;
}

// deletes card from posscession, but returns it
Card Pile::sendCard()
{
    Card temp = cardsPosessed.back();
    cardsPosessed.pop_back(); 
    return temp;
}

// adds card to possession, presumably from sendCard()
void Pile::recieveCard(Card cardIn)
{
    cardsPosessed.push_back(cardIn);
}

// couts the possessed cards, for debugging
void Pile::displayDebug()
{
    for (auto e : cardsPosessed) {
        std::cout << e.getCardDisplay();
    }
    std::cout << std::endl;
}

// generates a deck of 52 cards, shuffles using the randomgen
void Pile::makeDeck()
{
    cardsPosessed.clear();
    
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            cardsPosessed.push_back(Card(j,i));
        }
    }
    std::srand(time(0));
    std::random_shuffle(cardsPosessed.begin(), cardsPosessed.end(), randomgen);
}

void Pile::emptyDeck()
{
    cardsPosessed.clear();
}

//
std::string Pile::getName()
{
    return name;
}

// returns top card, rename?
std::string Pile::getTopCard()
{
    if(cardsPosessed.size() == 0)
        return "[   ]";
    return cardsPosessed.back().getCardDisplay();
}

bool Pile::isEmpty()
{
    return cardsPosessed.size() == 0;
}

Pile& Pile::operator=(const Pile& pileIn)           // Overloaded equal operator
{
    cardsPosessed = pileIn.cardsPosessed;
    name = pileIn.name;
}