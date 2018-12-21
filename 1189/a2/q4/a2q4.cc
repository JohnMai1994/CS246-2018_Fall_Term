#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[]) {
    bool character = false;
    bool list = false;
    bool word = false;
    bool file = false;
    string file_name;
    int i;
    for (i = 1; i < argc; ++i) {
      string args (argv[i]);
      if (args == "-c") {
         character = true; 
      } else if (args == "-w") {
         word = true;
      } else if (args == "-l") {
         list = true;
      } else {
         file = true;
         file_name = argv[i];
      }
    }
     
    string line;
    string content = "";
    int list_num = -1;
    
    if (!file) {
    while (!cin.eof()) {
       getline(cin, line);
       if (list_num != -1) content += " ";
       content += line;
       list_num += 1;
       }
    }  else {
      list_num = 0;
      ifstream file {file_name};
      while (getline(file, line)) {
        if (list_num != -1) content += " ";
        content += line;
        list_num += 1;
      }
    }

    if ((list)||(!((character)||(list)||(word)))){
      cout << list_num << " ";

    } 
    if ((word)||(!((character)||(list)||(word))))  {
      istringstream iss (content);
      string words;
      int word_num = 0;
      while (iss >> words) {
         word_num += 1;
      }
      cout << word_num << " ";
    }
    if ((character)||(!((character)||(list)||(word)))) {
      int character_num = content.length();
      cout << character_num << " " ;
    }
    if (file) {
      cout << file_name;
    }
    cout << "\n";
}

   // if (!((character)||(list)||(word))) {
       


