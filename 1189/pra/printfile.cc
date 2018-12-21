#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printfile (string name = "file.txt") {
     ifstream f {name};
     string s;
     while (f >> s) cout << s << endl;
}

int main () {
    string name;
    cin >> name;
    if (name != "file.txt") {
       printfile();
    } else {
    printfile(name);
}}
