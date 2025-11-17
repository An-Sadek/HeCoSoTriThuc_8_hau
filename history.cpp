#include "history.h"


Solver::Solver(const int _input_row, const int _input_col){
    assert(1 <= _input_row && _input_row <= 8);
    assert(1 <= _input_col && _input_col <= 8);

    start_row = _input_row - 1;
    start_col = _input_col - 1;
}

void Solver::add_record(FILE* history, std::string msg, const int depth){
    for (int i = 0; i < depth; i++){
        fprintf(history, "\t");
    }
    fprintf(history, "%s\n", msg.c_str());
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

    for (int i = 0; i <= 7; i++) {
        printf("%d| ", i+1);

        for (int j = 0; j <= 7; j++) {
            printf("%d  ", board[i][j]);
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
                printf("X ");
                continue;
            }

            if (board[i][j] == 1){
                printf("Q ");
                continue;
            }

            printf(". ");
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

void Solver::update(const int row, const int col, int sign) {
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

bool Solver::try_col(int row, int col, int count, FILE* history, int depth){
    /*
    Hàm dùng để backtrack, thay vì sử dụng for loop thì sử dụng try_col.
    Đầu vào:
        row:    Hàng đang xét
        col:    Cột đang xét
        count:  Biến đếm. Nếu biến đếm đạt 8 tức là quay về hàng ban đầu,
                trả về kết quả true.

    */
    std::string msg;
    
    if (count == 8) {
        msg = "Thỏa tất cả điều kiện\n";
        add_record(history, msg, depth);
        return true;
    } // Count đặt 8 quay về hàng đầu tiên

    if (col >= 8) {
        msg = "Đã xét hết cột nhưng không tìm thấy vị trí phù hợp";
        add_record(history, msg, depth);
        msg = "Return False";
        add_record(history, msg, depth);
        return false;
    } // Backtrack

    row = (row + 8) % 8; // Chia lấy phần nguyên mang về giá trị [0, 7]

    // Nếu vị trí hợp lệ thì update, count+1 và tiếp sang hàng tiếp theo
    msg = std::format("Xét quân hậu tại ({}, {})", row, col);
    add_record(history, msg, depth);
    if (check(row, col)){
        int sign = +1;
        update(row, col, sign);
        count++;
        msg = "Vị trí đặt quân hậu hợp lệ";
        add_record(history, msg, depth);

        // Sang hàng tiếp theo
        row++;
        depth++;
        if (try_col(row, 0, count, history, depth+1)){
            msg = "Return True";
            add_record(history, msg, depth);
            return true;
        }

        // Backtrack
        depth--;
        row--; // Trừ lại row đã + ở trên
        sign = -1;
        update(row, col, sign);
        count--;
        msg = std::format("Xét quân hậu tại ({}, {})", row, col);
        add_record(history, msg, depth);
    }

    // Đi đến cột tiếp theo nếu không tìm được vị trí phù hợp
    msg = "Vị trí không hợp lệ, đến cột tiếp theo";
    add_record(history, msg, depth);
    col++;
    return try_col(row, col, count, history, depth+1);
}

void Solver::solve() {
    std::remove("history.txt");
    FILE* history = std::fopen("history.txt", "w");

    add_record(history, "Bắt đầu", 0);
    add_record(history, "Đọc input", 0);
    add_record(history, "try_col(row, col) = True?", 0);

    if (try_col(start_row, start_col, 0, history, 1)){
        printf("Đã giải được bài toán\n");
        print_board_state();
        printf("\n");
        print_board_queen();
    } else{
        printf("Không giải được bài toán, tìm lỗi!\n");
        assert(false); // Dừng để debug
    };

    add_record(history, "In kết quả", 0);
    add_record(history, "Kết thúc", 0);

    fclose(history);
}
