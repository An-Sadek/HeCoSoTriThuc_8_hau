#include "_8_queens.h"


int main(int argc, char* argv[]){
    // Đọc input từ người dùng
    // |-- Kiểm tra thiếu argument
    if(argc < 2){
        printf("Thieu vi tri dat con hau dau tien. Cach su dung: ./main {1-8}");
        return 1;
    }

    // |-- Chuyển string sang short bằng atoi (cstdlib)
    short start_col = std::atoi(argv[1]);

    // |-- Kiểm tra người dùng có nhập trong phạm vi (1->8)
    if (!(1 <= start_col && start_col <= 8)){
        printf("Nhap gia tri tu 1 -> 8\n");
        return 1;
    }

    // |-- Chuyển thứ tự về index cho đồng bộ
    start_col--;

    // Giải bài toán
    Solver solver = Solver();
    solver.solve(start_col);
    solver.print_result();
    solver.print_board_queen();

    return 0;
}