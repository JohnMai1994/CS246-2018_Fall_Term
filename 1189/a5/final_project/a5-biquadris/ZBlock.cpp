//
//  ZBlock.cpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#include "ZBlock.hpp"
#include <iostream>
using namespace std;


ZBlock::ZBlock(){
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
        {"Z", "Z", " ", " "},
        {" ", "Z", "Z", " "},
    };
}

ZBlock::~ZBlock(){
}
void ZBlock::CW(){
    if (rotate_state == 0){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", "Z", " ", " "},
            {"Z", "Z", " ", " "},
            {"Z", " ", " ", " "},
        };
        rotate_state = 1;
    }
    else {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"Z", "Z", " ", " "},
            {" ", "Z", "Z", " "},
        };
        rotate_state = 0;
    }
};

void ZBlock:: CCW(){
    CW();
    CW();
    CW();
};

void ZBlock::print(){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> ZBlock::getBlock(){
    return this->v;
}

ZBlock* ZBlock::clone (){
    return new ZBlock (*this);
}

string ZBlock::GetType (){
    return BlockType;
}
