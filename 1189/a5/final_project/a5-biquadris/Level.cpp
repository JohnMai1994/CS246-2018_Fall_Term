#include "Level.hpp"
#include "player.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>


using namespace std;

extern string seqName1;
extern string seqName2;
extern int seedNum;//for seed, our initial number
extern bool seedFree;



Level::~Level(){}


//Return the int number for which level the player is
int Level:: GetLevel() const{
    return level_num;
}

///////////////////////////Leve0//////////////////////////////


//By creating a level0 class, we need correct sequence1.txt and
//sequence2.txt file
Level0::Level0(){
    
    ifstream seq1{seqName1};
    ifstream seq2{seqName2};
    
    string s;
    while(seq1 >> s){
        string tb1 = s;
        seqList1.emplace_back(tb1);
    }
    while(seq2 >> s){
        string tb2 = s;
        seqList2.emplace_back(tb2);
    }
    
    seqCount1 = 0;
    seqCount2 = 0;
    level_num = 0;
    //
}

Level0::~Level0(){}

//we pretend we need this function but actually not
void Level0::addBlockSeq(std::string filename,int id){}

//Return a block pointer
shared_ptr<Block> Level0::GetBlock(std::shared_ptr<Player> p){
    shared_ptr<Block> b = nullptr;
    char s;
    if(p->id == 1){
        if(seqCount1 > seqList1.size() - 1){//reset
            seqCount1 = 0;
        }
        
        //    cout << "This one is!" << seqList1[seqCount1] << endl;
        s = seqList1[seqCount1][0];
        ++seqCount1;
        
    } else {
        if(seqCount2 > seqList2.size() - 1){//reset
            seqCount2 = 0;
        }
        s = seqList2[seqCount2][0];
        ++seqCount2;
    }
    switch(s){
        case 'J' : b = make_shared<JBlock>();break;
        case 'O' : b = make_shared<OBlock>();break;
        case 'L' : b = make_shared<LBlock>();break;
        case 'I' : b = make_shared<IBlock>();break;
        case 'S' : b = make_shared<SBlock>();break;
        case 'Z' : b = make_shared<ZBlock>();break;
        case 'T' : b = make_shared<TBlock>();break;
            
    }
    return b;
}


void Level0::randomBack(int id ){}

////////////////////////////Level1//////////////////////////////

Level1::Level1(){
    level_num = 1;
    seqCount1_int = 0;
    seqCount2_int = 0;
    
    srand(seedNum);
    for(int i = 0 ; i < 4 ; i++ ) {
        seqList1_int.emplace_back(rand() % 12 + 1);
    }//for player1
    for(int i = 0 ; i < 4 ; i++ ) {
        seqList2_int.emplace_back(rand() % 12 + 1);
    }//for player2
}

Level1::~Level1(){}

//we pretend we need this function but actually not
void Level1::addBlockSeq(std::string filename,int id){}

//
shared_ptr<Block> Level1::GetBlock(std::shared_ptr<Player> p){
    shared_ptr<Block> b = nullptr;
    int rdmb = 1;
    //
    if(p->id == 1){
        if(seqCount1_int > seqList1_int.size() - 1){//reset
            seqCount1_int = 0;
        }
        
        rdmb = seqList1_int[seqCount1_int];
        ++seqCount1_int;
        
    } else {
        if(seqCount2_int > seqList2_int.size() - 1){//reset
            seqCount2_int = 0;
        }
        rdmb = seqList2_int[seqCount2_int];
        ++seqCount2_int;
    }
    //
    
    if(seedFree){//rewrite
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(1,6);
        rdmb = distr(eng);
    }
    switch (rdmb){
        case 1: b = make_shared<LBlock>(); break;
        case 2: b = make_shared<IBlock>(); break;
        case 3: b = make_shared<OBlock>(); break;
        case 4: b = make_shared<JBlock>(); break;
        case 5: b = make_shared<TBlock>(); break;//
        case 6: b = make_shared<LBlock>(); break;
        case 7: b = make_shared<IBlock>(); break;
        case 8: b = make_shared<OBlock>(); break;
        case 9: b = make_shared<JBlock>(); break;
        case 10: b = make_shared<TBlock>(); break;//
        case 11: b = make_shared<ZBlock>(); break;
        case 12: b = make_shared<SBlock>(); break;
    }
    return b;
}

