
#include <cstdlib>
#include <iostream>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <string>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Deck::Deck(){
    char suits[4] = {'d','c','h','s'};
    char value = '0';
    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 14; j++){
            if(j==1){
                value = 'A';
            }
            if(j==11){
                value = 'J';
            }
            if(j==12){
                value = 'Q';
            }
            if(j==13){
                value = 'K';
            }
            if((j > 1) && (j < 11)){
                value = 0x30 + j;
            }
            this->deck.push_back(card(value,suits[i])); 
        }
    }   
}



int Deck::getSize(){
    return this->deck.size();
}

int Deck::dealCard(Player *p){
    if(this->deck.size() == 0){
        return -1;
    }
    card *topCard = &(this->deck.back());
    
    //cout << topCard->getSuit() << ", " << topCard->getValue() << endl;
    
    p->addCard(*topCard);
    
    this->deck.pop_back();
    return 0;
}

void Deck::shuffle(){

    vector<card>::iterator iter;

    std::random_shuffle(this->deck.begin(),this->deck.end());
}


Deck::~Deck(){

}



