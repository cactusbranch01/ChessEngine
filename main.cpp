#include "chess.cpp"

int main() {
    std::vector<std::vector<int>> chessboard = initializeChessboard();

    int depth = 2;

    // Generate all possible positions up to the specified depth
    std::vector<std::vector<std::vector<int>>> allPossiblePositions = ply(chessboard, depth, 1);

    displayChessboard(allPossiblePositions[197741]);
    std::cout << allPossiblePositions.size() << std::endl;

    return 0;
}