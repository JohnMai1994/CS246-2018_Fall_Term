#include "example2_hidden.h"

void complicated(int *i) {
  //Lots of lines
  *i = 7; //A bug
  //Lots more lines
}
