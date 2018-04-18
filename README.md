# Gin-Rummy
Gin Rummy For UNC Charlotte

♣ ♦ ♥ ♠
1 2 3 4
C D H S


In-Progress Plan:
Create a deck vector and fill it with a predefined set of cards
Shuffle with #include <algorithm>  std::random_shuffle(beginning,end) for vectors
Itterate through the deck, starting from the top: deal 10 cards to the play and 10 to the computer
Put one card's information into the visible deck (from the normal deck), and show the player their deck on the bottom of the screen
The player can either draw from the deck (which doesn't show what they will get but pulls cards from the vector) or a visible deck.
They do this by entering Left or Right (for left deck or right deck, where the normal deck is on the left)
After selecting a deck, the card from that deck is replicated into a intermediate variable, so that the game knows to put it into the player's vector when their turn concludes
This intermediate variable will ensure the player doesn't throw away the card they just got IF IT CAME FROM THE KNOWN DECK (this is not allowed). If the card came from the unknown deck then it is fine to send it to the known deck.
If intermediate variable card = top of known deck vector, do not let the player drop the card into the known deck again

Making it easier for the player to see non dead wood by sorting deck: make a sort method/function for the cards
We will need to make this method from scratch I think

Aces=1 point
Face card=10 points
Numbered cards have a point value of their number

Point Rules (From Wikipedia) Not sure these are complete
Knock Points: When a player knocks, give the knocker |player1.hand-player2.hand| points
    After a player knocks, and the lay offs are made, the knocking player receives a score equal to the difference between the two hands. For example, if a player knocks with 8, and the defender has 10 deadwood points in his or her hand after laying off, the knocking player receives 2 points for the hand.
Gin Bonus: When a player calls gin, the player who called gin receives 25+opponent.deadwood
    After going gin, a player receives a bonus of 25 points plus the entire count of deadwood in the opponent's hand. There is no chance to lay off when a player goes gin.
Undercut (or underknocking): If the player knocks and this->deadwood <= opponent.deadwood, then they recieve the knock points + 25 points bonus
    Occurs when the defending player has a deadwood count lower than or equal to that of the knocking player (this can occur either naturally or by laying off after a knock). In this case, the defender scores an undercut bonus of 25 points plus the difference in deadwood in the knocking player's hand. (In some rule sets, the bonus is only 10 or 20 points, or is not awarded in case of a tie.)
Game Bonus: Maybe increase this limit to something like 250 or 300
    Once a player has acquired 100 points (or some other agreed-upon number) the game is over, and that player receives a game bonus of 100 points (or another agreed-upon number).
Line Bonus or Box Bonus: add this->wins*25 points for each of the players
    Added at the end of the game. For every hand a player won during the game, 25 points is added to his or her score.
Big Gin: 31+opponent.deadwood and keep the extra card (?
    Prior to knocking, if all 11 cards in a player's hand form a legal gin, the player can retain the extra card as part of his or her hand, and is awarded 31 points plus entire count of deadwood in his or her opponent's hand. (In some rule sets players may be awarded 50 points or another established amount plus the entire count of deadwood in the opponent's hand)
Shutout Bonus: if opponent.wins = 0, points*=2
    If a game is completed with the winner having won every hand, the points for each hand are doubled before adding the line bonus. 
    
