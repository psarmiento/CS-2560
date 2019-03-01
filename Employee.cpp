#include <iostream>
#include <string>
using namespace std;

/*
	This class holds information for employees which will include things like 
	their name, the department they work in, their position, and their id number 
	Getters and setters are also setup in order to access information inside the private area 

*/
class Employee {
private:
	string name;			// Name of employee
	string department;		// Department they work in
	string position;		// Their position
	int idNumber;			// Workers id number for work 

public:
	// Constructor that takes all the information as paramaters
	Employee(string name, string department, string position, int idNumber) {
		this->name = name;
		this->department = department;
		this->position = position;
		this->idNumber = idNumber;
	}

	// Constructor that takes name and idNumber as paramaters
	Employee(string name, int idNumber) {
		this->name = name;
		this->idNumber = idNumber;
		department = "";
		position = "";

	}

	// Default constructor 
	// If no values are assigned, empty string and 0 will be the
	// default values 
	Employee() {
		name = "";
		department = "";
		position = "";
		idNumber = 0;

	}

	// Getters for all private members 
	// Allows access to private members 
	string getName() { return name;}			// returns name of employee

	string getDept() { return department; }		// returns name of department worker is assigned to 

	string getPosition() { return position; }	// returns position name 

	int getIdNumber() { return idNumber; }		// returns id number

	// Setter for name 
	void setName(string name) {
		this->name = name;
	}

	// Setter for department 
	void setDept(string dept) {
		department = dept;
	}

	// Setter for position 
	void setPosition(string position) {
		this->position = position;
	}

	// Display employee's info 
	void display() {
		cout << "Name of employee: " << name << endl;
		cout << "Department: " << department << endl;
		cout << "Position: " << position << endl; 
		cout << "Id number: " << idNumber << endl << endl;

	}
};



int main() {
	// Declaring 3 employee objects, using the first constructor 
	Employee e1("Susan Meyers", "Accounting", "Vice President", 47899);
	Employee e2("Mark Jones", "IT", "Programmer", 39119);
	Employee e3("Joy Rogers", "Manufacturing", "Engineer", 81774);

	// Display employees info 
	e1.display();
	e2.display();
	e3.display();

	return 0;
}
