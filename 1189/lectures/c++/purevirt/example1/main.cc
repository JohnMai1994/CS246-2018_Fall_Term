#include <iostream>
#include "student.h"
#include "regular.h"
#include "coop.h"

using namespace std;

int main () {
  Regular r(5);
  Coop c(5);

  cout << "The regular student " << r.getFees() << endl;
  cout << "The co-op student " << c.getFees() << endl;

  Student *s = new Regular(4);
  Student *t = new Coop(4);

  cout << endl << "Through superclass pointers:" << endl << endl;

  cout << "The regular student " << s->getFees() << endl;
  cout << "The co-op student " << t->getFees() << endl;
}
