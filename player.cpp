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

Card Player::chooseCardFromHand() const{
    auto chosen = myHand.begin();
    return *chosen;
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
    for(int i = 0; i != myHand.size(); i++){
        if(myHand[i].getRank() == c.getRank()){
            Card removedCard = myHand[i];
            myHand.erase(myHand.begin()+i);
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
    return myBook.size()/2;
}

bool Player::checkHandForPair(){
    for(int i = 0; i < myHand.size(); ++i){
        for(int j = i+1; j < myHand.size(); ++j){
            if(myHand[i].getRank() == myHand[j].getRank()){
                Card c1 = myHand[i];
                Card c2 = myHand[j];
                removeCardFromHand(c1);
                removeCardFromHand(c2);
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
