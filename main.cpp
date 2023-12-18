#include <iostream>

#include "find.h"
#include "display.h"

void testDepth(std::vector<std::vector<char>> chessboard, bool white, int depth) {
    std::vector<move> allLegalMovesWhite;
    std::vector<move> allLegalMovesBlack;

    if (depth == 0) {
        return;
    }
    if (white) {
        for (auto &whiteMove: allLegalMovesWhite) {
            allLegalMovesBlack = findAllLegalMoves(makeMove(chessboard, whiteMove), white);
            for (auto &blackMove: allLegalMovesBlack) {
                return testDepth(makeMove(chessboard, blackMove), true, depth--);
            }
        }
    }
    else {
        for (auto &blackMove: allLegalMovesBlack) {
            allLegalMovesBlack = findAllLegalMoves(makeMove(chessboard, blackMove), white);
            for (auto &whiteMove: allLegalMovesWhite) {
                return testDepth(makeMove(chessboard, whiteMove), false, depth--);
            }
        }
    }
}

int main() {
    std::vector<std::vector<char>> chessboard = initializeChessboard();
    makeMove(chessboard, move(square(1, 4), square(3, 4)));
    makeMove(chessboard, move(square(6, 4), square(4, 4)));
    std::cout << displayChessboard(chessboard) << std::endl;

    std::vector<move> allLegalMoves = findAllLegalMoves(chessboard, true);

    for (const auto & move : allLegalMoves) {
        std::cout << displayMove(move, chessboard[move.start.row][move.start.col], chessboard[move.final.row][move.final.col]) << std::endl;
    }

    return 0;
}