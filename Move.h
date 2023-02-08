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
    int initial;
    int final;

public:
    explicit Move(int sq1, int sq2, int piece1, int take);
    //explicit Move(int initial, int final);
    int getInitial();
    int getFinal();
    int getInitialRow();
    int getFinalRow();
    int getInitialCol();
    int getFinalCol();
    //string printMove(int piece, int capture);
};


#endif //MATRIXCHESSENGINECODE_MOVE_H
