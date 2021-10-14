// CLASS PROVIDED:  Class 
//
// CONSTRUCTOR for the Card class:
//   Card()
//     Description:		constructor will initialize Card objects
//     Preconditions:	none
//     Postcondition:	none
//
// MODIFICATION MEMBER FUNCTIONS for the card class
//   void setsuit (const string suit)
//     Description:		set the suit of the card
//     Precondition:	value is either suit1, suit2, or suit3
//     Postcondition:	suit of the card has been set to string
//
//   void setvalue(const int value)
//     Description:		set the value of the card
//     Precondition:	value is 1-10
//     Postcondition:	value part of the card has been set to value
//
//
// CONSTANT MEMBER FUNCTIONS for the Fraction class
//   int getvalue (void) const
//     Description:		obtain the value of the card
//     Preconditions:	none
//     Postcondition:	value of the card is returned
//
//   string  getsuit(void) const
//     Description:		obtain suit of the card
//     Preconditions:	none
//     Postcondition:	suit part of the card is returned
//
//   void display (void) const
//     Description:		display fraction to the screen
//     Preconditions:	none
//     Postcondition:	value of the fraction is displayed on the screen
// CLASS PROVIDED:  Class 
//
// CONSTRUCTOR for the Deck class:
//   Deck()
//     Description:		constructor will initialize Deck object
//     Preconditions:	none
//     Postcondition:	will create deck of 30 cards with suit1, suit2, suit3 and values 1-10 on each
//
// CONSTANT MEMBER FUNCTIONS for the Deck class
//   Card getacard (void) const
//     Description:		obtain the card of the Deck
//     Preconditions:	must have deck constructed
//     Postcondition:	the card is returned
//
//   void  shuffle(void) const
//     Description:		rearrange the deck
//     Preconditions:	none
//     Postcondition:	deck returned shuffled order
//

const int SIZE=30;
#ifndef CARD_H
#define CARD_H
#include <string.h>

using namespace std;
class Card
{
  public:
    // CONSTRUCTOR
    Card();

    // MODIFICATION MEMBER FUNCTIONS
    void setvalue (const int);
    void setsuit(const string);

    // CONSTANT MEMBER FUNCTIONS
    int getvalue (void) const;
    string  getsuit(void) const;
    void display() const;

  private:
    int value;
    string suit;
};

class Deck
{
	public:
		Deck();
			
		void shuffle(void);
		Card getacard(const int);
	private:
		Card deck[SIZE];
};

#endif
