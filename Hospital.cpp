#include <iostream>
#include <string>
using namespace std;
/*
	This class keeps track of a patients charges from the hospital 
	Also keeps count of how many days have been spent at the hospital 
	Hospital day rate should be determined somewhere, and added to the total for the patient 
*/
class PatientAccount {
private:
	string m_name;
	double m_feeTotal;					// patients total amount of fees for staying inside the hospital
	int m_daysIn;						// total amount of days stay in hospital 
	double hospitalRate;				// the rate patient will be charged for staying each night in hospital
public:
	PatientAccount(string name, double rate) {
		m_name = name;
		hospitalRate = rate;
		m_feeTotal = 0;
		m_daysIn = 0;
	}

	PatientAccount() {					// Default constructor, call other constructor and set values to zero 
		PatientAccount("", 0);
	}

	void addDay() {						 // Increments the amount of days spent in hospital by 1, should be performed for every surgery a patient has
		m_daysIn++; 
		m_feeTotal += hospitalRate;
	}		

	// Displays the patients billing information
	void displayInfo() {
		cout << m_name << "'s total bill comes out to $" << m_feeTotal << endl;
	 }

	friend class Surgery;
	friend class Pharmacy;
};



/*
	Stores chargest for at least 5 different types of surgery 
	Updates the charge value inside of PatientAccount 
	Each surgery will have a different price point 
*/
class Surgery{
private:
	double priceArr[5];											// holds the values of the different surgeries offered
																// surgery types correspond with the menu

public:
	Surgery() {						
		// Setup default prices
		priceArr[0] = 3000.0;
		priceArr[1] = 1700.0;
		priceArr[2] = 1450.0;
		priceArr[3] = 4500.0;
		priceArr[4] = 2500.0;
	}

	/*
		When called from main, will display a menu and ask the user what kind of surgery their patient is going to have 
		When the proper selection is made, will add the total of that to patients total
	*/
	void selectSurgery(PatientAccount &patient) {
		cout << "Please select the surgery or several surgeries the patient will undergo\n";
		int input = 0;						// User input 
		while (input != 6) {
			surgeryMenu();
			cin >> input;
			if (input == 6)					// if input is 6, break out of loop
				break;
			else {
				patient.m_feeTotal += priceArr[input - 1];				// Add the total of the appropriate choice to the patients total on their bill
				patient.addDay();										// Also add an extra day of stay for patient everytime a surgery is added
			}

		}
	}

	void surgeryMenu() {
		cout << "1. Brain\n";
		cout << "2. Leg\n";
		cout << "3. Arm\n";
		cout << "4. Heart\n";
		cout << "5. Body\n";
		cout << "6. Exit\n";
	}
};

/*
	Stores prices for at least 5 different medications 
	Can update the charge value inside of PatientAccount 
*/
class Pharmacy{
private:
	double medArr[5];				// Array holding the prices for each different kind of medication offered 
									// the appropriate name for the medication corresponds with the menu 

public:
	Pharmacy() {
		medArr[0] = 30.0;
		medArr[1] = 15.0;
		medArr[2] = 38.0;
		medArr[3] = 11.0;
		medArr[4] = 60.0;
	}


	void selectMeds(PatientAccount &patient) {
		cout << "Please select the medication that the patient will also require\n";
		int input = 0;
		while (input != 6) {				// get user input
			medMenu();
			cin >> input;
			
			if (input == 6)					// break if the input is 6
				break;

			else
				patient.m_feeTotal += medArr[input - 1];			// add total to the patients bill, no need to add an hospital day 
		}
	}

	// Menu for the medications
	void medMenu() {
		cout << "1. Pain killers\n";
		cout << "2. Anti-biotics\n";
		cout << "3. Sleeping aid pills\n";
		cout << "4. Cough medicine\n";
		cout << "5. Fever reducer\n";
		cout << "6. Exit\n";
	}
};


/*
	main will include a menu based program
	User will be able to enter the type of surgery the patient is having, and 
	type of medication. Also should be able to check the patient out of the hospital.
	When patient is checked out, the patients charges should be displayed 

*/
int main()
{
	PatientAccount p1("Paul", 60);
	Pharmacy test;
	Surgery s1;
	s1.selectSurgery(p1);
	test.selectMeds(p1);
	p1.displayInfo();
	return 0;
}
