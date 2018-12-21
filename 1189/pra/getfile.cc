#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ifstream f {"file.txt"};
  string s;
  while (f >> s){
     cout << s <<endl;
  }
  ifstream k {"file2.txt"};
  char z;
  while (k >> z){
     cout << z << endl;
  }
}
