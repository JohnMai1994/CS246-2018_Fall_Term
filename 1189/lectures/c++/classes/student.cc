#include <iostream>
using namespace std;

struct Student {
  int assigns, mt, final;
  float grade();
};

float Student::grade() {
  return assigns * 0.4 + mt * 0.2 + final * 0.4;
}

int main () {
  Student s {60, 70, 80};
  cout << s.grade() << endl;
}
