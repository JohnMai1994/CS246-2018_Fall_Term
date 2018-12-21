#ifndef _COMIC_H_
#define _COMIC_H_
#include <string>
#include "abstractbook.h"

class Comic: public AbstractBook {
  std::string hero;
 public:
  Comic(const std::string &title, const std::string &author, int length, const std::string &hero);
  Comic(const Comic &c);

  Comic &operator=(const Comic &rhs);

  bool isHeavy() const override;
  std::string getHero() const;

  bool favourite() const override;
};

#endif
