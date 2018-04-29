#include <iostream>
#include <string>
#include "game.h"

Game::Game(std::string playerName) 
{
    Pile s("Stock");
    Pile d("Discard");
    Player p(playerName);
    AI b("UnbeataBill");
    Interface i("Gin Money");
    
    stock = s;
    disc = d;
    p1 = p;
    bot = b;
    intf = i;
    p1Points = 0;
    botPoints = 0;
}

void Game::initializeGame()
{
    // displays screen before cards are delt, type something to start!
    intf.preDealDisplay(p1,bot);
    std::string temp;
    std::cout << "Type anything to start! ";
    std::cin.ignore();
    std::getline(std::cin,temp);
}

void Game::initializeRound()
{
    // clear player hands for repeated rounds
    p1.clearHand();
    bot.clearHand();
    
    // deck is made
    stock.makeDeck();
    
    // deck is distributed
    for (int i = 1; i <= 10; i++)
        p1.recieveCard(stock.sendCard());
        
    for (int i = 1; i <= 10; i++)
        bot.recieveCard(stock.sendCard());
    
    Card blank;
    disc.recieveCard(blank);
    disc.recieveCard(stock.sendCard());
}

char Game::playRound()
{
    while(!stock.isEmpty()) //loop continues until deck is empty or until a player knocks (using returns for the latter)
    {
        intf.mainGameDisplay(p1,bot,stock,disc);
        
        /*** PLAYER 1's TURN ***/
        
        // player choses deck to pick a card from
        std::cout << "What deck you wanna get from? (1 is stock, 2 is discard)\n";
        std::string input;
        std::cin >> input;
        
        if (input == "1") {
            p1.recieveCard(stock.sendCard());
        } else {
            p1.recieveCard(disc.sendCard());
        }
        
        // refresh display, discard a card
        intf.mainGameDisplay(p1, bot, stock, disc);
        std::cout << "Ok what card do you want to throw away from your deck\n";
        disc.recieveCard(p1.sendCard());
        intf.mainGameDisplay(p1, bot, stock, disc);
        
        std::cout << "Would you like to knock? Enter y or n." << std::endl;
        std::string knock;
        std::cin.ignore();
        std::getline(std::cin,knock);
        if(knock.compare("y") == 0)
            return '1';
        
        /*** AI's TURN ***/
        
        //check again that the deck isn't empty
        if(stock.isEmpty())
            break;
        
        bot.takeTurn(&stock, &disc);
        intf.mainGameDisplay(p1, bot, stock, disc);
        
        if(bot.willKnock())
            return '2';
    } //END OF WHILE LOOP
    
    return '0';
}

void Game::playerKnocked(bool wasPlayerOne)
{
    intf.knockDisplay(p1, bot, stock, disc);
    
    //pull the players into temp players
    Player knocker = bot;
    Player defender = p1;
    
    if(wasPlayerOne) {
        knocker = p1;
        defender = bot;
    }
    
    knocker.findDeadwood();
    int knockerDW = knocker.countDeadWood();
    
    bool didTransfer;
    
    do {
        didTransfer = false;
        
        for(int i = 0; i < defender.getHandSize(); i++) {
            if(defender.knockSend(knocker, i))
                didTransfer = true;
        }
        
    } while(didTransfer);
    
    defender.findDeadwood();
    int defenderDW = defender.countDeadWood();
    
    /*** THE PLAYER KNOCKED ***/
    if(wasPlayerOne) {
        if(defenderDW < knockerDW) {
            std::cout << "After laying off their cards, the AI had less deadwood than you!\n";
            std::cout << "They get a 25 point undercut bonus!\n";
            std::cout << "The AI also gains the difference in the deadwood, " 
                << knockerDW - defenderDW << " points!\n";
                
            botPoints += 25 + (knockerDW - defenderDW);
        }
        else if(defenderDW == knockerDW) {
            std::cout << "After laying off their cards, the AI had the same deadwood points as you!\n";
            std::cout << "They get a 25 point undercut bonus!" << std::endl;
            
            botPoints += 25;
        }
        else {
            std::cout << "After the AI laid off their cards, you still had less deadwood!\n";
            std::cout << "You gain the difference in the deadwood, " << defenderDW - knockerDW << " points!\n";
            
            p1Points += defenderDW - knockerDW;
        }
    }
    
    /*** THE AI KNOCKED ***/
    else {
        std::cout << "The AI knocked!!!\n";
        if(defenderDW < knockerDW) {
            std::cout << "After laying off your cards, you had less deadwood than the AI!\n";
            std::cout << "You get a 25 point undercut bonus!\n";
            std::cout << "You also gain the difference in the deadwood, " 
                << knockerDW - defenderDW << " points!\n";
                
            p1Points += 25 + (knockerDW - defenderDW);
            
        }
        else if(defenderDW == knockerDW) {
            std::cout << "After laying off your cards, you had the same deadwood points as the AI!\n";
            std::cout << "You get a 25 point undercut bonus!" << std::endl;
            
            p1Points += 25;
        }
        else {
            std::cout << "After you laid off your cards, the AI still had less deadwood!\n";
            std::cout << "The AI gains the difference in the deadwood, " << defenderDW - knockerDW << " points!\n";
            
            botPoints += defenderDW - knockerDW;
        }
    }
    
    std::string temp;
    std::cout << "Type anything to continue. ";
    std::cin.ignore();
    std::getline(std::cin,temp);
}

char Game::checkWin()
{
    if(p1Points > winPoints && p1Points > botPoints)
        return '1';
    else if(botPoints > winPoints && botPoints > p1Points)
        return '2';
    else
        return '0';
}

void Game::printScores()
{
    std::cout << p1.getName() << ": " << p1Points << std::endl;
    std::cout << bot.getName() << ": " << botPoints << std::endl;
}