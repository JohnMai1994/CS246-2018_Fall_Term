//
//  CBlock.hpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#ifndef CBlock_hpp
#define CBlock_hpp

#include "CBlock.hpp"
#include "Block.hpp"
#include <string>
using namespace std;
#include <vector>
class CBlock : public Block{
    string BlockType = "C";
    int rotate_state;
protected:
    vector<vector <string>> v;
public:
    void CW() override;
    void CCW() override;
    CBlock();
    ~CBlock();
    void print () override;
    vector<vector <string>> getBlock() override;
    CBlock* clone () override;
    std::unique_ptr<CBlock> Aclone() {
        return std::unique_ptr<CBlock> (this->clone());
    }
    string GetType () override;
};


#endif /* CBlock_hpp */

