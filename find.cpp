//
// Created by benrr on 12/18/2023.
//

#include "find.h"

// Function to find legal pawn moves
std::vector<move> findPawnMoves(const std::vector<std::vector<char>>& chessboard, char row, char col) {
    std::vector<move> legalMoves;
    bool white = isWhite(chessboard[row][col]); // Determine if it's white or black
    // Pawn's move one square forward
    char forwardRow = row + (white ? 1 : -1);
    if (forwardRow >= 0 && forwardRow < 8 && chessboard[forwardRow][col] == EMPTY) {
        legalMoves.emplace_back(square(row, col), square(forwardRow, col));
        // Pawn's first move, can move two squares forward
        if ((white && row == 1) || (!white && row == 6)) {
            int doubleForwardRow = row + (white ? 2 : -2);
            if (chessboard[doubleForwardRow][col] == EMPTY) {
                legalMoves.emplace_back(square(row, col), square(doubleForwardRow, col));
            }
        }
    }
    // Pawn captures diagonally
    char leftDiagonalRow = row + (white ? 1 : -1);
    char leftDiagonalCol = col - 1;
    if (leftDiagonalRow >= 0
        && leftDiagonalRow < 8
        && leftDiagonalCol >= 0
        && leftDiagonalCol < 8
        && chessboard[leftDiagonalRow][leftDiagonalCol] != EMPTY
        && isWhite(chessboard[leftDiagonalRow][leftDiagonalCol]) ^ white) {
        legalMoves.emplace_back(square(row, col), square(leftDiagonalRow, leftDiagonalCol));
    }
    char rightDiagonalRow = row + (white ? 1 : -1);
    char rightDiagonalCol = col + 1;
    if (rightDiagonalRow >= 0
        && rightDiagonalRow < 8
        && rightDiagonalCol >= 0
        && rightDiagonalCol < 8
        && chessboard[rightDiagonalRow][rightDiagonalCol] != EMPTY
        && isWhite(chessboard[rightDiagonalRow][rightDiagonalCol]) ^ white) {
        legalMoves.emplace_back(square(row, col), square(rightDiagonalRow, rightDiagonalCol));
    }
    return legalMoves;
}

// Function to find legal knight moves
std::vector<move> findKnightMoves(const std::vector<std::vector<char>>& chessboard, char row, char col) {
    std::vector<move> legalMoves;
    bool white = isWhite(chessboard[row][col]); // Determine if it's a white or black knight
    // Possible knight moves
    char moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    for (auto & move : moves) {
        char newRow = row + move[0];
        char newCol = col + move[1];
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            char targetPiece = chessboard[newRow][newCol];
            // Check if the target square is empty or contains an enemy piece
            if (targetPiece == EMPTY || white ^ isWhite(targetPiece)) {
                legalMoves.emplace_back(square(row, col), square(newRow, newCol));
            }
        }
    }
    return legalMoves;
}

// Function to find legal bishop moves
std::vector<move> findBishopMoves(const std::vector<std::vector<char>>& chessboard, char row, char col) {
    std::vector<move> legalMoves;
    bool white = isWhite(chessboard[row][col]); // Determine if it's a white or black bishop
    // Define directions for diagonal movement (four directions)
    char directions[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (auto & direction : directions) {
        for (char step = 1; step <= 7; step++) {
            char newRow = row + direction[0] * step;
            char newCol = col + direction[1] * step;
            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                char targetPiece = chessboard[newRow][newCol];
                // If the target square is empty, add it to legal moves
                if (targetPiece == EMPTY) {
                    legalMoves.emplace_back(square(row, col), square(newRow, newCol));
                }
                    // If the target square contains an enemy piece, add it and stop searching in this direction
                else if (isWhite(targetPiece) ^ white) {
                    legalMoves.emplace_back(square(row, col), square(newRow, newCol));
                    break;
                }
                    // If the target square contains a friendly piece, stop searching in this direction
                else if (isWhite(targetPiece) == white) {
                    break;
                }
            } else {
                break; // Out of the board bounds
            }
        }
    }
    return legalMoves;
}

// Function to find legal rook moves
std::vector<move> findRookMoves(const std::vector<std::vector<char>>& chessboard, char row, char col) {
    std::vector<move> legalMoves;
    bool white = isWhite(chessboard[row][col]); // Determine if it's a white or black rook
    // Define directions for orthogonal movement (four directions)
    char directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto & direction : directions) {
        for (int step = 1; step <= 7; step++) {
            char newRow = row + direction[0] * step;
            char newCol = col + direction[1] * step;
            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                char targetPiece = chessboard[newRow][newCol];

                // If the target square is empty, add it to legal moves
                if (targetPiece == EMPTY) {
                    legalMoves.emplace_back(square(row, col), square(newRow, newCol));
                }
                    // If the target square contains an enemy piece, add it and stop searching in this direction
                else if (isWhite(targetPiece) ^ white) {
                    legalMoves.emplace_back(square(row, col), square(newRow, newCol));
                    break;
                }
                    // If the target square contains a friendly piece, stop searching in this direction
                else if (isWhite(targetPiece) == white) {
                    break;
                }
            } else {
                break; // Out of the board bounds
            }
        }
    }
    return legalMoves;
}

