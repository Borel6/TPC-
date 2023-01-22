#include "date.h"
#include "assert.h"

int Date::month() const {
	return _month;
}
int Date::day() const{
	return _day;
}
int Date::year() const{
	return _year;
}

bool Date::isDate(int month, int day, int year){
	if((day < 1) || (day >31)) return false;
	if((month<1) || (month>12))return false;
	if ((month ==2) && (year%4 == 0) && (day >29)) return false ;
	if ((month ==2) && (year%4 != 0) && (day >28)) return false;
	if (((month==4) || (month==6) || (month==9) || (month==11)) && (day>30)) return false;
	return true ;
}

Date::Date(int month, int day, int year):
_month(month), _day(day), _year(year){
bool status = isDate (month,day,year) ;
assert (status && "Date is note valid") ;
}

void Date::updateMonth(int month){
	_month=month;
}
void Date::updateDay(int day){
	_day = day ;
}
void Date::updateYear(int year){
	_year = year;
}
void Date::tostring(){
	std::cout <<_day << "/" << _month<< "/"<<_year << std::endl ;
}






std::ostream& operator << (std::ostream& os, const Date& d){
	std::string month [12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	std::string to_display = month[d.month() - 1] + "/" + std::to_string(d.day())+ "/" + std::to_string(d.year()) ;
	os << to_display;
	return os;
}

bool Date::operator == (const Date& d) const{
	if (_month==d.month() && _year==d.year() && _day==d.day()){
		return true;
	}
	return false;
}
bool Date::operator != (const Date& d) const{
	return !(*this == d);
}