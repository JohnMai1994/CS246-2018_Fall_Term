#include "BasicBoard.hpp"
#include "player.hpp"
#include <iostream>
#include <string>

extern bool specialOn;


using namespace std;

BasicBoard::BasicBoard () {
    player1 = shared_ptr <Player> (new Player);
    player2 = shared_ptr <Player> (new Player);
}

BasicBoard::~BasicBoard(){
}


// ********************** initialization **********************
void BasicBoard::SetPlayer(std::shared_ptr <Player> &player, string playername,int id,int level){
    
    player->PlayField.resize(15);
    for (int row = 0; row < 15; row++) {
        player->PlayField[row].resize(11);
        for (int col = 0; col < 11; col++) {
            player->PlayField[row][col] = Cell();
        }
    }
    //for level
    if (level == 0){
        player->levptr = unique_ptr <Level> (new Level0);
    }else if (level == 1){
        player->levptr = unique_ptr <Level> (new Level1);
    }else if (level == 2){
        player->levptr= unique_ptr <Level> (new Level2);
    }else if (level == 3){
        player->levptr= unique_ptr <Level> (new Level3);
    }else if (level == 4){
        player->levptr= unique_ptr <Level> (new Level4);
    }else if (level == 5){
        if (specialOn) player->levptr= unique_ptr <Level> (new Level5);
        else player->levptr= unique_ptr <Level> (new Level4);
    }
    
    //end for level
    
    player->id = id;//identify for player1 or player2
    
    player->CurBlock = nullptr;
    player->NextBlock = nullptr;
    player->name = playername;
    player->Score = 0;
    player->level = level;
    player->IsAlive = true;
    player->SpeAttack = 0;
    player->col = 0;
    player->row = 0;
    player->LeftPossible = true;
    player->RightPossible = true;
    player->DownPossible = true;
    player->cwPossible = true;
    player->ccwPossible = true;
    
    // this para to solve the second down
    player->cant_down = 0;
    
    // here is for set the player block number
    player->IBlock = 0;
    player->JBlock = 0;
    player->LBlock = 0;
    player->OBlock = 0;
    player->SBlock = 0;
    player->TBlock = 0;
    player->ZBlock = 0;
    
    // for Heavy function
    player->heavy = false;
    player->reverse = false;
}





// ********************** Get Private Field from board ********************** (it could be delete, no use)
std::shared_ptr <Player>& BasicBoard::GetPlayer1(){
    return player1;
    
}

std::shared_ptr <Player>& BasicBoard::GetPlayer2(){
    return player2;
}





// ********************** Get Private Field from player **********************
int BasicBoard::GetCurScore(std::shared_ptr <Player>& player){
    return player->Score;
}




std::string NumToString(int num){
    std::string temp = "";
    if(num == 0){
        temp = "0";
    }else{
        while(num != 0){
            int con = num % 10;
            switch (con){
                case 1: temp = temp + "1"; break;
                case 2: temp = temp + "2"; break;
                case 3: temp = temp + "3"; break;
                case 4: temp = temp + "4"; break;
                case 5: temp = temp + "5"; break;
                case 6: temp = temp + "6"; break;
                case 7: temp = temp + "7"; break;
                case 8: temp = temp + "8"; break;
                case 9: temp = temp + "9"; break;
                case 0: temp = temp + "0"; break;
            }
            num = num / 10;
        }
    }
    return temp;
}

