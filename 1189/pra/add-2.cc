#include <iostream>
using namespace std;

int main(){
  int x, y;
  cin >> x >> y;
  if (cin.eof()) cout << "fuck you1" << endl;
  if (cin.fail()) cout << "fuck you2" << endl;
  cout << x+y << endl;
}
  