void Level1::randomBack(int id ){}

////////////////////////////Level2//////////////////////////////

Level2::Level2(){
    level_num = 2;
    int seqCount1_int = 0;
    int seqCount2_int = 0;
    srand(seedNum);
    for(int i = 0 ; i < 4 ; i++ ) {
        seqList1_int.emplace_back(rand() % 7 + 1);
    }//for player1
    for(int i = 0 ; i < 4 ; i++ ) {
        seqList2_int.emplace_back(rand() % 7 + 1);
    }//for player2
}

//we pretend we need this function but actually not
void Level2::addBlockSeq(std::string filename,int id){}

Level2::~Level2(){};

shared_ptr<Block> Level2::GetBlock(std::shared_ptr<Player> p){
    shared_ptr<Block> b = nullptr;
    int rdmb = 1;
    //
    if(p->id == 1){
        if(seqCount1_int > seqList1_int.size() - 1){//reset
            seqCount1_int = 0;
        }
        rdmb = seqList1_int[seqCount1_int];
        ++seqCount1_int;
        
    } else {
        if(seqCount2_int > seqList2_int.size() - 1){//reset
            seqCount2_int = 0;
        }
        rdmb = seqList2_int[seqCount2_int];
        ++seqCount2_int;
    }
    //
    if (seedFree){
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(1,7);
        rdmb = distr(eng);
    }
    switch (rdmb){
        case 1: b = make_shared<LBlock>(); break;
        case 2: b = make_shared<IBlock>(); break;
        case 3: b = make_shared<OBlock>(); break;
        case 4: b = make_shared<JBlock>(); break;
        case 5: b = make_shared<TBlock>(); break;
        case 6: b = make_shared<ZBlock>(); break;
        case 7: b = make_shared<SBlock>(); break;
    }
    return b;
}

void Level2::randomBack(int id ){}

////////////////////////////Level3//////////////////////////////

Level3::Level3(){
    level_num = 3;
    random1 = true;//yes default is random
    random2 = true;
    seqCount1 = 0;
    seqCount2 = 0;//
    seqCount1_int = 0;
    seqCount2_int = 0;
    
    srand(seedNum);
    for(int i = 0 ; i < 4 ; i++ ) {
        seqList1_int.emplace_back(rand() % 9 + 1);
    }//for player1
    for(int i = 0 ; i < 4 ; i++ ) {
        seqList2_int.emplace_back(rand() % 9 + 1);
    }//for player2
}

Level3::~Level3(){}

void Level3::addBlockSeq(std::string filename,int id){
    string s;
    if (id == 1){
        ifstream seq1{filename};
        while(seq1 >> s){
            string tb1 = s;
            seqList1.emplace_back(tb1);
        }
        random1 = false;
    }else {
        ifstream seq2{filename};
        while(seq2 >> s){
            string tb2 = s;
            seqList2.emplace_back(tb2);
        }
        random2 = false;
    }
}

shared_ptr<Block> Level3::GetBlock(std::shared_ptr<Player> p){
    shared_ptr<Block> b = nullptr;
    bool random = false;
    if ((p->id == 1) && random1) random = true;
    if ((p->id == 2) && random2) random = true;
    if(random){
        int rdmb = 1;
        //
        if(p->id == 1){
            if(seqCount1_int > seqList1_int.size() - 1){//reset
                seqCount1_int = 0;
            }
            rdmb = seqList1_int[seqCount1_int];
            ++seqCount1_int;
            
        } else {
            if(seqCount2_int > seqList2_int.size() - 1){//reset
                seqCount2_int = 0;
            }
            rdmb = seqList2_int[seqCount2_int];
            ++seqCount2_int;
        }
        //
        if (seedFree){
            random_device rd;
            mt19937 eng(rd());
            uniform_int_distribution<> distr(1,9);
            rdmb = distr(eng);
        }
        switch (rdmb){
            case 1: b = make_shared<LBlock>(); break;
            case 2: b = make_shared<IBlock>(); break;
            case 3: b = make_shared<OBlock>(); break;
            case 4: b = make_shared<JBlock>(); break;
            case 5: b = make_shared<TBlock>(); break;
            case 6: b = make_shared<SBlock>(); break;
            case 7: b = make_shared<SBlock>(); break;
            case 8: b = make_shared<ZBlock>(); break;
            case 9: b = make_shared<ZBlock>(); break;
        }
    }else{//random flag is false , we will not be random anymore!!!
        
        //we use that weird file for get block
        char s;
        if(p->id == 1){
            if(seqCount1 > seqList1.size() - 1){//reset
                seqCount1 = 0;
            }
            
            //cout << "This one is!" << seqList1[seqCount1] << endl;
            s = seqList1[seqCount1][0];
            ++seqCount1;
            
        } else {//p->id == 2
            if(seqCount2 > seqList2.size() - 1){//reset
                seqCount2 = 0;
            }
            s = seqList2[seqCount2][0];
            ++seqCount2;
        }
        switch(s){
            case 'J' : b = make_shared<JBlock>();break;
            case 'O' : b = make_shared<OBlock>();break;
            case 'L' : b = make_shared<LBlock>();break;
            case 'I' : b = make_shared<IBlock>();break;
            case 'S' : b = make_shared<SBlock>();break;
            case 'Z' : b = make_shared<ZBlock>();break;
            case 'T' : b = make_shared<TBlock>();break;
        }
    }
    return b;
}

