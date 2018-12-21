#include <iostream>
#include <string>
#include <utility>
#include "book.h"
#include "text.h"
#include "comic.h"

using namespace std;


int main() {
  Text t1("Programming for Beginners", "Niklaus Wirth", 200, "BASIC");

  Text t2 = std::move(t1);  // Force call to move ctor.  This will STEAL
                            // t1's data.

  cout << "Book 1: " << t1.getTitle() << ", " << t1.getAuthor() << ", "
       << t1.getTopic() << endl;

  cout << "Book 2: " << t2.getTitle() << ", " << t2.getAuthor() << ", "
       << t2.getTopic() << endl;
}
