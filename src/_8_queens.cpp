#include <_8_queens.h>


Solver::Solver(int start_row_pos, int start_col_pos){
    // Input là vị trí
    if (!(1 <= start_row_pos && start_row_pos <= 8)) {
        std::cerr << "start_row_pos và start_row_pos phải nằm trong khoảng [1, 8]\n";
        exit(1);
    }
    start_row = start_row_pos - 1;
    start_col = start_col_pos - 1;
}

void Solver::print_board_state() {
    /*
    In trạng thái của bàn cờ
    */
    // In các vị trí cột
    printf("   ");
    for (int i = 0; i <= 7; i++){
        printf("%d  ", i+1);
    }
    printf("\n");

    // In đường kẻ
    printf("  ");
    for (int i = 0; i <= 7; i++){
        printf("___");
    }
    printf("\n");

    // In trạng thái bàn cờ
    for (int i = 0; i <= 7; i++) {
        printf("%d| ", i+1); // In vị trí hàng

        for (int j = 0; j <= 7; j++) {
            printf("%d  ", board[i][j]); // In trạng thái
        }
        printf("\n");
    }
}

void Solver::print_board_queen(){
    /*
    In bàn cờ dưới dạng quân hậu
    */
    // In các vị trí cột
    printf("  ");
    for (int i = 0; i <= 7; i++){
        printf("%d ", i+1);
    }
    printf("\n");

    for (int i = 0; i <= 7; i++) {
        printf("%d ", i+1); // In vị trí hàng

        for (int j = 0; j <= 7; j++) {
            if (i == start_row && j == start_col){
                printf("X "); // In X cho cho vị trí ban đầu dễ nhìn
                continue;
            }

            if (board[i][j] == 1){
                printf("Q "); // In quân hậu
                continue;
            }

            printf(". "); // Không in để trống
        }
        printf("\n");
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

void Solver::update(const int row, const int col, const int sign) {
    /*
    Hàm cập nhật trạng thái bàn cờ.
    Khi khởi tạo, các phần tử trong bàn cờ đều là 0.
    Khi đặt quân hậu, sẽ biểu thị trạng thái không đặt được bằng cách + 1 đơn vị
    Ngược lại, khi gỡ quân hậu thì các vị trí sẽ được - 1 đơn vị
    Giá trị 0 biểu thị vị trí có thể đặt được quân hậu
    Nguyên nhân:    Việc phải cập nhật quân hậu rất nhiều sẽ gây rắc rối nếu dùng boolean.
                    Nên dễ nhất là để chồng chéo vào nhau, khi cập nhật không bị ảnh hưởng.
    Đầu vào:
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
    for (int i = 0; i <= 7; i++) {
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

bool Solver::try_col(int row, int col, int count){
    /*
    Hàm dùng để backtrack, thay vì sử dụng for loop thì sử dụng try_col.
    Đầu vào:
        row:    Hàng đang xét
        col:    Cột đang xét
        count:  Biến đếm. Nếu biến đếm đạt 8 tức là quay về hàng ban đầu,
                trả về kết quả true.

    */
    if (count == 8) return true; // Count đặt 8 quay về hàng đầu tiên
    if (col == 8) return false; // Backtrack

    // Nếu vị trí hợp lệ thì update, count+1 và tiếp sang hàng tiếp theo
    row = (row + 8) % 8; // Chia lấy phần nguyên mang về giá trị [0, 7]
    if (check(row, col)){
        int sign = +1;
        update(row, col, sign);
        count++;

        // Sang hàng tiếp theo
        row++;
        if (try_col(row, 0, count)){
            return true;
        }

        // Backtrack
        row--; // Trừ lại row đã + ở trên
        sign = -1;
        update(row, col, sign);
        count--;
    }

    // Đi đến cột tiếp theo nếu không tìm được vị trí phù hợp
    col++;
    return try_col(row, col, count);
}

void Solver::solve() {
    if (try_col(start_row, start_col, 0)){
        printf("Đã giải được bài toán\n");
        print_board_state();
        printf("\n");
        print_board_queen();
    } else{
        printf("Không giải được bài toán, tìm lỗi!\n");
        assert(false); // Dừng để debug
    };
}
