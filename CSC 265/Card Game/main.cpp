#include <iostream>
#include <ctime>
#include "Card.h"
#include <cstdlib>



using namespace std;
void USRhand (int, int, Card []);
//     Description:		print values in usr hand
//     Precondition:	must have valid hand
//     Postcondition:	
Card CPUTURN(Card*, int, Card, int);
//     Description:		handles AI for computer players
//     Precondition:	must have hand of cards and know order
//     Postcondition:	Returns the card to the game as a play
Card USRTURN(Card*, int, int);
//     Description:		gets the input of card selection from human
//     Precondition:	hand of cards and order
//     Postcondition:	return card to game as play

int main(void)
{
	
	int i=0, u=0, handsize=10, tricks=0, t=0, turn=0, win=1, trick, cpu1point=0, cpu2point=0, usrpoint=0, bid;
	int trickbet;
	Card player[handsize];
	Card comp1[10];
	Card comp2[10];
	Card usrcard;
	Card cpu1card;
	Card cpu2card;
	Card showing;
	int play;
	const int points=10;
	srand(time(0));
	
	cout<<"Welcome to Trick War!"<<endl<<"You will battle the computer for trick supremecy"<<endl<<"All players will be dealt 10 cards, You will then select a card (the computer will see) to launch an attack"<<endl;
	cout<<"The first player to 100 points win!"<<endl<<"Since you claim to be 'smarter than the computer' you will have to bet how many tricks you can win per hand"<<"But be aware, playing conservative will not help you here"<<endl;
	cout<<"you will only get credit for the bids you win, and will lose point if you do not bid!"<<endl<<"GOOD LUCK!";
	do	
	{
	//must be created in loop, because it gets destroyed by end of game
	int cpu1point=0, cpu2point=0, usrpoint=0;
	Deck deckofcards;
	//shuffles cards
	deckofcards.shuffle();
	//deals cards to players
	i=0;
	int usrwin=0;
	for (i;i<handsize; i++)
	{
		player[i]=deckofcards.getacard(i);
	};
	for (i;i<20;i++)
	{
		comp1[i-10]=deckofcards.getacard(i);
	};
	for (i;i<30;i++)
	{
		comp2[i-20]=deckofcards.getacard(i);
	};
	
	USRhand(0, handsize, player); //show player their 10 cards
	cout<<"How many tricks can you win?"<<endl;
	while(!(cin>>trickbet) ||cin.peek() != '\n'|| (trickbet<0 && trickbet>11) )
	{
		cout<<"How many tricks can you win (please enter an integer between 1-10)"<<endl;
		cin.clear();
		cin.ignore(30000, '\n');
	}
	while (tricks<10)
	{
		if (win==1)
			{
				usrcard=USRTURN(player, 1, handsize);
				showing=usrcard;
				cout<< "Card showing ";
				showing.display();
				cpu1card=CPUTURN(comp1, handsize, showing, 0);
				cout<< endl<< "CPU1 plays ";
				cpu1card.display();
				cpu2card=CPUTURN(comp2, handsize, showing, 0);
				cout<< endl<< "CPU2 plays ";
				cpu2card.display();
			}
		if (win==2)
			{
				cpu1card=CPUTURN(comp1, handsize, showing, 1);
				showing=cpu1card;
				cout<< "Card showing ";
				cout<<endl<<endl<<endl;
				showing.display();
				usrcard=USRTURN(player, 0, handsize);
				cpu2card=CPUTURN(comp2, handsize, showing, 0);
				cout<< endl<< "CPU2 plays ";
				cpu2card.display();
				
			}
		if (win==3)
			{
				cpu2card=CPUTURN(comp2, handsize, showing, 1);
				showing=cpu2card;
				cout<< "Card showing ";
				cout<<endl<<endl<<endl;
				showing.display();
				usrcard=USRTURN(player, 0, handsize);
				cpu1card=CPUTURN(comp1, handsize, showing, 0);
				cout<< endl<< "CPU1 plays ";
				cpu1card.display();
			
			}
			
		//These check suit and if not match, set the card value to 0 to nullify that players chance of winning the trick
		//string oof;
		//oof=showing.getsuit();
		//cout<<oof<<endl;
		//cout<<"why";
		if (showing.getsuit()!= cpu1card.getsuit())
		{
			cpu1card.setvalue(0);
			cout<<"cpu1 void"<<endl;
		}
		if (showing.getsuit()!= cpu2card.getsuit())
		{
			cpu2card.setvalue(0);
			cout<<"cpu2 void"<<endl;
		}
		if (showing.getsuit()!= usrcard.getsuit())
		{
			usrcard.setvalue(0);
			cout<<"usr void"<<endl;
		}
		//check value of all cards played to determine winner
		if (usrcard.getvalue()>cpu1card.getvalue() && usrcard.getvalue()>cpu2card.getvalue())
		{	
			cout<<"Usr Wins trick"<<endl;
			usrwin=usrwin+1;
			if (usrwin<=trickbet)
			{
				usrpoint=usrpoint+10;
			}
			if (trickbet==0)
			{
				usrpoint=usrpoint-10;
			}
			trick=trick+1;
			win=1;
		}
		if (cpu1card.getvalue()>usrcard.getvalue() && cpu1card.getvalue()>cpu2card.getvalue())
		{
			cout<<"CPU1 wins trick"<<endl;
			cpu1point=cpu1point+points;
			trick=trick+1;
			win=2;
		}
		if (cpu2card.getvalue()>usrcard.getvalue() && cpu2card.getvalue()> cpu1card.getvalue())
		{
			cout<<"CPU2 wins trick"<<endl;
			cpu2point=cpu2point+points;
			trick=trick+1;
			win=3;
		}
		system("PAUSE");
		//reduce handsize as played card is removed from hand
		handsize=handsize-1;
		cout<<endl<<endl<<endl<<endl<<endl;
		cout<<"Score"<<endl<<endl<<endl<<"USR:\t"<<usrpoint<<"\tCPU1:\t"<<cpu1point<<"\tCPU2:\t"<<cpu2point<<endl<<endl<<endl<<endl;
		if (cpu1point>100 || cpu2point>100 || usrpoint>100)
		{
			cout<<"Congrats to "<<endl;
			if (cpu1point>100)
			{
				cout<<"CPU1"<<endl;
			}
			if (cpu2point>100)
			{
				cout<<"CPU2"<<endl;
			}
			if( usrpoint>100)
			{
				cout<<"User"<<endl;
			}
			cout<<"Would you like to play again?"<<endl<<"1 for yes"<<endl;
			cin>>play;

		}
	
	}
	
	}while (play==1 && cpu1point<100 && cpu2point<100 && usrpoint<100);
  system("PAUSE");
  return 0;
}

