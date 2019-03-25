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
int main() {
	std::cout << "Customers initial data\n";
	CustomerData c1("Sarmiento", "Paul", "3214 Somewhere Ave", 909456789, 100, false);
	std::cout << c1 << std::endl;

	// Change a few variables inside of c1
	c1.setCity("San Francisco");
	c1.setMailingList(true);
	c1.setFirst("Bob");
	c1.setCustomerNumber(500);

	// Output results after change
	std::cout << "\nCustomers data after being altered\n";
	std::cout << c1 << std::endl;
	return 0;
}
