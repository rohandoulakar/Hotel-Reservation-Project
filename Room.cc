#include "Room.h"



Room::Room(int roomNumber, string bedType, int capacity, bool hasFridge){
	this->roomNumber = roomNumber;
	this->bedType = bedType;
  this->capacity = capacity;
  this->hasFridge = hasFridge;
	numOfReservations = 0;
}
//
// //setters


bool Room::isMatch(string bt, int cap, bool f){
	if (bedType == bt){
		if (capacity >= cap){
			if (f == true){
				if (hasFridge == true){
					return true;
				}
			}
			else if(f == false){
				return true;
			}
		}
	}
	return false;
}


bool Room::lessThan(Room &r){
	if (roomNumber < r.roomNumber){
		return true;
	}
	return false;
}

bool Room::addReservation(string customerName, Date &d, int duration){
	Reservation* r1 = new Reservation(customerName, d, duration);

	Reservation localReservation(customerName, d, duration);

	if (numOfReservations >= MAX_RES){
		return false;
	}

	for (int i = 0; i<numOfReservations; ++i){
		if (reservation[i]->overlaps(*r1)){
			return false;
		}
	}


	for (int i = numOfReservations; i > 0; --i){
		if (!(r1->lessThan(*reservation[i-1]))){
			reservation[i] = reservation[i-1];
		}
		else{
			reservation[i] = r1;
			++numOfReservations;
			return true;
		}
	}
	//If r1 is less than all of them which means r1 should go to location 0
	reservation[0] = r1;
	++numOfReservations;
	return true;

}

void Room::print(){

	//cout << getMonthName()<<" "<<day<<", "<<year;
	cout <<"Room Number: "<< roomNumber << endl;
	cout <<"Bed Type: "<< bedType << endl;
	cout <<"Capacity: "<< capacity << endl;
	if (hasFridge == true){
		cout << "There is a fridge" << endl;
	}
	else{
		cout << "No fridge is there" << endl;
	}
}

void Room::printReservations(){
	print();
	for (int i=0; i < numOfReservations; i++){
		reservation[i]->print();
	}
}
























// //getters
int Room::getRoomNumber(){ return roomNumber; }
