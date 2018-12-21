#include "standard.h"

Standard::Standard(int rows, int cols, Maze& m): maze{m}, out{std::cout}{
  displayMap[EMPTY] = ' ';
  displayMap[WALL] = '#';
  displayMap[GOAL] = '*';
  displayMap[PLAYER] = '@';
  std::vector<char> row(cols+2, ' ');
  for (int i = 0; i < rows+2; ++i ){
    display.emplace_back(row);
  }
  for (int i = 0; i < cols + 2; ++i){
    display[0][i] = displayMap[WALL];
    display[rows+1][i] =  displayMap[WALL];
  }
  for (int i = 0; i < rows + 2; ++i){
    display[i][0] =  displayMap[WALL];
    display[i][cols+1] =  displayMap[WALL];
  }
}

void Standard::updateView(){
  for ( auto row: display ){
    for ( auto c: row ){
      out << c;
    }
    out << std::endl;
  }
}

void Standard::update(const std::string& msg){
  out << msg << std::endl;
}

void Standard::update(int row, int col, State state){
  display[row+1][col+1] = displayMap[state];
}
