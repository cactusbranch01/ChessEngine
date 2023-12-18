//
// Created by benrr on 12/18/2023.
//

#include "chess.h"

std::vector<std::vector<char>> initializeChessboard() {
    std::vector<std::vector<char>> chessboard(8, std::vector<char>(8, EMPTY));
    // Initialize the white pieces (positive integers)
    chessboard[0] = {W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK};
    for (int i = 0; i < 8; i++) {
        chessboard[1][i] = W_PAWN;
    }
    // Initialize the black pieces (negative integers)
    chessboard[7] = {B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK};
    for (int i = 0; i < 8; i++) {
        chessboard[6][i] = B_PAWN;
    }
    return chessboard;
}

// Function to make a deep copy of the chessboard
[[maybe_unused]] std::vector<std::vector<char>> copyChessboard(const std::vector<std::vector<char>>& chessboard) {
    std::vector<std::vector<char>> copy(chessboard);
    return copy;
}

// Checks if a given piece is white or black
/** Returns whether a given piece is white
 * @expects piece is not empty
 * @param piece
 * @return bool representing whether the piece is white
 */
bool isWhite(char piece) {
    if (piece == EMPTY) {
        throw std::runtime_error("isWhite should never be called on an empty square");
    }
    return piece  % 2 == 0;
}