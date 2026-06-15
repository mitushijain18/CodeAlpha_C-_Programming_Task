#include <iostream>

/**
 * @file main.cpp
 * @brief CodeAlpha C++ Programming Internship - TASK 3: Sudoku Solver
 * @details Solves a 9x9 Sudoku puzzle using a recursive backtracking algorithm.
 */

#define N 9

// Function Prototypes
void printGrid(int grid[N][N]);
bool isSafe(int grid[N][N], int row, int col, int num);
bool findEmptyLocation(int grid[N][N], int &row, int &col);
bool solveSudoku(int grid[N][N]);

int main() {
    // 1. Represent the Sudoku grid as a 2D array (0 indicates empty cells)
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    std::cout << "=========================================\n";
    std::cout << "          CODEALPHA SUDOKU SOLVER        \n";
    std::cout << "=========================================\n";
    std::cout << "\nOriginal Sudoku Puzzle:\n";
    printGrid(grid);

    // 2. Run the backtracking solver algorithm
    if (solveSudoku(grid)) {
        std::cout << "\nSudoku Puzzle Solved Successfully!:\n";
        printGrid(grid);
    } else {
        std::cout << "\nNo valid solution exists for this Sudoku puzzle.\n";
    }
    std::cout << "=========================================\n";

    return 0;
}

// Helper function to scan the grid for an unassigned (0) cell
bool findEmptyLocation(int grid[N][N], int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// 3. Rule constraints validation: Check row, col, and 3x3 box rules
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check row constraint
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) return false;
    }

    // Check column constraint
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) return false;
    }

    // Check 3x3 subgrid constraint
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }

    return true; // The number is valid under all constraints
}

// 2. Core Backtracking Logic: Recursively tries numbers 1-9
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // Base Case: If there are no empty cells left, puzzle is solved!
    if (!findEmptyLocation(grid, row, col)) {
        return true; 
    }

    // Consider digits 1 to 9
    for (int num = 1; num <= 9; num++) {
        // If the number fits the row, column, and subgrid constraints
        if (isSafe(grid, row, col, num)) {
            // Make a tentative assignment
            grid[row][col] = num;

            // Recursively try to solve the rest of the board
            if (solveSudoku(grid)) {
                return true;
            }

            // Failure step: If assigning 'num' doesn't lead to a solution, backtrack!
            grid[row][col] = 0;
        }
    }
    return false; // Triggers backtracking to previous recursive frames
}

// Utility function to cleanly display the grid board
void printGrid(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        if (r % 3 == 0 && r != 0) {
            std::cout << "------+-------+------\n";
        }
        for (int c = 0; c < N; c++) {
            if (c % 3 == 0 && c != 0) {
                std::cout << "| ";
            }
            if (grid[r][c] == 0) {
                std::cout << ". ";
            } else {
                std::cout << grid[r][c] << " ";
            }
        }
        std::cout << "\n";
    }
}