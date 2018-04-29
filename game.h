#ifndef GAME_H
#define GAME_H
#include"card.h"
#include"pile.h"
#include"player.h"
#include"ai.h"
#include"interface.h"

class Game {
    public:
        Game(std::string playerName);
        void initializeGame();
        void initializeRound();
        char playRound();   //return '0' if no knock, '1' if p1 knocked, '2' if bot knocks
        void playerKnocked(bool wasPlayerOne);
        char checkWin();    //return '0' if no winner, '1' if p1, '2' if bot
        void printScores();
    
    private:
        const int winPoints = 100;
        Pile stock, disc;
        Player p1;
        AI bot;
        Interface intf;
        int p1Points, botPoints;
};

#endif