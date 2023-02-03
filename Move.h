//
// Created by benrr on 2/2/2023.
//

#ifndef MATRIXCHESSENGINECODE_MOVE_H
#define MATRIXCHESSENGINECODE_MOVE_H
#include <string>
#include "Board.h"

using namespace std;

class Move {
public:
    int initial_row;
    int initial_col;
    int final_row;
    int final_col;

public:
    explicit Move(int row1, int col1, int row2, int col2);
    int getInitialRow();
    int getFinalRow();
    int getInitialCol();
    int getFinalCol();
    string printMove(int piece, int capture);
};


#endif //MATRIXCHESSENGINECODE_MOVE_H
