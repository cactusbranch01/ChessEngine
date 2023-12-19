//
// Created by benrr on 12/18/2023.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H

#include <string>
#include <vector>
#include <stdexcept>

// Constants for piece labels. Old values (converted to chars)
// const int EMPTY = 0;
[[maybe_unused]] const int PAWN = 1;
[[maybe_unused]] const int KNIGHT = 2;
[[maybe_unused]] const int BISHOP = 3;
[[maybe_unused]] const int ROOK = 4;
[[maybe_unused]] const int QUEEN = 5;
[[maybe_unused]] const int KING = 6;

const char EMPTY = 0x0;
const char W_PAWN = 0x2;
const char B_PAWN = 0x3;
const char W_KNIGHT = 0x4;
const char B_KNIGHT = 0x5;
const char W_BISHOP = 0x6;
const char B_BISHOP = 0x7;
const char W_ROOK = 0x8;
const char B_ROOK = 0x9;
const char W_QUEEN = 0xA;
const char B_QUEEN = 0xB;
const char W_KING = 0xC;
const char B_KING = 0xD;

struct square {
    square(char row, char col) : row(row), col(col) {}

    char row{};
    char col{};
};

std::vector<std::vector<char>> initializeChessboard();

[[maybe_unused]] std::vector<std::vector<char>> copyChessboard(const std::vector<std::vector<char>> &chessboard);

bool isWhite(char piece);


#endif //CHESS_CHESS_H