//displays user hand
void USRhand (int t, int handsize, Card player[]) 
{
	int u=0;
	
	if (t==0)
	{
		for(u;u<handsize; u++)
		{
			player[u].display();
		}
		t=1;
	}
	else
	{
		for (u;u<handsize; u++)
		{
			cout<< u << " for ";
			player[u].display();
		}
		t=0;
	}
	

}

Card USRTURN (Card player[],int first, int hand)
{
	//Card showing;
	string matchsuit, testsuit;
	int k;
	int playcard;
	Card temp, showing;
	
	
	if (first==1)
	{
		cout<<"Which card would you like to play"<<endl;
		USRhand(1, hand, player);
		while(!(cin>>k) ||cin.peek() != '\n'|| (k<0 && k>hand) )
		{
			cout<<"Please Pick a card (integer) in given range"<<endl;
			cin.clear();
			cin.ignore(30000, '\n');
		}
		player[k].display();
		
	}
	if (first==0)
	{
		cout<<"Which card would you like to play"<<endl<<"NOTE: a card of a different suit than the showing card, will be a discard of that card"<<endl;
		USRhand(1, hand, player);
		while(!(cin>>k) ||cin.peek() != '\n'|| (k<0 && k>hand) )
		{
			cout<<"Please Pick a card (integer) in given range"<<endl;
			cin.clear();
			cin.ignore(30000, '\n');
		}
		player[k].display();
	}
	showing=player[k];
	temp=player[k];

	player[k]=player[hand-1];

	player[hand-1]=player[11];

	return showing; //card that the user wants to play	
}


