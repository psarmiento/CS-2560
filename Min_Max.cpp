#include <iostream>
#include <string>


// Function that returns the max of the two values 
template<typename T>
T max(const T &a,const T &b) {
	// Return a if bigger, else return b
	if (a > b)				
		return a;
	else
		return b;
}

// Funtion that returns the min of the two values 
template<typename T>
T min(const T &a, const T &b) {
	if (a < b)
		return a;
	else
		return b;
}
int main() {
	int x = 10;
	int y = 4;

	std::string a = "sprite";
	std::string b = "cat";

	// Test out all template functions using different data types 
	std::cout << "The bigger of the two integers is: " << max(x, y) << std::endl;
	std::cout << "The min of the two integers is: " << min(x, y) << std::endl;
	std::cout << "The bigger of the two strings is: " << max<std::string>(a, b) << std::endl;
	std::cout << "The smaller of the two strings is: " << min<std::string>(a, b) << std::endl;
	return 0;
}
