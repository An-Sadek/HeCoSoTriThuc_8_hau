#include "_8_queens.h"


int main(int argc, char* argv[]){
    // Đọc input từ người dùng
    // |-- Kiểm tra thiếu argument
    if(argc < 3){
        printf("Thieu vi tri dat con hau dau tien. Cach su dung: ./main {x} {y}\n");
        return 1;
    }

    // |-- Chuyển string sang short bằng atoi (cstdlib)
    int start_row = std::atoi(argv[1]); // x
    int start_col = std::atoi(argv[2]); // y

    // |-- Kiểm tra người dùng có nhập trong phạm vi (1->8)
    if (!(1 <= start_row && start_row <= 8)){
        printf("Nhap gia tri tu 1 -> 8\n");
        return 1;
    }

    if (!(1 <= start_col && start_col <= 8)){
        printf("Nhap gia tri tu 1 -> 8\n");
        return 1;
    }

    // |-- Chuyển thứ tự về index cho đồng bộ
    start_row--;
    start_col--;
    int start_pos[2] = {start_row, start_col};

    Solver solver = Solver();
    solver.solve(start_pos);
    solver.print_board_state();
    printf("\n");
    solver.print_board_queen(start_pos);

    return 0;
}