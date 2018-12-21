#include <iostream>
using namespace std;

struct Student {
  int assigns, mt, final;
  float grade() {
    return assigns * 0.4 + mt * 0.2 + final * 0.4;
  }
  Student(int assigns, int mt, int final): assigns{assigns}, mt{mt}, final{final} {
     cout << "Default ctor is being called." << endl;
  }

  Student(const Student &other): assigns{other.assigns},
                                 mt{other.mt},
                                 final{other.final} {
     cout << "Copy ctor is being called." << endl;
  }
};

int main () {
  Student s {60, 70, 80};
  Student s2 = s;
  cout << s.grade() << endl;
  cout << s2.grade() << endl;
}
