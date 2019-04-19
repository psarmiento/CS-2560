#include <iostream>
#include <string>
#include <vector>

class Human {
private:
	std::string name;
	int age;
	char sex;

	// Private constructor
	Human(){}

protected:
	Human(std::string n, int a, char s) : name(n), age(a), sex(s) {

	}


	// Virtual Destructor
	virtual ~Human() {

	}

public:
	// Getters
	std::string const getName()const { return name; }
	inline int const getAge() const { return age; }
	char const getSex() const { return sex; }

	// Setters
	void setName(std::string n) { name = n; }
	void setAge(int a) { age = a; }
	void setSex(char s) { sex = s; }

};


class Child : public Human {
private:
	std::string momName, dadName;
	int allowance;

	// Private constructor
	Child():Human("",0,'0'){}

public:
	Child(std::string n, int a, char s, std::string m, std::string d) :Human(n, a, s), momName(m), dadName(d) {
		allowance = 0;
	}

	int getAllowance() const {
		std::cout << "Current allowance is " << allowance << std::endl;
		return allowance;
	}

	void printParent() {
		std::cout << this->getName() << "'s mother's name: " << momName << std::endl;
		std::cout << this->getName() << "'s dad's name: " << dadName << std::endl;
	}

	// Make parent class a friend class of Child 
	friend class Parent;
};


class Parent: public Human {
private:
	// Private Constructor
	Parent():Human("",0,'0'){}

	std::vector<std::string> children;

public:
	// Public constructor
	Parent(std::string n, int a, char s) :Human(n, a, s) {

	}

	// Prints name of all children
	void printChild() {
		// Check if vector is empty or not
		if (children.empty())
			std::cout << "This parent has no children\n";
		else
		{
			for (int x = 0; x < children.size(); x++) {
				std::cout << children.at(x) << " ";
			}
		}
		std::cout << "\n";
	}

	// Adds child to parent 
	void setChild(Child c) {
		children.push_back(c.getName());
	}

	// Change allowance of child 
	void setChildAllowance(int allowance, Child c) {
		c.allowance = allowance;
	}
};

/*void printInfo(Human h) {
	std::cout << "Name: " << h.getName() << std::endl;
	std::cout << "Age: " << h.getAge() << std::endl;
	std::cout << "Sex: " << h.getSex() << std::endl;

}*/

int main() {

	// Initialize all objects with info
	Parent Homer("Homer", 36, 'M');
	Parent March("March", 34, 'F');
	Child Lisa("Lisa", 12, 'F', March.getName(), Homer.getName());
	Child Bart("Bart", 10, 'M', March.getName(), Homer.getName());
	Child Maggie("Maggie", 3, 'F', March.getName(), Homer.getName());

	// Add children to the parent vectors 
	Homer.setChild(Lisa);
	Homer.setChild(Bart);
	Homer.setChild(Maggie);

	March.setChild(Lisa);
	March.setChild(Bart);
	March.setChild(Maggie);

	// Print Bart allowance and also change it
	Bart.getAllowance();
	Homer.setChildAllowance(5, Bart);

	// Bart print parent info
	Bart.printParent();

	// Call print info for March and Lisa
	//printInfo(March);
	//printInfo(Lisa);
	return 0;
}
