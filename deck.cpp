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
        myCards[i] = Card(i+1, Card::spades);
    }
    for(int i = 0; i < 13; i++){
        myCards[i+13] = Card(i+1, Card::hearts);
    }
    for(int i = 0; i < 13; i++){
        myCards[i+26] = Card(i+1, Card::diamonds);
    }
    for(int i = 0; i < 13; i++){
        myCards[i+39] = Card(i+1, Card::clubs);
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
        return Card(0, Card::spades);
    }
}

int Deck::size() const{
    return (52-myIndex);
}

