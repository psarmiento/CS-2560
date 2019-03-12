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
	bool winner;			// false if no winner
							// true if there is 

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
		winner = false;
	}

	// Rolling for computer 
	void computerRoll() {
		m_comp += roll();			// first roll
		m_comp += roll();			// second roll 
	}

	// Rolling for playing and adding to their total
	int playerRoll() {
		if (m_player < 21) {
			m_player += roll();			// first roll 
			m_player += roll();			// second roll 
		}

		else if (m_player > 21)
			checkWinner();		// if players score goes over 21, call checkWinner()
		return m_player;
	}

	// Reset the values of the computer and player totals 
	void reset() {
		m_comp = 0;
		m_player = 0;
	}

	// Return players total 
	inline int getPlayerRoll() const { return m_player; }

	// Return computers total 
	inline int getCompRoll()const { return m_comp; }

	// Check for winner 
	bool checkWinner() {
		// Players score over 21 
		if (m_player > 21) {
			cout << "Computer wins! Your score was over 21\n";
			cout << "Computers score was " << m_comp << endl;
			winner = true;
		}

		// Player score bigger than computers
		else if (m_player > m_comp || m_player <= 21) {
			cout << "Player wins!\n";
			cout << "Computers score was " << m_comp << endl;
			winner = true;
		}

		// Computer score bigger than player
		else if (m_comp > m_player) {
			cout << "Computer wins! With a score of " << m_comp << endl;
			winner = true;
		}

		// Tie score
		else if (m_comp == m_player) {
			cout << "Player and computer scores are the same, it is a tie\n";
			winner = true;
		}
		else
			winner = false;
		return winner;
	}

};

int main() {
	// Enables roll() function to be different everytime it is called 
	srand(time(NULL));

	Dice g1;
	g1.computerRoll();			// first perform computer roll 

	cout << "Game of 21, attempt to beat the computers score\n" << endl;
	cout << "First roll for player and computer will automatically be done\n";
	cout << "You may keep rolling or stop any time after that\n";
	cout << "After your last turn or if your score goes over 21, winner will be revealed\n";
	g1.computerRoll();
	g1.playerRoll();

	char input;
	bool endGame = false;
	while (endGame != true) {
		// Prompt user if they want to roll again 
		cout << "Your current score is " << g1.getPlayerRoll() << endl;
		cout << "Would you like to roll again? (Y/N) ";
		cin >> input;

		if (input == 'y' || input == 'Y') {
			g1.playerRoll();
			if (g1.getPlayerRoll() > 21)
				endGame = g1.checkWinner();
		}

		else if (input == 'n' || input == 'N') {
			 endGame = g1.checkWinner();
		}
	}

	return 0;
}
