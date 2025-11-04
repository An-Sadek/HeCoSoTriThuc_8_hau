#ifndef _8QUEENS_H
#define _8QUEENS_H
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <stack>


class Solver{
private:
    int board[8][8] = {0}; // Khởi tạo bàn cờ
    int result[8] = {0}; // Khởi tạo kết quả

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

#endif