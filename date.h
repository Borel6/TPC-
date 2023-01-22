#include <iostream>
#ifndef DATE_H
#define DATE_H


	class Date {

		public :

		Date (int month=1, int day=1, int year=1990);
		int month() const;
		int day() const;
		int year() const;
		void updateMonth(int month);
		void updateDay(int day);
		void updateYear(int year);
		void tostring();
		bool operator == (const Date& d) const;
		bool operator != (const Date& d) const;

	private:
		int _month;
		int _day;
		int _year;
		bool isDate(int month, int day, int year);
	};

	std::ostream& operator << (std::ostream& os, const Date& d);


#endif