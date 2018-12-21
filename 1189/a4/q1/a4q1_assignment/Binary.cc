#include "Expr.h"
#include "Binary.h"
#include <string>
#include <iostream>

using namespace std;

Binary::Binary(std::string method, Expr * l_part, Expr * r_part): method{method}, l_part{l_part}, r_part{r_part} {}

void Binary::prettyprint() const {
   if (method == "+" ) {
      cout << "(";
      l_part->prettyprint();
      cout << " + ";
      r_part->prettyprint();
      cout << ")";
   }else if (method == "-") {
      cout << "(";
      l_part->prettyprint();
      cout << " - ";
      r_part->prettyprint();
      cout << ")";
   }else if (method == "*") {
      cout << "(";
      l_part->prettyprint();
      cout << " * ";
      r_part->prettyprint();
      cout << ")";
   }else if (method == "/"){
      cout << "(";
      l_part->prettyprint();
      cout << " / ";
      r_part->prettyprint();
      cout << ")";
   }else {
      cout << "Binary Prettyprint wrong" << endl;
   }
}



int Binary::evaluate() const {
   if (method == "+") {
	return (l_part->evaluate() + r_part->evaluate());
   } else if (method == "-") {
	return (l_part->evaluate() - r_part->evaluate());
   } else if (method == "*") {
	return (l_part->evaluate() * r_part->evaluate());
   } else if (method == "/") {
	if (r_part->evaluate() == 0) {
	   throw "Floating point exception (core dumped) ";
        }
	return (l_part->evaluate() / r_part->evaluate());	
   } else {
	cout << "Binary evaluate wrong" << endl;
        return 0;
   }
}

void Binary::set(string a, int value) {
   l_part->set(a, value);
   r_part->set(a, value);
}

void Binary::unset(std::string a) {
   l_part->unset(a);
   r_part->unset(a);
}

Binary::~Binary(){
   delete l_part;
   delete r_part;
}
