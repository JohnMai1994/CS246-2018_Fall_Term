//
//  TBlock.hpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#ifndef TBlock_hpp
#define TBlock_hpp

#include "TBlock.hpp"
#include "Block.hpp"
#include <string>
using namespace std;
#include <vector>
class TBlock : public Block{
    string BlockType = "T";
    int rotate_state;
protected:
    vector<vector <string>> v;
public:
    void CW() override;
    void CCW() override;
    TBlock();
    ~TBlock();
    void print () override;
    vector<vector <string>> getBlock() override;
    TBlock* clone () override;
    std::unique_ptr<TBlock> Aclone() {
        return std::unique_ptr<TBlock> (this->clone());
    }
    string GetType () override;
};


#endif /* TBlock_hpp */
