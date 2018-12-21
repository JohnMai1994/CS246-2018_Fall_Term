#include "maze.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
  bool curses = false;
  int computer = 0;
  for ( int i = 1; i < argc; ++i ){
    std::string arg = argv[i];
    cout << arg << endl;
    if ( arg == "curses" ) curses = true;
    if ( arg == "computer" ){
      ++i;
      int val;
      istringstream iss{argv[i]};
      if ( iss  >> val && val == 1 ){
        computer = val;
      } else {
        cerr << "Invalid computer" << endl;
        return 1;
      }
    }
  }

  Maze m{31,31, curses, computer};
  m.play();
}
