#include <string>
#include <sstream>
#include <iostream>

using namespace std;


string intToString (int n) {
    ostringstream sock;
    sock << n;
    return sock.str();
}

int main() {
  int n;
  while (true) {
    cout << "enter a number:" << endl;
    string s;
    cin >> s;
    istringstream iss {s};
    if (iss >> n ) break;
    cout << "I Said, ";
  } 
    cout << "You entered " << n << endl;
}

