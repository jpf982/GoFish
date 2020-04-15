#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "deck.h"
#include "card.h"
#include "player.h"

using namespace std;

Player::Player(){
    myName = "Player";
}

void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::cardInHand(Card c) const{
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i].getRank() == c.getRank() && myHand[i].sameSuitAs(c)){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    for(auto i = myHand.begin(); i != myHand.end(); i++){
        if(*i == c){
            Card removedCard = *i;
            myHand.erase(i);
            return removedCard;
        }
    }
    return Card(0,Card::Suit::spades);
}

string Player::showHand() const{
    string handstring;
    for(int i = 0; i < myHand.size(); i++){
        handstring += myHand[i].toString() + " ";
    }
    return handstring;
}

string Player::showBooks() const{
    string bookstring;
    for(int i = 0; i < myBook.size(); i+=2){
        bookstring += myBook[i].toString();
        bookstring += myBook[i+1].toString() + " ";
    }
    return bookstring;
}

int Player::getHandSize() const{
    return myHand.size();
}

int Player::getBookSize() const{
    return myBook.size();
}

bool Player::checkHandForPair(){
    for(auto i = myHand.begin(); i != myHand.end(); i++){
        for(auto j = i++; j != myHand.end(); j++){
            if(*i == *j){
                Card c1 = *i;
                removeCardFromHand(*i);
                Card c2 = *j;
                removeCardFromHand(*j);
                bookCards(c1,c2);
                return true;
            }
        }
    }
    return false;
}

bool Player::sameRankInHand(Card c) const {
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}
