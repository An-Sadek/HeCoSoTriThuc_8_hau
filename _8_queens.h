#ifndef _8QUEENS_H
#define _8QUEENS_H
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <queue>

bool check(const short board[8][8], const short row, const short col);
void update(short board[8][8], const short row, const short col, const short sign);
short* solve(short board[8][8], const short start_col);
void print_board(const short board[8][8]);
void print_board(const short result[8]);

#endif