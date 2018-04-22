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
    Player p2("UnbeataBill");
    
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
        
        
    int input;
    Card blank;
    trash.recieveCard(blank);
    trash.recieveCard(draw.sendCard());
    
    while(1) {
    
    
    // displays epic gameplay
    game.mainGameDisplay(p1,p2,draw,trash);
    
    // player choses deck to pick a card from
    std::cout << "What deck you wanna get from hunh (1 is normal, 2 is trash)\n";
    std::cin >> input;
    switch(input) {
    case 1:
    p1.recieveCard(draw.sendCard());
    break;
    default:
    p1.recieveCard(trash.sendCard());
    break;
    }
    
        // refresh display
    game.mainGameDisplay(p1,p2,draw,trash);
    std::cout << "Ok what card do you want to throw away from your deck\n";
    trash.recieveCard(p1.sendCard());
    
    //////////////////////////////////////////
    
    
    
    // displays epic gameplay
    game.mainGameDisplay(p1,p2,draw,trash);
    
    // player choses deck to pick a card from
    std::cout << "What deck you wanna get from hunh (1 is normal, 2 is trash)\n";
    std::cin >> input;
    switch(input) {
    case 1:
    p2.recieveCard(draw.sendCard());
    break;
    default:
    p2.recieveCard(trash.sendCard());
    break;
    }
    
        // refresh display
    game.mainGameDisplay(p1,p2,draw,trash);
    std::cout << "Ok what card do you want to throw away from your deck\n";
    trash.recieveCard(p2.sendCard());
    }
   
    return 0;
}