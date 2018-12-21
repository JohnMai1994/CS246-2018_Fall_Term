#include <iostream>
#include "BasicBoard.hpp"
#include "LBlock.hpp"
#include "OBlock.hpp"
#include "JBlock.hpp"
#include "IBlock.hpp"
#include "SBlock.hpp"
#include "ZBlock.hpp"
#include "XBlock.hpp"
#include "CBlock.hpp"
#include "TBlock.hpp"
#include "StarBlock.hpp"
#include "BasicBoard.hpp"
#include "Board.hpp"
#include "cell.hpp"
#include "player.hpp"
#include "Level.hpp"

#include <cmath>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <memory>
#include <fstream>

#include "window.h"
#include "draw.h"

using namespace std;

string seqName1 = "sequence1.txt";
string seqName2 = "sequence2.txt";
string norstring;
string seqstring;
int seedNum = 888;//for seed, our initial number
bool seedFree = false;
bool sound = false;
bool specialOn = false;




int main(int argc, const char * argv[]) {
    
    //command-line interface*********************
    
    
    int startlevel = 0;//start level
    bool shortkey = false;
    BasicBoard b;
    
    if( argc > 1 ){
        for(int i = 1 ; i < argc ; i++){
            if(argv[i][0] == '-'){
                //-easy
                if(argv[i][1] == 'e'){
                    shortkey = true;
                }//we turn on a flag for short key
                
                //-text
                //runs the program in text-only mode
                if(argv[i][1] == 't'){
                    cout << "text only mode!" << endl;
                    b.IsText = true;
                }//end of text
                
                //-s
                if(argv[i][1] == 's'){
                    // -so.....
                    if (argv[i][2] == 'o') {
                       sound = true;
                    }
                    // -sp
                    if (argv[i][2] == 'p') {
                       specialOn = true;
                    }

                    //-sc
                    if(argv[i][2] == 'c'){
                        //scriptfile1
                        if(strncmp(argv[i],"-scriptfile1",12) == 0){
                            i++;
                            if ((i >= argc) || (argv[i][0] == '-')){
                                cout << "you forget to give me a filename!"<< endl;
                                i--;
                            }else{
                                seqName1 = argv[i];
                                cout << "we will find" << seqName1 << " seq for player1!" << endl;
                            }
                        }
                        //-scriptfile2
                        if(strncmp(argv[i],"-scriptfile2",12) == 0){
                            i++;
                            if ((i >= argc) || (argv[i][0] == '-')){
                                cout << "you forget to give me a filename!"<< endl;
                                i--;
                            }else{
                                seqName2 = argv[i];
                                cout << "we will find" << seqName2 << " seq for player2!" << endl;
                            }
                            
                        }
                    }
                    //-se
                    if(argv[i][2] == 'e'){
                        if(strncmp(argv[i],"-seed",5)){
                            i++;
                            if ((i >= argc) || (argv[i][0] < '0') ||(argv[i][0] > '9' )){
                                cout << "you forget to give a number for seed!"<< endl;
                                i--;
                            }else{
                                seedNum = stoi(argv[i]);
                            }
                        }
                        
                        else if(strncmp(argv[i],"-seedfree",5)){
                            i++;
                            seedFree = true;
                        }
                        
                    }//end of seed
                  
                    //-startlevel
                    if(argv[i][2] == 't'){
                        i++;
                        if ((i >= argc) || (argv[i][0] < '0') ||(argv[i][0] > '9' )){
                            cout << "you forget to give me a number for start level!"<< endl;
                            i--;
                        }else{
                            startlevel = stoi(argv[i]);
                            cout << "we will start the level from " << startlevel << endl;
                        }
                        
                    }//end of startlevel
                    
                }
                
                
            }//end of one command choose
            
        }//end of all of command choose
        
    }
    
    
    //
    
    Xwindow board(600, 550);;
    
    //Xwindow board1;
    //  board = Xwindow board(600, 550);
    drawMainBoard(board, sound);
    //default our players*********************
    
    string type;
    string command;
    
    
    
    //   Board * b = new BasicBoard();
    std::shared_ptr <Player>& player1 =b.GetPlayer1();
    std::shared_ptr <Player>& player2 =b.GetPlayer2();
    b.SetPlayer(player1, "John",1,startlevel);//we add id for level checkting
    b.SetPlayer(player2, "Yijian",2,startlevel);
    
    player1->CurBlock = player1->levptr->GetBlock(player1);
    player1->NextBlock = player1->levptr->GetBlock(player1);
    
    
    player2->CurBlock = player2->levptr->GetBlock(player2);
    player2->NextBlock = player2->levptr->GetBlock(player2);
    
    
    b.DrawBlock(player1, player1->row, player1->col);
    
    
    b.DrawBoard(player1, player2, &board);
    
    //all initial setting above
    //now we use NowPlayer() method to operate player's individual action
    
    
    
    //command interpreter*********************
    if (b.IsText){
        board.drawString(200, 250, "Enjoy your TEXT Biquadris!!", 1);
    }
    std::string cmdp;
    while (cin >> cmdp){
        std::vector<std::string> seqList;
        seqList.emplace_back("mapping");//the initial size will be 1

       if(cmdp == "sequence"){
           string comfile;
           cin >> comfile;
           ifstream comseq{comfile};
           string s;
           while(comseq >> s){
               string tb = s;
               seqList.emplace_back(tb);
           }

       }else{
           seqList.emplace_back(cmdp);
       }
        
        // _the_ real_ command
    while(seqList.size() != 1){
        string cmd = seqList[seqList.size() - 1];
        
        //deal the case with numbers!
        
        int num = -888;//which will be our error number
        
        int i = 0;
        if((cmd[0] <= '9')&&(cmd[0] >= '0')) num = 0;//we reset 0
        for(; ((cmd[i] <= '9')&&(cmd[i] >= '0')); i++){
            //then we change our num
            num =  num + stoi(string(1,cmd[0])) * pow( 10 , i);
            
        }
        string temp = "";
        int len = cmd.length();
        for(;i < len ;i++){
            temp = temp + cmd[i];
        }
        cmd = temp;
        
        // cout << "our num is "<< num << endl;
        // cout << "and our command is" << num << endl;
        
        
        //
        
        b.KillLiveCell(player1);
        b.KillLiveCell(player2);
        
        std::string contin;
        if (!b.GameOver (player1)){
            cout << "Player1's game is over" << endl;
            cout << "Do you want to restart?, yes or no" << endl;
            
            cin >> contin;
            if (contin == "yes") {
               b.Restart(b.NowPlayer(), b.OtherPlayer());
               b.NowPlayer()->CurBlock = b.NowPlayer()->levptr->GetBlock(player1);
               b.NowPlayer()->NextBlock = b.NowPlayer()->levptr->GetBlock(player1);
               b.OtherPlayer()->CurBlock = b.OtherPlayer()->levptr->GetBlock(player2);
               b.OtherPlayer()->NextBlock = b.OtherPlayer()->levptr->GetBlock(player2);
	       cmd = " ";
            } else {
               break;
            }
        }
        if (!b.GameOver (player2)){
            cout << "Player2's game is over" << endl;
            cout << "Do you want to restart?yes or no" << endl;
            
            cin >> contin;
            if (contin == "yes") {
               b.Restart(b.NowPlayer(), b.OtherPlayer());
               b.NowPlayer()->CurBlock = b.NowPlayer()->levptr->GetBlock(player1);
               b.NowPlayer()->NextBlock = b.NowPlayer()->levptr->GetBlock(player1);
               b.OtherPlayer()->CurBlock = b.OtherPlayer()->levptr->GetBlock(player2);
               b.OtherPlayer()->NextBlock = b.OtherPlayer()->levptr->GetBlock(player2);
 	       cmd = " ";
            } else {
               break;
            }
        }
        
        
        //down - s
        //right - a
        //left - d
        //cw - q
        //ccw - e
        //drop - ' '
        if (shortkey){
            // for veverse function
            if (b.NowPlayer()->reverse) {
                if (cmd == "d") {
                    cmd = "a";
                } else if (cmd == "a"){
                    cmd = "d";
                }
            }
            // for veverse function
            
            if(cmd == "d"){//right
                if(num < 0) num = 1;
                while(num != 0){
                    b.right(b.NowPlayer());
                    b.update(b.NowPlayer());
                    
                    b.LevelHeavy(b.NowPlayer());
                    b.BlockHeavy(b.NowPlayer());
                    num--;
                }
            }
            if(cmd == "a"){//left
                if(num < 0) num = 1;
                while(num != 0){
                    b.left(b.NowPlayer());
                    b.update(b.NowPlayer());
                    
                    b.LevelHeavy(b.NowPlayer());
                    b.BlockHeavy(b.NowPlayer());
                    num--;
                }
            }
            if(cmd == "s"){//down
                if (num < 0) num = 1;
                for(;num > 0;num--){
                    b.update(b.NowPlayer());
                    b.down(b.NowPlayer());
                    
                    b.update(b.NowPlayer());
                }
            }
            if(cmd == "q"){//cw
                if(num < 0) num = 1;
                for(;num > 0;num--){
                    if (b.NowPlayer()->cwPossible){
                        b.NowPlayer()->CurBlock->CW();
                    }
                    b.SetPossibles();
                    b.update(b.NowPlayer());
                }
            }
            if(cmd == "e"){//ccw
                
                if(num < 0) num = 1;
                for(;num > 0;num--){
                    if (b.NowPlayer()->ccwPossible){
                        b.NowPlayer()->CurBlock->CCW();
                    }
                    b.SetPossibles();
                    b.update(b.NowPlayer());
                }
            }
            if(cmd == "ss"){//drop
                b.drop(b.NowPlayer());
                
                b.LevelHeavy(b.NowPlayer());
                b.BlockHeavy(b.NowPlayer());
            }
        }
        
        
        //a
        //b
        //c
        if(cmd[0] == 'c'){
            //clockwise and counterclockwise
            
            if(cmd.length() > 1){//clockwise
                if(cmd[1] == 'c'){//ccw
                    if(num < 0) num = 1;
                    for(;num > 0;num--){
                        if (b.NowPlayer()->ccwPossible){
                            b.NowPlayer()->CurBlock->CCW();
                        }
                        b.SetPossibles();
                        b.update(b.NowPlayer());
                        
                    }
                }
                if(cmd[1] == 'l'){//clockwise
                    if(num < 0) num = 1;
                    for(;num > 0;num--){
                        if (b.NowPlayer()->cwPossible){
                            b.NowPlayer()->CurBlock->CW();
                        }
                        b.SetPossibles();
                        b.update(b.NowPlayer());
                        
                    }
                }
                //we also have cw for clockwise and ccw for counterclockwise
                
                if(cmd[1] == 'o'){//counterclockwise
                    if(num < 0) num = 1;
                    for(;num > 0;num--){
                        if (b.NowPlayer()->ccwPossible){
                            b.NowPlayer()->CurBlock->CCW();
                        }
                        b.SetPossibles();
                        b.update(b.NowPlayer());
                        
                    }
                }
                if(cmd[1] == 'w'){//cw
                    if(num < 0) num = 1;
                    for(;num > 0;num--){
                        if (b.NowPlayer()->cwPossible){
                            b.NowPlayer()->CurBlock->CW();
                        }
                        b.SetPossibles();
                        b.update(b.NowPlayer());
                        
                    }
                }
            }
        }
        //d
        if(cmd[0] == 'd'){
            //down
            //drop
            // if(cmd.length() > 4) break;
            
            if(cmd.length() > 1){
                if(cmd[1] == 'o'){//down
                    if (num < 0) num = 1;
                    for(;num > 0;num--){
                        b.update(b.NowPlayer());
                        b.down(b.NowPlayer());
                        
                        b.update(b.NowPlayer());
                        
                    }
                }
                if(cmd[1] == 'r'){//drop
                    b.drop(b.NowPlayer());
                      
                }
            }
        }
        
        // for reverse function
        if (b.NowPlayer()->reverse) {
            if ((cmd[0] == 'l')&&(cmd[2] == 'f')) {
                cmd = "right";
            } else if ((cmd[0] == 'r')&&(cmd[1] == 'i')){
                cmd = "left";
            }
        }
        
        // for reverse function
        
        
        //e
        //f
        //g
        //h
        //i
        //j
        //k
        //l
        if(cmd[0] == 'l'){
            //left
            //levelup
            //leveldown
            // if(cmd.length() > 9) break;
            
            if(cmd.length() > 2){
                if(cmd[2] == 'f'){
                    if(num < 0) num = 1;
                    while(num != 0){
                        b.left(b.NowPlayer());
                        b.update(b.NowPlayer());
                        
                        b.LevelHeavy(b.NowPlayer());
                        b.BlockHeavy(b.NowPlayer());
                        num--;
                    }
                }
                if(cmd.length() > 5){
                    if(cmd[5] == 'u'){//levelup
                        if(num < 0) num = 1;
                        while(num != 0){
                            b.LevelUp(b.NowPlayer());
                            num--;
                        }
                    }
                    if(cmd[5] == 'd'){//leveldown
                        if(num < 0) num = 1;
                        while(num != 0){
                            b.LevelDown(b.NowPlayer());
                            num--;
                        }
                    }
                }
            }
        }
        //m
        //n
        if(cmd[0] == 'n'){
            //norandom + file
            //  if(cmd.length() > 8) break;
            if( cin >> norstring){
                if((b.NowPlayer()->level == 0)||(b.NowPlayer()->level == 1)||(b.NowPlayer()->level == 2)){
                    cout << "only level 3 and level 4 can norandom!!" << endl;
                }else{//yes now we do this
                    cout << "we will find" << norstring << " for testing!" <<endl;
                    b.NowPlayer()->levptr->addBlockSeq(norstring,b.NowPlayer()->id);
                }
            }
        }
        //o
        //p
        //q
        //r
        if(cmd[0] == 'r'){
            //random
            //restart
            //right
            // if(cmd.length() > 7) break;
            
            if(cmd.length() > 1){
                if(cmd[1] == 'a'){
                    //random
                    if((b.NowPlayer()->level == 0)||(b.NowPlayer()->level == 1)||(b.NowPlayer()->level == 2)){
                        cout << "only level 3 and level 4 can random back!!" << endl;
                    }else{//yes now we do this
                        
                        b.NowPlayer()->levptr->randomBack(b.NowPlayer()->id);
                        
                    }
                }
                if(cmd[1] == 'e'){
                    b.Restart(b.NowPlayer(), b.OtherPlayer());
                    b.NowPlayer()->CurBlock = b.NowPlayer()->levptr->GetBlock(player1);
                    b.NowPlayer()->NextBlock = b.NowPlayer()->levptr->GetBlock(player1);
                    b.OtherPlayer()->CurBlock = b.OtherPlayer()->levptr->GetBlock(player2);
                    b.OtherPlayer()->NextBlock = b.OtherPlayer()->levptr->GetBlock(player2);
                    cout << "we can restart" << endl;
                }
                if(cmd[1] == 'i'){
                    //right
                    if(num < 0) num = 1;
                    while(num != 0){
                        b.right(b.NowPlayer());
                        b.update(b.NowPlayer());
                        
                        b.LevelHeavy(b.NowPlayer());
                        b.BlockHeavy(b.NowPlayer());
                        num--;
                    }
                }
            }
        }
        //s
        if(cmd[0] == 's'){
            //sequence + file
            if(cmd[1] == 'e'){
                if(cin >> seqstring){
                    cout << "we sequence" << seqstring << " something" << endl;
                }
            }
        }
        //t
        //u
        //v
        //w
        //x
        //y
        //z
        
        //for some random testing
        if(cmd == "I"){
            b.NowPlayer()->CurBlock = make_shared<IBlock>();
        }
        if(cmd == "J"){
            b.NowPlayer()->CurBlock = make_shared<JBlock>();
        }
        if(cmd == "L"){
            b.NowPlayer()->CurBlock = make_shared<LBlock>();
        }
        if(cmd == "O"){
            b.NowPlayer()->CurBlock = make_shared<OBlock>();
        }
        if(cmd == "S"){
            b.NowPlayer()->CurBlock = make_shared<SBlock>();
        }
        if(cmd == "Z"){
            b.NowPlayer()->CurBlock = make_shared<ZBlock>();
        }
        if (cmd == "T"){
            b.NowPlayer()->CurBlock = make_shared<TBlock>();
        }
        if (cmd == "X"){
            b.NowPlayer()->CurBlock = make_shared<XBlock>();
        }
        if (cmd == "C"){
            b.NowPlayer()->CurBlock = make_shared<CBlock>();
        }
        
        
        
        
        if(b.DrawBlock(b.NowPlayer(), b.NowPlayer()->row, b.NowPlayer()->col))  {
            b.NowPlayer()->NextBlock  = b.NowPlayer()->levptr->GetBlock(b.NowPlayer());
            int clear_rows = b.Recalculate(b.NowPlayer(), sound);//
            if (clear_rows >= 2) {
                std::string cmd2;
                cout << "Which Punishment you want to choice? heavy or blind or force or reverse";
                
                cout << endl;
                while (cin >> cmd2) {
                    if (cmd2 == "heavy") {
                        b.OtherPlayer()->heavy = true;
                        break;
                    } else if (cmd2 == "blind") {
                        b.Blind (b.OtherPlayer());
                        break;
                    }else if( cmd2 == "force"){
                        cout << "which block? "<< endl;
                        char tempblock;
                        cin >> tempblock;
                        b.ChangeTurn();//we switch player for now
                        shared_ptr<Block> bk = nullptr;
                        switch(tempblock){
                            case 'J' : bk = make_shared<JBlock>();break;
                            case 'O' : bk = make_shared<OBlock>();break;
                            case 'L' : bk = make_shared<LBlock>();break;
                            case 'I' : bk = make_shared<IBlock>();break;
                            case 'S' : bk = make_shared<SBlock>();break;
                            case 'Z' : bk = make_shared<ZBlock>();break;
                            case 'T' : bk = make_shared<TBlock>();break;
			    case 'C' : bk = make_shared<CBlock>();break;
                            case 'X' : bk = make_shared<XBlock>();break;
                        }
                        //   Block* del = b.NowPlayer()->CurBlock;
                        b.NowPlayer()->CurBlock = bk;
                        //  delete del;
                        b.ChangeTurn();//and we switch back
                        break;
                        //end of force
                    } else if (cmd2 == "reverse") {
                        cout << "Hahaha you re going die!!!" << endl;
                        b.OtherPlayer()->reverse = true;
                        break;
                    } else {
                        continue;
                    }
                }
            }
            
            b.ChangeTurn();//
        }//end  of punishment
        
        //we set the punish
        if (b.NowPlayer()->staron){//here is the * punishment
            if(b.NowPlayer()->notclear == 5){
                shared_ptr<Block> startemp = b.NowPlayer()->CurBlock;
                b.NowPlayer()->CurBlock = make_shared<StarBlock>();
                
                b.right(b.NowPlayer());
                b.right(b.NowPlayer());
                
                b.drop(b.NowPlayer());
                
                b.update(b.NowPlayer());
                
                b.Recalculate(b.NowPlayer(), sound);
                b.DrawBlock(b.NowPlayer(), b.NowPlayer()->row, b.NowPlayer()->col);
                b.DrawBoard(player1, player2, &board);
                
                
                b.NowPlayer()->CurBlock = startemp;//
                b.NowPlayer()->notclear = 0;//we reset
            }
        }//end of *
        
        b.Recalculate(b.NowPlayer(), sound);
        
        b.DrawBlock(b.NowPlayer(), b.NowPlayer()->row, b.NowPlayer()->col);
        b.DrawBoard(player1, player2, &board);
        
          seqList.pop_back();
    }//end of command loop
        
    

      
    }//end of the real command loop
    
    
    return 0;
}





