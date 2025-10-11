#ifndef _8QUEENS_H
#define _8QUEENS_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cassert>

bool check(const int board[8][8], const int row, const int col);
void update(int board[8][8], const int row, const int col, const int sign);
int* solve(int board[8][8], const int start_col);
void print_board(const int board[8][8]);

#endif