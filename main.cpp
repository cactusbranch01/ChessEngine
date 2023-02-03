#include <iostream>
#include <bits/stdc++.h>
#include "Board.h"
#include "Move.h"
#include <string>
using namespace std;

int main() {

    Board b = Board();

    cout<< b.printBoard()<<endl;

    b.makeMove(1,3,3,3);
    Move m1 = Move(1, 3, 3, 3);
    cout<< m1.printMove(1, 0)<<endl;
    cout<< b.printBoard()<<endl;

    b.makeMove(0,1,2,2);
    Move m2 = Move(0, 1, 2, 2);
    cout<< m2.printMove(2, 0)<<endl;
    cout<< b.printBoard()<<endl;

    b.makeMove(0,2,1,3);
    Move m3 = Move(0, 2, 1, 3);
    cout<< m3.printMove(3, 0)<<endl;
    cout<< b.printBoard()<<endl;

    b.castle(0,0);
    Move m4 = Move(0, 3, 0, 1);
    cout<< m4.printMove(6, 0)<<endl;
    cout<<b.printBoard()<<endl;

    return 0;
}
