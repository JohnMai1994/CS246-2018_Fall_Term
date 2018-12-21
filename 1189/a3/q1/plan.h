#ifndef _PLAN_H
#define _PLAN_H
#include "call.h"

class Plan {
    
    /* Your private member variables and functions */

    friend std::ostream & operator<<( std::ostream & out, const Plan & plan );

public:
    Plan();
    ~Plan();

    // Adds the call to the month's current list of calls.
    void add( Call call ); 

    // Outputs the month's current list of calls and the amount owed.
    // Clears out the calls for the month.
    void calculateBill(); 
};

// Outputs the current month's calls, ordered by date and then by start time 
// within date. 
std::ostream & operator<<( std::ostream & out, const Plan & plan );

#endif
