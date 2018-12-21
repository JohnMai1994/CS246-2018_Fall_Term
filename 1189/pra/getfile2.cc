#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ifstream k {"file.txt"};
  char z;
  while (k >> z){
    cout << z << " ";
    z = z+3;
    cout << z << endl;
  }
}

