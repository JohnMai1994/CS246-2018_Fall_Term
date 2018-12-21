#ifndef __CATALOGUE_H__
#define __CATALOGUE_H__
#include <map>
#include <string>

#include "BookVisitor.h"
#include "book.h"
#include "comic.h"
#include "text.h"

struct CatalogueVisitor: public BookVisitor {
  std::map<std::string, int> theCatalogue;

  virtual void visit(Book &b) override;
  virtual void visit(Comic &cb) override;
  virtual void visit(Text &csb) override;
};

#endif
