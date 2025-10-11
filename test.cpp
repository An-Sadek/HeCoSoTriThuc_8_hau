#include "_8_queens.h"


int main() {
    // Khoi tao ban co de test
    short board[8][8] = {0};
    print_board(board);

    // Kiem tra function check()
    bool isValid1 = check(board, 0, 0);
    printf("\nCheck (0,0): %d\n", isValid1);

    // Kiem tra update (+) 
    update(board, 5, 5, 1);
    printf("\nUpdate(5,5,1):\n");
    print_board(board);

    // Kiem tra update (-) 
    update(board, 5, 5, -1);
    printf("\nUpdate(5,5,-1):\n");
    print_board(board);

    // Test check for row 2
    printf("Check(board, 2, i): ");
    for (short i = 0; i < 8; i++) {
        bool isValid2 = check(board, 2, i);
        printf("%d ", isValid2);
    }
    printf("\n\n");

    // Kiem tra update (-) lan 2
    update(board, 1, 2, -1);
    printf("Update(1,2,-1):\n");
    print_board(board);

    // Kiem tra ham check sau khi cap nhat
    printf("Check(board, 2, i): ");
    for (short i = 0; i < 8; i++) {
        bool isValid3 = check(board, 2, i);
        printf("%d ", isValid3);
    }
    printf("\n\n");

    // Test solve
    short board_puzzle[8][8] = {0};
    short* result = (short*)malloc(8 * sizeof(short));
    result = solve(board_puzzle, 1);

    for(short i = 0; i < 8; i++){
        printf("%d ", result[i]);
    }
    printf("\n ");

    free(result);
    return 0;
}