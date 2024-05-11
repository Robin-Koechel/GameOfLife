#include "Board.hpp" 

#include <random>
#include <chrono>
#include <thread>
#include <iostream>

// Constructor
Board::Board(uint64_t width, uint64_t height) {
    this->width = width;
    this->height = height;
    this->running = true;
    board.resize(height, std::vector<bool>(width, false));
    this->init();
}

Board::~Board(){
}

// Initialize the board with random values
void Board::init() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            board[i][j] = generateRandomBool();
        }   
    }
}

// Generate a random boolean value
bool Board::generateRandomBool() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    
    // Distribution for boolean values
    std::uniform_int_distribution<int> distribution(0, 1);
    
    // Generate and return a random boolean value
    return distribution(gen);
}

// Implement delay with specified duration
void Board::run(float delay) {
    while(this->running) {
        this->step();
        this->clearConsole();
        this->print();
        std::chrono::milliseconds timespan(static_cast<int>(delay * 1000)); // Cast to int
        std::this_thread::sleep_for(timespan);
    }
}

// Implement one step of the Game of Life
void Board::step() {
    std::vector<std::vector<bool>> new_board = board;
    
    // Iterate through each cell
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            // Count live neighbors
            int live_neighbors = 0;
            for(int ni = -1; ni <= 1; ni++) {
                for(int nj = -1; nj <= 1; nj++) {
                    if(ni == 0 && nj == 0) // Skip the cell itself
                        continue;
                    
                    int ni_wrap = (i + ni + height) % height; // Wrap around for toroidal grid
                    int nj_wrap = (j + nj + width) % width;   // Wrap around for toroidal grid
                    if(board[ni_wrap][nj_wrap])
                        live_neighbors++;
                }
            }

            // Apply the rules of the Game of Life
            if(board[i][j]) { // If the cell is alive
                if(live_neighbors < 2 || live_neighbors > 3)
                    new_board[i][j] = false; // Die due to underpopulation or overpopulation
            } else { // If the cell is dead
                if(live_neighbors == 3)
                    new_board[i][j] = true; // Come to life due to reproduction
            }
        }   
    }

    // Update the board state
    board = new_board;
}


// Print the board to the console
void Board::print() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            std::cout << (board[i][j] ? "█" : " ") << " ";
        }
        std::cout << std::endl;
    }
}

// Clear the console
void Board::clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

