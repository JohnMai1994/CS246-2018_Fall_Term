#include <iostream>
using namespace std;

struct Student {
  int assigns, mt, final;
  float grade() {
    return assigns * 0.4 + mt * 0.2 + final * 0.4;
  }
  Student(int assigns, int mt, int final) {
    this->assigns = assigns;
    this->mt = mt;
    this->final = final;
  }
};

int main () {
  Student s{60, 70, 80};
  Student s2 = Student{70, 80, 90};
  cout << s.grade() << endl;
  cout << s2.grade() << endl;
}
