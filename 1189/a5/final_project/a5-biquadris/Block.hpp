//
//  Block.hpp
//  Tetris
//
//  Created by Harry Wang on 2018-11-16.
//  Copyright © 2018 Harry Wang. All rights reserved.
//

#ifndef Block_hpp
#define Block_hpp
#include <string>
#include <vector>
#include <memory>
using namespace std;


class Block {
protected:
    vector<vector <string>> v;
public:
    Block ();
    virtual void CW () = 0;
    virtual void CCW () = 0;
    virtual ~Block();
    virtual void print () = 0;
    virtual vector<vector <string>> getBlock() = 0;
    virtual Block* clone () = 0;
    std::shared_ptr<Block> Aclone(){
        return std::shared_ptr<Block> (this->clone());
    }
    virtual string GetType () = 0;
    Block (const Block& b);
    Block& operator = (const Block& b);
};

#endif /* Block_hpp */
