#ifndef INTERFACE_H
#define INTERFACE_H
#include "container.h"
#include "pile.h"
#include "player.h"

class Interface {
    
    public:
        Interface(std::string nameIn);                                      // Token constructor
        void preDealDisplay(Player p1, Player p2);                          // displays game before deck creation
        void mainGameDisplay(Player p1, Player p2, Pile draw, Pile trash);  // displays main game as action happens WIP
        void knockDisplay(Player p1, Player p2, Pile draw, Pile trash);                                                // WIP
    
    
    private:
        
        std::string name;
        
};
#endif