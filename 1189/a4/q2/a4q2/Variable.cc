#include "Expr.h"
#include "Variable.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

Variable::Variable(string name, bool flag = false, int num = 0): name{name}, flag{flag}, num{num} {}

void Variable::prettyprint() const {
	if (flag) {
	   cout << num;
  	} else {
	   cout << name;
	}
}
int Variable::evaluate() const {
     if (flag) {
	return num;
     } else {
	cerr << name <<" has no value" << endl;
	throw std::invalid_argument("have no value");
     }
}

void Variable::set(string a, int value){
    if (name == a){
    flag = true;
    num = value;
    }
}

void Variable::unset(std::string a){
    if (name == a){
      flag = false;
    }
}

Variable::~Variable(){ }

/*
Variable &Variable::operator= (const Variable &other){
    name = other.name;
    flag = other.flag;
    num = other.num;
    return *this;
}
*/
Variable::Variable (const Variable &other): name{other.name}, flag{other.flag}, num{other.num} {}

Variable * Variable::copy() const {
    //cout << "It work Variable" << endl;
    return new Variable {*this};
}

