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

std::string displayChessboard(const std::vector<std::vector<char>>& chessboard) {
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

std::string displayMove(move move, char startPiece, char targetPiece) {
    char startCol = displayCol(move.start.col);
    char startRow = displayRow(move.start.row);
    char finalCol = displayCol(move.final.col);
    char finalRow = displayRow(move.final.row);

    std::string notation;

    // For pawns, the file is only included on capture
    if (startPiece == W_PAWN || startPiece == B_PAWN) {
        if (targetPiece != EMPTY) {
            notation += startCol; // Include file only on capture
            notation += "x";
        }
    } else {
        notation += displayPiece(startPiece);
        if (targetPiece != EMPTY) {
            notation += "x";
        }
    }

    notation += finalCol;
    notation += finalRow;

    return notation;
}
