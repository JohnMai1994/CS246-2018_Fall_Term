#include <iostream>
#include <string>
#include "book.h"
#include "text.h"
#include "comic.h"

using namespace std;

// Polymorphism in action.
void printMyFavourites(Book *myBooks[], int numBooks) {
  for (int i=0; i < numBooks; ++i) {
    if (myBooks[i]->favourite()) cout << myBooks[i]->getTitle() << endl;
  }
}

int main() {
  Book* collection[] { 
   new Book{"War and Peace", "Tolstoy", 5000},
   new Book{"Peter Rabbit", "Potter", 50},
   new Text{"Programming for Beginners", "??", 200, "BASIC"},
   new Text{"Programming for Big Kids", "??", 200, "C++"},
   new Comic{"Aquaman Swims Again", "??", 20, "Aquaman"},
   new Comic{"Clark Kent Loses His Glasses", "??", 20, "Superman"}
  };

  printMyFavourites(collection, 6);
  for (int i=0; i < 6; ++i) delete collection[i];
}
