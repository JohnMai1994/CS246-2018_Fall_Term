//
//  JBlock.cpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#include "JBlock.hpp"
#include <iostream>
using namespace std;


JBlock::JBlock(){
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
        {"J", " ", " ", " "},
        {"J", "J", "J", " "},
    };
}

JBlock::~JBlock(){
}
void JBlock::CW(){
    if (rotate_state == 0){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"J", "J", " ", " "},
            {"J", " ", " ", " "},
            {"J", " ", " ", " "},
        };
        rotate_state = 1;
    }
    else if (rotate_state == 1){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"J", "J", "J", " "},
            {" ", " ", "J", " "},
        };
        rotate_state = 2;
    }
    else if (rotate_state == 2){
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", "J", " ", " "},
            {" ", "J", " ", " "},
            {"J", "J", " ", " "},
        };
        rotate_state = 3;
    }
    else {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"J", " ", " ", " "},
            {"J", "J", "J", " "},
        };
        rotate_state = 0;
    }
};

void JBlock:: CCW(){
    CW();
    CW();
    CW();
};

void JBlock::print(){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> JBlock::getBlock(){
    return this->v;
}

JBlock* JBlock::clone (){
    return new JBlock (*this);
}

string JBlock::GetType (){
    return BlockType;
}
