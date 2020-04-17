#include <iostream>
#include <sstream>
#include <string>
#include "card.h"

using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card::toString() const{
    string rank = rankString(myRank);
    string suit = suitString(mySuit);
    return rank + suit;
}

bool Card::sameSuitAs(const Card& c) const{
    return c.mySuit == mySuit;
}

int Card::getRank() const{
    return myRank;
}

string Card::suitString(Suit s) const{
    if(s == spades){
        return "s";
    }
    else if(s == hearts){
        return "h";
    }
    else if(s == diamonds){
        return "d";
    }
    else{
        return "c";
    }
}

string Card::rankString(int r) const{
    if(r == 1){
        return "A";
    }
    else if(r == 11){
        return "J";
    }
    else if(r == 12){
        return "Q";
    }
    else if(r == 13){
        return "K";
    }
    else{
        stringstream s;
	s << r;
	string out = s.str();
        return out;
    }
}

bool Card::operator == (const Card &rhs) const{
    return (rhs.myRank == this->myRank) &&
           (rhs.mySuit == this->mySuit);
}

bool Card::operator != (const Card &rhs) const{
    return (rhs.myRank != this->myRank) &&
           (rhs.mySuit != this->mySuit);
}
