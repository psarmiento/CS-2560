// virtual destructor example   base pointer problem
//#include "stdafx.h"
#include<iostream>
using namespace std;


class base {
public:
	base()
	{
		cout << "Constructing base \n";
	}
	virtual~base()
	{
		cout << "Destructing base \n";
	}
};

class derived : public base {
public:
	derived()
	{
		cout << "Constructing derived \n";
	}
	~derived()
	{
		cout << "Destructing derived \n";
	}
};

int main(void)
{
	derived *d = new derived();
	base *b = d;
	// Deleting derived class using base pointer 
	// Order for destructor output: 1) Derived  2) Base
	delete b;
	getchar();
	return 0;
}
