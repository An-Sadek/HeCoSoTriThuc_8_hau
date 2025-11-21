#ifndef _8QUEENS_H
#define _8QUEENS_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <stack>


class Solver{
private:
    int start_row;
    int start_col;
    int board[8][8] = {0}; // Khởi tạo bàn cờ

public:
    Solver(int start_row_pos, int start_col_pos);

    // Hàm in
    void print_board_queen();
    void print_board_state();

    // Hàm hoạt động
    bool in_bound(const int value);
    bool check(const int row, const int col);
    void update(const int row, const int col, const int sign);
    bool try_col(int row, const int col, int count);
    void solve();
};

#endif