//
//  CBlock.cpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#include "CBlock.hpp"
#include <iostream>
using namespace std;


CBlock::CBlock(){
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
        {"C", "C", " ", " "},
        {"C", " ", " ", " "},
        {"C", "C", " ", " "},
    };
}

CBlock::~CBlock(){
}
void CBlock::CW(){
    if (rotate_state == 0){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"C", "C", "C", " "},
            {"C", " ", "C", " "},
        };
        rotate_state = 1;
    }
    else if (rotate_state == 1){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"C", "C", " ", " "},
            {" ", "C", " ", " "},
            {"C", "C", " ", " "},
        };
        rotate_state = 2;
    }
    else if (rotate_state == 2){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"C", " ", "C", " "},
            {"C", "C", "C", " "},
        };
        rotate_state = 3;
    }
    else {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"C", "C", " ", " "},
            {"C", " ", " ", " "},
            {"C", "C", " ", " "},
        };
        rotate_state = 0;
    }
};

void CBlock:: CCW(){
    CW();
    CW();
    CW();
};

void CBlock::print(){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> CBlock::getBlock(){
    return this->v;
}

CBlock* CBlock::clone (){
    return new CBlock (*this);
}

string CBlock::GetType (){
    return BlockType;
}

