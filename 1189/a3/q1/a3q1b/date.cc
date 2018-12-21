#include "date.h"
#include <iomanip>
using namespace std;


/* Your constructor implementation HERE */

// https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Corresponding_days
Date::DayOfWeek Date::getDay() const {
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	int year_ = year - (month < 3);
	return static_cast<Date::DayOfWeek>( (year_ + year_/4 - year_/100 + year_/400 + t[month-1] + day) % 7 );
}

/* Your member and non-member functions HERE */

Date::Date(int y, int m, int d): year{y}, month{m}, day{d} {};

bool Date::operator==( Date other ) const{
      if ((other.year == year)&&(other.month == month)&&(other.day == day)) return true;
      return false;
}    


bool Date::operator<( Date other ) const{
      if (year < other.year)  {
         return true;
      } 
      if ((year == other.year)&&(month < other.month)) {
         return true;
      } 
      if ((year == other.year)&&(month == other.month)&&(day < other.day)) {
         return true;
      } 
      return false;

}


std::istream & operator>>( std::istream & in, Date & date ){
      char trash;
      in >> date.year;
      in >> trash;
      in >> date.month;
      in >> trash;
      in >> date.day;
      return in;
}


std::ostream & operator<<( std::ostream & out, Date date ){
     out << date.year << '/';
     if (date.month < 10) {
         out << "0" << date.month ;
     } else {
         out << date.month;
     }             
     out << '/' ;
     if (date.day < 10) {
         out << "0" << date.day;
     } else {
         out << date.day;
     } 
     return out;
     
}



std::ostream & operator<<( std::ostream & out, Date::DayOfWeek day ){
     if (day == Date::DayOfWeek::Sunday) {
       out << "Sunday" << endl;
     } else if (day == Date::DayOfWeek::Monday) {
       out << "Monday" << endl;
     } else if (day == Date::DayOfWeek::Tuesday) {
       out << "Tuesday" << endl;
     } else if (day == Date::DayOfWeek::Wednesday) {
       out << "Wednesday" << endl;
     } else if (day == Date::DayOfWeek::Thursday) {
       out << "Thursday" << endl;
     } else if (day == Date::DayOfWeek::Friday) {
       out << "Friday" << endl;
     } else {
       out << "Saturday" << endl;
     } 
     return out;
}

