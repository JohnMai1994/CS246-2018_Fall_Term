//
//  IBlock.cpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#include "IBlock.hpp"
#include <iostream>
using namespace std;


IBlock::IBlock(){
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
        {"I", "I", "I", "I"},
        {" ", " ", " ", " "},
    };
}

IBlock::~IBlock(){
}
void IBlock::CW(){
    if (rotate_state == 1){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"I", "I", "I", "I"},
            {" ", " ", " ", " "},
        };
        rotate_state = 0;
    }
    else {
        v = {
            {"I", " ", " ", " "},
            {"I", " ", " ", " "},
            {"I", " ", " ", " "},
            {"I", " ", " ", " "},
            {" ", " ", " ", " "},
        };
        rotate_state = 1;
    }
};

void IBlock:: CCW(){
    CW();
    CW();
    CW();
};

void IBlock::print(){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}


vector<vector <string>> IBlock::getBlock(){
    return this->v;
}

IBlock* IBlock::clone (){
    return new IBlock (*this);
}

string IBlock::GetType (){
    return BlockType;
}
