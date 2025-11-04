#include "_8_queens.h"


Solver::Solver(){}

void Solver::print_board_state() {
    /*
    In trạng thái của bàn cờ
    */
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%5d", board[i][j]);
        }
        printf("\n");
    }
}

void Solver::print_board_queen(){
    /*
    In bàn cờ dưới dạng quân hậu
    */
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j]==1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void Solver::print_result(){
    /*
    In kết quả bài toán (dạng mảng)
    */
    for (int i = 0; i < 8; i++){
        printf("%d ", result[i]);
    }
}

bool Solver::in_bound(const int value){
    /*
    Dùng để xét hàng cột đang xét có trong phạm vi không.
    Ví dụ đang xét ở vị trí (0, 0), 
    phạm vi có thể xét là (-7, -7) -> (7, 7)
    Mà phạm vi có thể cập nhật là (0, 0) -> (7, 7)
    */
    return (0 <= value && value <= 7);
}

bool Solver::check(const int row, const int col) {
    /*
    Hàm kiểm tra vị trí đặt con hậu có hợp lệ hay không
    Do đã quy định trong hàm update, những vị trí đặt được = 0, 
    kiểm tra tại vị trí có = 0 hay không là được.
    */
    return board[row][col] == 0;
}


void Solver::update(int row, int col, int sign) {
    /*
    Hàm cập nhật trạng thái bàn cờ.
    Khi khởi tạo, các phần tử trong bàn cờ đều là 0.
    Khi đặt quân hậu, sẽ biểu thị trạng thái không đặt được bằng cách + 1 đơn vị
    Ngược lại, khi gỡ quân hậu thì các vị trí sẽ được - 1 đơn vị
    Giá trị 0 biểu thị vị trí có thể đặt được quân hậu
    Nguyên nhân:    Việc phải cập nhật quân hậu rất nhiều sẽ gây rắc rối nếu dùng boolean.
                    Nên dễ nhất là để chồng chéo vào nhau, khi cập nhật không bị ảnh hưởng.
    Đầu vào:
        board:  Bàn cờ muốn cập nhật
        row:    Chỉ số hàng muốn cập nhật con hậu
        col:    Chỉ số cột muốn cập nhật con hậu
        sign:   Mang giá trị +1 biểu thị cho việc đặt con hậu
                Mang giá trị -1 biểu thị cho việc gỡ con hậu
                sign \in {-1, 1}
    */

    // Debug
    assert(sign == 1 || sign == -1);
    assert(in_bound(row));
    assert(in_bound(col));

    // Khai báo chỉ số có thể xuất hiện khi tính đường chéo (-7 -> 7)
    int poss_row, poss_col;

    // Cập nhật đường ngang dọc
    for (int i = 0; i < 8; i++) {
        board[row][i] += sign;
        board[i][col] += sign;
    }

    // Cập nhật đường chéo
    for (int i = -7; i <= 7; i++) {
        poss_row = row + i;
        poss_col = col + i;

        // Đường chéo chính
        if (in_bound(poss_row) && in_bound(poss_col)) {
            board[poss_row][poss_col] += sign;
        }

        // Đường chéo phụ
        poss_col = col - i;
        if (in_bound(poss_row) && in_bound(poss_col)) {
            board[poss_row][poss_col] += sign;
        }
    }

    // Trong quá trình cập nhật trạng thái thì
    // vị trí trung tâm được cập nhật 4 lần,
    // nên trừ 3 lại (ngang, dọc, 2 đường chéo)
    board[row][col] -= 3 * sign;
}

bool Solver::try_col(const int row, const int col) {
    if (row == 8) return true;
    if (col == 8) return false;

    if (check(row, col)) {
        update(row, col, 1);
        result[row] = col;

        if (try_col(row + 1, 0)) return true;

        update(row, col, -1);
        result[row] = -1;
    }

    return try_col(row, col + 1);
}

void Solver::solve(const int start_col) {
    if(try_col(0, start_col)){
        printf("Đã giải được bài toán\n");
    } else{
        assert(false);
        printf("Không giải được bài toán, tìm lỗi!\n");
    };
}