// Function to find legal queen moves
std::vector<move> findQueenMoves(const std::vector<std::vector<char>>& chessboard, char row, char col) {
    std::vector<move> legalMoves;
    bool white = isWhite(chessboard[row][col]); // Determine if it's a white or black queen
    // Define directions for orthogonal and diagonal movement (eight directions)
    char directions[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (auto & direction : directions) {
        for (char step = 1; step <= 7; step++) {
            char newRow = row + direction[0] * step;
            char newCol = col + direction[1] * step;
            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                char targetPiece = chessboard[newRow][newCol];
                // If the target square is empty, add it to legal moves
                if (targetPiece == EMPTY) {
                    legalMoves.emplace_back(square(row, col), square(newRow, newCol));
                }
                    // If the target square contains an enemy piece, add it and stop searching in this direction
                else if (isWhite(targetPiece) ^ white) {
                    legalMoves.emplace_back(square(row, col), square(newRow, newCol));
                    break;
                }
                    // If the target square contains a friendly piece, stop searching in this direction
                else if (isWhite(targetPiece) == white) {
                    break;
                }
            } else {
                break; // Out of the board bounds
            }
        }
    }
    return legalMoves;
}

// Function to find legal king moves.
std::vector<move> findKingMoves(const std::vector<std::vector<char>>& chessboard, char row, char col) {
    std::vector<move> legalMoves;
    bool white = isWhite(chessboard[row][col]); // Determine if it's a white or black king
    // Possible king moves (orthogonal and diagonal)
    char moves[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (auto & move : moves) {
        char newRow = row + move[0];
        char newCol = col + move[1];
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            char targetPiece = chessboard[newRow][newCol];
            // Check if the target square is empty or contains an enemy piece
            if (targetPiece == EMPTY || white ^ isWhite(targetPiece)) {
                legalMoves.emplace_back(square(row, col), square(newRow, newCol));
            }
        }
    }
    return legalMoves;
}

// Function to find all legal moves.
std::vector<move> findAllLegalMoves(const std::vector<std::vector<char>>& chessboard, bool white) {
    std::vector<move> allLegalMoves;
    for (char row = 0; row < 8; row++) {
        for (char col = 0; col < 8; col++) {
            char piece = chessboard[row][col];
            if (piece != EMPTY) {
                bool whitePiece = isWhite(piece);
                if (white == whitePiece) {
                    std::vector<move> pieceMoves;
                    switch (piece) {
                        // Ensure each case calls a function that returns std::vector<move>
                        case W_PAWN:
                        case B_PAWN:
                            pieceMoves = findPawnMoves(chessboard, row, col);
                            break;
                        case W_KNIGHT:
                        case B_KNIGHT:
                            pieceMoves = findKnightMoves(chessboard, row, col);
                            break;
                        case W_BISHOP:
                        case B_BISHOP:
                            pieceMoves = findBishopMoves(chessboard, row, col);
                            break;
                        case W_ROOK:
                        case B_ROOK:
                            pieceMoves = findRookMoves(chessboard, row, col);
                            break;
                        case W_QUEEN:
                        case B_QUEEN:
                            pieceMoves = findQueenMoves(chessboard, row, col);
                            break;
                        case W_KING:
                        case B_KING:
                            pieceMoves = findKingMoves(chessboard, row, col);
                            break;
                        default:
                            // Handle other cases or do nothing
                            continue;
                    }
                    allLegalMoves.insert(allLegalMoves.end(), pieceMoves.begin(), pieceMoves.end());
                }
            }
        }
    }
    return allLegalMoves;
}

/** Function to update board to the state after the given move.
 * @expects the move is legal
 * @param chessboard a vector array of chars representing the chessboard
 * @param move the original move stored as two squares (initial, final)
 * @return the chessboard after unmaking the last move
 */
std::vector<std::vector<char>> makeMove(std::vector<std::vector<char>>& chessboard, move move) {
    chessboard[move.final.row][move.final.col] = chessboard[move.start.row][move.start.col];
    chessboard[move.start.row][move.start.col] = 0x0;
    return chessboard;
}

/** Function to update board to the state after the given move.
 *      Slightly optimized function redefinition
 * @expects the move is legal
 * @param chessboard a vector array of chars representing the chessboard
 * @param move the original move stored as two squares (initial, final)
 * @param piece the char of the piece making the move
 * @return the chessboard after unmaking the last move
 */
std::vector<std::vector<char>> makeMove(std::vector<std::vector<char>>& chessboard, move move, char piece) {
    chessboard[move.final.row][move.final.col] = piece;
    chessboard[move.start.row][move.start.col] = 0x0;
    return chessboard;
}

/** Function to restore board to the state before the prev move.
 * @expects the last move was legal
 * @param chessboard a vector array of chars representing the chessboard
 * @param move the original move stored as two squares (initial, final)
 * @param oldTarget the piece (or empty square) prev on the final square
 * @return the chessboard after unmaking the last move
 */
std::vector<std::vector<char>> unmakeMove(std::vector<std::vector<char>>& chessboard, move move, char oldTarget) {
    chessboard[move.final.row][move.final.col] = chessboard[move.start.row][move.start.col];
    chessboard[move.start.row][move.final.col] = 0x0;
    return chessboard;
}

/** Function to restore board to the state before the prev move.
 *      Slightly optimized function redefinition
 * @expects the last move was legal
 * @param chessboard a vector array of chars representing the chessboard
 * @param move the original move stored as two squares (initial, final)
 * @param piece the char of the piece making the move
 * @param oldTarget the piece (or empty square) prev on the final square
 * @return the chessboard after unmaking the last move
 */
std::vector<std::vector<char>> unmakeMove(std::vector<std::vector<char>>& chessboard, move move, char piece, char oldTarget) {
    chessboard[move.final.row][move.final.col] = oldTarget;
    chessboard[move.start.row][move.final.col] = piece;
    return chessboard;
}
