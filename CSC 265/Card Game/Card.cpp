#include <iostream>
#include "Card.h"
#include <ctime>
#include <cstdlib>


using namespace std;

// CONSTRUCTOR
Card::Card()
{

}


// MODIFICATION MEMBER FUNCTIONS
void Card::setvalue(const int val)
{
  value = val;
}


void Card::setsuit(const string greg)
{
  suit = greg;
}

// CONSTANT MEMBER FUNCTIONS
int Card::getvalue(void) const
{
  return value;
}


string Card::getsuit(void) const
{
  return suit;
}

void Card::display(void) const
{
	cout<<value<<"  of "<<suit<<endl;

}

//constructs deck using multiple for loops
Deck::Deck()
{
	Card card1;
	int i=0;
	for (i;i<10;i++)
	{
		card1.setvalue(i+1);
		card1.setsuit("suit1");
		deck[i]=card1;
	}
	for (i;i<20;i++)
	{
		card1.setvalue(i-9);
		card1.setsuit("suit2");
		deck[i]=card1;
	}
	for (i;i<30;i++)
	{
		card1.setvalue(i-19);
		card1.setsuit("suit3");
		deck[i]=card1;
	}

	
}
void Deck::shuffle(void) 
{
	Card temp;
	int i, u,j;
	
	for (i=0; i<2000; i++)
	{
		
		u=rand()%30;
		j=rand()%30;
		temp=deck[u];
		deck[u]=deck[j];
		deck[j]=temp;
	}
}

Card Deck::getacard(const int slot) 
{
	Card carda;
	carda=deck[slot];
	return carda
;}


