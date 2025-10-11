#include "_8_queens.h"


int main(int argc, char* argv[]){
    // Doc input tu nguoi dung
    // |-- Kiem tra thieu argument
    if(argc < 2){
        printf("Thieu vi tri dat con hau dau tien. Cach su dung: ./main {1-8}");
        return 1;
    }
    // |-- Chuyen string sang int
    int start_col = std::atoi(argv[1]);

    // |-- Kiem tra nguoi dung co nhap thu tu (1->8)
    if (!(1 <= start_col && start_col <= 8)){
        printf("Nhap gia tri tu 1 -> 8\n");
        return 1;
    }
    // |-- Chuyen thu tu ve index (0 -> 7)
    start_col--;

    // Khoi tao ban co
    int board[8][8] = {0};

    // Khoi tao mang ket qua
    int* result = (int*)malloc(8 * sizeof(int));

    // Giai bai toan
    result = solve(board, start_col);

    // Cong them 1, bien index (0->7) sang thu thu tu (1->8)
    for (int i = 0; i < 8; i++){
        printf("%d ", result[i]+1);
    }
    printf("\n");

    // Giai phong bo nho
    free(result);

    return 0;
}