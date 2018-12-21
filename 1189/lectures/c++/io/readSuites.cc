#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printSuiteFile(string name = "suite.txt") {
  ifstream file(name.c_str());
  string s;
  while (file >> s) cout << s << endl;
}

int main() {
  cout << "Default:" << endl;
  printSuiteFile();

  cout << endl << "Other file:" << endl;
  printSuiteFile("suite2.txt");
}
