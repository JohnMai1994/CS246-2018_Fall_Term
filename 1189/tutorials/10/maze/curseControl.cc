#include "curseControl.h"
#include <string>

CurseKeyboard::CurseKeyboard() {
  mapping['w'] = Action::UP;
  mapping['d'] = Action::RIGHT;
  mapping['s'] = Action::DOWN;
  mapping['a'] = Action::LEFT;
  mapping[KEY_UP] = Action::UP;
  mapping[KEY_RIGHT] = Action::RIGHT;
  mapping[KEY_DOWN] = Action::DOWN;
  mapping[KEY_LEFT] = Action::LEFT;
}

Action CurseKeyboard::action(){
  int n;
  while ( (n = getch()) == ERR ) continue;

  if ( mapping.find(n) != mapping.end() ){
    return mapping[n];
  }
  return Action::INVALID;
}
