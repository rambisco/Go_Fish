//DOCUMENT HERE

#ifndef UTPOD_H
#define UTPOD_H
#include <string>
#include <vector>
#include <cstdlib>
#include "card.h"
#include "player.h"

using namespace std;

//UtPod class declaration
class Deck
{
   private:
      std::vector<card> deck;
   
   public:

      //Default constructor
      //output params: deck has 52 cards, 2-A, all 4 suits
      Deck();

      /* FUNCTION - getSize
       input params - deck exists
       output params - returns amount of cards left in deck
       */

      int getSize();


      /* FUNCTION - deal card
       input params - deck exists and player exists
       output params - returns 0 if player given a card, -1 if deck empty
       */

      int dealCard(Player *p);


      /* FUNCTION - void shuffle
       *  shuffles the deck into random order

         input parms - deck exists

         output parms - order of cards is randomized
      */

      void shuffle();


      /* FUNCTION - deck destructor

         input parms - deck exists

         output parms - deck memory cleared with default destrcutor
      */
      ~Deck();


 
};



#endif