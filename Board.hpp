
#ifndef BOARD
#define BOARD

#include <vector> // Include the necessary header for std::vector
#include <cstdint> // Include the necessary header for uint64_t

class Board{

    public:
        Board(uint64_t width, uint64_t height);
        ~Board();

        void run(float delay);

    private:
        std::vector<std::vector<bool>> board;
        uint64_t width;
        uint64_t height;
        bool running;


        void init();
        void step();
        void print();
        void clearConsole();
        static bool generateRandomBool();
        void setBackgroundColor(int color);
        void setConsoleColor(int color);

};

#endif