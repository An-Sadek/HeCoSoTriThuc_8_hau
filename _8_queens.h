#ifndef _8QUEENS_H
#define _8QUEENS_H
#include <cstdio>
#include <queue>

bool check(int board[8][8], const int row, const int col);
void update(int board[8][8], const int row, const int col, const int sign);
bool solve(int board[8][8], int row, int col, int result[8]);
bool dfs(int board[8][8], const int row, std::queue<int> result);
void print_board(int board[8][8]);

#endif