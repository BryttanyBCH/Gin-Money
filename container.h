#ifndef CONTAINER_H
#define CONTAINER_H
#include "card.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Container             // containers are things that hold cards, like like draw piles, discard piles, and players
{
    public:
        
        virtual Card sendCard() = 0;
        virtual void recieveCard(Card cardIn) = 0;
        virtual void displayDebug() = 0;
        virtual std::string getName() = 0;
    
};
#endif