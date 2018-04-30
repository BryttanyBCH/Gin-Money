#include <iostream>
#include <string>
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
    std::getline(std::cin, name);
    
    if(name.compare(" ") == 0 || name.compare("\n"))
        name = "UnbeataBill";
    
    Game game(name);
    
    game.initializeGame();
    
    do{
        game.initializeRound();
        
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
            std::string temp;
            std::cout << "Type anything to continue. ";
            std::cin.ignore();
            std::getline(std::cin,temp);
        }
    } while(game.checkWin() == '0');
    
    if(game.checkWin() == '1')
        std::cout << std::endl << "CONGRATS! You won!" << std::endl;
    else
        std::cout << std::endl << "Sorry, you lost." << std::endl;
        
    std::cout << "The final score was:" << std::endl;
    game.printScores();
}