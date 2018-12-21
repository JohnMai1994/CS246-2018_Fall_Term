//
//  JBlock.hpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#ifndef JBlock_hpp
#define JBlock_hpp

#include <string>
#include "Block.hpp"
#include <memory>
using namespace std;
#include <vector>
class JBlock : public Block{
    string BlockType = "J";
    int rotate_state;
protected:
    vector<vector <string>> v;
public:
    void CW() override;
    void CCW() override;
    JBlock();
    ~JBlock();
    void print () override;
    vector<vector <string>> getBlock() override;
    JBlock* clone () override;
    std::unique_ptr<JBlock> Aclone() {
        return std::unique_ptr<JBlock> (this->clone());
    }
    string GetType () override;
};

#endif /* JBlock_hpp */
