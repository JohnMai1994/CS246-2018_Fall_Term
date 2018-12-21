//
//  XBlock.hpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-17.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#ifndef XBlock_hpp
#define XBlock_hpp

#include <string>
#include "Block.hpp"
using namespace std;
#include <vector>
class XBlock : public Block{
    string BlockType = "X";
    int rotate_state;
protected:
    vector<vector <string>> v;
public:
    void CW() override;
    void CCW() override;
    XBlock();
    ~XBlock();
    void print () override;
    vector<vector <string>> getBlock() override;
    XBlock* clone () override;
    std::unique_ptr<XBlock> Aclone() {
        return std::unique_ptr<XBlock> (this->clone());
    }
    string GetType () override;
};

#endif /* XBlock_hpp */

