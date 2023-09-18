#include <iostream>
#include <vector>
// Will this comment be committed.

// Constants for piece labels
const int EMPTY = 0;
const int PAWN = 1;
const int KNIGHT = 2;
const int BISHOP = 3;
const int ROOK = 4;
const int QUEEN = 5;
const int KING = 6;

std::vector<std::vector<int>> initializeChessboard() {
    std::vector<std::vector<int>> chessboard(8, std::vector<int>(8, EMPTY));
    // Initialize the white pieces (positive integers)
    chessboard[0] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
    for (int i = 0; i < 8; i++) {
        chessboard[1][i] = PAWN;
    }
    // Initialize the black pieces (negative integers)
    chessboard[7] = {-ROOK, -KNIGHT, -BISHOP, -QUEEN, -KING, -BISHOP, -KNIGHT, -ROOK};
    for (int i = 0; i < 8; i++) {
        chessboard[6][i] = -PAWN;
    }
    return chessboard;
}

// Function to display the chessboard
void displayChessboard(const std::vector<std::vector<int>>& chessboard) {
    std::string pieceSymbols = " PNBRQK";
    for (int i = 7; i >= 0; i--) { // Start from rank 8 (a8 to h8)
        for (int j = 0; j < 8; j++) { // File a to h
            int piece = chessboard[i][j];
            char pieceChar;
            if (piece < 0) {
                pieceChar = std::tolower(pieceSymbols[-piece]);
            } else {
                pieceChar = pieceSymbols[piece];
            }
            std::cout << pieceChar << " ";
        }
        std::cout << " | " << i + 1 << std::endl; // Display row label again
    }
    std::cout << "_ _ _ _ _ _ _ _" << std::endl; // Border
    std::cout << "a b c d e f g h" << std::endl; // Display column labels
}

// Function to find legal pawn moves
std::vector<std::pair<int, int>> findPawnMoves(const std::vector<std::vector<int>>& chessboard, int row, int col) {
    std::vector<std::pair<int, int>> legalMoves;
    int color = (chessboard[row][col] > 0) ? 1 : -1; // Determine if it's white or black
    // Pawn's move one square forward
    int forwardRow = row + color;
    if (forwardRow >= 0 && forwardRow < 8 && chessboard[forwardRow][col] == EMPTY) {
        legalMoves.emplace_back(forwardRow, col);
        // Pawn's first move, can move two squares forward
        if ((color == 1 && row == 1) || (color == -1 && row == 6)) {
            int doubleForwardRow = row + 2 * color;
            if (chessboard[doubleForwardRow][col] == EMPTY) {
                legalMoves.emplace_back(doubleForwardRow, col);
            }
        }
    }
    // Pawn captures diagonally
    int leftDiagonalRow = row + color;
    int leftDiagonalCol = col - 1;
    if (leftDiagonalRow >= 0 && leftDiagonalRow < 8 && leftDiagonalCol >= 0 && leftDiagonalCol < 8 &&
        chessboard[leftDiagonalRow][leftDiagonalCol] * color < 0) {
        legalMoves.emplace_back(leftDiagonalRow, leftDiagonalCol);
    }
    int rightDiagonalRow = row + color;
    int rightDiagonalCol = col + 1;
    if (rightDiagonalRow >= 0 && rightDiagonalRow < 8 && rightDiagonalCol >= 0 && rightDiagonalCol < 8 &&
        chessboard[rightDiagonalRow][rightDiagonalCol] * color < 0) {
        legalMoves.emplace_back(rightDiagonalRow, rightDiagonalCol);
    }
    return legalMoves;
}

// Function to find legal knight moves
std::vector<std::pair<int, int>> findKnightMoves(const std::vector<std::vector<int>>& chessboard, int row, int col) {
    std::vector<std::pair<int, int>> legalMoves;
    int color = (chessboard[row][col] > 0) ? 1 : -1; // Determine if it's a white or black knight
    // Possible knight moves
    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    for (auto & move : moves) {
        int newRow = row + move[0];
        int newCol = col + move[1];
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            int targetPiece = chessboard[newRow][newCol];
            // Check if the target square is empty or contains an enemy piece
            if (targetPiece * color <= 0) {
                legalMoves.emplace_back(newRow, newCol);
            }
        }
    }
    return legalMoves;
}

