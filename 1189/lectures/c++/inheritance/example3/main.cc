#include <iostream>
#include <string>
#include "book.h"
#include "text.h"
#include "comic.h"

using namespace std;

int main() {
  Comic c("Robin Rescues Batman Twice", "Robin", 40, "Robin");

  Book b = c;

  cout << "The comic book: " << c.getTitle() << "; " << c.getAuthor()
       << "; " << (c.isHeavy() ? "heavy" : "not heavy") << endl;

  cout << "The book: " << b.getTitle() << "; " << b.getAuthor()
       << "; " << (b.isHeavy() ? "heavy" : "not heavy") << endl;

  cout << endl << "Through pointers: " << endl;

  Comic *pc = new Comic("Spiderman Unabridged", "Peter Parker", 100, "Spiderman");
  Book *pb = pc;

  cout << "The comic book ptr: " << pc->getTitle() << "; " << pc->getAuthor()
       << "; " << (pc->isHeavy() ? "heavy" : "not heavy") << endl;

  cout << "The book ptr: " << pb->getTitle() << "; " << pb->getAuthor()
       << "; " << (pb->isHeavy() ? "heavy" : "not heavy") << endl;

}
