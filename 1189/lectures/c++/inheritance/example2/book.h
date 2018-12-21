#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>

class Book {
  std::string title, author;
  int length;
 protected:
  int getLength() const;
 public:
  Book(const std::string &title, const std::string &author, int length);
  std::string getTitle() const;
  std::string getAuthor() const;
  bool isHeavy() const;
};

#endif
