
#include <cstdlib>
#include <iostream>
#include "card.h"
#include <string>

using namespace std;

card::card(char val, char su){

    this->value = val;
    this->suit = su;

}

char card::getValue(){
    return this->value;

}

char card::getSuit(){
    return this->suit;

}

bool card::operator == (const card &s){
    if(this->value != s.value){
        return 0;
    }
    return 1;
}





