//
// Created by benrr on 12/18/2023.
//

#ifndef CHESS_DISPLAY_H
#define CHESS_DISPLAY_H

#include "find.h"

char displayPiece(char piece);
char displayRow(char row);
char displayCol(char col);
std::string displayChessboard(const std::vector<std::vector<char>>& chessboard);
std::string displayMove(move move, char startPiece, char targetPiece);


#endif //CHESS_DISPLAY_H
