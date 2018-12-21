#include <iostream>
#include <memory>
using namespace std;

class Basic {
 public:
  int x;
  Basic (int x) : x(x) { cout << "Basic ctor running (x = " << x << ")" << endl; }
  ~Basic() { cout << "Basic dtor running" << endl; }
};

int main () {
  // auto for brevity; type of bp is std::unique_ptr<Basic>
  auto bp = make_unique<Basic>(5);  // 5 is ctor argument, passed to Basic

  cout << "Access x field through smart ptr:  " << bp->x << endl;
}
