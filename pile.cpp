#include "pile.h"

// for card shuffling
int randomgen(int i) 
{
    return std::rand() % i;
}

// token contructor
Pile::Pile(std::string nameIn)
{
    name = nameIn;
}

/*Card Pile::scan() //This is needed for the ai to take a card from the trash without actually taking it
{
    Card temp = cardsPosessed.back();
    cardsPosessed.pop_back(); 
    return temp;
}*/

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
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            cardsPosessed.push_back(Card(j,i));
        }
    }
    std::srand(time(0));
    std::random_shuffle(cardsPosessed.begin(), cardsPosessed.end(), randomgen);
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