Card CPUTURN (Card comp[], int hand, Card showing, int first)
{
	string matchsuit, testsuit;
	int matchval, testval, full, otherval=0,otherval1,
	k=0, g=0, l=0, u=0; 
	string suit; 
	int suit1, suit2, suit3; //for accumulating suits if no matching suit
	Card temp[12];
	//cout<<"into cpu";
	//if the cpu goes first for trick
	if (first==1)
	{
		do
		{
			//generate random suit for the first card
			matchsuit=rand()%3+1;
			//process each card searching for highest value of that suit
			for(u; u<hand; u++)
			{
				testsuit=comp[u].getsuit();
						if (testsuit==matchsuit)
					{
						testval=comp[u].getvalue();
						if (testval>otherval)
						{
							showing=comp[u];
							otherval=testval;
							k=u;
							g=1;
						}
					}
			}
			showing=comp[k];
		}while (g!=0); //g is a flag to make sure there is something to return, if no suit used, it will loop
	
	}
	
	
	if (first==0)
	{
		//cout<<"into second";
	
		matchsuit=showing.getsuit();
		matchval=showing.getvalue();
	
	
		//set flags for determining if the cpu card is bigger than the faceup card
		otherval1=matchval;
		otherval=matchval;
		
		//loop for processing cards
		for (u; u<hand-1; u++)
		{
			//comp[u].display();
			//cout<<" In For LOOP";
			//compare suits
			testsuit=comp[u].getsuit();
			if (testsuit==matchsuit)
				{
					//test values
				temp[u]=comp[u];
				full=1;
				testval=comp[u].getvalue();
				
				//if value could win, play
				if(testval>matchval)
				{
				//	cout<<"common suit"<<endl;
					if (testval>otherval)
					{
						//cout<<"found higher val";
						showing=comp[u];
						otherval=testval;
						k=u;
					}
				}
				else
				//if not a winner then look for smallest of correct suit
					{
						if (testval<otherval1)
						{
							showing=comp[u];
							otherval1=testval;
							l=u;
						}
					}
			}
			
			}
	}

	//if no card of same suit
	if (k==0 && l==0)
	{
		for (u; u<hand-1; u++)
		{
			suit=comp[u].getsuit();
			if (suit=="suit1")
			{
				suit1=suit1+1;
			}
			if (suit=="suit2")
			{
				suit2=suit2+1;
			}
			if (suit=="suit3")
			{
				suit3=suit3+1;
			}
		}
		if (suit1>suit2 && suit1>suit3)
		{
			matchsuit="suit1";
				//loop for processing cards
			for (u; u<hand; u++)
			{
				//compare suits
				testsuit=comp[u].getsuit();
				if (testsuit==matchsuit)
					{
					//test values
						testval=comp[u].getvalue();
							if (testval<otherval1)
							{
								showing=comp[u];
								otherval1=testval;
								l=u;
							}
					}
			}
		}
		
	}
	if (k==0) //make sure card returning has value
	{
		k=l;
	}
	//swaps the return card with last card of hand
	//cout<<"card id found";
	temp[11]=comp[k];
	//cout<<"temp";
	comp[k]=comp[hand-1];
	//cout<<"swap";
	comp[hand-1]=temp[11];
	return showing;
	}

