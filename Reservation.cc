#include "Reservation.h"



Reservation::Reservation(string customerName, Date& checkIn, int duration){
	this->customerName = customerName;
	this->checkIn = checkIn;
	this->duration = duration;
}
//
// //setters

void Reservation::setDuration(int d){
  if (d>= 0){
    duration = d;
  }
	else{
		duration = 1;
	}
}



bool Reservation::overlaps(Reservation& r){
	if (this->checkIn.lessThan(r.checkIn)){
		Date localDate(checkIn);
		localDate.addDays(duration);
		if (localDate.equals(r.checkIn) || localDate.lessThan(r.checkIn)){
			return false;
		}
		else{
			return true;
		}
	}
	else{
		Date localDate(r.checkIn);
		localDate.addDays(r.duration);
		if (localDate.equals(this->checkIn) || localDate.lessThan(this->checkIn)){
			return false;
		}
		else{
			return true;
		}
	}
}




bool Reservation::lessThan(Reservation& res){
	Date localDate(this->checkIn);
	localDate.addDays(duration);
	if (overlaps(res)){
		return false;
	}
	else{
		if (localDate.equals(this->checkIn) || localDate.lessThan(this->checkIn)){
			return true;
		}
		return false;
	}
}




bool Reservation::lessThan(Date &d){
	Date localDate(this->checkIn);
	for (int i=0; i< duration; i++){
		localDate.incDate();
	}
	if (localDate.equals(d) || localDate.lessThan(d)){
		return true;
	}
	else{
		return false;
	}
}




void Reservation::print(){

	//cout << getMonthName()<<" "<<day<<", "<<year;
	cout <<"Reservation for "<<customerName << " on " << this->checkIn.getMonth()<<" "<< this->checkIn.getDay() << ", " << this->checkIn.getYear() << " for " << getDuration() << " days ";
}




// //getters
int Reservation::getDuration(){ return duration; }
