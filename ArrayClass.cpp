#include <iostream>
using namespace std;

class Arr {
private: 
	int size;
	double *arrPtr;

public:
	// Constructor accepting int to dynamically create an array
	Arr(int n) {
		size = n;
		arrPtr = new double[size];	
	}

	~Arr(){
		delete[] arrPtr;			// free memory
	}

	// Store a number in any element of the array
	void store(double input, int index) {
		if (index <= size) {
			arrPtr[index] = input;
		}
	}

	// Return value from certain index
	double retrieve(int index) {
		if (index <= size)
			return arrPtr[index];
	}

	// Return highest value in array
	double highestVal() {
		double largest;
		
		// Set largest to first index 
		// Compare all values after
		largest = arrPtr[0];

		for (int x = 1; x < size; x++) {
			if (arrPtr[x] > largest)
				largest = arrPtr[x];
		}
		return largest;
	}


	// Return least value in array
	double leastVal() {
		double least;

		// Set largest to first index 
		// Compare all values after
		least = arrPtr[0];

		for (int y = 1; y < size; y++) {
			if (arrPtr[y] < least)
				least = arrPtr[y];
		}
		return least;
	}

};
int main() {
	Arr a1(10);
	a1.store(10.34, 0);
	a1.store(100.1, 1);
	a1.store(45.4, 2);
	a1.store(0.34, 3);

	double test;
	test = a1.retrieve(0);
	cout << "Tests value at index 0: " << test << endl;

	test = a1.retrieve(2);
	cout << "Tests value at index 2: " << test << endl;

	cout << "Largest value is " << a1.highestVal() << endl;
	cout << "Lowest value is " << a1.leastVal() << endl;
	
	return 0;
}
