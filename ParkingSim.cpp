#include <iostream>
#include <string>
using namespace std;
/*
	This program demostrates several classes working together to simulate 
	an officer issuing a parking permit, which each class having a set responsibility 
*/
// Class simulating a parked car 
// Holds critical information on the car 
class ParkedCar {
private:
	int m_plate, m_minParked;
	string m_brand, m_model, m_color;

public:
	// Constructor taking all arguments to initialize every member variable
	ParkedCar(string brand, string model, string color, int plate, int minParked) {
		m_brand = brand;
		m_model = model;
		m_color = color;
		m_plate = plate;
		m_minParked = minParked;
	}

	// Default constructor 
	ParkedCar() {
		ParkedCar("", "", "", 0, 0);
	}
	
	// Making ParkingTicket class friend of 
	// ParkedCar class 
	friend class ParkingTicket;
	
	// Make PoliceOfficer class friend
	friend class PoliceOfficer;
};

// Simulates a parking meter 
// Holds the amount of time a parked car has been parked 
class ParkingMeter {
private:
	// Number of minutes bought for parking 
	int m_timeBought;
public:
	// Initializes how much time has been bought
	ParkingMeter(int minPaid) { m_timeBought = minPaid; }

	// Default constructor, total time = 0
	ParkingMeter() { m_timeBought = 0; }

	// Make ParkingTicket class a friend of Parking Meter
	friend class ParkingTicket;

	// Making PoliceOfficer class a friend 
	friend class PoliceOfficer;

};

// Reports info on car that is being ticketed 
// Also provides the fine amount 
class ParkingTicket {
private:
	// Amount of fine to be issued to the car
	double m_fine;

public:
	ParkingTicket() {
		m_fine = 0;
	}

	// Issue a fine amount if the parked cars minutes exceed 
	// the amount of time bought to park 
	double issueFine(ParkedCar &car, ParkingMeter &meter) {
		if (car.m_minParked < meter.m_timeBought) {
			// cars parked time now exceeds the amount of time bought
			// get difference and issue fine accordingly 
			// 60 min per hr 
			double difference = car.m_minParked - meter.m_timeBought;

			// Algorithm for percentage of time parked
			// (difference/60) * 25
			// first part gives percentage of time used up 
			if (difference < 60)
				m_fine = (difference / 60) * 25;
			else if (difference >= 60) {
				// Add first 25 dollars b/c gaurenteed time is over an hr 
				// Then compute each hr after that 
				m_fine += 25;
				difference -= 60;
				// Total up fine if the amount of minutes exceeds an hr 
				while (difference > 60) {
					// subtract off 60 minutes and add time 
					difference -= 60;
					m_fine += 10;
				}
				// Implement same algorithm as before, but only for $10
				if (difference < 60)
					m_fine += (difference / 60) * 10;

			}
			return m_fine;
		}

		else
		return m_fine;
	}
};


// This class should inspect Parkedcar and ParkingMeter objects 
// if necessary, issue a ticket 
// Also holds information on the PoliceOfficer 
class PoliceOfficer {
private:
	string m_name;
	int m_badgeId;

public:
	PoliceOfficer(string name, int badgeId) {
		m_name = name;
		m_badgeId = badgeId;
	}

	// Default constructor 
	PoliceOfficer() {
		PoliceOfficer("", 0);
	}


};
