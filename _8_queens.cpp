#include <iostream>
#include <queue>
#include <cassert>

bool check(int board[8][8], int row, int col) {
    return board[row][col] == 0;
}

void update(int board[8][8], int row, int col, int sign) {
    assert(sign == 1 || sign == -1);
    assert(0 <= row && row <= 7);
    assert(0 <= col && col <= 7);
    for (int i = 0; i < 8; i++) {
        board[row][i] += sign;
        board[i][col] += sign;
    }
    for (int i = -7; i <= 7; i++) {
        int poss_row = row + i;
        int poss_col = col + i;
        if (poss_row >= 0 && poss_row < 8 && poss_col >= 0 && poss_col < 8) {
            board[poss_row][poss_col] += sign;
        }
        poss_col = col - i;
        if (poss_row >= 0 && poss_row < 8 && poss_col >= 0 && poss_col < 8) {
            board[poss_row][poss_col] += sign;
        }
    }
    board[row][col] -= 3 * sign;
}

bool solve(int board[8][8], int row, int col, int result[8]) {
    // Base case: all queens are placed
    if (row == 8) {
        return true;
    }

    // Try placing a queen in each column of the current row
    for (int c = col; c < 8; c++) {
        if (check(board, row, c)) {
            result[row] = c; // Place queen
            update(board, row, c, -1); // Mark attacked positions

            // Move to the next row
            if (solve(board, row + 1, 0, result)) {
                return true;
            }

            // Backtrack: remove queen and unmark positions
            update(board, row, c, 1);
            result[row] = 0;
        }
    }

    // No valid position found in this row, backtrack to previous row
    return false;
}

void print_board(int board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%2d\t", board[i][j]);
        }
        printf("\n");
    }
}