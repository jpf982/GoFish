#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES made by Roger Priebe for functions used by this program:
void dealHand(Deck &d, Player &p, int numCards);

int main( ) {
    ofstream file;
    file.open("gofish_results.txt");

    Card dealt;
    int numCards = 7;

    Player p1("Adam");
    Player p2("Eve");


    file << "creating new deck for players " << p1.getName() << " & " << p2.getName() << "..." << endl;
    Deck d;  //create a deck of cards
    d.shuffle();
    file << "deck created and shuffled" << endl;

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    file << p1.getName() <<" has : " << p1.showHand() << endl;
    file << p2.getName() <<" has : " << p2.showHand() << endl;

    file << "Both players look for initial pairs in their hands..." << endl;
    for(int i = 0; i < p1.getHandSize(); i++){
        p1.checkHandForPair();
    }
    for(int i = 0; i < p2.getHandSize(); i++){
        p2.checkHandForPair();
    }

    Card taken;
    while(p1.getBookSize() < 14 && p2.getBookSize() < 14 && d.size() > 0){
        if(p1.getHandSize() != 0){
            Card choice = p1.chooseCardFromHand();
            file << p1.getName() << " asks - Do you have a " << choice.rankString(choice.getRank()) << "?" << endl;
            if(p2.sameRankInHand(choice)){
                file << p2.getName() << " says - Yes. I have a " << choice.rankString(choice.getRank()) << "." << endl;
                taken = p2.removeCardFromHand(choice);
                p1.addCard(taken);
                p1.checkHandForPair();
                file << p1.getName() << " books the " << taken.rankString(taken.getRank()) << endl;
            }
            else{
                file << p2.getName() << " says - Go Fish" << endl;
                dealt = d.dealCard();
                file << p1.getName() << " draws " << dealt.toString() << endl;
                p1.addCard(dealt);
                p1.checkHandForPair();
                file << p1.getName() << " books the " << dealt.rankString(dealt.getRank()) << endl;
            }
        }
        else{
            file << p1.getName() << " draws a card due to an empty hand." << endl;
            p1.addCard(d.dealCard());
        }

        if(p2.getHandSize() != 0){
            Card choice = p2.chooseCardFromHand();
            file << p2.getName() << " asks - Do you have a " << choice.rankString(choice.getRank()) << "?" << endl;
            if(p1.sameRankInHand(choice)){
                file << p1.getName() << " says - Yes. I have a " << choice.rankString(choice.getRank()) << "." << endl;
                taken = p1.removeCardFromHand(choice);
                p2.addCard(taken);
                p2.checkHandForPair();
                file << p2.getName() << " books the " << taken.rankString(taken.getRank()) << endl;
            }
            else if(d.size() > 0){
                file << p1.getName() << " says - Go Fish" << endl;
                dealt = d.dealCard();
                file << p2.getName() << " draws " << dealt.toString() << endl;
                p2.addCard(dealt);
                p2.checkHandForPair();
                file << p2.getName() << " books the " << dealt.rankString(dealt.getRank()) << endl;
            }
        }
        else if(d.size() > 0){
            file << p2.getName() << " draws a card due to an empty hand." << endl;
            p2.addCard(d.dealCard());
        }

    }

    if(d.size() == 0){
        file << "No more cards in the deck." << endl;
    }

    if(p1.getBookSize() > p2.getBookSize()){
        file << p1.getName() << " wins!" << endl;
    }
    else if(p1.getBookSize() < p2.getBookSize()){
        file << p2.getName() << " wins!" << endl;
    }
    else if(p1.getBookSize() == p2.getBookSize()){
        file << "Tie game." << endl;
    }

    file << p1.getName() << "'s Books: " << p1.showBooks() << endl;
    file << p2.getName() << "'s Books: " << p2.showBooks() << endl;

    file << "Game over" << endl;

    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
