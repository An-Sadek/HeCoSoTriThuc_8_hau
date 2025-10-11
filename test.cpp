#include "_8_queens.h"


int main() {
    // Initialize 8x8 board
    int board[8][8] = {0};
    print_board(board);

    // Test check function
    bool isValid1 = check(board, 0, 0);
    printf("\nCheck (0,0): %d\n", isValid1);

    // Test update (+) 
    update(board, 5, 5, 1);
    printf("\nAfter update(5,5,1):\n");
    print_board(board);

    // Test update (-) 
    update(board, 5, 5, -1);
    printf("\nAfter update(5,5,-1):\n");
    print_board(board);

    // Test check for row 2
    printf("Test check(board, 2, i): ");
    for (int i = 0; i < 8; i++) {
        bool isValid2 = check(board, 2, i);
        printf("%d ", isValid2);
    }
    printf("\n\n");

    // Test update (-) 
    update(board, 1, 2, -1);
    printf("After update(1,2,-1):\n");
    print_board(board);

    // Test check for row 2 again
    printf("Test check(board, 2, i): ");
    for (int i = 0; i < 8; i++) {
        bool isValid3 = check(board, 2, i);
        printf("%d ", isValid3);
    }
    printf("\n\n");

    // Test solve
    int board_puzzle[8][8] = {0};
    int result[8] = {0};
    for (int v: result){
        printf("%d ", v);
    }
    printf("\n ");

    solve(board_puzzle, 0, 0, result);
    for (int v: result){
        printf("%d ", v);
    }
    printf("\n ");
    return 0;
}