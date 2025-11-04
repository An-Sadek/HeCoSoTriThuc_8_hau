#ifndef _8QUEENS_H
#define _8QUEENS_H
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <stack>

bool check(const short board[8][8], const short row, const short col);
void update(short board[8][8], const short row, const short col, const short sign);
bool try_col(short board[8][8], const short row, const short col, short result[8]);
void solve(short board[8][8], const short start_col, short result[8]);
void print_board_queen(const short board[8][8]);
void print_board_state(const short board[8][8]);
void print_result(short result[8]);

#endif