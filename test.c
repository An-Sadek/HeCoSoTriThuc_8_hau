#define NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>



bool check(int board[9][9], const int row, const int col){
	int poss_col, poss_row;
	
	for (int i = 1; i <= 8; i++){
		// Kiem tra rang buoc hang
		if (board[row][i] < 0)
			return false;
		
		// Kiem tra rang buoc cot
		if (board[i][col] < 0){
			return false;
		}
	}
	
	// Kiem tra rang buoc cheo
	// Thay doi am voi duong tuong ung duong cheo phu/chinh
	// poss_row = i [+/-] row
	// poss_col = i [+/-] col
	for (int i = -7; i <= 7; i++){
		poss_row = i + row;
		poss_col = i + col;
			
		// Kiem tra trong pham vi gioi han
		if (
			((1 <= poss_row) && (poss_row <= 8)) &&
			((1 <= poss_row) && (poss_row <= 8))
		) {
			
			// Kiem tra dong thoi duong cheo chinh lan duong cheo phu
			if (
				(board[9 - poss_row][9 - poss_col] < 0) 
			)
				return false;
		}
		
		poss_row = 9 - i + row;
		poss_col = 9 - i + col;
		
		if (
			((1 <= poss_row) && (poss_row <= 8)) &&
			((1 <= poss_row) && (poss_row <= 8))
		) {
			
			// Kiem tra dong thoi duong cheo chinh lan duong cheo phu
			if (
				(board[poss_row][poss_col] < 0) 
			)
				return false;
		}
	}

	
	return true;
}


void update(int board[9][9], const int row, const int col, int sign) {
    assert(sign == 1 || sign == -1);
    assert(1 <= row && row <= 8);
	assert(1 <= col && col <= 8);
	
	int poss_row, poss_col;

    
    for (int i = 1; i <= 8; i++) {
        board[row][i] += sign;
		board[i][col] += sign;
    }
	
	for (int i = -7; i <= 7; i++){
		poss_row = row + i;
		poss_col = col + i;
		
		if (
			((1 <= poss_row) && (poss_row <= 8)) &&
			((1 <= poss_row) && (poss_row <= 8))
		) {
			board[poss_row][poss_col] += sign;
			board[poss_row][col-i] += sign;
		}
		
	}
	
	board[row][col] -= 3*sign;
}


bool solve(int** board, const int row, const int col, int* result){
	// Dung khi phan tu cuoi mang ket qua != 0
	if (result[9] != 0){
		return true;
	}
	
	// Khi thuc thi ham nay thi tien hanh cap nhat luon
	update(board, row, col, -1);
	result[row] = col;
	
}

void print_board(int board[9][9]){
	for (int i = 1; i <= 8; i++){
		for (int j = 1; j <= 8; j++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

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
	int board[9][9] = {0};
	print_board(board);
	
	// Khoi tao mang ket qua voi cac phan tu deu bang 0
	// Neu result[i] = 0 thi chua xet hang i
	int result[9] = {0};
	
	// TEST
	// KT vi tri kha thi 1
	bool isValid1 = check(board, 0, 0);
	printf("\n%d\n", isValid1);
	
	// KT update (+) 
	update(board, 5, 5, 1);
	print_board(board);
	printf("\n");
	
	// KT update (-) 
	update(board, 2, 2, -1);
	print_board(board);
	
	bool isValid2 = check(board, 2, 2);
	printf("\n%d\n", isValid2);
	
	return 0;
}