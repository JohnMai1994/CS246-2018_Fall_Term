#include <iostream>

int main() {
  int *elements = new int[9];
  for (int i = 0; i < 10; i++)
      elements[i] = i*i;

  for (int i = 0; i < 10; i++)
      std::cout << i << "*" << i << "=" <<  elements[i] << std::endl;

  delete [] elements;
  return 0;
}