// ********************** Draw the whole Board **********************
// I add a Xwindow pointer here!!!
void BasicBoard::DrawBoard(std::shared_ptr <Player>& player1, std::shared_ptr <Player>& player2, Xwindow * board){
    int temp_col = 0;
    cout << "Level:    " << player1->level << "     " << "Level:    " << player2->level << endl;
    cout << "Score:    " << player1->Score << "     " << "Score:    " << player2->Score << endl;
    cout << "High :    " << player1->High << "     " << "High :    " << player2->High << endl;
    if (!IsText){
        board->fillRectangle(0,0,600,30,10);
        board->drawString(5, 25, "Level:", 1);
        string levelStr1 = NumToString(player1->level);
        board->drawString(55, 25, levelStr1, 1);
        
        board->drawString(100, 25, "Score:", 1);
        string scoreStr1 = NumToString(player1->Score);
        board->drawString(150, 25, scoreStr1, 1);
        
        board->drawString(200, 25, "High:", 1);
        string highStr1 = NumToString(player1->High);
        board->drawString(250, 25, highStr1, 1);
        
        board->drawString(330, 25, "Level:", 1);
        string levelStr2 = NumToString(player2->level);
        board->drawString(380, 25, levelStr2, 1);
        
        board->drawString(425, 25, "Score:", 1);
        string scoreStr2 = NumToString(player2->Score);
        board->drawString(475, 25, scoreStr2, 1);
        
        board->drawString(525, 25, "High:", 1);
        string highStr2 = NumToString(player2->High);
        board->drawString(575, 25, highStr2, 1);
    }
    
    cout << "-----------     -----------" << endl;
    if (!IsText){
        board->drawLine(0, 50, 265, 50);
        board->drawLine(350, 50, 600, 50);
    }
    for (int row = 0; row < 15; row++) {
        
        for (int col1 = 0; col1 < 11; col1++) {
            cout << player1->PlayField[row][col1];
            if (!IsText){
                player1->PlayField[row][col1].draw(col1, row+2, board);
                temp_col = col1;
            }
            
        }
        cout << "     ";
        //board->fillRectangle((temp_col+200), row *25, 25, 25, 7);
        for (int col2 = 0; col2 < 11; col2++) {
            cout << player2->PlayField[row][col2];
            if (!IsText){
                player2->PlayField[row][col2].draw(col2+temp_col+3, row+2, board);
            }
        }
        cout << endl;
        
        if ((row+1) == 15){
            cout << "-----------     -----------" << endl;
            cout << "Next:           Next:      " << endl;
            if (!IsText){
                board->drawString(5, 440, "Next:", 1);
                board->drawString(330, 440, "Next:", 1);
            }
        }
        
    }
    if (!IsText){
        for (int i = 18; i < 30; ++i){
            for (int j = 0; j < 24; ++j){
                board->fillRectangle(j*25, i*25, 25, 25, 7);
            }
            // DrawNextBlock(player1, player2, board);
        }
    }
    
    DrawNextBlock(player1, player2, board);
}




bool BasicBoard::DrawBlock(std::shared_ptr <Player>& player, int x, int y){
    int block_row = 5;
    int block_col = 4;
    int board_row = 15;
    int board_col = 11;
    bool ava = CellsAva(player, x, y);
    vector <vector <string>> v = player->CurBlock->getBlock();
    
    
    for (int row = 0; row < block_row; ++ row) {
        for (int col = 0; col < block_col; ++ col) {
            int new_row = row + x;
            int new_col = col + y;
            string color = v[row][col];
            if ((new_col >= board_col)||(new_row >= board_row)||(color == " ")) {
                continue;
            }
            else {
                if (player->cant_down == 1) {
                    player->PlayField[new_row][new_col].TurnOff(color);
                    continue;
                }
                if (ava){
                    player->PlayField[new_row][new_col].TurnOn(color);
                }
            }
        }
    }
    // return a bool to tell to change the block
    if (player->cant_down == 1) {
        player->cant_down = 0;
        player->col = 0;
        player->row = 0;
        player->CurBlock = player->NextBlock;
        player->RightPossible = true;
        player->LeftPossible = true;
        player->DownPossible = true;
        player->cwPossible = true;
        player->ccwPossible = true;
        return true;
    }
    return false;
}



