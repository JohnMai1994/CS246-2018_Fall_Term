//
//  SBlock.hpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//


#ifndef SBlock_hpp
#define SBlock_hpp

#include <string>
#include "Block.hpp"
using namespace std;
#include <vector>
class SBlock : public Block{
    string BlockType = "S";
    int rotate_state;
protected:
    vector<vector <string>> v;
public:
    void CW() override;
    void CCW() override;
    SBlock();
    ~SBlock();
    void print () override;
    vector<vector <string>> getBlock() override;
    SBlock* clone () override;
    std::unique_ptr<SBlock> Aclone() {
        return std::unique_ptr<SBlock> (this->clone());
    }
    string GetType () override;
};

#endif /* SBlock_hpp */
