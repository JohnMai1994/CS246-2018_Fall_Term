//
//  ZBlock.hpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#ifndef ZBlock_hpp
#define ZBlock_hpp

#include <string>
#include "Block.hpp"
using namespace std;
#include <vector>
class ZBlock : public Block{
    string BlockType = "Z";
    int rotate_state;
protected:
    vector<vector <string>> v;
public:
    void CW() override;
    void CCW() override;
    ZBlock();
    ~ZBlock();
    void print () override;
    vector<vector <string>> getBlock() override;
    ZBlock* clone () override;
    std::unique_ptr<ZBlock> Aclone() {
        return std::unique_ptr<ZBlock> (this->clone());
    }
    string GetType () override;
};

#endif /* ZBlock_hpp */