void BasicBoard::DrawNextBlock(std::shared_ptr <Player>& player1, std::shared_ptr <Player>& player2, Xwindow * board){
    std::shared_ptr<Block> py1 = player1->NextBlock;
    std::shared_ptr<Block> py2 = player2->NextBlock;
    vector<vector<string>> b1 = py1->getBlock();
    vector<vector<string>> b2 = py2->getBlock();
    
    for (int i = 2; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << b1[i][j];
            if (!IsText){
                if (b1[i][j] != " "){

                   if (b1[i][j] == "I") {
                      board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 2);
                   } else if (b1[i][j] == "J"){
                      board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 3);
                   } else if (b1[i][j] == "L"){
                      board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 4);
                   } else if (b1[i][j] == "Z"){
                      board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 5);
                   } else if (b1[i][j] == "S"){
                      board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 9);
                   } else if (b1[i][j] == "O"){
                      board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 15);
                   } else if (b1[i][j] == "T"){
                      board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 8);
                   } else if (b1[i][j] == "C"){
                      board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 10);
                   } else if (b1[i][j] == "X"){
                      board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 11);
                   }

                }
            }
        }
        cout << "            ";
        for (int j = 0; j < 4; ++j){
            cout << b2[i][j];
            if (!IsText){
                if (b2[i][j] != " "){
                   if (b2[i][j] == "I") {
                      board->fillRectangle((16+j)*25, (16+i)*25, 25, 25, 2);
                   } else if (b2[i][j] == "J"){
                      board->fillRectangle((16+j)*25, (16+i)*25, 25, 25, 3);
                   } else if (b2[i][j] == "L"){
                      board->fillRectangle((16+j)*25, (16+i)*25, 25, 25, 4);
                   } else if (b2[i][j] == "Z"){
                      board->fillRectangle((16+j)*25, (16+i)*25, 25, 25, 5);
                   } else if (b2[i][j] == "S"){
                      board->fillRectangle((16+j)*25, (16+i)*25, 25, 25, 9);
                   } else if (b2[i][j] == "O"){
                      board->fillRectangle((16+j)*25, (16+i)*25, 25, 25, 15);
                   } else if (b2[i][j] == "T"){
                      board->fillRectangle((16+j)*25, (16+i)*25, 25, 25, 8);
                   } else if (b2[i][j] == "C"){
                      board->fillRectangle((16+j)*25, (16+i)*25, 25, 25, 10);
                   } else if (b2[i][j] == "X"){
                      board->fillRectangle((16+j)*25, (16+i)*25, 25, 25, 11);
                   }

                }
            }
        }
        cout << endl;
    }
    
}



// helper function of DrawBlock
bool BasicBoard::CellsAva (std::shared_ptr <Player>& player, int x, int y){
    int block_row = 5;
    int block_col = 4;
    int board_row = 15;
    int board_col = 11;
    vector <vector <string>> v = player->CurBlock->getBlock();
    for (int row = 0; row < block_row; ++ row) {
        for (int col = 0; col < block_col; ++ col) {
            int new_row = row + x;
            int new_col = col + y;
            string color = v[row][col];
            if ((new_col >= board_col)||(new_row >= board_row)||(color == " ")) {
                continue;
            }
            else if (player->PlayField[new_row][new_col].GetColor() != " "){
                return false;
                break;
            }
        }
    }
    return true;
}





// ********************** switch player **********************

std::shared_ptr <Player>& BasicBoard::NowPlayer(){
    if (turn){
        return player1;
    }else{
        return player2;
    }
}

std::shared_ptr <Player>& BasicBoard::OtherPlayer(){
    if (turn){
        return player2;
    }else{
        return player1;
    }
}



void BasicBoard::ChangeTurn(){
    turn = !turn;
}





// ********************** Left, Right, Down, Drop, CW, CCW**********************
void BasicBoard::left(std::shared_ptr <Player>& player){
    int player_col = player->col;
    if ((player_col > 0)&&(player->LeftPossible)){
        
        player->col -= 1;
        player->RightPossible = true;
        player->DownPossible = true;
    }
    else {
        player->RightPossible = true;
        player->LeftPossible = true;
        player->DownPossible = true;
    }
    player->cwPossible = true;
    player->ccwPossible = true;
}



void BasicBoard::right(std::shared_ptr <Player>& player){
    int player_col = player->col;
    int require_col = 0;
    int board_col = 11;
    for (int row = 0; row < 5; ++ row) {
        for (int col = 0; col < 4; ++col) {
            vector <vector <string>> v = player->CurBlock->getBlock();
            if ((v[row][col] != " ")&&(col > require_col)) {
                require_col = col;
            }
        }
    }
    
    
    if ((player_col + require_col + 2 <= board_col) && (player->RightPossible)) {
        
        player->col += 1;
        player->LeftPossible = true;
        player->DownPossible = true;
        
    }
    else if (!player->RightPossible) {
        player->RightPossible = true;
        player->LeftPossible = true;
        player->DownPossible = true;
    }
    player->cwPossible = true;
    player->ccwPossible = true;
}



