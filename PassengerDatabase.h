#pragma once
#include <vector>
#include "Passenger.h"

namespace AirlineReservationSystem {
	const int kFirstPassengerNumber = 1000;

	class PassengerDatabase
	{
	private:
		std::vector<Passenger> mPassengers;

	public:
		Passenger& addPassenger(const std::string& passFirstName, const std::string& passLastName);
		Passenger& addPassenger(const std::string& passFirstName, const std::string& passLastName, const std::string& passPhoneNum, const std::string& passEmail);
		Passenger& getPassenger(const std::string& passFirstName, const std::string& passLastName);

		void displayAllPassengers() const;

	};
}
