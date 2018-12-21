#ifndef __TEXT_H__
#define __TEXT_H__
#include <string>
#include "book.h"

class Text: public Book {
  std::string topic;
 public:
  Text(const std::string &title, const std::string &author, int length, const std::string &topic);
  Text(const Text &other) = default;

  bool isHeavy() const override;
  std::string getTopic() const;

  bool favourite() const override;

  Text(Text &&other);
};

#endif
