#include <vector>
#include "card.h"
#include <algorithm>

/* A Deck is a pile of cards. It is initialized as a shuffled, 52 card
 * deck, but can be emptied to be designated as a discard pile.
 */
 
class Deck {
private:
    std::vector<Card> allCards;
public:
    Deck(void);
    Card takeCard(void);
    int getCount(void) const;
    void addCard(Card c);
    Card viewCard(void) const;
    void setAsDiscard(void);
};