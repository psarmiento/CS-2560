/*
	BigNumber allows to store large values up to 1,000 digits long using vectors

	TODO LIST:
		- Clean up code on +overload function
			works properly
		- Work on -overload function
			TEST FUNCTION CODE

*/
//#include "stdafx.h"
#include "BigNumber.h"
#include <iostream>
#include <string>

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
	int sum;
	// Temp vector 
	std::vector<int> biggerVector;
	std::vector<int> smallerVector;
	int biggerSize;
	int smallerSize;

	// Assign bigger vector to temp
	// Smaller vector to temp2
	if (v1.size() >= num.getSize()) {
		biggerVector = v1;
		biggerSize = biggerVector.size() - 1;
		smallerVector = num.getVector();
		smallerSize = smallerVector.size() - 1;
	}
	else {
		biggerVector = num.getVector();
		biggerSize = biggerVector.size() - 1;
		smallerVector = v1;
		smallerSize = smallerVector.size() - 1;
	}

	// Start at the end of each vector
	// Add the two elements and carry remainders as necessary 
	for (int x = smallerSize; x >= 0; x--) {
		int val = biggerVector.at(biggerSize);
		int val2 = smallerVector.at(smallerSize);
		sum = val + val2;

		// if sum greater than 10
		if (sum >= 10) {
			int remainder = sum % 10;

			// If more space is required at beginning of vector
			// Shift all elements down 1 
			if (biggerSize == 0) {
				int temp, temp2;
				temp = biggerVector.at(0);
				biggerVector.resize(biggerVector.size() + 1);
				for (int y = 0; y < biggerVector.size() - 1; y++) {
					temp2 = biggerVector.at(y + 1);
					biggerVector.at(y + 1) = temp;
					temp = temp2;
				}
				biggerVector.at(0) = 1;
				biggerVector.at(1) = remainder;
			}

			else if (biggerSize > 0) {

				if (biggerSize == 0) {
					biggerVector.resize(biggerVector.size() + 1);
					biggerVector.at(0) = 1;
					biggerVector.at(1) = 0;
					int temp = biggerVector.at(2);
					int temp2;
					for (int z = 2; z < biggerVector.size(); z++) {
						temp2 = biggerVector.at(z + 1);
						biggerVector.at(z + 1) = temp;
						temp = temp2;
					}

				}
				else {
					biggerVector.at(biggerSize) = remainder;
					biggerVector.at(biggerSize - 1) += 1;
				}
			}
		}

		// if sum is exactly 10
		else if (sum == 10) {
			if (biggerSize > 0) {
				biggerVector.at(biggerSize) = 0;
				biggerVector.at(biggerSize - 1) += 1;
			}
		}

		// Sum 0 - 9
		else if (sum >= 0 && sum < 10)
			biggerVector.at(biggerSize) = sum;

		biggerSize--;
		smallerSize--;
	}

	return BigNumber(biggerVector);
}

BigNumber BigNumber::operator -(BigNumber num) {
	// 2 Temp vectors 
	std::vector<int> largerNum;
	std::vector<int> smallerNum;

	int largerSize, smallerSize;

	// Set largest and smallest vectors based on size 
	if (v1.size() >= num.getSize()) {
		largerNum = v1;
		largerSize = largerNum.size() - 1;

		smallerNum = num.getVector();
		smallerSize = smallerNum.size() - 1;
	}

	else {
		largerNum = num.getVector();
		largerSize = largerNum.size() - 1;

		smallerNum = v1;
		smallerSize = v1.size() - 1;
	}

	int difference, largerVal, smallerVal;
	// Loop to process subtraction calculation 
	for (int x = smallerSize; x >= 0; x--) {
		largerVal = largerNum.at(largerSize);
		smallerVal = smallerNum.at(smallerSize);
		// Check to see if largerVal is less than smallerVal
		if (largerVal < smallerVal) {
			// Need to deal with this case 
			// Add ten to current spot, then calculate difference 
			largerVal += 10;
			largerNum.at(largerSize - 1) -= 1;		
			difference = largerVal - smallerVal;
			largerNum.at(largerSize) = difference;
		}

		// Else carry on with normal subtraction 
		else {
			difference = largerVal - smallerVal;
			largerNum.at(largerSize) = difference;
		}

		// Update values of the sizes 
		largerSize--;
		smallerSize--;
	}

	// if value at beginning is 0, resize 
	if (largerNum.at(0) == 0) {
		int resizeCount = 0;
		// Shift all values down, leave no leading zeros
		while (resizeCount < largerNum.size() - 1) {
			//std::cout << "Larger num at end: " << largerNum.at(2) << std::endl;
			largerNum.at(resizeCount) = largerNum.at(resizeCount + 1);
			resizeCount++;
		}

	}
	

	return BigNumber(largerNum);
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
	v1 = num.getVector();
	return BigNumber(v1);
}


// Print the number 
std::string BigNumber::print() {
	for (int x = 0; x < v1.size(); x++) {
		str += std::to_string(v1.at(x));
	}

	return str;
}

inline int const BigNumber::getSize() { return v1.size(); }

const std::vector<int> BigNumber::getVector() { return v1; }

// Pass in false when number is still being entered 
// When an operator is entered, set to true 
void BigNumber::numEntered(bool b) {
	check = b;
}

// Return check 
bool BigNumber::getBool() { return check; }
