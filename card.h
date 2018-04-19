/*♣ ♦ ♥ ♠
1 2 3 4
C D H S*/
#include<string>
class Card {
    public:
    Card(int cardNum,int cardType); //give the constructor the number of the card type, and this constructor will save that number as a char (as described in the comment table at the top of this file) for comparison
    int getCardNum();
    char getCardType(); //the cardType is always saved as a character by the card class, even if the int cardType constructor is used
    int getCardPoints(); //getters
    void cardPrint();
    
    private:
    int cardNum; //what is the card's number? (Ace=1, Jack=11, Queen=12, King=13)
    char cardType; //what type of suit card is the card (clubs, diamonds, hearts, or spades). Never printed, ony used to check player's input
    int cardPoints; //how many points is the card worth (if cardNum>10 then this is 10)
    std::string cardDisplay; //the card icon (♣ ♦ ♥ ♠). A J, K, or Q will be added (and number not printed, as it will be set to null)
};