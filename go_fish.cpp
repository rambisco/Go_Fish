#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <ctime>
using namespace std;

string convertChar(char v);


int main(int argc, char *argv[]) {

	ofstream output;
  	output.open ("output.txt");

  	std::vector<Player*> players;

  	vector<Player*>::iterator playerList;

  	int startCardsNum;

	srand(time(NULL)); //seed random number generator

    Deck *deck = new Deck();
    int k = rand() % 1000;
    k = rand() % 1000;
    k = rand() % 1000;

    for(k = k; k > 0; k--){
    deck->shuffle();
    }

    Player player1("John");

    Player player2("Jake");

    Player player3("Joe");

    Player player4("Randy");

    players.push_back(&player1);

    players.push_back(&player2);

    players.push_back(&player3);

    players.push_back(&player4);

    if(players.size() != 2){
    	startCardsNum = 7;
    }

	if(players.size() == 2){
    	startCardsNum = 5;
    }

    for(int i = 0;i < startCardsNum; i++){ //deal cards to each player
    	for(playerList = players.begin(); playerList != players.end(); playerList++){
    		Player* dealTo = *playerList;
    		deck->dealCard(dealTo);
    	}
    }

    /*The player whose turn it is to play asks another player 
    for their cards of a particular rank. For example, 
    "Agatha, do you have any threes?". A player may only 
    ask for a rank of which they already hold at least one 
    card. The recipient of the request must then hand over all 
    cards of that rank. If the call was successful, the same 
    player has another turn. If the player who was asked has 
    no cards of that rank, they say "Go fish" (or simply "Fish"), 
    and the asking player draws the top card from the pack. 
    The turn then passes to the player who was asked.
	
	When one player has four of the same cards of a given rank, 
	they form a book, and the cards are placed face up on the table. 
	The game ends when all 13 books are formed, and the 
	player who won the most books wins.

	If the player whose turn it is has no cards left in hand, 
	the game is not over, but they simply draw the top card 
	from the pack and the turn passes to the next player in
	the rotation, or, in the case of a two-player game, the 
	other player.*/


    int totalBooks = 0;
    bool done = 0;
    vector<Player*>::iterator playerIter;
    playerIter = players.begin();

    while(totalBooks != 13){ //Main game logic

    	
    	vector<Player*>::iterator iter;

    	iter = players.begin();

    	Player* p = *(playerIter); //it is p's turn

		char askFor;

		if(p->getHandSize() == 0){
			cout << p->getName() << " draws a card because hand is empty." << endl;
			deck->dealCard(p);
			if(p->getHandSize() != 0){ //upon successful draw, output
				output << p->getName() << " draws a card because their hand is empty." << endl;
			}
		}

		if(p->getHandSize() != 0){ //if not empty hand + empty deck
			while(p->hasCardbyValue(askFor) == 0){ //find a card the player has
				int j = rand() % 14;

				if(j==1){
			        askFor = 'A';
			    }
			    if(j==11){
			        askFor = 'J';
			    }
			    if(j==12){
			        askFor = 'Q';
			    }
			    if(j==13){
			        askFor = 'K';
			    }
			    if((j > 1) && (j < 11)){
			        askFor = 0x30 + j;
			    }
			}

			iter = players.begin();

			int randPlayer = rand() % players.size();

			Player* p2 = *(iter + randPlayer); //p2 is player being asked

			while(p2->getName() == p->getName()){ 
				randPlayer = rand() % players.size(); //find a random player to ask
				p2 = *(iter + randPlayer);

			}
			 
			cout << p->getName() << ": " << p2->getName() << ", do you have any " << convertChar(askFor) << "'s?" << endl;
			output << p->getName() << ": " << p2->getName() << ", do you have any " << convertChar(askFor) << "'s?" << endl;

			int hasCard = p2->hasCardbyValue(askFor);

			if(hasCard){

				cout << p2->getName() << ": Yes, I have " << hasCard << " " << convertChar(askFor) << "'s." << endl;
				output << p2->getName() << ": Yes, I have " << hasCard << " " << convertChar(askFor) << "'s." << endl;

				for(int i = hasCard; i > 0; i--){

					p2->giveCardbyValue(askFor, *p); //give those cards to other player

				}
				
			}

			if(!hasCard){
				cout << p2->getName() << ": No, I don't have any " << convertChar(askFor) << "'s." << endl;
				output << p2->getName() << ": Go Fish!" << endl;
				if(deck->dealCard(p) == -1){
					cout << "deck is empty" << endl;
					output << "Player receives no cards because the deck is empty." << endl;
				}
			}

			cout << p->getName() << "'s cards: " << p->showHand() << endl;
			cout << p2->getName() << "'s cards: " << p2->showHand() << endl;

			//check for books
			char newBook = p->addBooks();
			if(newBook != '0'){
				cout << p->getName() << " books the " << convertChar(newBook) << "'s." << endl;
				output << p->getName() << " books the " << convertChar(newBook) << "'s." << endl;
				totalBooks++; //they booked something
			}		
			


			if((playerIter+1) != players.end()){ //loop through the player list
				playerIter++;
			}
			else{
				playerIter = players.begin();
			}
	    }
	    else{ //skip because hand empty and deck empty
	    	output << p->getName() << " is skipped because their hand and the deck are empty." << endl;
	    	cout << p->getName() << " is skipped because their hand and the deck are empty." << endl;
	    	if((playerIter+1) != players.end()){ //loop through the player list
				playerIter++;
			}
			else{
				playerIter = players.begin();
			}
	    }
	}
	

	//determine the winner

	int maxBooks = 0;
	bool tie = 0;
	string winner = "";
	string winner2 = "";
	for(playerList = players.begin(); playerList != players.end(); playerList++){
		Player* currentPlayer = *(playerList);

		output << currentPlayer->getName() << " has " << currentPlayer->getBooks() << " books." << endl;

		if(currentPlayer->getBooks() == maxBooks){
			tie = 1;
			winner2 = currentPlayer->getName();
		}

		if(currentPlayer->getBooks() > maxBooks){

			maxBooks = currentPlayer->getBooks();
			winner = currentPlayer->getName();
			tie = 0;

		}
	}

	if(!tie){
		output << winner << " wins!";
	}
	if(tie){
		output << "Tie between " << winner << " and " << winner2 << "!" << endl;
	}

}

string convertChar(char v){
	if(v == ':'){
			return "10"; //this section serves to fix the fact that 10 is not a single character
		}
		else{
			string temp = "";
			temp.push_back(v);
			return temp;
		}
}



