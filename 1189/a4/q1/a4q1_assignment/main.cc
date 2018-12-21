#include <iostream>
#include <sstream>
#include <string>
#include "Expr.h"
#include "Binary.h"
#include "Unary.h"
#include "Variable.h"
#include "Integer.h"
#include <vector>
#include <stdexcept>


using namespace std;

// You will need to write your own test harness

// Read and construct expression object. Returns a pointer to a heap-allocated
// object (caller must delete it).
istream &operator>>(istream &in, Expr *&e) {
  string s;
  vector <Expr *> v ;
  while (in >> s) {
    istringstream ss(s);
    int n;
    if (ss >> n) {
	Integer * num = new Integer{n};
	v.push_back(num);
    }
    else if (s == "NEG" || s == "ABS") {
	Expr * part = v.back();
	v.pop_back();
	Unary * una = new Unary{s, part};
 	v.push_back(una);
    }
    else if (s == "+" || s == "-" || s == "*" || s == "/") {
	Expr * r_part = v.back();
        v.pop_back();
   	Expr * l_part = v.back();
        v.pop_back();
	Binary * bin = new Binary{s, l_part, r_part};
   	v.push_back(bin);
    }
    else if (s == "done") {
	e = v.back(); 
	v.pop_back(); 
	e->prettyprint();
	cout << endl;
       	break;
    }
    else {
 	Variable * var = new Variable{s, false, 0};
	v.push_back (var);
    }
  }
  return in;
}

int main () {
  string s;
  Expr *e;
  cin >> e;

  // Command interpreter
  while (cin >> s) {
    if (s == "eval") {
	try {
	   int k = e->evaluate();
	   cout << k << endl;
 	} catch (const std::invalid_argument& a)  {
 	} catch (const char* msg) {
	   cerr << msg << endl;
	}	
    }
    else if (s == "set") {
	string a;
	int b;
	cin >> a >> b;
	e->set(a, b);
    }
    else if (s == "unset") {
	string a;
	cin >> a;
	e->unset(a);
    }
    else if (s == "print") {
	e->prettyprint();
 	cout << endl;
    }
  }
  delete e;
}
