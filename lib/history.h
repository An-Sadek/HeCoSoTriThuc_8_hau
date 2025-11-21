#ifndef HISTORY_H
#define HISTORY_H
#include <_8_queens.h>
#include <string>
#include <format>


class History: public Solver{
public:
    void add_record(FILE* history, std::string msg, const int depth);
    bool try_col(int row, int col, int count, FILE* history, int depth);
    void solve();
};

#endif