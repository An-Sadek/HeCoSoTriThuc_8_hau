#include "history.h"


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

    History solver = History(start_row, start_col);
    solver.solve();

    return 0;
}