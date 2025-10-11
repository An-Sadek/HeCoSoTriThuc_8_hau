#include "_8_queens.h"

int main(){
	/*
	De tranh truong hop lon xon giua thu tu va chi so
	them 1 hang, 1 cot cho ca ban co lan ket qua.
	Y tuong: Moi phan tu trong ban co co gia tri [-8; 1]
		Trong do:
			1: Hien co quan hau
			0: Co the dat quan hau
			<0: Bi cam dat quan hau
		Muc dich
			Trong truong hop muon cap nhat thi co the cap nhat de dang
			chi tiet trong README.md
	*/
	// Khoi tao mang 2 chieu 9x9 the hien trang thai cua ban co
	int board[8][8] = {0};
	print_board(board);
	
	
	// TEST
	// KT vi tri kha thi 1
	bool isValid1 = check(board, 0, 0);
	printf("\n%d\n", isValid1);
	
	// KT update (+) 
	update(board, 5, 5, 1);
	print_board(board);
	printf("\n");
	
	// KT update (-) 1
	update(board, 5, 5, -1);
	print_board(board);
	
	// KT vi tri kha thi 2
	bool isValid2;
	printf("Test check(board, 2, i) 2: ");
	for (int i = 1; i <= 8; i++){
		isValid2 = check(board, 2, i);
		printf("%d ", isValid2);
	}
	printf("\n\n");
	
	// KT update (-) 2
	update(board, 1, 2, -1);
	print_board(board);
	
	// KT vi tri kha thi 3
	bool isValid3;
	printf("Test check(board, 2, i) 3: ");
	for(int i = 1; i <= 8; i++){
		isValid3 = check(board, 2, i);
		printf("%d ", isValid3);
	}
	printf("\n\n");
	
	
	// Test solve
	int board_puzzle[8][8] = {0};
	int v;
	std::queue<int> result = solve(board_puzzle, 1);
	for (int i = 0; i <= 7; i++){
		v = result.front();
		result.pop();
		printf("%d ", v);
	}
	
	return 0;
}