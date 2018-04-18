/*♣ ♦ ♥ ♠
1 2 3 4
C D H S*/
#include"card.h"

int Card::Card(int number,char type) {
    cardNum=number;
    cardType=type;
    if(number > 10) {pointVal=10;}
    else {pointVal=number;}
}

int Card::Card(int number,int type) {
    cardNum=number;
    if(number > 10) {pointVal=10;}
    else {pointVal=number;}
    switch(cardType) { 
        case 1:
        cardType='C';
        break;
        case 2:
        cardType='D';
        break;
        case 3;
        cardType='H';
        break;
        default:
        cardType='S';
    }
    //this switch turns the entered number value into a character 
    //that can be easily printed and compaired to other cards 
    //(when checking combos for scoring)
}

int Card::getPointVal() {return pointVal;}
char Card::getCardType() {return cardType;}
int Card::getCardNum() {return cardNum;}
