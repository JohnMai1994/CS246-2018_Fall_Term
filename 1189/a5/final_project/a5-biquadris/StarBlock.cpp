//
//  StarBlock.cpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#include "StarBlock.hpp"
#include <iostream>
using namespace std;



StarBlock::StarBlock(){
    rotate_state = 0;
    //4 vectors of strings
    v.resize(5);
    //each vector has 4 strings
    v[0].resize(4);
    v = {
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", "*"},
        {" ", " ", " ", " "},
        
    };
}

StarBlock::~StarBlock(){
}
void StarBlock::CW(){
};

void StarBlock:: CCW(){
};

void StarBlock::print(){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> StarBlock::getBlock(){
    return this->v;
}

StarBlock* StarBlock::clone (){
    return new StarBlock (*this);
}

string StarBlock::GetType (){
    return BlockType;
}

