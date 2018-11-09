//DOCUMENT HERE

#ifndef CARD_H
#define CARD_H
#include <string>
#include <cstdlib>

using namespace std;

class card{
private:
        char value; //2-10, J Q K A
        char suit; //s, c, d, or h

public:

	      /* FUNCTION - card constructor
       input params - given valid value 2-10, J, Q, K, or A and suit s, c, d, or h
       output params - card made with the given value and suit
       */

card(char value, char suit);

card() {}

~card() {}

      /* FUNCTION - getValue
       input params - card exists
       output params - returns value of card
       */

char getValue();

      /* FUNCTION - getSuit
       input params - card exists
       output params - returns suit of card
       */

char getSuit();

      /* FUNCTION - ==
       input params - both cards exist
       output params - returns true if both cards have same value, false otherwise.
       suit not considered.
       */

bool operator== (const card &s);
    

};



#endif