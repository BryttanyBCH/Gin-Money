//This is just a test for what the ai should do
#include<vector>
#include"card.h"
#include"player.h"


class AI: public Player {                               // AI's parent class is player
    
    public:
        
        AI(std::string nameIn);                         // token constructor
        void scanTrash();
        int thinkDiscard();                             // returns the index of the card that should be popped out
        Pile* thinkDraw(pile *p1,pile *p2);             //returns a pointer to the deck that should be drawn from
        
    
    private:
        
        std::vector<Card> trashEstimation;              // Remember the last 8 cards (or maybe some other number) that were in the trash on normal, remember every card drawn on hardcore 
        std::vector<Card> playerEstimation;             // this vector will only hold the last two cards the player took into their deck (to be fair)
        int priority[10]; //this array doesn't need to be carried over as it will always be rewritten, but keeping the space allocated saves time for the computer
};