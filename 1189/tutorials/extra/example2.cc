#include <iostream>
#include <string>
#include "example2_hidden.h"

struct some_data {
  std::string str;
  int i;
  int j;
};

void print_data(const some_data *dat) {
  std::cout << "The contents of dat are: " << std::endl
    << "  str = " << dat->str << " (expected: Hello World) " << std::endl
    << "  i   = " << dat->i << " (expected: 5) " << std::endl
    << "  j   = " << dat->j << " (expected: 3) " << std::endl;
}

int main(int argc, char **argv) {
  some_data dat;
  dat.str = "Hello World";
  dat.i = 5;
  dat.j = 3;
  int *ip = &dat.i;
  //Lots of lines which make us forget that ip points to dat.i
  complicated(ip); //We don't know what this does
  print_data(&dat);
  return 0;
}
