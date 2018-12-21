//
//  StarBlock.hpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#ifndef StarBlock_hpp
#define StarBlock_hpp
#include "Block.hpp"
#include <string>
using namespace std;
#include <vector>


class StarBlock : public Block{
    string BlockType = "*";
    int rotate_state;
protected:
    vector<vector <string>> v;
public:
    void CW() override;
    void CCW() override;
    StarBlock();
    ~StarBlock();
    void print () override;
    vector<vector <string>> getBlock() override;
    StarBlock* clone () override;
    string GetType () override;
};





#endif /* OBlock_hpp */

