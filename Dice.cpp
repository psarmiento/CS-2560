#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/*
	This class represents a die for the game of 21
	Will randomly generate a number between 1 - 6

*/
class Dice {
private:
	int m_die;					// Represents random number generated 
public:
	// Default Constructor, set value of die to 0
	Dice() { m_die = 0; }

	// Generate random number using the rand function
	// Range is 1 - 6
	void roll() {
		m_die = (rand() % 6) + 1;
	}

	// Return m_die value 
	int getRoll()const { return m_die; }

};

int main() {
	srand(time(NULL));
	int y;
	
	Dice etc;
	etc.roll();
	int x = etc.getRoll();
	cout << x << endl;
	return 0;
}
