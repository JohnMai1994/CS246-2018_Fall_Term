//
//  TBlock.cpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#include "TBlock.hpp"
#include <iostream>
using namespace std;


TBlock::TBlock(){
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
        {"T", "T", "T", " "},
        {" ", "T", " ", " "},
    };
}

TBlock::~TBlock(){
}
void TBlock::CW(){
    if (rotate_state == 0){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", "T", " ", " "},
            {"T", "T", " ", " "},
            {" ", "T", " ", " "},
        };
        rotate_state = 1;
    }
    else if (rotate_state == 1){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", "T", " ", " "},
            {"T", "T", "T", " "},
        };
        rotate_state = 2;
    }
    else if (rotate_state == 2){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"T", " ", " ", " "},
            {"T", "T", " ", " "},
            {"T", " ", " ", " "},
        };
        rotate_state = 3;
    }
    else {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"T", "T", "T", " "},
            {" ", "T", " ", " "},
        };
        rotate_state = 0;
    }
};

void TBlock:: CCW(){
    CW();
    CW();
    CW();
};

void TBlock::print(){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> TBlock::getBlock(){
    return this->v;
}

TBlock* TBlock::clone (){
    return new TBlock (*this);
}

string TBlock::GetType (){
    return BlockType;
}