void BasicBoard::down(std::shared_ptr <Player>& player){
    int player_row = player->row;
    if (!player->DownPossible) {
        ++player->notclear;//
        //  cout << "can't down" << endl;
        player->cant_down += 1;
        for (int i = 0; i < 15; ++i){
            for (int j = 0; j < 11; ++j){
                player->PlayField[i][j].NotBlind();
            }
        }
    }
    
    if ((player_row < 15)&&(player->DownPossible)){
        player->row += 1;
        player->RightPossible = true;
        player->LeftPossible = true;
    } else {
        player->RightPossible = true;
        player->LeftPossible = true;
        player->DownPossible = true;
    }
    player->cwPossible = true;
    player->ccwPossible = true;
    
};



void BasicBoard::drop(std::shared_ptr <Player>& player) {
    while (player->cant_down == 0) {
        update(player);
        down(player);
        update(player);
    }
}



void BasicBoard::cwpossible(std::shared_ptr <Player>& player){
    int x = player->row;
    int y = player->col;
    int block_row = 5;
    int block_col = 4;
    int board_row = 15;
    int board_col = 11;
    shared_ptr<Block>copy = player->CurBlock->Aclone();
    copy->CW();
    string BlockType = copy->GetType();
    
    for (int row = 0; row < block_row; ++ row) {
        for (int col = 0; col < block_col; ++ col) {
            
            int new_row = row + x;
            int new_col = col + y;
            if ((new_col >= 11) && (BlockType == "I")){
                player->cwPossible = false;
                break;
            }
            if ((new_col > 11) && (BlockType != "I")){
                player->cwPossible = false;
                break;
            }
            
            //heap copy the block and cw rotate it *************
            vector <vector <string>> v_copy = copy->getBlock();
            string cwcolor = v_copy[row][col];
            //
            
            //ignore white space
            if ((new_col >= board_col)||(new_row >= board_row)||(cwcolor == " ")) {
                continue;
            }
            //cw checkingcw
            
            if (player->PlayField[new_row][new_col].GetColor() != " "){
                player->cwPossible = false;
                break;
            }
        }
    }
}



void BasicBoard::ccwpossible(std::shared_ptr <Player>& player){
    int x = player->row;
    int y = player->col;
    int block_row = 5;
    int block_col = 4;
    int board_row = 15;
    int board_col = 11;
    shared_ptr<Block>copy = player->CurBlock->Aclone();
    copy->CCW();
    string BlockType = copy->GetType();
    
    for (int row = 0; row < block_row; ++ row) {
        for (int col = 0; col < block_col; ++ col) {
            
            int new_row = row + x;
            int new_col = col + y;
            if ((new_col >= 11) && (BlockType == "I")){
                player->ccwPossible = false;
                break;
            }
            if ((new_col > 11) && (BlockType != "I")){
                player->ccwPossible = false;
                break;
            }
            
            //heap copy the block and cw rotate it *************
            vector <vector <string>> v_copy = copy->getBlock();
            string cwcolor = v_copy[row][col];
            //
            
            //ignore white space
            if ((new_col >= board_col)||(new_row >= board_row)||(cwcolor == " ")) {
                continue;
            }
            //cw checkingcw
            
            
            
            if (player->PlayField[new_row][new_col].GetColor() != " "){
                player->ccwPossible = false;
                break;
            }
        }
    }
}



// initialize all possible
void BasicBoard::SetPossibles () {
    player1->DownPossible = true;
    player1->RightPossible = true;
    player1->LeftPossible = true;
    player2->DownPossible = true;
    player2->RightPossible = true;
    player2->LeftPossible = true;
}



