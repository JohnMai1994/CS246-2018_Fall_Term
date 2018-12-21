#include "curseView.h"
#include <ncurses.h>

Curses::Curses(int rows, int cols, Maze& m): width{rows}, height{cols}, model{m}{
  initscr();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  displayMap[EMPTY] = ' ';
  displayMap[WALL] = '#';
  displayMap[GOAL] = '*';
  displayMap[PLAYER] = '@';
  
  // exterior walls
  for (int i = 0; i < cols + 2; ++i){
    mvwaddch(stdscr, 0, i, displayMap[WALL]);
    mvwaddch(stdscr, rows+1, i, displayMap[WALL]);
  }
  for (int i = 0; i < rows + 2; ++i){
    mvwaddch(stdscr, i, 0, displayMap[WALL]);
    mvwaddch(stdscr, i, cols+1, displayMap[WALL]);
  }

  // fill in map
  for (int i = 0; i < rows; ++i ){
    for( int j = 0; j < cols; ++j ){
      mvwaddch(stdscr, i+1, j+1, displayMap[EMPTY]);
    }
  }
}

void Curses::updateView(){
  refresh();
}

void Curses::update(const std::string& msg){
  wmove(stdscr, height+3,0);
  waddstr(stdscr,"                                              ");
  wmove(stdscr, height+3,0);
  waddstr(stdscr,msg.c_str());
}


void Curses::update(int row, int col, State state){
  mvwaddch(stdscr,row+1,col+1,displayMap[state]);
}

Curses::~Curses(){ endwin(); }
