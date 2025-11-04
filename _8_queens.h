#ifndef _8QUEENS_H
#define _8QUEENS_H
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <stack>


class Solver{
private:
    int board[8][8] = {0};
    int result[8] = {0};

public:
    Solver();

    void print_board_queen();
    void print_board_state();
    void print_result();

    bool in_bound(const int value);
    bool check(const int row, const int col);
    void update(const int row, const int col, const int sign);
    bool try_col( const int row, const int col);
    void solve(const int start_col);
};

bool in_bound(const int value);
bool check(const int board[8][8], const int row, const int col);
void update(int board[8][8], const int row, const int col, const int sign);
bool try_col(int board[8][8], const int row, const int col, int result[8]);
void solve(int board[8][8], const int start_col, int result[8]);
void print_board_queen(const int board[8][8]);
void print_board_state(const int board[8][8]);
void print_result(const int result[8]);

#endif