#include "draw.h"




void drawPx(int a, int b, Xwindow& board){
    int x = 10;
    int y = 180;
    int w = 16;
    int c = 7;
    
    board.fillRectangle(x + w*a, y + w*b  ,w , w , c);
    
}


void drawMainBoard(Xwindow &board, bool sound) {
    

    std::string s1;
    
    int bg = 10;
    while(1){
        //we end(actually start game here)
        
        //background
        board.fillRectangle( 0 , 0 , 600 , 550 , bg);
        
        //then we do our title
        
        //b
        
        drawPx(0,-1,board);
        drawPx(1,0,board);
        drawPx(1,1,board);
        drawPx(1,2,board);
        drawPx(1,3,board);
        drawPx(1,4,board);
        drawPx(1,5,board);
        drawPx(1,6,board);
        drawPx(0,6,board);
        drawPx(2,6,board);
        drawPx(3,6,board);
        drawPx(4,6,board);
        drawPx(5,6,board);
        drawPx(4,5,board);
        drawPx(4,4,board);
        drawPx(4,3,board);
        drawPx(3,3,board);
        drawPx(2,3,board);
        drawPx(3,2,board);
        //drawPx(2,3,board);
        drawPx(3,1,board);
        drawPx(3,0,board);
        drawPx(2,0,board);
        
        //i
        
        drawPx(7,2,board);
        drawPx(6,3,board);
        drawPx(7,4,board);
        drawPx(7,5,board);
        drawPx(7,6,board);
        
        //q
        
        drawPx(12,3,board);
        drawPx(11,4,board);
        drawPx(10,4,board);
        drawPx(9,4,board);
        drawPx(9,5,board);
        drawPx(9,6,board);
        drawPx(10,6,board);
        drawPx(11,5,board);
        drawPx(11,6,board);
        drawPx(11,7,board);
        drawPx(11,8,board);
        //drawPx(12,9,board);
        
        //u
        
        drawPx(13,4,board);
        drawPx(13,5,board);
        drawPx(13,6,board);
        drawPx(14,6,board);
        drawPx(15,6,board);
        drawPx(15,5,board);
        drawPx(15,4,board);
        
        //a
        
        drawPx(20,3,board);
        drawPx(19,4,board);
        drawPx(18,4,board);
        drawPx(17,4,board);
        drawPx(17,5,board);
        drawPx(17,6,board);
        drawPx(18,6,board);
        drawPx(19,6,board);
        drawPx(19,5,board);
        drawPx(20,7,board);
        
        //d
        drawPx(22,4,board);
        drawPx(21,4,board);
        drawPx(21,5,board);
        drawPx(21,6,board);
        drawPx(22,6,board);
        drawPx(23,1,board);
        drawPx(23,2,board);
        drawPx(23,3,board);
        drawPx(23,4,board);
        drawPx(23,5,board);
        drawPx(23,6,board);
        drawPx(24,7,board);
        
        
        //r
        drawPx(25,4,board);
        drawPx(25,5,board);
        drawPx(25,6,board);
        drawPx(26,4,board);
        drawPx(27,4,board);
        
        //i
        drawPx(29,2,board);
        drawPx(28,3,board);
        drawPx(29,4,board);
        drawPx(29,5,board);
        drawPx(29,6,board);
        
        //s
        drawPx(33,3,board);
        drawPx(32,3,board);
        drawPx(31,4,board);
        drawPx(31,5,board);
        drawPx(32,5,board);
        drawPx(33,6,board);
        drawPx(32,7,board);
        drawPx(31,7,board);
        
        
        //our words
        std::string s = "Press anykey to start\\(^ w ^*\\)";
        board.drawString(175 , 530  , s);
        
        
        
        if(std::cin >> s1) break;
    }
    
    
    
    while(1){
        //here is about the rules
        board.fillRectangle( 0 , 0 , 600 , 550 , bg);
        
        //words
        std::string msg = "Abouuuuuuuuuut our rules!";
        board.drawString(230,150,msg,7);        
            
        std::string line1 = "Welcome to our low baudget biquadris game!!";
        std::string line2 = "This is game takes two players,";
        std::string line3 = "Hope you fimailar with tetris! ";
        std::string line4 = "The command that takes control of the blockes includes";
        std::string line5 = "right, left, down, drop, levelup, leveldown, clockwise and counterclockwise.";
        std::string line6 = "if you open with -easy mode, you can also input a s d ss q e.";
        std::string line7 = "Hope you enjoy the game!! ";

        board.drawString( 80 , 200 , line1,4);
        board.drawString( 80 , 230 , line2,4);
        board.drawString( 80 , 260 , line3,4);
        board.drawString( 80 , 290 , line4,4);
        board.drawString( 80 , 320 , line5,4);
        board.drawString( 80 , 350 , line6,4);
        board.drawString( 80 , 380 , line7,4);
/*
        std::string line8 = "test ";
        board.drawString( 80 , 450 , line8,4);
*/
// board.drawString( 400 , 550 , s);

       
        //
        std::string r = "Press anykey to start /(* ` b `)/";
        board.drawString( 175 , 530  , r);
        
        if(std::cin >> s1) break;
    }
    
  board.fillRectangle( 0 , 0 , 600 , 550 , bg);
}
