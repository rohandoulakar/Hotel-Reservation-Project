
#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class Reservation {

	public:
		//constructors
		Reservation();
		Reservation(string customerName, Date& checkIn, int duration);
		Reservation(const Reservation&);

		//setters

		void setDuration(int);


		void setReservation(string, Date&, int);
		void setReservation(Reservation&);


		bool overlaps(Reservation& r);
		bool lessThan(Reservation& r);
		bool lessThan(Date& d);
		void print();

		//getters
		int getDuration();


		//other


	private:
		//functions

		//variables
		string customerName;
		Date checkIn;
		int duration;

};
#endif
