#include <iostream>
using namespace std;

struct Grade {
  int theGrade;
};

ostream &operator<<(ostream &out, const Grade &g) {
  out << g.theGrade << "%";
  return out;
}

istream &operator>>(istream &in, Grade &g) {
  in >> g.theGrade;
  if (g.theGrade < 0) g.theGrade = 0;
  if (g.theGrade > 100) g.theGrade = 100;
  return in;
}

int main () {
  Grade g;   // not must g, it just an example
  while (cin >> g) cout << g << endl;
}
