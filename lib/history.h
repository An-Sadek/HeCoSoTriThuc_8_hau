#ifndef HISTORY_H
#define HISTORY_H
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <format>
#include <iostream>


class Solver{
private:
    int start_row;
    int start_col;
    int board[8][8] = {0}; // Khởi tạo bàn cờ

public:
    Solver(const int _input_row, const int _input_col);

    // Hàm in
    void add_record(FILE* history, std::string msg, const int depth);
    void print_board_queen();
    void print_board_state();

    // Hàm hoạt động
    bool in_bound(const int value);
    bool check(const int row, const int col);
    void update(const int row, const int col, const int sign);
    bool try_col(int row, const int col, int count, FILE* history, int depth);
    void solve();
};

#endif