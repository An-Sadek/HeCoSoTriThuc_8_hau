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


short* solve(short board[8][8], const short start_col) {
    /*
    Hàm back tracking đẻ giải bài toán
        Đầu vào:
            board:      Trạng thái khởi tạo của bàn cờ
            start_col:  Vị trí con hậu được đặt đầu tiên (0, start_col)

        Đầu ra:
            result:     Mang kết quả thể hiện vị trí đặt con hậu tại cột
                        result[i] = col, i là vị trí hàng
    */
    // Khởi tạo result
    short* result = (short*)malloc(8 * sizeof(short)); // Phân bổ bộ nhớ
    for (short i = 0; i < 8; i++) 
        result[i] = 0; // Từng phần tử = 0

    // Khởi tạo các biến
    // |-- row: Hàng đang xét
    // |-- col: Cột đang xét
    // |-- prev_col:    Giá trị cuối cùng trong hàm kết quả,
    //                  dùng để backtracking cột tiếp theo
    short row = 0;
    short col = start_col;
    short prev_col;

    while (true) {
        // Duyệt từng cột, bỏ qua các cột mang giá trị <0
        while (col < 8 && !check(board, row, col)) {
            col++;
        }

        // Nếu tìm được vị trí có thể đặt con hậu thì cập nhật
        if (col < 8) {
            update(board, row, col, -1);
            result[row] = col;

            // Đến biên thì trả về kết quả
            if (row == 7)
                return result;

            // Chưa đến biên thì sang hàng tiếp theo
            row++;
            col = 0;
        } else {
            // Trường hợp kiểm tra hết cột
            // Nếu không có khả thi thì về hàng trước
            // Tiếp tục với cột tiếp theo đang xét
            row--;

            // Nếu bị lỗi khúc này thì lỗi giải thuật do 92 lời giải
            // đều có từng cột ở hàng đầu tiên
            if (row < 0){
                assert(false);
                printf("Bi loi trong thuat toan"); 
            }

            // Xóa con hậu và tiến hành backtrack
            // Lấy cột tiếp theo từ giá trị lưu lần cuối trong kết quả
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
    Hàm in trạng thái của bàn cờ
    */
    for (short i = 0; i < 8; i++) {
        for (short j = 0; j < 8; j++) {
            printf("%2d\t", board[i][j]);
        }
        printf("\n");
    }
}


void print_board(const short result[8]) {
    /*
    In vị trí các quân hậu trong bàn cờ 8x8
        Đầu vào:
            result: Mảng kết quả, đặt con hậu tại cột result[i] ở hàng i
    */
    for (short i = 0; i < 8; i++) {
        for (short j = 0; j < 8; j++) {
            if (result[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}