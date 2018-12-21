//
//  IBlock.hpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#ifndef IBlock_hpp
#define IBlock_hpp

#include <string>
#include "Block.hpp"
#include <memory>
using namespace std;
#include <vector>
class IBlock : public Block{
    string BlockType = "I";
    int rotate_state;
protected:
    vector<vector <string>> v;
public:
    void CW() override;
    void CCW() override;
    IBlock();
    ~IBlock();
    void print () override;
    vector<vector <string>> getBlock() override;
    IBlock* clone () override;
    std::unique_ptr<IBlock> Aclone() {
        return std::unique_ptr<IBlock> (this->clone());
    }
    string GetType () override;
};

#endif /* IBlock_hpp */
