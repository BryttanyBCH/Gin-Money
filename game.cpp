#include<iostream>
#include"game.h"

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
    getline(std::cin,temp);
}

void Game::initializeRound()
{
    // deck is made
    stock.makeDeck();
    
    // deck is distributed
    for (int i = 1; i <= 10; i++)
        p1.recieveCard(stock.sendCard());
        
    for (int i = 1; i <= 10; i++)
        p2.recieveCard(stock.sendCard());
    
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
        std::cout << "What deck you wanna get from hunh (1 is normal, 2 is trash)\n";
        int input;
        std::cin >> input;
        
        switch(input) {
        case 1:
            p1.recieveCard(draw.sendCard());
            break;
        default:
            p1.recieveCard(trash.sendCard());
            break;
        }
        
        // refresh display, discard a card
        game.mainGameDisplay(p1, p2, draw, trash);
        std::cout << "Ok what card do you want to throw away from your deck\n";
        trash.recieveCard(p1.sendCard());
        game.mainGameDisplay(p1, p2, draw, trash);
        
        std::cout<< "Would you like to knock? Enter y or n. ";
        char knock;
        std::cin >> knock;
        if(knock = 'y')
            return '1';
        
        /*** AI's TURN ***/
        
        //check again that the deck isn't empty
        if(stock.isEmpty())
            break;
        
        std::cout << "It's the AI's turn!" << end;
        bot.takeTurn(&stock, &disc)
        game.mainGameDisplay(p1, p2, draw, trash);
        
        if(bot.willKnock())
            return '2';
    } //END OF WHILE LOOP
    
    return '0';
}

void Game::playerKnocked(bool wasPlayerOne)
{
    //pull the players into temp players
    Player knocker = bot;
    Player defender = p1;
    
    if(wasPlayerOne) {
        knocker = p1;
        defender = bot;
    }
    
    knocker.findDW();
    int knockerDW = knocker.countDeadwood();
    
    bool didTransfer;
    
    do {
        didTransfer = false;
        
        for(int i = 0; i < defender.getHandSize(); i++) {
            if(defender.knockSend(knocker, i))
                didTransfer = true;
        }
        
    } while(didTransfer);
    
    /*//copy the players back out of the temp values
    if(wasPlayerOne) {
        p1 = knocker;
        bot = defender;
    }
    else {
        p1 = defender;
        bot = knocker;
    }*/
    
    defender.findDW();
    int defenderDW = defender.countDeadwood();
    
    
    //FIXME: I STILL HAVE STUFF TO DO HERE
    if(defenderDW <= knockerDW) {
        std::cout << "After laying off their cards, the defender had less or the same deadwood as the knocker!\n"
        std::cout << "They get a 25 point undercut bonus!"
        if(wasPlayerOne)
            botPoints += 25;
    }
    else {
        
    }
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