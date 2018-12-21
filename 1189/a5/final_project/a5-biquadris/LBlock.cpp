//
//  LBlock.cpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-16.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#include "LBlock.hpp"
#include <iostream>
using namespace std;


LBlock::LBlock(){
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
        {" ", " ", "L", " "},
        {"L", "L", "L", " "},
    };
}

LBlock::~LBlock(){
}
void LBlock::CW(){
    if (rotate_state == 0){
        v = {
                {" ", " ", " ", " "},
                {" ", " ", " ", " "},
                {"L", " ", " ", " "},
                {"L", " ", " ", " "},
                {"L", "L", " ", " "},
            };
        rotate_state = 1;
    }
    else if (rotate_state == 1){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"L", "L", "L", " "},
            {"L", " ", " ", " "},
        };
        rotate_state = 2;
    }
    else if (rotate_state == 2){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"L", "L", " ", " "},
            {" ", "L", " ", " "},
            {" ", "L", " ", " "},
        };
        rotate_state = 3;
    }
    else {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", "L", " "},
            {"L", "L", "L", " "},
        };
        rotate_state = 0;
    }
};

void LBlock:: CCW(){
    CW();
    CW();
    CW();
};

void LBlock::print(){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> LBlock::getBlock(){
    return this->v;
}

LBlock* LBlock::clone (){
    return new LBlock (*this);
}

string LBlock::GetType (){
    return BlockType;
}
