#include<iostream>
#include "pile.h"
#include "player.h"
#include "interface.h"
#include "ai.h"
#include "game.h"

// this is for testing
int main() 
{
    // ask the player for their name
    std::cout << "\nWelcome to Gin Rummy! What is your name? ";
    std::string name;
    getLine(std::cin, name);
    
    Game game(name);
    
    game.initializeGame();
    
    do{
        //play a round of the game
        char roundStatus = game.playRound();
        
        //react to the round
        if(roundStatus == '1') {
            game.playerKnocked(true);
        }
        else if(roundStatus == '2') {
            game.playerKnocked(false);
        }
        else {
            std::cout << "The stock pile is empty! No points awarded for this round!";
        }
    } while(game.checkWin() == '0');
    
    if(game.checkWin() == '1')
        std::cout << endl << "Thank god you won now we can cease playing this accursed game\n";
    else
        std::cout << endl << "You lost to our shitty robot?? Jeez try to grow at least one brain cell next time\n";
}