/*
	This program demonstrates the use of several operator overloading functions 
	by utilizing it within the date class 
*/
#include <iostream>
#include <string>
using namespace std;

/*
	Date class will take in 3 int values, month, date, and year 
	User will be able to perform certain operations utilizing the overload operations 
	Bounds checking will also be included
*/
class Date {
private:
	int m_month, m_day, m_year;
	string monthArr[12];					// String array holding the name for every month, will be used for output 
public:
	Date(int month, int day, int year) {	// Constructor taking 3 int values to set the date
		// Bounds checking for months
		if (month < 1 || month > 12) {
			cout << "Your selected month is out of bounds, month will be set to January";
			m_month = 1;
		}

		// Bounds checking for February
		if (month == 2 && (day < 1 || day > 28)) {
			cout << "Day is out of bounds for your selected month, day will be set to 1\n";
			m_day = 1;
		}

		// Bounds checking for months ending with 30 days
		if (month == 4 || month == 6 || month == 9 || month == 11 && (day < 1 ||day > 30)) {
			cout << "Day is out of bounds for your selected month, day will be set to 1\n";
			m_day = 1;
		}

		// Bounds checking for months ending with 31 days
		if (day < 1 || day > 31) {
			cout << "Day is out of bounds for your selected month, day will be set to 1\n";
			m_day = 1;
		}
		m_month = month;
		m_day = day;
		m_year = year;
		// Set each months name in the monthArr
		monthArr[0] = "January";
		monthArr[1] = "February";
		monthArr[2] = "March";
		monthArr[3] = "April";
		monthArr[4] = "May";
		monthArr[5] = "June";
		monthArr[6] = "July";
		monthArr[7] = "August";
		monthArr[8] = "September";
		monthArr[9] = "October";
		monthArr[10] = "Nevember";
		monthArr[11] = "December";
	}
	// Default constructor calling first constructor
	Date() {								
		Date(1, 1, 1);
	}

	inline int getDay()const { return m_day; }							// Return day of current object

	inline string getMonth()const { return monthArr[m_month - 1]; }		// Return month of current object in string

	inline int getYear()const { return m_year; }						// Return year 

	void setDay(int day) { m_day = day; }								// Set day

	void setMonth(int month) { m_month = month; }						// Set month

	void setYear(int year) { m_year = year; }							// Set year 

	// This function will increment the day member of this class
	// If it is the last day of the month, increment to next month 
	// If it is the last day of the year, go to the next year
	void operator ++() {
		// If last day is in February
		if (m_month == 2 && m_day == 28) {
			m_month++;
			m_day = 1;
		}
		// Checking if it is last day of a month with only 30 days 
		else if ((m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11) && m_day == 30) {
			m_month++;
			m_day = 1;
		}
		// If it is the last day of the year, increment to 1rst day of next year 
		else if (m_month == 12 && m_day == 31) {
			m_month = 1;
			m_day = 1;
			m_year++;
		}
		// Remaining months end with 31 days
		else if (m_day == 31) {
			m_month++;
			m_day = 1;
		}
		// Increment day if it is not the last day of month 
		else
			m_day++;
	}

	// This function will decrease the day by 1
	// If day is 1rst of the month, go to next day 
	// If it is the 1rst day of the year, go back one year
	void operator-- () {
		// Checking for 1rst day of the year
		if (m_month == 1 && m_day == 1) {
			m_day = 31;
			m_month = 12;
			m_year--;
		}
		// 1rst day of the month going back to a month starting at 31
		else if ((m_month == 4 || m_month == 6 || m_month == 8 || m_month == 9 || m_month == 11) && m_day == 1) {
			m_month--;
			m_day = 31;
		}
		// 1rst day of the month going back to a month starting at 30
		else if ((m_month == 5 || m_month == 7 || m_month == 10 || m_month == 12) && m_day == 1) {
			m_month--;
			m_day = 30;
		}
		// Going back into February
		else if (m_month == 3 && m_day == 1) {
			m_month--;
			m_day = 28;
		}
		// If the day is in the middle
		else
			m_day--;
	}

	// Returns the difference between two dates 
	int operator-(Date &second)const {
		return (this->m_day - second.getDay());
	}

};

// Operator overload for << 
// Prints out the date
std::ostream &operator << (ostream &output,const Date &temp) {
	return output << temp.getMonth() << " " << temp.getDay() << ", " << temp.getYear() << endl;
}

// Operator overload for >> 
// Prompts user to enter a date to be stored
std::istream &operator >> (istream &input, Date &temp) {
	// Temp variables to take in user input 
	int day, month, year;
	cout << "You will now be able to enter in a new date\n";
	cout << "Enter month: ";
	cin >> month;

	// Bounds checking for month
	while (month < 1 || month > 12) {
		cout << "Invalid input for month, enter another month (1-12): ";
		cin >> month;
	}
	temp.setMonth(month);

	cout << "Enter a day: ";
	cin >> day;

	// Bounds checking if month is February
	while (month == 2 && (day < 1 || day > 28)) {
		cout << "Invalid day entered for February, enter another day: ";
		cin >> day;
	}

	// Bounds checking for months ending with 30 
	while ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) {
		cout << "Invalid day entered for months ending with 30 days, enter another day: ";
		cin >> day;
	}

	// Bounds checking for months ending with 31 days 
	while ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 30)) {
		cout << "Invalid day entered for months ending with 31 days, enter another day: ";
		cin >> day;
	}

	// If day passes all checks, then assign it to the object 
	temp.setDay(day);

	// Set year 
	cout << "Enter a year : ";
	cin >> year;
	temp.setYear(year);
	return input;
}


int main() {
	Date d1(10, 25, 1995);
	Date d2(2, 28, 1990);
	cout << d1;
	cout << d2;
	++d1;
	++d2;
	cout << "Values after incrementing by 1\n";
	cout << d1;
	cout << d2;

	cout << "Values after decrementing by 1\n";
	--d1;
	--d2;
	cout << d1 << d2;


	cin >> d1;
	cout << "\n\nD1 after cin...\n";
	cout << d1;
	return 0;
}
