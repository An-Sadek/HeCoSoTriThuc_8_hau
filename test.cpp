#include "_8_queens.h"


int main() {
    // Khoi tao ban co de test
    short board[8][8] = {0};
    print_board_state(board);

    // Kiem tra function check()
    bool isValid1 = check(board, 0, 0);
    printf("\nCheck (0,0): %d\n", isValid1);

    // Kiem tra update (+) 
    update(board, 5, 5, 1);
    printf("\nUpdate(5,5,1):\n");
    print_board_state(board);

    // Kiem tra update (-) 
    update(board, 5, 5, -1);
    printf("\nUpdate(5,5,-1):\n");
    print_board_state(board);

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
    print_board_state(board);

    // Kiem tra ham check sau khi cap nhat
    printf("Check(board, 2, i): ");
    for (short i = 0; i < 8; i++) {
        bool isValid3 = check(board, 2, i);
        printf("%d ", isValid3);
    }
    printf("\n\n");

    // Test
    printf("\nTest solution\n");
    short result[8] = {0};
    short puzzle[8][8] = {0};
    solve(puzzle, 0, result);

    printf("\nResult\n");
    print_result(result);
    printf("\nBoard\n");
    print_board_queen(puzzle);

    return 0;
}