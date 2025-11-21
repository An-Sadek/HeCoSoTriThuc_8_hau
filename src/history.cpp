#include "history.h"


void History::add_record(FILE* history, std::string msg, const int depth){
    /*
    In kết quả theo độ sâu của tiến trình
    */
    for (int i = 0; i < depth; i++){
        fprintf(history, "\t");
    }
    fprintf(history, "%s\n", msg.c_str());
}

bool History::try_col(int row, int col, int count, FILE* history, int depth){
    /*
    Hàm dùng để backtrack, thay vì sử dụng for loop thì sử dụng try_col.
    Đầu vào:
        row:    Hàng đang xét
        col:    Cột đang xét
        count:  Biến đếm. Nếu biến đếm đạt 8 tức là quay về hàng ban đầu,
                trả về kết quả true.

    */
    std::string msg;
    
    if (count == 8){
        msg = "Thỏa tất cả điều kiện\n";
        add_record(history, msg, depth);
        return true;
    } // Count đặt 8 quay về hàng đầu tiên

    if (col >= 8){
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

void History::solve(){
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
