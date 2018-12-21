#ifndef LBlock_hpp
#define LBlock_hpp
#include "Block.hpp"
#include <string>
using namespace std;
#include <vector>
class LBlock : public Block{
    string BlockType = "L";
    int rotate_state;
protected:
    vector<vector <string>> v;

public:
    void CW() override;
    void CCW() override;
    LBlock();
    ~LBlock();
    void print () override;
    vector<vector <string>> getBlock() override;
    LBlock* clone () override;
    std::unique_ptr<LBlock> Aclone() {
        return std::unique_ptr<LBlock> (this->clone());
    }
    string GetType () override;
};



#endif /* LBlock_hpp */
