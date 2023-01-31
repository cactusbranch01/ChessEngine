//
// Created by benrr on 1/25/2023.
//
#include <bits/stdc++.h>
#include "Board.h"
#include <string>
using namespace std;

Board::Board()
{
    int input[64] = {4, 2, 3, 6, 5, 3, 2, 4, 1, 1, 1, 1, 1, 1, 1, 1, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0
                     ,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, -1,-1,-1,-1,-1,-1,-1,-1, -4,-2,-3,-6,-5,-3,-2,-4};
    int count=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            board[i][j]= input[count++];
        }
    }

    int test[3]= {1,2,3};


}

string Board::printBoard(){

    string result ="";

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
           cout<<(board[i][j]);

        }
        cout<< endl;

    }




    return result;
}