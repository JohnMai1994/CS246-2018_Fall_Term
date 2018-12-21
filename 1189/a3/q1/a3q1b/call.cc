#include "call.h"
#include <iostream>
#include <string>
using namespace std;


Call::Call( Date date, int startTime, int duration ): date{date}, startTime{startTime}, duration{duration} {}

std::istream & operator>>( std::istream & in, Call & call ){    
    in >> call.date ;
    in >> call.startTime;
    in >> call.duration; 
    return in;
}

std::ostream & operator<< (std::ostream &out, Call call){
    out << call.date << " " ;
    if (call.startTime < 10) {
       out << "000" << call.startTime;
    } else if (call.startTime < 100) {
       out << "00" << call.startTime;
    } else if (call.startTime < 1000) {
       out << "0" << call.startTime;
    } else {
       out << call.startTime;
    }
    out << " "<< call.duration << endl;
    return out;
}




