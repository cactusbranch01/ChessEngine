//
// Created by benrr on 1/25/2023.
//
#include <bits/stdc++.h>
#include "Board.h"
#include <string>
using namespace std;

Board::Board()
{

    int input[8][8] =  {{4,2,3,6,5,3,2,4},
        {1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-4,-2,-3,-6,-5,-3,-2,-4}};

    for(int i=0;i<8;i++){

        for(int j=0;j<8;j++){

            board[i][j]= input[i][j];
        }
    }
}

Board::Board(int input[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            board[i][j]= input[i][j];
        }
    }
}


void Board::makeMove(int initial_pos_row, int initial_pos_col, int final_pos_row, int final_pos_col){

    int material = board[initial_pos_row][initial_pos_col];

    board[initial_pos_row][initial_pos_col]=0;
    board[final_pos_row][final_pos_col]= material;
}

void Board::castle(int row_of_rook, int col_of_rook)
{
    if(col_of_rook==0){
        board[row_of_rook][1] = 6;
        board[row_of_rook][3] = 0;
        board[row_of_rook][2]= 4;
        board[row_of_rook][col_of_rook]= 0;
    }

    if(col_of_rook==7){
        board[row_of_rook][5] = 6;
        board[row_of_rook][3] = 0;
        board[row_of_rook][4]= 4;
        board[row_of_rook][col_of_rook]= 0;
    }
}

string Board::printBoard(){

    string result ="";

    for(int i=0;i<8;i++){

        for(int j=0;j<8;j++){

           result+=to_string(board[i][j]);

        }
       result+="\n";

    }




    return result;
}