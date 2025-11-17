#include <_8_queens.h>


int main() {
    printf("main\n");
    Solver solver = Solver();
    const int start_pos[2] = {5, 5};
    solver.solve(start_pos);

    return 0;
}