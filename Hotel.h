
#ifndef HOTEL_H
#define HOTEL_H

#define MAX_ROOMS 256

#include <iostream>
#include <string>
#include <iomanip>
#include "Room.h"

using namespace std;

class Hotel {

	public:
		//constructors
		Hotel();

		//getters
		bool getRoom(int, Room**);


		//other
    bool addRoom(int, string, int, bool);
    bool deleteRoom(int);
    bool addReservation(string, string, int, bool, Date&, int);
    void print();
    void printReservations();


	private:
		//functions

		//variables
    Room* rooms[MAX_ROOMS];
    int numOfReservations;

};
#endif
