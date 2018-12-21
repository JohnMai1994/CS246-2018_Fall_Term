//
//  OBlock.hpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#ifndef OBlock_hpp
#define OBlock_hpp
#include "Block.hpp"
#include <string>
using namespace std;
#include <vector>


class OBlock : public Block{
    string BlockType = "O";
    int rotate_state;
protected:
    vector<vector <string>> v;
public:
    void CW() override;
    void CCW() override;
    OBlock();
    ~OBlock();
    void print () override;
    vector<vector <string>> getBlock() override;
    OBlock* clone () override;
    std::unique_ptr<OBlock> Aclone() {
        return std::unique_ptr<OBlock> (this->clone());
    }
    string GetType () override;
};





#endif /* OBlock_hpp */
