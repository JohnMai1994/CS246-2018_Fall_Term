#include "binarynum.h"
#include <string>
#include <iostream>
using namespace std;

BinaryNum readBinaryNum() {
   BinaryNum binary {0,0};
   binary.capacity = 4;
   binary.contents = new bool[binary.capacity];
   char c;
   while (!cin.eof()){
     cin >> c;
     if (c == '0') {
       binary.contents[binary.size] = false;
       binary.size += 1;
     } else if (c == '1') {
       binary.contents[binary.size] = true;     
       binary.size += 1;
     } else {
       return binary;
     }

     if (binary.size >= binary.capacity) {
        binary.capacity *= 2;
        bool *new_contents = new bool[binary.capacity];
        for (int i = 0; i < binary.size; ++i) {
            new_contents[i] = binary.contents[i];
        }
        delete binary.contents;
        binary.contents = new_contents;
     }
   }
   return binary;
 }

void binaryConcat(BinaryNum &binNum) {
     char c;
     while (!cin.eof()){
       cin >> c;
       if (c == '0') {
         binNum.contents[binNum.size] = false;
         binNum.size += 1;
       } else if (c == '1') {
         binNum.contents[binNum.size] = true;
         binNum.size += 1;
       }else {
         break;
       } 

       if (binNum.size >= binNum.capacity) {
          binNum.capacity *= 2;
          bool *new_contents = new bool[binNum.capacity];
          for (int i = 0; i < binNum.size; ++i) {
             new_contents[i] = binNum.contents[i];
          }
          delete binNum.contents;
          binNum.contents = new_contents;
       }
    } 
}

int pow(int x, int y) {
   int out = 1;
   while(y-- >0){ 
       out *= x;
   }
   return out;
 
}


int binaryToDecimal (const BinaryNum &binNum) {
    int num, a;
   // int b = 0;
    num = 0;
    for(int i = binNum.size -1 ; i >= 0; i--) {
        if (binNum.contents[i]) {
          a = 1;
        } else {
          a = 0;
        }
        num += a * pow(2, binNum.size -i -1);  
    }
    return num;
}

BinaryNum &operator<< (BinaryNum &binNum, int num) {
    int new_size = binNum.size + num;
    if (new_size >= binNum.capacity) binNum.capacity *= 2;
    bool *new_contents = new bool[binNum.capacity];
    for (int i = 0; i < binNum.size; ++i) {
       new_contents[i] = binNum.contents[i];
    }
    delete binNum.contents;
    for (int k = 0; k < num; ++k) {
       new_contents[binNum.size] = false;
       binNum.size += 1;
    }
    binNum.contents = new_contents;
    return binNum;
}



void printBinaryNum(ostream &out, const BinaryNum &binNum, char sep) {
     int size = binNum.size;
     if (binNum.size != 0) cout << binNum.contents[0];
     for (int i =1; i < size; ++i){
        cout << sep << binNum.contents[i];
     }
}
/*
int main ( ) {
  cout << "Remember to Delet the main function"<< endl;
  BinaryNum a =  readBinaryNum();
  cout << binaryToDecimal(a) << endl;
  cout << a.size << "  " << a.capacity << "  "  <<endl;
  printBinaryNum(cout, a, '*');
  cout << binaryToDecimal(a) << endl;
  binaryConcat(a);
  printBinaryNum(cout, a, '*');
  cout <<  binaryToDecimal(a) << endl;
  int f;
  cin >> f;
   a << f;
  printBinaryNum(cout, a, '*'); 
} 
*/
