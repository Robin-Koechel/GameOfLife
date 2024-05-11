#include "Board.hpp"
#include <cstdlib>

int main(int argc, char *argv[]) {
    
    int width = std::atoi(argv[1]);
    int height = std::atoi(argv[2]);
    // Create a board object with width 100 and height 100
    Board board(width, height);

    float delayTime = std::atof(argv[3]);

    // Run the board for 2 seconds
    board.run(delayTime);

    return 0;
}
