#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "deck.h"
#include "card.h"

using namespace std;

Deck::Deck() {
    myIndex = 0;
    for(int i = 0; i < 13; i++){
        myCards[i] = Card(i+1, Card::Suit::spades);
    }
    for(int i = 0; i < 13; i++){
        myCards[i+13] = Card(i+1, Card::Suit::hearts);
    }
    for(int i = 0; i < 13; i++){
        myCards[i+26] = Card(i+1, Card::Suit::diamonds);
    }
    for(int i = 0; i < 13; i++){
        myCards[i+39] = Card(i+1, Card::Suit::clubs);
    }
    srand(time(0));
}

void Deck::shuffle(){
    for(int i = 0; i < 52; i++){
        int swapIndex = rand() % 52;
        Card swapped = myCards[swapIndex];
        myCards[swapIndex] = myCards[i];
        myCards[i] = swapped;
    }
}

Card Deck::dealCard(){
    if(myIndex != 52){
        Card dealt = myCards[myIndex];
        myIndex++;
        return dealt;
    }
    else{
        exit(1);
    }
}

int Deck::size() const{
    return (52-myIndex);
}
