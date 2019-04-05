/*
	This program deomonstrates the use of vectors and how they can dynamically 
	allocate space required to perform actions similar to arrays 
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

// print function for for_each
void print(int i) {
	std::cout << " " << i;
}

// prints only prime numbers in the vector 
void prime(int i) {
	// if % through numbers 1-9 is 0, add to count
	// count == 2 --> prime number 
	// else composite 
	int remainder;
	int count = 0;

	for (int x = 1; x <= i; x++) {
		// get remainder 
		remainder = i % x;

		if (remainder == 0)
			count++;
	}

	if (count == 2)
		std::cout << " " << i;
}

int main() {
	std::vector<int> initial;			// initial vector that will contain all numbers starting from 2 up to user input
	int userInput;						// user will input space for vector 

	std::cout << "Enter an integer 2 or greater: ";
	std::cin >> userInput;

	// if user entered 2 only 2 in the vector 
	if (userInput == 2)
		initial.push_back(2);

	// Else initilize vector 
	else if (userInput > 2) {
		for (int x = 2; x <= userInput; x++) {
			initial.push_back(x);
		}
	}

	// print out initial vector 
	std::cout << "Initial vector\n";
	for_each(initial.begin(), initial.end(), print);

	// print out prime numbers 
	std::cout << "\nPrime numbers\n";
	for_each(initial.begin(), initial.end(), prime);

	std::cout << "\nEnd of program\n";
	return 0;
}