// update all possible
void BasicBoard::update(std::shared_ptr <Player>& player){
    int x = player->row;
    int y = player->col;
    int block_row = 5;
    int block_col = 4;
    int board_row = 15;
    int board_col = 11;
    int check_row = 0;
    vector <vector <string>> v = player->CurBlock->getBlock();
    
    for (int row = 0; row < block_row; ++ row) {
        check_row = 0;    // reset check_row
        for (int col = 0; col < block_col; ++ col) {
            int new_row = row + x;
            int new_col = col + y;
            string color = v[row][col];
            if ((new_col >= board_col)||(new_row >= board_row)||(color == " ")) {
                continue;
            }
            else {
                if ((new_col+1 > 10)||(player->PlayField[new_row][new_col+1].GetColor() != " ")){
                    player->RightPossible = false;
                }
                //cout << "it pass right possible" << endl;
                if (check_row == 0) {
                    check_row += 1;
                    if ((new_col -1 < 0)|| (player->PlayField[new_row][new_col-1].GetColor() != " ")){
                        player->LeftPossible = false;
                    }
                }
                //cout << "it pass left possible" << endl;
                
                if ((new_row+1 >= 15) || (player->PlayField[new_row+1][new_col].GetColor() != " ")){
                    player->DownPossible = false;
                }
                //cout << "it pass down possible" << endl;
                
                
                
                
            }
        }
    }
    
    cwpossible(player);
    //cout << "it pass cw possible" << endl;
    ccwpossible(player);
    //cout << "it pass ccw possible" << endl;
    /*
     cout << "leftpossible: " << player->LeftPossible << endl;
     cout << "rightpossible: " << player->RightPossible << endl;
     cout << "downpossible: " << player->DownPossible << endl;
     cout << "cwpossible: " << player->cwPossible << endl;
     cout << "ccwpossible: " << player->ccwPossible << endl;
     */
    
}

// ********************** clean line **********************
int BasicBoard::Recalculate(std::shared_ptr <Player>& player, bool sound) {
    vector < int > clean_row;
    for (int row = 14; row > 0 ; row-- ) {
        int num_dead_cell = 0;
        for (int col = 0; col < 11; ++col) {
            if (player->PlayField[row][col].GetColor() == " ") {
                continue;
            }
            else if ((!player->PlayField[row][col].IsAlive())&&(player->PlayField[row][col].GetColor() != " ")) {
                num_dead_cell += 1;
            }
            // cout << "num_dead_cell: "<<num_dead_cell << endl;  // it is fine
            if (num_dead_cell == 11) {
                clean_row.push_back(row);
                
            }
        }
    }
    // for scoring
    int a = clean_row.size();
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < 11; ++j) {
            string color = player->PlayField[clean_row[i]][j].GetColor();
            if (color == "I") {
                player->IBlock += 1;
            } else if (color == "J") {
                player->JBlock += 1;
            } else if (color == "L") {
                player->LBlock += 1;
            } else if (color == "O") {
                player->OBlock += 1;
            } else if (color == "S") {
                player->SBlock += 1;
            } else if (color == "T") {
                player->TBlock += 1;
            } else if (color == "Z") {
                player->ZBlock += 1;
            }
        }
    }
    
    
    
    if (clean_row.size() != 0) {
        ClearLine(player, clean_row, sound);
    }
    return a;
}



void BasicBoard::ClearLine(std::shared_ptr <Player>& player,  vector< int > & clean_row, bool sound){
    vector < vector < Cell> > new_PlayField;
    int num_clean_row = clean_row.size();
    int x = 0;
    new_PlayField.resize(15);
    
    for (int row = 0; row < num_clean_row; row++) {
        new_PlayField[row].resize(11);
        for (int col = 0; col < 11; col++) {
            new_PlayField[row][col] = Cell();
            
        }
    }
    
    
    for (int row = 0; row < 15; row++) {
        if (row + x >= 15) {
            break;
        }
        
        if (clean_row.back() == row ) {
            clean_row.pop_back();
            x += 1;
            continue;
        } else {
            new_PlayField[row + num_clean_row - x].resize(11);
            
            
            for (int col = 0; col < 11; col++) {
                new_PlayField[row + num_clean_row - x][col] = player->PlayField[row][col];
            }
        }
    }
    
    
    
    int add_score = (num_clean_row + player->level)*(num_clean_row + player->level);
    //cout << add_score << endl;
    
    if ((player->IBlock != 0)&&(player->IBlock % 4 == 0)) {
        add_score += 1;
    }
    if ((player->JBlock != 0)&&(player->JBlock % 4 == 0)) {
        add_score += 1;
    }
    if ((player->LBlock != 0)&&(player->LBlock % 4 == 0)) {
        add_score += 1;
    }
    if ((player->OBlock != 0)&&(player->OBlock % 4 == 0)) {
        add_score += 1;
    }
    if ((player->SBlock != 0)&&(player->SBlock % 4 == 0)) {
        add_score += 1;
    }
    if ((player->TBlock != 0)&&(player->TBlock % 4 == 0)) {
        add_score += 1;
    }
    
    cout << add_score << endl;
    player->IBlock = 0;
    player->JBlock = 0;
    player->LBlock = 0;
    player->OBlock = 0;
    player->SBlock = 0;
    player->TBlock = 0;
    
    player->PlayField = new_PlayField;
    player->Score += add_score;
    if (player->High < player->Score) {
        player->High = player->Score;
    }
}

