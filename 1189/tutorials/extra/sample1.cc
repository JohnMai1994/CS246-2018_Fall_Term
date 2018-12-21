#include <iostream>

int main() {
  int *elements = new int[10];
  for (int i = 0; i < 10; i++)
      elements[i] = i*i;

  for (int i = 0; i < 10; i++)
      std::cout << i << "*" << i << "=" <<  elements[i] << std::endl;
  return 0;
}
