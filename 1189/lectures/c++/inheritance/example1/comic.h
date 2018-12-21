#ifndef _COMIC_H_
#define _COMIC_H_
#include <string>
#include "book.h"

class Comic: public Book {
  std::string hero;
 public:
  Comic(const std::string &title, const std::string &author, int length, const std::string &hero);
  std::string getHero() const;
};

#endif
