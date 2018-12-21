#ifndef Level_hpp
#define Level_hpp

#include <stdio.h>
#include <vector>
#include "Block.hpp"
#include "LBlock.hpp"
#include "OBlock.hpp"
#include "JBlock.hpp"
#include "IBlock.hpp"
#include "SBlock.hpp"
#include "ZBlock.hpp"
#include "TBlock.hpp"
#include "XBlock.hpp"
#include "CBlock.hpp"
#include <memory>

struct Player;


//The abstract level class
class Level{
    
public:
    int level_num;
    int GetLevel() const;
    virtual std::shared_ptr<Block> GetBlock(std::shared_ptr<Player> ) = 0;
    virtual ~Level() = 0;
    virtual void addBlockSeq(std::string,int) = 0;
    virtual void randomBack(int) = 0;
    
};



//*************************subclasses****************************


/////////////////////////////Level0///////////////////////////////


class Level0 : public Level{
    
    std::vector<std::string> seqList1;
    std::vector<std::string> seqList2;
    int seqCount1;
    int seqCount2;
    
public:
    Level0();
    std::shared_ptr<Block> GetBlock(std::shared_ptr<Player>  ) override;
    ~Level0();
    void addBlockSeq(std::string,int) override;
    void randomBack(int) override;
};



//////////////////////////////Level1//////////////////////////////


class Level1 : public Level{
    std::vector<int> seqList1_int;
    std::vector<int> seqList2_int;
    int seqCount1_int;
    int seqCount2_int;
    
public:
    Level1();
    std::shared_ptr<Block> GetBlock(std::shared_ptr<Player>  ) override;
    ~Level1();
    void addBlockSeq(std::string,int) override;
    void randomBack(int) override;
};

////////////////////////////Level2//////////////////////////////



class Level2 : public Level{
    std::vector<int> seqList1_int;
    std::vector<int> seqList2_int;
    int seqCount1_int;
    int seqCount2_int;
    
public:
    Level2();
    std::shared_ptr<Block> GetBlock(std::shared_ptr<Player>  ) override;
    ~Level2();
    void addBlockSeq(std::string,int) override;
    void randomBack(int) override;
};

////////////////////////////Level3//////////////////////////////

class Level3 : public Level{
    std::vector<std::string> seqList1;
    std::vector<std::string> seqList2;
    int seqCount1;
    int seqCount2;
    bool random1;
    bool random2;
    std::vector<int> seqList1_int;
    std::vector<int> seqList2_int;
    int seqCount1_int;
    int seqCount2_int;
    
public:
    
    Level3();
    std::shared_ptr<Block> GetBlock(std::shared_ptr<Player>  ) override;
    ~Level3();
    void addBlockSeq(std::string,int) override;
    void randomBack(int) override;
};

////////////////////////////Level4//////////////////////////////

class Level4 : public Level{
    std::vector<std::string> seqList1;
    std::vector<std::string> seqList2;
    int seqCount1;
    int seqCount2;
    bool random1;
    bool random2;
    std::vector<int> seqList1_int;
    std::vector<int> seqList2_int;
    int seqCount1_int;
    int seqCount2_int;
    
public:
    Level4();
    std::shared_ptr<Block> GetBlock(std::shared_ptr<Player> ) override;
    ~Level4();
    void addBlockSeq(std::string,int) override;
    void randomBack(int) override;
    
};

////////////////////////////Level5//////////////////////////////

class Level5 : public Level{
    std::vector<std::string> seqList1;
    std::vector<std::string> seqList2;
    int seqCount1;
    int seqCount2;
    bool random1;
    bool random2;
    std::vector<int> seqList1_int;
    std::vector<int> seqList2_int;
    int seqCount1_int;
    int seqCount2_int;
    
public:
    Level5();
    std::shared_ptr<Block> GetBlock(std::shared_ptr<Player> ) override;
    ~Level5();
    void addBlockSeq(std::string,int) override;
    void randomBack(int) override;
    
};


#endif /* Level_hpp */
