#include<iostream>
#include <string>

// Base class holding basic information for people 
class PersonData {
protected:
	std::string _lastName, _firstName, _address,
		_city, _state;
	int _zip, _phone;

private:
	// Private constructor 
	// Object must be defined when derived 
	// from this class 
	PersonData() {}

public:
	// Constructor utilizing list to initialize all member variables 
	PersonData(const std::string last, const std::string first, const std::string address, const std::string city, const std::string state,
		int z, int p) : _lastName(last), _firstName(first), _address(address), _city(city), _state(state), _zip(z), _phone(p)
	{

	}

	// Accessor functions
	const std::string getLast() { return _lastName; }
	const std::string getFirst() { return _firstName; }
	const std::string getAddress() { return _address; }
	const std::string getCity() { return _city; }
	const std::string getState() { return _state; }
	inline const int getZip() { return _zip; }
	inline const int getPhone() { return _phone; }

	// Setter functions 
	void setLast(std::string last){_lastName = last; }
	void setFirst(std::string first) { _firstName = first; }
	void setAddress(std::string address) { _address = address; }
	void setCity(std::string city) { _city = city; }
	void setState(std::string state) { _state = state; }
	void setZip(int zip) { _zip = zip; }
	void setPhone(int phone) { _phone = phone; }
};

// Derived class from PersonData 
// Contains two additional data members
class CustomerData: public PersonData {
private:
	int _customerNumber;
	bool _mailingList;

public:
	// Constructor that calls base class constructor 
	CustomerData(std::string last, std::string first, std::string address, int phone,int customerN, bool mail)
		: PersonData(last, first, address, "Walnut", "California", 91710, phone),
		_customerNumber(customerN), _mailingList(mail) {

	}

	// Setter functions for the 2 additional member variables 
	void setCustomerNumber(int n) { _customerNumber = n; }
	void setMailingList(bool m) { _mailingList = m; }

	// Getter functions
	inline const int getCustomerNumber()const { return _customerNumber; }
	const bool getMailingList()const { return _mailingList; }
};

// << operator overload 
// Outputs all the information about the customer
std::ostream &operator<< (std::ostream &output, CustomerData &c) {
	output << "Name: " << c.getFirst() << " " << c.getLast() << std::endl;
	output << "Address: " << c.getAddress() << std::endl;
	output << "City: " << c.getCity() << std::endl;
	output << "State: " << c.getState() << std::endl;
	output << "Zip code: " << c.getZip() << std::endl;
	output << "Phone: " << c.getPhone() << std::endl;
	output << "Customer number: " << c.getCustomerNumber() << std::endl;
	// Output if customer is subscribed for the mailing list or not 
	// by checking the mailingList variable
	if (c.getMailingList() == false)
		output << "Customer is not subscribed to mailing list\n";
	else
		output << "Customer is subscribed to mailing list\n";

	return output;
}

// Class derived from CustomerData
// Allows user to add purchases, while also keeping track of a user's discount level 
class PreferredCustomer:public CustomerData {
private: 
	double _purchasesAmount, _discountLevel;

public:
	// Constructor calling CustomerData's constructor 
	PreferredCustomer(std::string last, std::string first, std::string address, int phone, int customerN, bool mail) :
		CustomerData(last, first, address, 91710, customerN, mail) {
		// Two additional members will start at 0
		_purchasesAmount = 0;
		_discountLevel = 0;
	}

	// This function adds purchase amount to the customers total purchase history 
	// If a discount is applicable, then it will be applied before adding into total 
	void addPurchase(double purchase) {
		// Checking if purchase is a positive value  
		// Come back later and factor in discounts
		if (purchase < 1)
			std::cout << "Purchase was a negative number or 0, only positive values are accepted\n";

		else if (purchase > 0) {
			// If customer has qualified for a discount, then apply first before adding to total
			if (_discountLevel > 0) {
				purchase = purchase - (purchase * _discountLevel);
				_purchasesAmount += purchase;
			}

			else
				_purchasesAmount += purchase;
		}

		// Check to see if the customer can upgrade their discount level 
		if (_purchasesAmount >= 500 && _purchasesAmount < 1000 && _discountLevel == 0) {
			std::cout << "Congratulations! Your discount has been upgraded to 5% !!\n";
			_discountLevel = 0.05;
		}
		else if (_purchasesAmount >= 1000 && _purchasesAmount < 1500 && _discountLevel == 0.05) {
			std::cout << "Congratulations! Your discount has been ugraded to 6% !!\n";
			_discountLevel = 0.06;
		}
		else if (_purchasesAmount >= 1500 && _purchasesAmount < 2000 && _discountLevel == 0.06) {
			std::cout << "Congratulations! Your discount has been ugraded to 7% !!\n";
			_discountLevel = 0.07;
		}
		else if (_purchasesAmount >= 2000 && _discountLevel == 0.07) {
			std::cout << "Congratulations! Your discount has been ugraded to 10% !!\n";
			_discountLevel = 0.1;
		}
	}

	inline const double getDiscount()const { return _discountLevel; }
	inline const double getTotal()const { return _purchasesAmount; }
};

// << operator overload 
// Outputs information on the preffered customer
std::ostream &operator<< (std::ostream &output, PreferredCustomer &p) {
	output << "Name: " << p.getFirst() << " " << p.getLast() << std::endl;
	output << "Address: " << p.getAddress() << std::endl;
	output << "City: " << p.getCity() << std::endl;
	output << "State: " << p.getState() << std::endl;
	output << "Zip code: " << p.getZip() << std::endl;
	output << "Phone: " << p.getPhone() << std::endl;
	output << "Customer number: " << p.getCustomerNumber() << std::endl;
	// Output what the customers current purchase total is 
	// and also what their discount level is 
	output << p.getFirst() << "'s total purchases: $" << p.getTotal() << std::endl;
	if (p.getDiscount() == 0)
		output << p.getFirst() << "'s discount is currently at 0%\n";
	else if (p.getDiscount() == 0.05)
		output << p.getFirst() << "'s discount is currently at 5%\n";
	else if (p.getDiscount() == 0.06)
		output << p.getFirst() << "'s discount is currently at 6%\n";
	else if (p.getDiscount() == 0.07)
		output << p.getFirst() << "'s discount is currently at 7%\n";
	else if (p.getDiscount() == 0.1)
		output << p.getFirst() << "'s discount is currently at 10%\n";

	return output;
}

int main() {
	std::cout << "Preferred customers initial data\n";
	PreferredCustomer p1("Sarmiento", "Paul", "3214 Somewhere Ave", 909456789, 100, false);
	std::cout << p1 << std::endl;

	// Adding in purchase amounts
	p1.addPurchase(-12);
	p1.addPurchase(500);
	p1.addPurchase(30);

	std::cout << "\nCustomer's info after a few purchases\n";
	std::cout << p1 << std::endl;

	p1.addPurchase(1000);
	
	return 0;
}
