#include "a.h"
#include "b.h"
#include <iostream>
#include <string>
using namespace std;
//#define DEBUG

#ifdef DEBUG
string GLOBAL = "Debugging ON!";
#else
string GLOBAL = "Debugging OFF!";
#endif

int main(){
    cout << GLOBAL << endl;
    return 0;    
}