// Function to find legal bishop moves
std::vector<std::pair<int, int>> findBishopMoves(const std::vector<std::vector<int>>& chessboard, int row, int col) {
    std::vector<std::pair<int, int>> legalMoves;
    int color = (chessboard[row][col] > 0) ? 1 : -1; // Determine if it's a white or black bishop
    // Define directions for diagonal movement (four directions)
    int directions[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (auto & direction : directions) {
        for (int step = 1; step <= 7; step++) {
            int newRow = row + direction[0] * step;
            int newCol = col + direction[1] * step;
            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                int targetPiece = chessboard[newRow][newCol];
                // If the target square is empty, add it to legal moves
                if (targetPiece == EMPTY) {
                    legalMoves.emplace_back(newRow, newCol);
                }
                // If the target square contains an enemy piece, add it and stop searching in this direction
                else if (targetPiece * color < 0) {
                    legalMoves.emplace_back(newRow, newCol);
                    break;
                }
                // If the target square contains a friendly piece, stop searching in this direction
                else if (targetPiece * color > 0) {
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
std::vector<std::pair<int, int>> findRookMoves(const std::vector<std::vector<int>>& chessboard, int row, int col) {
    std::vector<std::pair<int, int>> legalMoves;
    int color = (chessboard[row][col] > 0) ? 1 : -1; // Determine if it's a white or black rook
    // Define directions for orthogonal movement (four directions)
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto & direction : directions) {
        for (int step = 1; step <= 7; step++) {
            int newRow = row + direction[0] * step;
            int newCol = col + direction[1] * step;
            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                int targetPiece = chessboard[newRow][newCol];

                // If the target square is empty, add it to legal moves
                if (targetPiece == EMPTY) {
                    legalMoves.emplace_back(newRow, newCol);
                }
                // If the target square contains an enemy piece, add it and stop searching in this direction
                else if (targetPiece * color < 0) {
                    legalMoves.emplace_back(newRow, newCol);
                    break;
                }
                // If the target square contains a friendly piece, stop searching in this direction
                else if (targetPiece * color > 0) {
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
std::vector<std::pair<int, int>> findQueenMoves(const std::vector<std::vector<int>>& chessboard, int row, int col) {
    std::vector<std::pair<int, int>> legalMoves;
    int color = (chessboard[row][col] > 0) ? 1 : -1; // Determine if it's a white or black queen
    // Define directions for orthogonal and diagonal movement (eight directions)
    int directions[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (auto & direction : directions) {
        for (int step = 1; step <= 7; step++) {
            int newRow = row + direction[0] * step;
            int newCol = col + direction[1] * step;
            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                int targetPiece = chessboard[newRow][newCol];
                // If the target square is empty, add it to legal moves
                if (targetPiece == EMPTY) {
                    legalMoves.emplace_back(newRow, newCol);
                }
                // If the target square contains an enemy piece, add it and stop searching in this direction
                else if (targetPiece * color < 0) {
                    legalMoves.emplace_back(newRow, newCol);
                    break;
                }
                // If the target square contains a friendly piece, stop searching in this direction
                else if (targetPiece * color > 0) {
                    break;
                }
            } else {
                break; // Out of the board bounds
            }
        }
    }
    return legalMoves;
}

// Function to find legal king moves
std::vector<std::pair<int, int>> findKingMoves(const std::vector<std::vector<int>>& chessboard, int row, int col) {
    std::vector<std::pair<int, int>> legalMoves;
    int color = (chessboard[row][col] > 0) ? 1 : -1; // Determine if it's a white or black king
    // Possible king moves (orthogonal and diagonal)
    int moves[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (auto & move : moves) {
        int newRow = row + move[0];
        int newCol = col + move[1];
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            int targetPiece = chessboard[newRow][newCol];
            // Check if the target square is empty or contains an enemy piece
            if (targetPiece == EMPTY || targetPiece * color < 0) {
                legalMoves.emplace_back(newRow, newCol);
            }
        }
    }
    return legalMoves;
}

// Function to find all legal moves for all pieces on the chessboard for a specific side
std::vector<std::pair<int, int>> findAllLegalMoves(const std::vector<std::vector<int>>& chessboard, int sideToPlay) {
    std::vector<std::pair<int, int>> allLegalMoves;
    std::vector<std::pair<int, int>> pieceMoves; // Declare a variable to hold the moves
    // Iterate over the entire chessboard
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            int piece = chessboard[row][col];
            // Determine the piece type (pawn, knight, bishop, rook, queen, king)
            switch (std::abs(piece)) {
                case PAWN:
                    if (piece * sideToPlay > 0) { // Check if it's the correct side to play
                        pieceMoves = findPawnMoves(chessboard, row, col);
                        allLegalMoves.insert(allLegalMoves.end(), pieceMoves.begin(), pieceMoves.end());
                    }
                    break;
                case KNIGHT:
                    if (piece * sideToPlay > 0) {
                        pieceMoves = findKnightMoves(chessboard, row, col);
                        allLegalMoves.insert(allLegalMoves.end(), pieceMoves.begin(), pieceMoves.end());
                    }
                    break;
                case BISHOP:
                    if (piece * sideToPlay > 0) {
                        pieceMoves = findBishopMoves(chessboard, row, col);
                        allLegalMoves.insert(allLegalMoves.end(), pieceMoves.begin(), pieceMoves.end());
                    }
                    break;
                case ROOK:
                    if (piece * sideToPlay > 0) {
                        pieceMoves = findRookMoves(chessboard, row, col);
                        allLegalMoves.insert(allLegalMoves.end(), pieceMoves.begin(), pieceMoves.end());
                    }
                    break;
                case QUEEN:
                    if (piece * sideToPlay > 0) {
                        pieceMoves = findQueenMoves(chessboard, row, col);
                        allLegalMoves.insert(allLegalMoves.end(), pieceMoves.begin(), pieceMoves.end());
                    }
                    break;
                case KING:
                    if (piece * sideToPlay > 0) {
                        pieceMoves = findKingMoves(chessboard, row, col);
                        allLegalMoves.insert(allLegalMoves.end(), pieceMoves.begin(), pieceMoves.end());
                    }
                    break;
                default:
                    // Empty square
                    break;
            }
        }
    }
    return allLegalMoves;
}

// Function to make a deep copy of the chessboard
std::vector<std::vector<int>> copyChessboard(const std::vector<std::vector<int>>& chessboard) {
    std::vector<std::vector<int>> copy(chessboard);
    return copy;
}

int main() {
    std::vector<std::vector<int>> chessboard = initializeChessboard();
    displayChessboard(chessboard);

    std::vector<std::pair<int, int>> allLegalMoves = findAllLegalMoves(chessboard, 1);
    // std::vector<std::pair<int, int>> allLegalMoves = findAllLegalMoves(chessboard, -1);

    std::cout << "All Legal Moves on the Chessboard:" << std::endl;
    for (const auto& move : allLegalMoves) {
        char file = 'a' + move.second;
        int rank = move.first + 1;
        std::cout << file << rank << " ";
    }
    std::cout << std::endl;

    return 0;
}