// ********************** Level UP and Down **********************
void BasicBoard::LevelUp(std::shared_ptr <Player>& player){
    int le = player->level + 1;
    
    if(le == 1) {
        //unique_ptr <Level> temp = player->levptr;
        player->levptr= unique_ptr <Level> (new Level1);
        player->level = 1;
        player->staron = false;
        //delete temp;
        
    }else if (le == 2){
        //unique_ptr <Level> temp = player->levptr;
        player->levptr= unique_ptr <Level> (new Level2);
        player->level = 2;
        player->staron = false;
        //delete temp;
        
    }else if (le == 3){
        
        //unique_ptr <Level> temp = player->levptr;
        player->levptr= unique_ptr <Level> (new Level3);
        player->level = 3;
        player->staron = false;
        //delete temp;
        
    }else if (le == 4){
        
        //unique_ptr <Level> temp = player->levptr;
        player->levptr= unique_ptr <Level> (new Level4);
        player->level = 4;
        player->staron = true;
        //delete temp;
        
    }else if ((le == 5)&&(specialOn)){
        player->levptr= unique_ptr <Level> (new Level5);
        player->level = 5;
        player->staron = false;
    }
    
    
}

void BasicBoard::LevelDown(std::shared_ptr <Player>& player){
    
    int le = player->level - 1;
    
    if(le == 1) {
        //unique_ptr <Level> temp = player->levptr;
        player->levptr= unique_ptr <Level> (new Level1);
        player->level = 1;
        player->staron = false;
        //delete temp;
        
    }else if (le == 2){
        //unique_ptr <Level> temp = player->levptr;
        player->levptr= unique_ptr <Level> (new Level2);
        player->level = 2;
        player->staron = false;
        //delete temp;
        
    }else if (le == 3){
        
        //unique_ptr <Level> temp = player->levptr;
        player->levptr= unique_ptr <Level> (new Level3);
        player->level = 3;
        player->staron = false;
        //delete temp;
        
    }else if (le == 0){
        
        //unique_ptr <Level> temp = player->levptr;
        player->levptr= unique_ptr <Level> (new Level0);
        player->level = 0;
        player->staron = false;
        //delete temp;
    }else if (le == 4){
        
        player->levptr= unique_ptr <Level> (new Level4);
        player->level = 4;
        player->staron = true;
    }
    
}

// ********************** helper function to test **********************
void BasicBoard::SetDeadCell(std::shared_ptr <Player>& player, int row1, int col1, int row2, int col2){
    int row_times = row2 - row1 ;
    int col_times = col2 - col1 ;
    
    
    for (int i = 0; i <= row_times ; ++i) {
        for (int j = 0; j <= col_times; ++j) {
            
            player->PlayField[row1 + i][col1 + j].TurnOff("*");
        }
    }
}



void BasicBoard::KillLiveCell(std::shared_ptr <Player>& player){
    for (int row = 0; row < 15; ++row){
        for (int col = 0; col < 11; ++col){
            Cell cur = player->PlayField[row][col];
            if (cur.IsAlive()){
                player->PlayField[row][col].TurnOff(" ");
            }
        }
    }
}





// ********************** Heavy **********************
void BasicBoard::LevelHeavy (std::shared_ptr <Player>& player) {
    if ((player->cant_down == 0)&&(player->level >= 3)) {
        update(player);
        down(player);
        update(player);
        
    }
}