void Level3::randomBack(int id ){
    if (id == 1){
        random1 = true;
    }else if (id == 2){
        random2 = true;
    }
    
}
////////////////////////////Level4//////////////////////////////

Level4::Level4(){
    level_num = 4;
    random1 = true;//yes default is random
    random2 = true;
    seqCount1 = 0;
    seqCount2 = 0;
    seqCount1_int = 0;
    seqCount2_int = 0;
    
    srand(seedNum);
    for(int i = 0 ; i < 4 ; i++ ) {
        seqList1_int.emplace_back(rand() % 9 + 1);
    }//for player1
    for(int i = 0 ; i < 4 ; i++ ) {
        seqList2_int.emplace_back(rand() % 9 + 1);
    }//for player2
    
}

Level4::~Level4(){};


void Level4::addBlockSeq(std::string filename,int id){
    string s;
    if (id == 1){
        ifstream seq1{filename};
        while(seq1 >> s){
            string tb1 = s;
            seqList1.emplace_back(tb1);
        }
        random1 = false;
    }else {
        ifstream seq2{filename};
        while(seq2 >> s){
            
            string tb2 = s;
            seqList2.emplace_back(tb2);
        }
        random2 = false;
    }
    
}


shared_ptr<Block> Level4::GetBlock(std::shared_ptr<Player> p){
    shared_ptr<Block> b = nullptr;
    bool random = false;
    if ((p->id == 1) && random1) random = true;
    if ((p->id == 2) && random2) random = true;
    if(random){
        int rdmb;
        //
        if(p->id == 1){
            if(seqCount1_int > seqList1_int.size() - 1){//reset
                seqCount1_int = 0;
            }
            rdmb = seqList1_int[seqCount1_int];
            ++seqCount1_int;
            
        } else {
            if(seqCount2_int > seqList2_int.size() - 1){//reset
                seqCount2_int = 0;
            }
            rdmb = seqList2_int[seqCount2_int];
            ++seqCount2_int;
        }
        //
        if (seedFree){
            random_device rd;
            mt19937 eng(rd());
            uniform_int_distribution<> distr(1,9);
            rdmb = distr(eng);
        }
        switch (rdmb){
            case 1: b = make_shared<LBlock>(); break;
            case 2: b = make_shared<IBlock>(); break;
            case 3: b = make_shared<OBlock>(); break;
            case 4: b = make_shared<JBlock>(); break;
            case 5: b = make_shared<TBlock>(); break;
            case 6: b = make_shared<SBlock>(); break;
            case 7: b = make_shared<SBlock>(); break;
            case 8: b = make_shared<ZBlock>(); break;
            case 9: b = make_shared<ZBlock>(); break;
                
        }
    }else{
        
        char s;
        if(p->id == 1){
            if(seqCount1 > seqList1.size() - 1){//reset
                seqCount1 = 0;
            }
            
            s = seqList1[seqCount1][0];
            ++seqCount1;
            
        } else {//p->id == 2
            if(seqCount2 > seqList2.size() - 1){//reset
                seqCount2 = 0;
            }
            s = seqList2[seqCount2][0];
            ++seqCount2;
        }
        switch(s){
            case 'J' : b = make_shared<JBlock>();break;
            case 'O' : b = make_shared<OBlock>();break;
            case 'L' : b = make_shared<LBlock>();break;
            case 'I' : b = make_shared<IBlock>();break;
            case 'S' : b = make_shared<SBlock>();break;
            case 'Z' : b = make_shared<ZBlock>();break;
            case 'T' : b = make_shared<TBlock>();break;
        }
    }
    return b;
    
}

