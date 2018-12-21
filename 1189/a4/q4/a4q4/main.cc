#include "grid.h"
#include "cell.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    Grid theGrid;
    string s;
    string command;
    int size;
    int x, y;
    int step;
    bool gameOn = false; // check if a game is called?
    while (cin >> command) {
       if ((!gameOn) && (command == "new")) {
          //cout << "input number" << endl;
	  cin >> s;
          istringstream ss(s);
          if ((ss >> size)&&(size > 0)) {
            theGrid.init(size);
            //cout << "it should look like this" << endl;
            //cout << theGrid << endl;
            
          } else {
            cerr << "your size is wrong" << endl;
            return 0;
          }
       }
       if (command == "init") {
          
          while (cin >> x >> y) { 
             if ((x < 0)&&(y < 0)) {
                break;
             }
             theGrid.turnOn(y, x);
          }
       }
       if (command == "print") {
         cout << theGrid;
       }
       if (command == "step") {
         theGrid.tick();
       }
       if (command == "steps") {
          cin >> s;
          istringstream ss(s);
          if (ss >> step) {
             for (int i = 0; i < step; ++i) {
                theGrid.tick();
             }
          }
          else {
             cerr << "something wrong on you steps number" << endl;
          }
       }
    }
    return 0;
}
