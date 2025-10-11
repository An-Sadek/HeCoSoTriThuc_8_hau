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

    // Khởi tạo bàn cờ
    short board[8][8] = {0};

    // Khởi tạo mảng kết quả
    short* result = (short*)malloc(8 * sizeof(short)); // Phân bổ bộ nhớ

    // Giải bài toán
    result = solve(board, start_col);

    // Biến index sang thứ tự (1 -> 8)
    for (short i = 0; i < 8; i++){
        printf("%d ", result[i]+1);
    }
    printf("\n");

    // In vị trí con hậu
    print_board(result);

    // Giải phóng bộ nhớ
    free(result);

    return 0;
}