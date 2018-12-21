#include <iostream>
#include <stdexcept>
using namespace std;

void f () {
  cout << "Start f" << endl;
  throw (out_of_range("f"));
  cout << "Finish f" << endl;
}

void g() {
  cout << "Start g" << endl;    f ();    cout << "Finish g" << endl;
}

void h() {
  cout << "Start h" << endl;    g ();    cout << "Finish h" << endl;
}

int main () {
  cout << "Start main" << endl;
  try {
    h();
  }
  catch (out_of_range) { cerr << "Range error" << endl; }
  cout << "Finish main" << endl;
}
