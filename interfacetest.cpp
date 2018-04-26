#include "interface.h"

int main() {
    
    Pile draw("Draw");
    Pile trash("Trash");
    Player p1("Count Deadwood");
    Player p2("UnbeataBill");
    
    // defining the interface? idk whatever
    Interface game("Gin Money");
    
    game.preDealDisplay(p1,p2);
    std::string temp;
    getline(std::cin,temp);
    
    game.mainGameDisplay(p1,p2,draw,trash);
    std::string temp;
    getline(std::cin,temp); 
    
    game.knockDisplay(p1,p2,draw,trash);
    std::string temp;
    getline(std::cin,temp); 
    
    
    
    return 0;
}