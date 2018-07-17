#include "stdafx.h"
#include <iostream>
#include "PassengerDatabase.h"
#include <stdexcept>

using namespace std;

namespace AirlineReservationSystem {
	Passenger& PassengerDatabase::addPassenger(const string& passFirstName,
		const string& passLastName) {
		Passenger thePassenger(passFirstName, passLastName);
		thePassenger.setPassengerID(mNextPassengerNumber++);
		mPassengers.push_back(thePassenger);
		return mPassengers[mPassengers.size() - 1];
	}

	Passenger& PassengerDatabase::addPassenger(const string& passFirstName,
		const string& passLastName, const string& passPhoneNumber, const string& passEmail) {
		Passenger thePassenger(passFirstName, passLastName, passPhoneNumber, passEmail);
		thePassenger.setPassengerID(mNextPassengerNumber++);
		mPassengers.push_back(thePassenger);
		return mPassengers[mPassengers.size() - 1];
	}

	Passenger& PassengerDatabase::getPassenger(int passengerNumber) {
		for (auto& passenger : mPassengers) {
			if (passenger.getPassengerID() == passengerNumber) {
				return passenger;
			}
		}
		throw logic_error("No passenger found.");
	}

	Passenger& PassengerDatabase::getPassenger(const string& passFirstName,
		const string& passLastName) {
		for (auto& passenger : mPassengers) {
			if (passenger.getFirstName() == passFirstName &&
				passenger.getLastName() == passLastName) {
				return passenger;
			}
		}
		throw logic_error("No Passenger found.");
	}

	void PassengerDatabase::displayAll() const {
		for (const auto& passenger : mPassengers) {
			passenger.display();
		}
	}

	void PassengerDatabase::displayCurrent() const {
		for (const auto& passenger : mPassengers) {
			if (passenger.isAdded()) {
				passenger.display();
			}
		}
	}

	void PassengerDatabase::displayFormer() const {
		for (const auto& passenger : mPassengers) {
			if (!passenger.isAdded()) {
				passenger.display();
			}
		}
	}
}
