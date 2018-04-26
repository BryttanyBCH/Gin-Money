#ifndef AI_H
#define AI_H
#include<vector>
#include"card.h"
#include"pile.h"
#include"player.h"


class AI: public Player {                               // AI's parent class is player
    
    public:
        AI(std::string name) : Player(name){lastCardIndex = -1;}
        void takeTurn(Pile* stock, Pile* disc) ;         // do everything
        bool willKnock(void);
        
    private:
        bool checkDiscard(Pile* disc, int startVal);    // decide if they want to draw from discard and take the card if so. returns true in that case
        int removeIndex(int startVal);                  // chooses which card it wants to remove from hand
        int lastCardIndex;                              // stores the last card received so that the AI doesn't get in a loop of discarding
};
#endif