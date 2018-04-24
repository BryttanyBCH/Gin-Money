//This is just a test for what the ai should do
#include<vector>
#include"card.h"
#include"player.h"


class AI: public Player {                               // AI's parent class is player
    
    public:
        //AI(std::string name);
        //using Player::Player;                        // this works but it won't let you add to the constructor
        AI(std::string nameIn, int x) : Player(nameIn) {for(int i=0;i<10;i++) {priority[i]=0;}}       //same deal with this one
        /*
        void scanTrash();
        int thinkDiscard();                             // returns the index of the card that should be popped out
        //Pile* thinkDraw(pile *p1,pile *p2);             //returns a pointer to the deck that should be drawn from
        */
    
    private:
        
        std::vector<Card> trashEstimation;              // Remember the last 8 cards (or maybe some other number) that were in the trash on normal, remember every card drawn on hardcore 
        int priority[10]; //this array doesn't need to be carried over as it will always be rewritten, but keeping the space allocated saves time for the computer
};