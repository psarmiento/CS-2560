/*
	This program demonstrates the use of exception handling classes within already built classes 
*/
#include <iostream>
#include <string>

// Base class, holds basic Employee information 
class Employee {
private:
	std::string _name, _hireDate;
	int _eNumber;

	// Private default constructor 
	Employee(){}

public:
	// Constructor defining all member variables 
	Employee(std::string name, std::string hireDate, int number) : _name(name), _hireDate(hireDate), _eNumber(number) {

	}

	// Exception class for an invalid employee number 
	class InvalidEmployeeNumber {
	private:
		int value;
	public:
		InvalidEmployeeNumber(int val) {
			value = val;
		}

		inline const int getVal() const {
			return value;
		}
	};

	// Getter functions 
	std::string const getName()const { return _name; }
	std::string const getHireDate()const { return _hireDate; }
	inline int const getNumber()const { return _eNumber; }

	// Setter functions 
	void setName(std::string &name) { _name = name; }
	void setHireDate(std::string &date) { _hireDate = date; }
	void setNumber(int num) { 
		if (num <= 0 && num > 10000)
			_eNumber = num;
		else
			throw InvalidEmployeeNumber(num);
	}
};

// Derived class from Employee 
// Includes shift and hourly rate 
class ProductionWorker : public Employee {
private:
	// shift indicates if worker has day or night shift 
	// 1 == day shift,  2 == night shift
	int _shift;
	double _payRate;
	
public:
	// Constructor defining all variable members 
	ProductionWorker(std::string name, std::string date, int num, int shift, double pay) : Employee(name, date, num),
		_shift(shift), _payRate(pay) {

	}

	// Exception class for invalid shift numbers
	class InvalidShift {
	private:
		int value;
	public:
		InvalidShift(int val) { value = val; }

		inline const int getVal()const { return value; }
	};

	// Exeption class for invalid pay rate numbers
	class InvalidPayRate {
	private:
		int value;
	public:
		InvalidPayRate(int val) { value = val; }

		inline const int getVal()const { return value; }
	};

	// Getter functions 
	inline int const getShift()const { return _shift; }
	inline double const getPayRate()const { return _payRate; }

	// Setter functions 
	void setShift(int s) {
		if (s == 1 || s == 2)
			_shift = s;
		else
			throw InvalidShift(s);
	}
	void setPayRate(double pay) {
		if (pay >= 0)
			_payRate = pay;
		else
			throw InvalidPayRate(pay);
	}

};



int main() {
	Employee e1("Paul", "1/2/2019", 10);
	ProductionWorker p1("Bob", "1/4/2019", 500, 0, 12.34);

	// Test every case for exceptions in both classes 
	try {
		e1.setNumber(-14);
	}

	catch (Employee::InvalidEmployeeNumber e) {
		std::cout << "Invalid employee number entered, value is " << e.getVal() << ", value must be between 0 - 9999\n";
		std::cout << "Value entered was " << e.getVal() << std::endl;
	}

	try {
		p1.setPayRate(-10.3);
	}

	catch (ProductionWorker::InvalidPayRate p) {
		std::cout << "Negative value for pay rate entered, must be greater than 0\n";
		std::cout << "Value entered was " << p.getVal() << std::endl;
	}
	
	try {
		p1.setShift(10);
	}
	catch (ProductionWorker::InvalidShift p) {
		std::cout << "Invalid shift entered, must either be 1 or 2\n";
		std::cout << "Shift value entered was " << p.getVal() << std::endl;
	}

	std::cout << "End of program\n";
	return 0;
}
