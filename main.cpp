#include <iostream>
#include <bits/stdc++.h>
#include "Board.h"

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

    return 0;
}
