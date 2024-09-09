
#ifndef ROOM_H
#define ROOM_H

#define MAX_RES 64

#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"


using namespace std;

class Room {

	public:
		//constructors
		Room();
		Room(int roomNumber, string bedType, int capacity, bool hasFridge);

		void print();
		void printReservations();

		//getters
		int getRoomNumber();


		//other
		bool isMatch(string, int, bool);
		bool lessThan(Room& r);
		bool addReservation(string, Date& d, int);


	private:
		//functions

		//variables
		int roomNumber;
    string bedType;
    int capacity;
    bool hasFridge;
    Reservation* reservation[MAX_RES];
    int numOfReservations;

};
#endif
