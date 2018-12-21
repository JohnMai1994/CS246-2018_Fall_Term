#include "model.h"
#include "standard.h"
#include "keyboard.h"
#include "curseControl.h"
#include "curseView.h"
#include "writtenView.h"

Model::Model(int x, int y) {
  //views.emplace_back(std::make_unique<Standard>(x, y, *this));
  //views.emplace_back(std::make_unique<Written>(x, y, *this));
  //control = std::make_unique<Keyboard>();
  //control{std::make_unique<CurseKeyboard>()}  
}

void Model::updateViews(int row, int col, State s){
  for( auto& view: views ){
    view->update(row, col, s);
  }
}

void Model::updateViews(const std::string& s){
  for( auto& view: views ){
    view->update(s);
  }
}

void Model::displayViews(){
  for( auto& view: views ){
    view->updateView();
  }
}

void Model::addView(std::unique_ptr<View> v){
  views.emplace_back(std::move(v));
}
void Model::addController(std::unique_ptr<Controller> c){
  control = std::move(c);
}
bool Model::hasController(){
  return control != nullptr;
}

Action Model::getAction(){
  return control->getAction();
}
