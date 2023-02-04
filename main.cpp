#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Board.h"
#include "Input.h"

using namespace std;

int main() {


    Board b= Board();

    cout<< b.printBoard()<<endl;

    b.makeMove(1,3,3,3);
    cout<< b.printBoard()<<endl;

    b.makeMove(0,1,2,2);
    cout<< b.printBoard()<<endl;

    b.makeMove(0,2,1,3);
    cout<< b.printBoard()<<endl;

    b.castle(0,0);
    cout<<b.printBoard()<<endl;

    int test[8][8] ={0,};
    Board c = Board(test);
    cout<<c.printBoard()<< endl;

    Input("C:\\Users\\user\\GitHub\\matricesChessEngine\\DataBase\\Magnus_games");


    return 0;
}
