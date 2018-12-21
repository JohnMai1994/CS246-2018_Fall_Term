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
  Book(const Book &b);

  Book& operator=(const Book &rhs);

  std::string getTitle() const;
  std::string getAuthor() const;
  virtual bool isHeavy() const;

  virtual bool favourite() const;
};

#endif
