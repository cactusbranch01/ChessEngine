#include <iostream>

#include "find.h"
#include "display.h"

void testDepth(std::vector<std::vector<char>> chessboard, bool white, int depth, const std::vector<move> &gameMoves) {
    std::vector<move> allLegalMovesWhite;
    std::vector<move> allLegalMovesBlack;

    if (depth == 0) {
        return;
    }
    if (white) {
        for (auto &whiteMove: allLegalMovesWhite) {
            allLegalMovesBlack = findAllLegalMoves(makeMove(chessboard, whiteMove), white, gameMoves);
            for (auto &blackMove: allLegalMovesBlack) {
                return testDepth(makeMove(chessboard, blackMove), true, depth--, gameMoves);

            }
        }
    } else {
        for (auto &blackMove: allLegalMovesBlack) {
            allLegalMovesBlack = findAllLegalMoves(makeMove(chessboard, blackMove), white, gameMoves);
            for (auto &whiteMove: allLegalMovesWhite) {
                return testDepth(makeMove(chessboard, whiteMove), false, depth--, gameMoves);
            }
        }
    }
}

int main() {
    std::vector<std::vector<char>> chessboard = initializeChessboard();

    // Correcting the move initializations
    move e4 = move(square(6, 4), square(4, 4), W_PAWN, EMPTY); // e4
    move e5 = move(square(1, 4), square(3, 4), B_PAWN, EMPTY); // e5
    move nf3 = move(square(7, 6), square(5, 5), W_KNIGHT, EMPTY); // Nf3
    move nf6 = move(square(0, 6), square(2, 5), B_KNIGHT, EMPTY); // Nf6
    move be2 = move(square(0, 5), square(1, 4), W_BISHOP, EMPTY); // Be2
    move bc5 = move(square(7, 5), square(4, 2), B_BISHOP, EMPTY); // Bc5

    std::vector<move> gameMoves = {e4, e5, nf3, nf6, be2, bc5};

    // Playing the moves
    makeMove(chessboard, e4);
    makeMove(chessboard, e5);
    makeMove(chessboard, nf3);
    makeMove(chessboard, nf6);
    makeMove(chessboard, be2);
    makeMove(chessboard, bc5);

    std::cout << displayChessboard(chessboard) << std::endl;

    std::vector<move> allLegalMoves = findAllLegalMoves(chessboard, true, gameMoves);

    for (const auto &move: allLegalMoves) {
        std::cout << displayMove(move) << std::endl;
    }

    return 0;
}