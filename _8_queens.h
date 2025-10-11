#ifndef _8QUEENS_H
#define _8QUEENS_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cassert>

bool check(const short board[8][8], const short row, const short col);
void update(short board[8][8], const short row, const short col, const short sign);
short* solve(short board[8][8], const short start_col);
void print_board(const short board[8][8]);

#endif