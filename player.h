//DOCUMENT HERE

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <cstdlib>
#include "card.h"
#include "deck.h"

using namespace std;

class Player
{
   private:

      string name;
      
      std::vector<card> hand;

      std::vector<char> books;
   
   public:

      /* FUNCTION - constructor

       input parms - given a valid string

       output parms - new player created whose name was given string
      */
      Player(string name);

      /* FUNCTION - getName

       input parms - player exists

       output parms - returns name of player as string
      */

      string getName();

      /* FUNCTION - addBooks

       input parms - player exists

       output parms - returns '0' if the player did not have 4 of any card.

       if the player has 4 of a card value, returns the value of the 4 cards and removes them
       from the player's hand.
      */

      char addBooks();

      /* FUNCTION - getBooks

       input parms - player exists

       output parms - returns the number of books a player has
      */

      int getBooks();

      /* FUNCTION - getHandSize

       input parms - player exists

       output parms - returns number of cards in player's hand
      */

      int getHandSize();

      /* FUNCTION - add Card

       input parms - player exists, card exists

       output parms - card is added to the player's hand
      */

      void addCard(card const &s);

      /* FUNCTION - hasCard

       input parms - player exists, card exists

       output parms - returns number of cards that match the inputted cards,
       0 if none do
      */

      int hasCard(card const &s);

      /* FUNCTION - hasCardbyValue

       input parms - player exists, input is valid character value of card

       output parms - number of cards with that value in the player's hand
      */

      int hasCardbyValue(char v);


      /* FUNCTION - removeCard

       input parms - player exists, card exists

       output parms - removes a card that matches the input card
      */


      int removeCard(card const &s);

      /* FUNCTION - removeCardbyValue

       input parms - player exists, input is valid char value of card

       output parms - removes a card that has the same value as input
      */


      int removeCardbyValue(char v);

      /* FUNCTION - giveCard

       input parms - both players exist

       output parms - gives a card that matches the input card to the input
       player, and removes it from original player's hand
      */


      int giveCard(card const &s, Player &p);

      /* FUNCTION - giveCardbyValue

       input parms - both players exist, input value is valid card char value

       output parms - gives a card that matches the input value to the input
       player, and removes it from original player's hand
      */


      int giveCardbyValue(char v, Player &p);


      /* FUNCTION - showHand

       input parms - player exists

       output parms - returns a string containing each card in the player's hand's
       value and suit, separated by commas. 
      */

      string showHand();

 
};



#endif