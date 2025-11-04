#include "_8_queens.h"


bool check(const short board[8][8], const short row, const short col) {
    /*
    Hàm kiểm tra vị trí đặt con hậu có hợp lệ hay không
    Do đã quy định trong hàm update, những vị trí đặt được = 0, 
    kiểm tra tại vị trí có = 0 hay không là được
        Đầu vào:
            board: Trạng thái hiện tại của bàn cờ
            row: Chỉ số hàng đang xét
            col: Chỉ số cột đang xét
        Dau ra:
            isValid: Vị trí đang xét hợp lệ
    */
    return board[row][col] == 0;
}


void update(short board[8][8], short row, short col, short sign) {
    /*
    Hàm cập nhật trạng thái bàn cờ.
    Khi khởi tạo, các phần tử trong bàn cờ đều là 0.
    Khi đặt quân hậu, sẽ biểu thị trạng thái không đặt được bằng cách - 1 đơn vị
    Ngược lại, khi gỡ quân hậu thì các vị trí sẽ được + 1 đơn vị
    Giá trị 0 biểu thị vị trí có thể đặt được quân hậu
    Nguyên nhân:    Việc phải cập nhật quân hậu rất nhiều sẽ gây rắc rối nếu dùng boolean.
                    Nên dễ nhất là để chồng chéo vào nhau, khi cập nhật không bị ảnh hưởng.
    Dau vao:
        board:  Bàn cờ muốn cập nhật
        row:    Chỉ số hàng muốn cập nhật con hậu
        col:    Chỉ số cột muốn cập nhật con hậu
        sign:   Mang giá trị -1 biểu thị cho việc đặt con hậu
                Mang giá trị  1 biểu thị cho việc gỡ con hậu
                sign \in {-1, 1}
    */
    assert(sign == 1 || sign == -1);

    // Debug
    assert(0 <= row && row <= 7);
    assert(0 <= col && col <= 7);

    // Khai báo chỉ số có thể xuất hiện khi tính đường chéo (-7 -> 7)
    short poss_row, poss_col;

    // Cập nhật đường ngang dọc
    for (short i = 0; i < 8; i++) {
        board[row][i] += sign;
        board[i][col] += sign;
    }

    // Cập nhật đường chéo
    for (short i = -7; i <= 7; i++) {
        poss_row = row + i;
        poss_col = col + i;

        // Đường chéo chính
        if (poss_row >= 0 && poss_row < 8 && poss_col >= 0 && poss_col < 8) {
            board[poss_row][poss_col] += sign;
        }

        // Đường chéo phụ
        poss_col = col - i;
        if (poss_row >= 0 && poss_row < 8 && poss_col >= 0 && poss_col < 8) {
            board[poss_row][poss_col] += sign;
        }
    }

    // Trong quá trình cập nhật trạng thái thì
    // vị trí trung tâm được cập nhật 4 lần,
    // nên trừ 3 lại (ngang, dọc, 2 đường chéo)
    board[row][col] -= 3 * sign;
}

bool try_col(short board[8][8], const short row, const short col, short result[8]) {
    if (row == 8) return true;
    if (col == 8) return false;

    if (check(board, row, col)) {
        update(board, row, col, 1);
        result[row] = col;

        if (try_col(board, row + 1, 0, result)) return true;

        update(board, row, col, -1);
        result[row] = -1;
    }

    return try_col(board, row, col + 1, result);
}

void solve(short board[8][8], const short start_col, short result[8]) {
    try_col(board, 0, start_col, result);
}


void print_board_state(const short board[8][8]) {
    /*
    Hàm in trạng thái của bàn cờ
    */
    for (short i = 0; i < 8; i++) {
        for (short j = 0; j < 8; j++) {
            printf("%5d", board[i][j]);
        }
        printf("\n");
    }
}

void print_board_queen(const short board[8][8]){
    for (short i = 0; i < 8; i++) {
        for (short j = 0; j < 8; j++) {
            if (board[i][j]==1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}


void print_result(short result[8]){
    for (int i = 0; i < 8; i++){
        printf("%d ", result[i]);
    }
}