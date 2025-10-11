#include "_8_queens.h"

#include <iostream>
#include <queue>
#include <cassert>


bool check(int board[8][8], const int row, const int col){
	if (board[row][col] < 0){
		return false;
	}
	
	return true;
}


void update(int board[8][8], const int row, const int col, int sign) {
    assert(sign == 1 || sign == -1);
    assert(1 <= row && row <= 8);
	assert(1 <= col && col <= 8);
	
	int poss_row, poss_col;

    
    for (int i = 0; i <= 7; i++) {
        board[row][i] += sign;
		board[i][col] += sign;
    }
	
	for (int i = -7; i <= 7; i++){
		poss_row = row + i;
		poss_col = col + i;
		
		if (
			((0 <= poss_row) && (poss_row <= 7)) &&
			((0 <= poss_col) && (poss_col <= 7))
		) {
			board[poss_row][poss_col] += sign;
			board[poss_row][col-i] += sign;
		}
		
	}
	
	board[row][col] -= 3*sign;
}


std::queue<int> solve(int board[8][8], const int col){
	// Cap nhat trang thai ban co, mac dinh se la hang 1, cot tu chon
	// tru lai bieu thi ko duoc dat quan hau
	update(board, 1, col, -1);

	// Khoi tao row = 1, do qua hang thu 2
	int row = 1;
	int i;
	int last_col;
	bool placed;

	// Khoi tao mang 2 chieu vieng tham, ket hop da dat lan
	bool visited[8][8];
	visited[0][col] = true;

	// Khoi tao hang doi q voi cac buoc kha thi o hang thu 2
	std::queue<int> result;
	result.push(col);

	// Duyet den khi row = 8
	while (row < 8){
		
		
	}
	
	
	return std::queue<int>();
}

void print_board(int board[8][8]){
	for (int i = 0; i <= 7; i++){
		for (int j = 0; j <= 7; j++){
			printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
}
