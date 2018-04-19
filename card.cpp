/*♣ ♦ ♥ ♠
1 2 3 4
C D H S*/
#include"card.h"
#include<iostream>
Card::Card(int number,int type) {
    cardNum=number;
    if(number > 10) {cardPoints=10;}
    else {cardPoints=number;}
    switch(type) { 
        case 1:
        cardType='C';
        cardDisplay="♣";
        break;
        case 2:
        cardType='D';
        cardDisplay="♦";
        break;
        case 3:
        cardType='H';
        cardDisplay="♥";
        break;
        default:
        cardType='S';
        cardDisplay="♠";
    }
    if(!(number <= 10 && number > 1)) {
        if(number == 13) {cardDisplay = "K" + cardDisplay;}
        else if(number == 12) {cardDisplay = "Q" + cardDisplay;}
        else if(number == 11) {cardDisplay = "J" + cardDisplay;}
        else {cardDisplay = "A" + cardDisplay;}
    }
    else {cardDisplay = std::to_string(number) + cardDisplay;}
    //this switch turns the entered number value into a character 
    //that can be easily printed and compaired to other cards 
    //(when checking combos for scoring)
}

int Card::getCardPoints() {return cardPoints;}
char Card::getCardType() {return cardType;}
int Card::getCardNum() {return cardNum;}
void Card::cardPrint() {std::cout << "[" << cardDisplay << "]";}