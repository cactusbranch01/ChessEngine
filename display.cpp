//
// Created by benrr on 12/18/2023.
//

#include "display.h"

char displayPiece(char piece) {
    std::string pieceSymbols = "  PpNnBbRrQqKk";
    return pieceSymbols[piece];
}

char displayRow(char row) {
    return '1' + row;
}

char displayCol(char col) {
    return 'a' + col;
}

std::string displayChessboard(const std::vector<std::vector<char>> &chessboard) {
    std::string result;

    for (int i = 7; i >= 0; i--) { // Start from rank 8 (a8 to h8)
        for (int j = 0; j < 8; j++) { // File a to h
            char piece = chessboard[i][j];
            result += displayPiece(piece) + std::string(" ");
        }
        result += " | " + std::to_string(i + 1) + "\n"; // Display row label
    }

    result += "_ _ _ _ _ _ _ _\n"; // Border
    result += "a b c d e f g h\n"; // Display column labels

    return result;
}

std::string displayMove(move move) {
    std::string notation;

    // Check for castling
    if ((move.piece == W_KING || move.piece == B_KING) && abs(move.start.col - move.final.col) == 2) {
        // Kingside castling
        if (move.final.col - move.start.col == 2) {
            notation = (move.piece == W_KING) ? "O-O" : "o-o";
        }
            // Queenside castling
        else {
            notation = (move.piece == W_KING) ? "O-O-O" : "o-o-o";
        }
        return notation;
    }

    // For pawns, the file is only included on capture
    if (move.piece == W_PAWN || move.piece == B_PAWN) {
        if (move.target != EMPTY) {
            notation += move.start.col; // Include file only on capture
            notation += "x";
        }
    } else {
        notation += displayPiece(move.piece);
        if (move.target != EMPTY) {
            notation += "x";
        }
    }

    notation += displayCol(move.final.col);
    notation += displayRow(move.final.row);

    return notation;
}
