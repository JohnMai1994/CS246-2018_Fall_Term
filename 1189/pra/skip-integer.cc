#include <iostream>
using namespace std;

int main() {
     int i;
     while (true){
       if (!(cin>>i)){
         if (cin.eof()) break;
         cin.clear();
         cin.ignore();
       }
       else 
        cout << "Hexadecimal:" << hex << i << endl;
     }
   }
