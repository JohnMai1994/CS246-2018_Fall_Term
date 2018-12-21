#ifndef ___MODEL____H_
#define ___MODEL____H_

#include <memory>
#include <vector>
#include "controller.h"
#include "view.h"

enum Action;

class Model{
  std::vector<std::unique_ptr<View>> views;
  std::unique_ptr<Controller> control;
 protected:
  void addView(std::unique_ptr<View> v);
  void addController(std::unique_ptr<Controller> v);
  bool hasController();
 public:
  Model(int, int);
  virtual ~Model() = default;
  void updateViews(int, int, State);
  void updateViews(const std::string& s);
  Action getAction();
  void displayViews();
};

#endif
