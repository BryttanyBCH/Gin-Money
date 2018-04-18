/*♣ ♦ ♥ ♠
1 2 3 4
C D H S*/
class Card {
    public:
    Card(int cardNum,int cardType)
    Card(int number,char type) //give the constructor the number of the card and the Letter of the card's type (3 of clubs is Cards(3,C)
    int getPointVal(); //getters
    char getCardType();
    int getCardNum();
    
    private:
    int cardNum; //what is the card's number? (Ace=1, Jack=11, Queen=12, King=13)
    char cardType; //what type of card is the card (clubs, diamonds, hearts, or spades)
    int pointVal; //how many points is the card worth (if cardNum>10 then this is 10)
}
