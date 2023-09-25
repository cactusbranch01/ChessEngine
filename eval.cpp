//
// Created by benrr on 9/19/2023.
//

#include "eval.h"

float CAST_INT_TO_FLOAT[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
[[maybe_unused]] int DEFAULT_PIECE_WEIGHTS[] = {0, 1, 3, 3, 5, 9, 100};

float PIECE_WEIGHTS_MIDGAME[] = {0.0, 0.8, 3.2, 3.3, 4.7, 9.4};
float PIECE_WEIGHTS_THRESHOLD[] = {0.0, 0.9, 3.2, 3.3, 4.8, 9.4};
float PIECE_WEIGHTS_ENDGAME[] = {0.0, 1.0, 3.2, 3.3, 5.3, 9.4};
float* PIECE_WEIGHTS[] = {PIECE_WEIGHTS_MIDGAME, PIECE_WEIGHTS_THRESHOLD, PIECE_WEIGHTS_ENDGAME};

float BISHOP_PAIR_BONUS_MIDGAME = 0.3;
float BISHOP_PAIR_BONUS_THRESHOLD = 0.4;
float BISHOP_PAIR_BONUS_ENDGAME = 0.5;
float BISHOP_PAIR_BONUS[] = {BISHOP_PAIR_BONUS_MIDGAME, BISHOP_PAIR_BONUS_THRESHOLD, BISHOP_PAIR_BONUS_ENDGAME};

float SECOND_ROOK_PENALTY_MIDGAME = -0.2;
float SECOND_ROOK_PENALTY_THRESHOLD = 0.1;
float SECOND_ROOK_PENALTY_ENDGAME = -0.3;
float SECOND_ROOK_PENALTY[] = {SECOND_ROOK_PENALTY_MIDGAME, SECOND_ROOK_PENALTY_THRESHOLD, SECOND_ROOK_PENALTY_ENDGAME};

float BOARD_SQUARE_WEIGHTS[8][8] = {
        {.11, .13, .13, .13, .13, .13, .13, .11},
        {.13, .15, .17, .17, .17, .17, .15, .13},
        {.13, .17, .19, .19, .19, .19, .17, .13},
        {.13, .17, .19, .20, .20, .19, .17, .13},
        {.13, .17, .19, .20, .20, .19, .17, .13},
        {.13, .17, .19, .19, .19, .19, .17, .13},
        {.13, .15, .17, .17, .17, .17, .15, .13},
        {.11, .13, .13, .13, .13, .13, .13, .11}
};

// Function to evaluate material on the board with better weights
float evaluate(std::vector<std::vector<int>>& chessboard) {
    float materialBalance = 0.0;
    int whitePieces[] = {0, 0, 0, 0, 0, 0, 0};
    int blackPieces[] = {0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int piece = chessboard[i][j];
            if (piece > 0) {
                whitePieces[piece - 1] += 1;
                materialBalance += BOARD_SQUARE_WEIGHTS[i][j];
            }
            else if (piece < 0) {
                blackPieces[abs(piece) - 1] += 1;
                materialBalance -= BOARD_SQUARE_WEIGHTS[i][j];
            }
        }
    }

    int gamestate = 0;
    if (whitePieces[5] != blackPieces[5]) {
        gamestate = 1;
    }
    if (whitePieces[5] == 0) {
        gamestate = 2;
    }

    for (int i = 0; i < 6; i++) {
        materialBalance += CAST_INT_TO_FLOAT[whitePieces[i]] * PIECE_WEIGHTS[gamestate][i];
        materialBalance -= CAST_INT_TO_FLOAT[blackPieces[i]] * PIECE_WEIGHTS[gamestate][i];
    }
    if (whitePieces[2] >= 2) {
        materialBalance += BISHOP_PAIR_BONUS[gamestate];
    }
    if (blackPieces[2] >= 2) {
        materialBalance -= BISHOP_PAIR_BONUS[gamestate];
    }
    if (whitePieces[3] >= 2) {
        materialBalance += SECOND_ROOK_PENALTY[gamestate];
    }
    if (blackPieces[3] >= 2) {
        materialBalance -= SECOND_ROOK_PENALTY[gamestate];
    }

    return materialBalance;
}