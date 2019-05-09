/*
	BigNumber allows to store large values up to 1,000 digits long using vectors

*/
#include "BigNumber.h"
#include <iostream>


BigNumber::BigNumber() {}

BigNumber::BigNumber(int x) {
	// If number greater than 10, grab remainder 
	// Store remainder at end
	if (x > 10) {
		remainder = x % 10;
		v1.push_back(remainder);
		v1.insert(v1.begin(), 1);
	}

	// If value is 10 then store 10
	else if (x == 10) {
		v1.push_back(0);
		v1.insert(v1.begin(), 1);
	}

	// If value is 0 - 9
	else if (x < 10 && x >= 0)
		v1.push_back(x);
}

// Constructor taking vector as an argument and assigning v1 to that vector
BigNumber::BigNumber(std::vector<int> num) { v1 = num; }


// Adds an integer to the back 
void BigNumber::addDigit(int x) {
	if (v1.size() == MAX_DIGITS) {
		std::cout << "Max number of digits reached\n";
	}

	else
		v1.push_back(x);
}

BigNumber BigNumber::operator+ (BigNumber num) {
	std::cout << "Test\n";
	int sum;
	// Temp vector 
	std::vector<int> temp;

	if (v1.size() >= num.getSize())
		temp = v1;
	else
		temp = num.getVector();

	int tempSize = num.getSize();

	std::cout << "temp size: " << tempSize << std::endl;
	// Start at the end of each vector
	// Add the two elements and carry remainders as necessary 
	for (int x = tempSize; x >= 0; x--) {
		int val = v1.at(x);
		int tempVal = num.getVector().at(tempSize);
		sum = val + tempVal;

		if (sum >= 10) {
			int remainder = sum % 10;
			temp.at(x) = remainder;
			temp.at(x + 1) += 1;
		}

		else if (sum == 10) {
			temp.at(x) = 0;
			temp.at(x + 1) += 1;
		}

		else {
			temp.at(x) = sum;
		}
	}

	return BigNumber(temp);
}

BigNumber BigNumber::operator -(BigNumber num) {
	return num;

}

BigNumber BigNumber::operator /(BigNumber num) {
	return num;

}

BigNumber BigNumber::operator *(BigNumber num) {
	return num;

}

BigNumber BigNumber::operator %(BigNumber num) {
	return num;

}

BigNumber BigNumber::operator= (BigNumber num) {
	return BigNumber(num.getVector());
}


// Print the number 
void BigNumber::print() {
	for (int x = 0; x < v1.size(); x++) {
		std::cout << v1.at(x);
	}
	std::cout << "\n";
}

inline int const BigNumber::getSize() { return v1.size(); }

const std::vector<int> BigNumber::getVector() { return v1; }
