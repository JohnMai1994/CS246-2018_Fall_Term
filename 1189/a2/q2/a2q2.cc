#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    int num;
    string dir;
    if (argc-1 > 2) {
       cout<< "ERROR: program should not be called with more than 2 argments" << endl;
    } else {
      if (argc -1 == 2) {
         num = stoi(argv[1]);
         dir = argv[2];
     } else if (argc -1 == 1) {
         num = stoi(argv[1]);
         dir = "right";
     } else {
         num = 3;
         dir = "right";
     }
   } 
   if (!((0 <= num)&&(num <= 25))) cout << "ERROR: Incorrect shift value" << endl;
   if (!((dir == "right")||(dir == "left"))) cout << "ERROR: Incorrect direction (only left or right allowed)" << endl;

while (true) {
   string line_contents;
   getline(cin, line_contents);
   char z;     
   int line_num = line_contents.length();
   int x;
   if (cin.eof()) exit(0);
   if (((line_contents[0] == 'e')&&(dir == "right"))||((line_contents[0] == 'd')&&(dir == "left" )))    {
    for (x = 1; x < line_num; ++ x){
     z = line_contents[x];
     if ((z <= 'z')&&(z >='a')) {
       if ('z' - z < num) {
        z = z -26 + num;
       } else {
        z = z + num;
       }
     } else if ((z<='Z')&&(z>='A')){
       z = z+num;
       if (z > 'Z') {
         z = z -26;
       }
     }
     cout << z; 
    }
    cout << "" << endl; 
   } else if (((line_contents[0] == 'e')&&(dir == "left"))||((line_contents[0] == 'd')&&(dir == "right"))) {
     for (x = 1; x < line_num; ++ x){
      z = line_contents[x];
     if ((z <= 'z')&&(z>='a')) {
       z = z-num;
       if (z < 'a') {
         z = z + 26;
       }
     } else if ((z<='Z')&&(z>='A')){
       z = z-num;
       if (z < 'A') {
         z = z + 26;
       }
     }
     cout << z;      
    }
    cout << "" << endl;
   } else if (line_contents[0] == 'q') {
     exit(0);
   } 
 }
}
