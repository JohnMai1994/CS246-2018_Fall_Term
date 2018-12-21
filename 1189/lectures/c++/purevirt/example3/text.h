#ifndef _TEXT_H_
#define _TEXT_H_
#include <string>
#include "abstractbook.h"

class Text: public AbstractBook {
  std::string topic;
 public:
  Text(const std::string &title, const std::string &author, int length, const std::string &topic);

  bool isHeavy() const override;
  std::string getTopic() const;

  bool favourite() const override;

  Text(const Text &other);

  Text &operator=(const Text &rhs);
};

#endif
