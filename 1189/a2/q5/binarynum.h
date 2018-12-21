#ifndef BINARYNUM_H
#define BINARYNUM_H

#include <iostream>

struct BinaryNum {
    int size;         // number of elements the array currently holds
    int capacity;     // number of elements the array could hold, 
                      // given current memory allocation to contents
    bool *contents;   // (pointer to) heap-allocated array of bools
};

BinaryNum readBinaryNum(); 
void binaryConcat(BinaryNum &binNum); 
int binaryToDecimal(const BinaryNum &binNum); 
void printBinaryNum(std::ostream &out, const BinaryNum &binNum, char sep); 
BinaryNum &operator<<(BinaryNum &binNum, int num);

#endif
