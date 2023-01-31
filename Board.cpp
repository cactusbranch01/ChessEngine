//
// Created by benrr on 1/25/2023.
//
#include <bits/stdc++.h>
#include "Board.h"
using namespace std;

Board::Board()
{
    int board[8][8]= {{4, 2, 3, 6, 5, 3, 2, 4},
                      {1, 1, 1, 1, 1, 1, 1, 1},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {-1,-1,-1,-1,-1,-1,-1,-1},
                      {-4,-2,-3,-6,-5,-3,-2,-4}};

    cout<<board[1][1];
}

string Board::printBoard(){

    string result;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {

            result+=to_string(board[i][j]);
        }
        result+="\n";
    }

    return "result";
}