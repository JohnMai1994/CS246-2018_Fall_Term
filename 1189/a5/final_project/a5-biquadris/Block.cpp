//
//  Block.cpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-16.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#include "Block.hpp"
#include <string>

Block::Block () {};
Block::~Block(){
};

Block::Block (const Block& b) {
    v = b.v;
}
Block& Block::operator = (const Block& other){
    if (this == &other) return *this;
    v = other.v;
    return *this;
}
