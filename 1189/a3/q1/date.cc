#include "date.h"

/* Your constructor implementation HERE */

// https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Corresponding_days
Date::DayOfWeek Date::getDay() const {
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	int year_ = year - (month < 3);
	return static_cast<Date::DayOfWeek>( (year_ + year_/4 - year_/100 + year_/400 + t[month-1] + day) % 7 );
}

/* Your member and non-member functions HERE */
