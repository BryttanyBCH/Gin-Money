#include "pile.h"
#include "player.h"
#include "interface.h"

// this is for testing
int main() 
{
    // defining containers
    Pile draw("Draw");
    Pile trash("Trash");
    Player p1("Jim");
    Player p2("Bob");
    
    // defining the interface? idk whatever
    Interface game("Gin Money");
    
    // displays screen before cards are delt, type something to start!
    game.preDealDisplay(p1,p2);
    std::string temp;
    getline(std::cin,temp);
    
    // deck is made
    draw.makeDeck();
    
    // deck is distributed
    for (int i = 1; i <= 10; i++)
        p1.recieveCard(draw.sendCard());
        
    for (int i = 1; i <= 10; i++)
        p2.recieveCard(draw.sendCard());
    
    trash.recieveCard(draw.sendCard());
    
    // displays epic gameplay
    game.mainGameDisplay(p1,p2,draw,trash);
    
    // player choses card to discard
    trash.recieveCard(p1.sendCard());
    
    // refresh display
    game.mainGameDisplay(p1,p2,draw,trash);
   
    return 0;
}