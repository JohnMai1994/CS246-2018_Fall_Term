#include "plan.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Plan::Plan(): size(0), cap(1), total(nullptr) {}

Plan::~Plan(){
    for (int i = 0; i < size; ++i) delete total[i];
    delete [] total;
    }

void Plan::add( Call call ) { 
   if (size >= cap) {
      Call **new_total = new Call *[2*cap];   // create a new pointer to pointer 
      for(int i = 0; i < size; ++i) {         // move form old pointer to new pointer
         new_total[i] = total[i];
      }

      delete [] total;
      total = new_total;
      cap *= 2;
      
   }
   if (size == 0) {                            // when size is zero
     total = new Call *[cap];
     total[size] = new Call{call};
   } else {
     total[size] = new Call{call};     
   }

   size+=1;
   int a, b;
   for (a = 0; a < size; a++) {                 // sort the array
      for (b = a + 1; b < size; b++) {
         if (((total[b]->date == total[a]->date)&&(total[b]->startTime < total[a]->startTime))|| (total[b]->date < total[a]->date)) {
             Call *temp = total[b];
             total[b] = total[a];
             total[a] = temp;
           
         }
      }
   }
}


   

void Plan::calculateBill(){
   float bill = 25;
   int time = 150;
   int used_time = 0;
   for (int i = 0; i < size; ++i) {
       Call *call = total[i];
       if (((call->date).getDay() != Date::DayOfWeek::Saturday)&&((call->date).getDay() != Date::DayOfWeek::Sunday)) {
           // On weekday
           int hour, minute, endTime, call_time;
           hour = call->duration/60;                                             
           minute = call->duration%60;
           endTime = call->startTime + hour*100 + minute;               // Translate the end time with 24 hour sytle
           if (endTime%100 >= 60) endTime += 40;
           if (endTime/100 >= 24) endTime = 2400;
           if ((call->startTime >= 1800)||(endTime <= 700)) {           // 4 different style to calculate
              used_time += 0;
           } else if ((call->startTime >= 700)&&(endTime <= 1800)) {
              used_time += call->duration;
           } else if (call->startTime < 700){
              if (endTime >= 1800) endTime = 1800;
              call_time = endTime - 700;
              hour = call_time / 100;
              minute = call_time % 100;
              used_time += hour * 60 + minute;
           } else {
              
              call_time = 1760 - call->startTime;
              hour = call_time / 100;
              minute = call_time % 100;
              used_time += hour * 60 + minute;
           }
        
       }
       cout << *(total[i]);
   }
   if (used_time > time) {
      bill += (used_time - time) * 0.5;
   } else {
      bill = 25;
   }
   
   size = 0;
   cap = 1;
   total = nullptr;

   cout << endl;
   cout << "Day time minutes: " << used_time << endl;
   cout << fixed << setprecision(2) << "Total cost $" << bill << endl;
} 


std::ostream & operator<<( std::ostream & out, const Plan & plan ){
    for (int i = 0; i < plan.size; ++i) {
       out << *(plan.total[i]);
  }
  return out;
}
