// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
//#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
//void dealHand(Deck &d, Player &p, int numCards);




int main( ) {
    Card ace;                                      //default ace of spades
    Card jack(11, Card::Suit::spades);   //jack of spades
    Card queen(12, Card::Suit::hearts); //queen of hearts
    Card king(13, Card::Suit::clubs);   //king of clubs
    Card two(2, Card::Suit::diamonds);  //two of diamonds

    cout << "checking if ace of spades is same suit as jack of spades..." << endl;
    if (ace.sameSuitAs(jack)) {
        cout << "same suit" << endl;
    } else {
        cout << "not same suit" << endl;
    }

    cout << "checking if king of clubs is same suit as queen of hearts..." << endl;
    if (king.sameSuitAs(queen)) {
        cout << "same suit" << endl;
    } else {
        cout << "not same suit" << endl;
    }
    cout << endl;

    cout << "Queen rank = " << queen.getRank() << endl;
    cout << "king rank = " << king.getRank() << endl;
    cout << "jack rank = " << jack.getRank() << endl;
    cout << "ace rank = " << ace.getRank() << endl << endl;

    cout << "string version of ace of spades = " << ace.toString() << endl;
    cout << "string version of two of diamonds = " << two.toString() << endl;
    cout << "string version of jack of spades = " << jack.toString() << endl;
    cout << "string version of queen of hearts = " << queen.toString() << endl;
    cout << "string version of king of clubs = " << king.toString() << endl << endl;

    cout << "creating deck..." << endl;
    Deck a;
    cout << "deck created" << endl;
    cout << "Deck size = " << a.size() << endl;

    Card dealt;
    for (int i = 0; i < 52; i++) {
        dealt = a.dealCard();
        cout << "Card is " << dealt.toString() << endl;
    }

    cout << endl;

    cout << "creating deck..." << endl;
    Deck b;
    cout << "deck created" << endl;
    b.shuffle();
    cout << "shuffling deck..." << endl;
    for(int i = 0; i < 52; i++){
        dealt = b.dealCard();
        cout << "Card is " << dealt.toString() << endl;
    }

    cout << endl;

    cout << "creating deck..." << endl;
    Deck c;
    cout << "deck created" << endl;
    c.shuffle();
    cout << "shuffling deck..." << endl;
    for(int i = 0; i < 52; i++){
        dealt = c.dealCard();
        cout << "Card is " << dealt.toString() << endl;
    }

    cout << "dealing a 53rd card... expecting fail..." << endl;
    c.dealCard();

    cout << "53rd card drawing should have failed. If you see this, it didn't" << endl;

    /*
    int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
*/
    return EXIT_SUCCESS;
}


/*
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}*/
