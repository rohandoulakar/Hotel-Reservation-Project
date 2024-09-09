
#include "Date.h"

Date::Date(){
	setDate(1901,1,1);
}

Date::Date(int y, int m, int d){
	setDate(y,m,d);
}

Date::Date(const Date& d){
	setDate(d.year,d.month,d.day);
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d){
	setYear(y);
	setMonth(m);
	setDay(d);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day);
}


//getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
string Date::getMonthName(){
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	return months[month-1];
}

//other
void Date::incDate(){
	day += 1;
	// is it now the 32nd of January (for example)? If so make it February 1st
	if (day > getMaxDay()){
		day = 1;
		month += 1;
	}

	// is it now the 13th month? (Smarch 1st) If so make it January of next year
	// https://simpsonswiki.com/wiki/Smarch
	if (month > 12){
		month = 1;
		year += 1;
	}
}



bool Date::lessThan(Date& d){
	if (year < d.year) return true;
	if (year > d.year) return false;
	//years are equal
	if (month < d.month) return true;
	if (month > d.month) return false;
	//months are equal
	return (day < d.day);
}

bool Date::equals(Date& d){
	//If the day, month, and year are all equal then it will return true
	//If any of the above are not equal then it will return false
	if (year == d.year){
		if (month == d.month){
			if (day == d.day){
				return true;
			}
		}
	}
	return false;
}

void Date::addDays(int days){
	for (int i=0; i<days; ++i){
		incDate();
	}
}




void Date::print(){
	cout << getMonthName()<<" "<<day<<", "<<year;
}


int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}
