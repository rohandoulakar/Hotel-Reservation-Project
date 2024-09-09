#include "Hotel.h"

Hotel::Hotel(){
  numOfReservations = 0;
}

bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr){
  Room* localRoom = new Room(roomNumber, bedType, capacity, fr);

  if (numOfReservations >= MAX_RES){
    return false;
  }

  for (int i=0; i< numOfReservations; ++i){
    if (roomNumber == rooms[i]->getRoomNumber()){
      return false;
    }
  }

  int iterate = numOfReservations;

  while (iterate > 0){
    if (rooms[iterate - 1]->lessThan(*localRoom)){
      break;
    }
    rooms[iterate] = rooms[iterate-1];
    --iterate;

  }
  rooms[iterate] = localRoom;
  ++numOfReservations;
  return true;

}

bool Hotel::deleteRoom(int roomNumber){
  bool roomFound;
  int iterate = 0;

  for (int i=0; i < numOfReservations; ++i){
    if (rooms[i]->getRoomNumber() == roomNumber){
      roomFound = true;
      break;
    }
    ++iterate;
  }

  if (iterate == numOfReservations){
    return false;
  }

  if (roomFound){
    delete rooms[iterate];
    --numOfReservations;
    while(iterate < numOfReservations){
      rooms[iterate] = rooms[iterate+1];
      ++iterate;
    }
    return true;
  }
  return false;


}


bool Hotel::getRoom(int roomNumber, Room** room){
  for (int i=0; i < numOfReservations; i++){
    if (roomNumber == rooms[i]->getRoomNumber()){
      *room = rooms[i];
      return true;
    }
  }
  return false;
}

bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration){
  for (int i=0; i < numOfReservations; ++i){
    if (rooms[i]->isMatch(bedType, capacity, fr)){
      if (rooms[i]->addReservation(customer, date, duration)){
        return true;
      }
      return false;
    }
  }
  return false;
}


void Hotel::print(){
  for (int i=0; i<numOfReservations; ++i){
    rooms[i]->print();
  }
}

void Hotel::printReservations(){
  for (int i=0; i < numOfReservations; ++i){
    rooms[i]->printReservations();
  }
}