void BasicBoard::BlockHeavy (std::shared_ptr <Player>& player) {
    
    for (int i = 0; i < 2; ++i) {
        if ((player->cant_down == 0)&&(player->heavy)) {
            cout << "here is bu" << endl;
            update(player);
            down(player);
            update(player);
        }
    }
}





// ********************** GameOver **********************
bool BasicBoard::GameOver (std::shared_ptr <Player>& player) {
    string four0 = player->PlayField[3][0].GetColor();
    bool four0bool = player->PlayField[3][0].IsAlive();
    string four1 = player->PlayField[3][1].GetColor();
    bool four1bool = player->PlayField[3][1].IsAlive();
    string four2 = player->PlayField[3][2].GetColor();
    bool four2bool = player->PlayField[3][2].IsAlive();
    string four3 = player->PlayField[3][3].GetColor();
    bool four3bool = player->PlayField[3][3].IsAlive();
    string five0 = player->PlayField[4][0].GetColor();
    bool five0bool = player->PlayField[4][0].IsAlive();
    string five1 = player->PlayField[4][1].GetColor();
    bool five1bool = player->PlayField[4][1].IsAlive();
    string five2 = player->PlayField[4][2].GetColor();
    bool five2bool = player->PlayField[4][2].IsAlive();
    string five3 = player->PlayField[4][3].GetColor();
    
    
    if ((player->NextBlock->GetType() == "I")&&
        (((four0 != " ") && (!four0bool)) ||
         ((four1 != " ") && (!four1bool)) ||
         ((four2 != " ") && (!four2bool)) ||
         ((four3 != " ") && (!four3bool)))){
            // cout << "I here" << endl;
            return false;
        }
    if ((player->NextBlock->GetType() == "O")&&
        (((four0 != " ") && (!four0bool))||
         ((four1 != " ") && (!four1bool))||
         ((five0 != " ") && (!five0bool))||
         ((five1 != " ") && (!five1bool)))){
            //cout << "O here" << endl;
            return false;
        }
    if ((player->NextBlock->GetType() == "T")&&
        (((four1 != " ") && (!four1bool))||
         ((five0 != " ") && (!five0bool))||
         ((five1 != " ") && (!five1bool))||
         ((five2 != " ") && (!five2bool)))){
            //cout << "T here" << endl;
            return false;
        }
    if ((player->NextBlock->GetType() == "L")&&
        (((four3 != " ") && (!four3bool))||
         ((five0 != " ") && (!five0bool))||
         ((five1 != " ") && (!five1bool))||
         ((five2 != " ") && (!five2bool)))){
            //cout << "L here" << endl;
            return false;
        }
    if ((player->NextBlock->GetType() == "J")&&
        (((four0 != " ") && (!four0bool))||
         ((five0 != " ") && (!five0bool))||
         ((five1 != " ") && (!five1bool))||
         ((five2 != " ") && (!five2bool)))){
            //cout << "J here" << endl;
            return false;
        }
    if ((player->NextBlock->GetType() == "Z")&&
        (((four0 != " ") && (!four0bool))||
         ((four1 != " ") && (!four1bool))||
         ((five1 != " ") && (!five1bool))||
         ((five2 != " ") && (!five2bool)))){
            //cout << "Z here" << endl;
            return false;
        }
    if ((player->NextBlock->GetType() == "S")&&
        (((four1 != " ") && (!four1bool))||
         ((four2 != " ") && (!four2bool))||
         ((five0 != " ") && (!five0bool))||
         ((five1 != " ") && (!five1bool)))){
            //cout << "S here" << endl;
            
            
            return false;
        }
    //cout << "end here" << endl;
    return true;
}

// ********************** Restart **********************
void BasicBoard::Restart(std::shared_ptr <Player>& player1, std::shared_ptr <Player>& player2){
    SetPlayer(player1, "John" , 1, 0);
    SetPlayer(player2, "AZ" , 2, 0);
    
}

void BasicBoard::Blind (std::shared_ptr <Player>& player){
    for (int i = 2; i < 12; ++i){
        for (int j = 2; j < 9; ++j){
            player->PlayField[i][j].
            TurnBlind();
        }
    }
}


