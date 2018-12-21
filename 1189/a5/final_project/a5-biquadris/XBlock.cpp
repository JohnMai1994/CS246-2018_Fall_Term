//
//  XBlock.cpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#include "XBlock.hpp"
#include <iostream>
using namespace std;


XBlock::XBlock(){
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
        {" ", "X", " ", " "},
        {"X", "X", "X", " "},
        {" ", "X", " ", " "},
    };
}

XBlock::~XBlock(){
}
void XBlock::CW(){

};

void XBlock:: CCW(){
};

void XBlock::print(){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> XBlock::getBlock(){
    return this->v;
}

XBlock* XBlock::clone (){
    return new XBlock (*this);
}

string XBlock::GetType (){
    return BlockType;
}

