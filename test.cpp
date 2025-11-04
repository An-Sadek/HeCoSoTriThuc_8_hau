#include "_8_queens.h"


int main() {
    Solver solver = Solver();
    solver.solve(3);
    solver.print_result();
    solver.print_board_queen();

    return 0;
}