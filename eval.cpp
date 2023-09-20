//
// Created by benrr on 9/19/2023.
//

#include "eval.h"

float PRE_CAST_INT_TO_FLOAT[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
int DEFAULT_PIECE_WEIGHTS[] = {0, 1, 3, 3, 5, 9, 100};

float ADVANCED_PIECE_WEIGHTS_MIDGAME[] = {0.0, 0.8, 3.2, 3.3, 4.7, 9.4};
float ADVANCED_PIECE_WEIGHTS_THRESHOLD[] = {0.0, 0.9, 3.2, 3.3, 4.8, 9.4};
float ADVANCED_PIECE_WEIGHTS_ENDGAME[] = {0.0, 1.0, 3.2, 3.3, 5.3, 9.4};

float BISHOP_PAIR_BONUS_MIDGAME = 0.3;
float BISHOP_PAIR_BONUS_THRESHOLD = 0.4;
float BISHOP_PAIR_BONUS_ENDGAME = 0.5;

float SECOND_ROOK_PENALTY_MIDGAME = -0.2;
float SECOND_ROOK_PENALTY_THRESHOLD = 0.1;
float SECOND_ROOK_PENALTY_ENDGAME = -0.3;

// Function to evaluate material on the board with better weights
int evaluate(std::vector<std::vector<int>>& chessboard) {
    int material_balance = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            material_balance += chessboard[i][j];
        }
    }
    return material_balance;
}