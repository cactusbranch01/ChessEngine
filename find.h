//
// Created by benrr on 12/18/2023.
//

#ifndef CHESS_FIND_H
#define CHESS_FIND_H

#include "chess.h"

struct move {
    move(square start, square final) : start(start), final(final) {}

    square start;
    square final;
};

std::vector<move> findPawnMoves(const std::vector<std::vector<char>>& chessboard, char row, char col);
std::vector<move> findKnightMoves(const std::vector<std::vector<char>>& chessboard, char row, char col);
std::vector<move> findBishopMoves(const std::vector<std::vector<char>>& chessboard, char row, char col);
std::vector<move> findRookMoves(const std::vector<std::vector<char>>& chessboard, char row, char col);
std::vector<move> findQueenMoves(const std::vector<std::vector<char>>& chessboard, char row, char col);
std::vector<move> findKingMoves(const std::vector<std::vector<char>>& chessboard, char row, char col);
std::vector<move> findAllLegalMoves(const std::vector<std::vector<char>>& chessboard, bool white);
std::vector<std::vector<char>> makeMove(std::vector<std::vector<char>>& chessboard, move move);
std::vector<std::vector<char>> makeMove(std::vector<std::vector<char>>& chessboard, move move, char piece);
std::vector<std::vector<char>> unmakeMove(std::vector<std::vector<char>>& chessboard, move move, char targetPiece);
std::vector<std::vector<char>> unmakeMove(std::vector<std::vector<char>>& chessboard, move move, char piece, char targetPiece);


#endif //CHESS_FIND_H
