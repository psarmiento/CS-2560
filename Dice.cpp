/*
	This program simulates a game of 21, where users will be competing against 
	a computer.  They will be asked if they want to keep rolling, until they either stop or go 
	over the value of 21 
	Each roll for every player should roll 2 of the dice per roll 
	Computer roll will only roll once 

*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Dice {
private:
	// Represents random number generated
	int m_die;	 
	int m_comp;				// computers total
	int m_player;			// players total 

	// Generate random number using the rand function
	// Range is 1 - 6
	int roll() {
		m_die = (rand() % 6) + 1;
		return m_die;
	}
public:
	// Default Constructor, set all values to 0
	Dice() {
		m_die = 0; 
		m_comp = 0;
		m_player = 0;
	}

	// Rolling for computer 
	void computerRoll() {
		m_comp += roll();			// first roll
		m_comp += roll();			// second roll 
	}

	// Rolling for playing and adding to their total
	int playerRoll() {
		m_player += roll();			// first roll 
		m_player += roll();			// second roll 
		return m_player;
	}

	// Reset the values of the computer and player totals 
	void reset() {
		m_comp = 0;
		m_player = 0;
	}

	// Return players total 
	inline int getPlayerRoll() const { return m_player; }

	// Compare computer and player's value and see if it's over 21 
	// Return false if either value over 21
	// Otherwise return true 
	bool over21() {
		if (m_comp > 21) {
			cout << "Player wins!\n";
			return false;
		}
		else if (m_player > 21) {
			cout << "Computer wins! \n";
			return false;
		}
		else
			return true;
	}

};

int main() {
	// Enables roll() function to be different everytime it is called 
	srand(time(NULL));
	
	char input;
	bool end_Round = true;

	do {


	} while (end_Round != false);
	
	return 0;
}
