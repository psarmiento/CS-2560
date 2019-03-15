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
	double m_feeTotal;					// patients total amount of fees for staying inside the hotel
	int m_daysIn;						// total amount of days stay in hospital 
public:
	PatientAccount(double fee, int daysIn) {
		m_feeTotal = fee;
		m_daysIn = daysIn;
	}

	PatientAccount() {					// Default constructor, call other constructor and set values to zero 
		PatientAccount(0, 0);
	}

	void addDay() { m_daysIn++; }		// Increments the amount of days spent in hospital by 1, should be performed for every surgery a patient has

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
	double m_brainS, m_legS, m_armS, m_heartS, m_bodyS;

public:
	Surgery() {						// Default constructor, setup default prices for all the surgeries
		m_brainS = 3000.0;
		m_legS = 1700.0;
		m_armS = 1450.0;
		m_heartS = 4500.0;
		m_bodyS = 2500.0;
	}

	/*
		When called from main, will display a menu and ask the user what kind of surgery their patient is going to have 
		When the proper selection is made, will add the total of that to patients total
	*/
	void selectSurgery(PatientAccount &patient) {
		cout << "Please select the surgery or several surgeries the patient will undergo\n";
		int input;						// User input 
		while (input != 6) {
			surgeryMenu();
			cin >> input;
			if (input == 1) {
				patient.m_feeTotal += m_brainS;
				patient.addDay();		// Should always add an extra day when a surgery is added for the patient 
			}

			else if (input == 2) {
				patient.m_feeTotal += m_legS;
				patient.addDay();
			}
			else if (input == 3) {
				patient.m_feeTotal += m_armS;
				patient.addDay();
			}
			else if (input == 4) {
				patient.m_feeTotal += m_heartS;
				patient.addDay();
			}
			else if (input == 5) {
				patient.m_feeTotal += m_bodyS;
				patient.addDay();
			}
			else if (input == 6)
				break;
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
class Pharmacy{};


/*
	main will include a menu based program
	User will be able to enter the type of surgery the patient is having, and 
	type of medication. Also should be able to check the patient out of the hospital.
	When patient is checked out, the patients charges should be displayed 

*/
int main()
{

	return 0;
}
