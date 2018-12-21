//
//  SBlock.cpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#include "SBlock.hpp"
#include <iostream>
using namespace std;


SBlock::SBlock(){
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
        {" ", "S", "S", " "},
        {"S", "S", " ", " "},
    };
}

SBlock::~SBlock(){
}
void SBlock::CW(){
    if (rotate_state == 0){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"S", " ", " ", " "},
            {"S", "S", " ", " "},
            {" ", "S", " ", " "},
        };
        rotate_state = 1;
    }
    else {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", "S", "S", " "},
            {"S", "S", " ", " "},
        };
        rotate_state = 0;
    }
};

void SBlock:: CCW(){
    CW();
    CW();
    CW();
};

void SBlock::print(){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> SBlock::getBlock(){
    return this->v;
}

SBlock* SBlock::clone (){
    return new SBlock (*this);
}

string SBlock::GetType (){
    return BlockType;
}
