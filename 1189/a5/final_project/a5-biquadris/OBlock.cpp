//
//  OBlock.cpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#include "OBlock.hpp"
#include <iostream>
using namespace std;



OBlock::OBlock(){
    rotate_state = 0;
    //4 vectors of strings
    v.resize(5);
    //each vector has 4 strings
    for (int i = 0; i < 4; ++i){
        v.resize(4);
    }
    v = {
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {"O", "O", " ", " "},
        {"O", "O", " ", " "},
    };
}

OBlock::~OBlock(){
}
void OBlock::CW(){
};

void OBlock:: CCW(){
};

void OBlock::print(){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> OBlock::getBlock(){
    return this->v;
}

OBlock* OBlock::clone (){
    return new OBlock (*this);
}

string OBlock::GetType (){
    return BlockType;
}
