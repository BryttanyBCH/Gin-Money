/*♣ ♦ ♥ ♠
1 2 3 4
C D H S*/
class Card {
    public:
    Card(int cardNum,int cardType) //give the constructor the number of the card type, and this constructor will save that number as a char (as described in the comment table at the top of this file) for comparison
    Card(int number,char type) //give the constructor the number of the card and the Letter of the card's type (3 of clubs is Cards(3,C)
    int getPointVal(); //getters
    char getCardType(); //the cardType is always saved as a character by the card class, even if the int cardType constructor is used
    int getCardNum();
    
    private:
    int cardNum; //what is the card's number? (Ace=1, Jack=11, Queen=12, King=13)
    char cardType; //what type of card is the card (clubs, diamonds, hearts, or spades)
    int pointVal; //how many points is the card worth (if cardNum>10 then this is 10)
}
