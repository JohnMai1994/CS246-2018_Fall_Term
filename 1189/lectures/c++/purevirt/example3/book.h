#ifndef _BOOK_H_
#define _BOOK_H_
#include "abstractbook.h"
#include <string>

class Book: public AbstractBook {
 public:
  Book(const std::string &title, const std::string &author, int length);
  Book(const Book &b);

  Book& operator=(const Book &rhs);

  ~Book();
};

#endif
