
#include <cstdlib>
#include <iostream>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <string>

using namespace std;

Player::Player(string n){
    this->name = n;

}

void Player::addCard(card const &s){

    this->hand.push_back(s);

}

int Player::getHandSize(){
    return this->hand.size();
}

char Player::addBooks(){
    vector<card>::iterator iter;

    for(iter = this->hand.begin(); iter != this->hand.end(); iter++){
        if((this->hasCard(*iter)) == 4){
            char newBook = iter->getValue();
            this->books.push_back(newBook); //add to the players books
            for(int i = 0; i != 4; i++){ //remove all 4 cards
                this->removeCardbyValue(newBook);
            }
            return newBook;
        }
    }
    return '0';
}

int Player::getBooks(){
    return this->books.size();

}

int Player::hasCard(card const &s){
    vector<card>::iterator iter;

    int total = 0;

    for(iter = this->hand.begin(); iter != this->hand.end(); iter++){
        if(*iter == s){
            total++;
        }
    }
    return total;
}

int Player::hasCardbyValue(char v){
    vector<card>::iterator iter;

    int total = 0;

    for(iter = this->hand.begin(); iter != this->hand.end(); iter++){
        if(iter->getValue() == v){
            total++;
        }
    }
    return total;
}

int Player::removeCard(card const &s){
    vector<card>::iterator iter;
    int i = 0;
    for(iter = this->hand.begin(); iter != this->hand.end(); iter++){
        if(*iter == s){
            this->hand.erase(this->hand.begin() + i);
            return 1;
        }
        i++;
    }
    return 0;
}

int Player::removeCardbyValue(char v){
    vector<card>::iterator iter;
    int i = 0;
    for(iter = this->hand.begin(); iter != this->hand.end(); iter++){
        if(iter->getValue() == v){
            this->hand.erase(this->hand.begin() + i);
            return 1;
        }
        i++;
    }
    return 0;
}

    /* searches for a card and if it finds it removes it 
    & gives it to the player p*/

int Player::giveCard(card const &s, Player &p){
    vector<card>::iterator iter;
    int i = 0;
    for(iter = this->hand.begin(); iter != this->hand.end(); iter++){
        if(*iter == s){
            p.addCard(*iter);
            this->hand.erase(this->hand.begin() + i);
            return 1;
        }
        i++;
    }
    return 0;
}

int Player::giveCardbyValue(char v, Player &p){
    vector<card>::iterator iter;
    int i = 0;
    for(iter = this->hand.begin(); iter != this->hand.end(); iter++){
        if(iter->getValue() == v){
            p.addCard(*iter);
            this->hand.erase(this->hand.begin() + i);
            return 1;
        }
        i++;
    }
    return 0;
}

string Player::getName(){
    return this->name;
}

string Player::showHand(){

    vector<card>::iterator iter;

    string h = "";

    for(iter = this->hand.begin(); iter != this->hand.end(); iter++){
        //cout << iter->getSuit() << ", " << iter->getValue() << endl;
        h.push_back(iter->getSuit());
        h.append(" ");
        h.push_back(iter->getValue());
        h.append(", ");
    }
    h.pop_back();
    h.pop_back(); //delete last space and comma

    return h;

}


