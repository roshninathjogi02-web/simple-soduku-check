#include <stdio.h>

#define SIZE 9

// Function prototypes
int isValidRow(int board[SIZE][SIZE], int row);
int isValidCol(int board[SIZE][SIZE], int col);
int isValidBox(int board[SIZE][SIZE], int startRow, int startCol);
int isValidSudoku(int board[SIZE][SIZE]);

int main() {
    // Example Sudoku board (you can modify the numbers)
    int board[SIZE][SIZE] = {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    };

    if (isValidSudoku(board))
        printf("✅ The Sudoku board is valid.\n");
    else
        printf("❌ The Sudoku board is NOT valid.\n");

    return 0;
}

// Check if a specific row is valid
int isValidRow(int board[SIZE][SIZE], int row) {
    int seen[SIZE + 1] = {0};
    for (int col = 0; col < SIZE; col++) {
        int num = board[row][col];
        if (num < 1 || num > 9) return 0; // invalid number
        if (seen[num]) return 0; // duplicate found
        seen[num] = 1;
    }
    return 1;
}

// Check if a specific column is valid
int isValidCol(int board[SIZE][SIZE], int col) {
    int seen[SIZE + 1] = {0};
    for (int row = 0; row < SIZE; row++) {
        int num = board[row][col];
        if (num < 1 || num > 9) return 0;
        if (seen[num]) return 0;
        seen[num] = 1;
    }
    return 1;
}

// Check if a 3x3 sub-box is valid
int isValidBox(int board[SIZE][SIZE], int startRow, int startCol) {
    int seen[SIZE + 1] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = board[startRow + i][startCol + j];
            if (num < 1 || num > 9) return 0;
            if (seen[num]) return 0;
            seen[num] = 1;
        }
    }
    return 1;
}

// Main Sudoku validation function
int isValidSudoku(int board[SIZE][SIZE]) {
    // Check all rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (!isValidRow(board, i) || !isValidCol(board, i))
            return 0;
    }

    // Check all 3x3 boxes
    for (int row = 0; row < SIZE; row += 3) {
        for (int col = 0; col < SIZE; col += 3) {
            if (!isValidBox(board, row, col))
                return 0;
        }
    }

    return 1; // If all checks passed, Sudoku is valid
}
