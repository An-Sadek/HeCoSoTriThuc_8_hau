#ifndef _8QUEENS_H
#define _8QUEENS_H
#include <cstdio>
#include <queue>

bool check(int board[8][8], const int row, const int col);
void update(int board[8][8], const int row, const int col, int sign);
std::queue<int> solve(int board[8][8], const int col);
void print_board(int board[8][8]);

#endif