void Level4::randomBack(int id ){
    if (id == 1){
        random1 = true;
    }else if (id == 2){
        random2 = true;
    }
    
}


////////////////////////////Level5//////////////////////////////

Level5::Level5(){
    level_num = 5;
    random1 = true;//yes default is random
    random2 = true;
    seqCount1 = 0;
    seqCount2 = 0;
    cout << "welcome to the secret level! "<< endl;
    seqCount1_int = 0;
    seqCount2_int = 0;
    
    srand(seedNum);
    for(int i = 0 ; i < 4 ; i++ ) {
        seqList1_int.emplace_back(rand() % 9 + 1);
    }//for player1
    for(int i = 0 ; i < 4 ; i++ ) {
        seqList2_int.emplace_back(rand() % 9 + 1);
    }//for player2
}

Level5::~Level5(){};


void Level5::addBlockSeq(std::string filename,int id){
    string s;
    if (id == 1){
        ifstream seq1{filename};
        while(seq1 >> s){
            string tb1 = s;
            seqList1.emplace_back(tb1);
        }
        random1 = false;
    }else{
        ifstream seq2{filename};
        while(seq2 >> s){
            string tb2 = s;
            seqList2.emplace_back(tb2);
        }
        random2 = false;
    }
    
}


shared_ptr<Block> Level5::GetBlock(std::shared_ptr<Player> p){
    shared_ptr<Block> b = nullptr;
    bool random = false;
    if ((p->id == 1) && random1) random = true;
    if ((p->id == 2) && random2) random = true;
    if(random){
        int rdmb = 1;
        //
        if(p->id == 1){
            if(seqCount1_int > seqList1_int.size() - 1){//reset
                seqCount1_int = 0;
            }
            rdmb = seqList1_int[seqCount1_int];
            ++seqCount1_int;
            
        } else {
            if(seqCount2_int > seqList2_int.size() - 1){//reset
                seqCount2_int = 0;
            }
            rdmb = seqList2_int[seqCount2_int];
            ++seqCount2_int;
        }
        //
        if (seedFree){
            random_device rd;
            mt19937 eng(rd());
            uniform_int_distribution<> distr(1,9);
            rdmb = distr(eng);
        }
        switch (rdmb){
            case 1: b = make_shared<LBlock>(); break;
            case 2: b = make_shared<IBlock>(); break;
            case 3: b = make_shared<OBlock>(); break;
            case 4: b = make_shared<JBlock>(); break;
            case 5: b = make_shared<TBlock>(); break;
            case 6: b = make_shared<SBlock>(); break;
            case 7: b = make_shared<XBlock>(); break;//new block
            case 8: b = make_shared<ZBlock>(); break;
            case 9: b = make_shared<CBlock>(); break;//new block
                
        }
    }else{
        
        char s;
        if(p->id == 1){
            if(seqCount1 > seqList1.size() - 1){//reset
                seqCount1 = 0;
            }
            
            
            s = seqList1[seqCount1][0];
            ++seqCount1;
            
        } else {//p->id == 2
            if(seqCount2 > seqList2.size() - 1){//reset
                seqCount2 = 0;
            }
            s = seqList2[seqCount2][0];
            ++seqCount2;
        }
        switch(s){
            case 'J' : b = make_shared<JBlock>();break;
            case 'O' : b = make_shared<OBlock>();break;
            case 'L' : b = make_shared<LBlock>();break;
            case 'I' : b = make_shared<IBlock>();break;
            case 'S' : b = make_shared<SBlock>();break;
            case 'Z' : b = make_shared<ZBlock>();break;
            case 'T' : b = make_shared<TBlock>();break;
            case 'X' : b = make_shared<XBlock>();break;//
            case 'C' : b = make_shared<CBlock>();break;//
        }
    }
    return b;
    
}

void Level5::randomBack(int id ){
    if (id == 1){
        random1 = true;
    }else if (id == 2){
        random2 = true;
    }
    
}
