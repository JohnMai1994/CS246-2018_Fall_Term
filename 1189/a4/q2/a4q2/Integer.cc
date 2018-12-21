#include "Expr.h"
#include "Integer.h"
#include <string>
#include <iostream>

using namespace std;

Integer::Integer(int num): num{num} {}

void Integer::prettyprint() const {
         cout << num;
      }
int Integer::evaluate() const {
      return num;
}

void Integer::set(string a, int value) {
   return;
}

void Integer::unset(std::string a){
   return;
}

Integer::~Integer() { }
/*
Integer &Integer::operator= (const Integer &other){
     num = other.num;
     return *this;
}
*/


Integer * Integer::copy() const {
     //cout << "It work Integer" << endl;
     return new Integer {*this};
}
