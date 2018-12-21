#include <iostream>
using namespace std;

class E1 {
 public:
  virtual void f() {
     cout << "E1" << endl;
  }
};

class E2: public E1 {
 public:
  void f() override {
    cout << "E2" << endl;
  }
};

int main() {
  try {
    try {
      throw E2{};
    }
    catch (E1
  #ifdef BYREF1
    &
  #endif
    e) {
      e.f();
  #ifdef RETHROW
      throw
  #else
      throw e;
  #endif
    }
  }
  catch (E1
  #ifdef BYREF2
    &
  #endif
  e) {
    e.f();
  }
}
