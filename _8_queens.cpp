#include "_8_queens.h"


bool check(const short board[8][8], const short row, const short col) {
    /*
    Ham kiem tra vi tri dat con hau co hop le hay khong.
    Do da quy dinh trong ham update nhung vi tri duoc phep dat la 0,
    nen kiem tra phan tu tai vi tri do = 0 hay khong
        Dau vao:
            board: Trang thai hien tai cua ban co
            row: Chi so hang muon xet
            col: Chi so cot muon xet
        Dau ra:
            isValid: Boolean vi tri con hau hop le
    */
    return board[row][col] == 0;
}


void update(short board[8][8], short row, short col, short sign) {
    /*
    Ham cap nhat trang thai ban co.
    Neu dat con hau thi tru 1 lai cac huong di chuyen.
    Neu go con hau thi +1 lai cac huong di chuyen.
    Nguyen nhan: De cap nhat khi co hien tuong chong cheo huong tan cong
    Dau vao:
        board:  Trang thai ban co muon cap nhat
        row:    Chi so hang muon cap nhat con hau
        col:    Chi so cot muon cap nhat con hau
        sign:   Neu mang gia tri -1 thi dai dien cho viec dat con hau
                Neu mang gia tri  1 thi dai dien cho viec go con hau
    */
    // sign \in {-1, 1}
    assert(sign == 1 || sign == -1);

    // Debug
    assert(0 <= row && row <= 7);
    assert(0 <= col && col <= 7);

    // Khai bao cac chi so co the dat duoc trong duong cheo
    short poss_row, poss_col;

    // Cap nhat ngang doc
    for (short i = 0; i < 8; i++) {
        board[row][i] += sign;
        board[i][col] += sign;
    }

    // Cap nhat theo duong cheo
    for (short i = -7; i <= 7; i++) {
        poss_row = row + i;
        poss_col = col + i;

        // Duong cheo chinh
        if (poss_row >= 0 && poss_row < 8 && poss_col >= 0 && poss_col < 8) {
            board[poss_row][poss_col] += sign;
        }

        // Duong cheo phu
        poss_col = col - i;
        if (poss_row >= 0 && poss_row < 8 && poss_col >= 0 && poss_col < 8) {
            board[poss_row][poss_col] += sign;
        }
    }

    // Trong qua trinh cap nhat thi 
    // vi tri trung tam duoc cap nhat 4 lan (ngang, doc, 2 duong cheo),
    // nen can tru 3
    board[row][col] -= 3 * sign;
}


short* solve(short board[8][8], const short start_col) {
    /*
    Ham backtracking dung de giai bai toan
        Dau vao: 
            board:      Mang 2 chieu duoc khoi tao tu ben ngoai ham
            start_col:  Vi tri cot dat con hau dau tien tai hang thu I (index 0)

        Dau ra:
            result:     Mang ket qua the hien vi tri dat con hau. 
                        Moi chi so dai dien cho hang, va gia tri dai dien cho cot.
    */
    // Khoi tao result bang cach phan bo bo nho, 
    // tung phan tu = 0, chua co ket qua
    short* result = (short*)malloc(8 * sizeof(short));
    for (short i = 0; i < 8; i++) result[i] = 0;

    // Khoi tao cac gia tri
    // |-- row: Hang dang duoc xet
    // |-- col: Cot dang duoc xet
    // |-- prev_col: Cot cuoi cung trong ket qua, 
    //     dung de backtrack vi tri tiep theo
    short row = 0;
    short col = start_col;
    short prev_col;

    while (true) {
        // Duyet tung cot (0 -> 7), 
        // bo qua cac vi tri khong dat duoc hau (-1)
        while (col < 8 && !check(board, row, col)) {
            col++;
        }

        // Cham dem o co gia tri 0 thi tien hanh cap nhat, 
        // sang hang tiep theo, dat lai col = 0.
        // Neu hang dat den bien thi tra ve ket qua
        if (col < 8) {
            update(board, row, col, -1);
            result[row] = col;

            // Cham den bien thi tra ve ket qua
            if (row == 7)
                return result;

            // Chua cham den bien thi sang hang tiep theo
            row++;
            col = 0;
        } else {
            // Backtrack
            // Trong truong hop da kiem tra het cot 
            // nhung khong tim thay vi tri phu hop thi backtrack
            row--;

            // Neu bi loi khuc nay thi co loi giai thuat
            if (row < 0){
                assert(false);
                printf("Bi loi trong thuat toan"); 
            }

            // Xoa con hau va tien hanh backtrack 
            // theo cot cuoi cung tiep theo
            prev_col = result[row];
            update(board, row, prev_col, +1);
            col = prev_col + 1;
            result[row] = 0;
        }
    }

    return result;
}


void print_board(const short board[8][8]) {
    /*
    Ham kiem tra trang thai ban co phuc vu go loi la chinh
        Dau vao:
            board: Ban co
    */
    for (short i = 0; i < 8; i++) {
        for (short j = 0; j < 8; j++) {
            printf("%2d\t", board[i][j]);
        }
        printf("\n");
    }
}