#include "Expr.h"
#include "Unary.h"
#include <string>
#include <iostream>

using namespace std;

Unary::Unary(string method, Expr * part): method{method}, part{part} {}

void Unary::prettyprint() const {
   if (method == "ABS") {
      cout << "|";
      part->prettyprint();
      cout << "|";
   } else if (method == "NEG") {
      cout << "-";
      part->prettyprint();
   } else {
      cout << "Unary prettyprint wrong" << endl;
   }
}


int Unary::evaluate() const {
     if (method == "ABS") {
        if (part->evaluate() >= 0) {
	   return part->evaluate();
        }
	else{
	   return -part->evaluate();
 	}
     } else if (method == "NEG") {
	return -part->evaluate();
     } else {
	cout << "Unary Evaluation Wrong" << endl;
	return 0;
     }
}

void Unary::set(string a, int value) {
   part->set(a, value);
}

void Unary::unset(std::string a){
   part->unset(a);
}

Unary::~Unary(){
   delete part;
}
