template <class TVALUE>
class Stack {
    enum { EMPTY = -1, MAX_SIZE = 10 };
 
    TVALUE data[MAX_SIZE];    // mảng chứa các phần tử trong stack
    int top;        // chỉ số của phần tử trên cùng stack
public:
    Stack() {
        top = EMPTY; // khởi tạo stack rỗng tới top = -1
    }
    void Push(TVALUE v) { data[++top] = v; } // hàm thêm phần tử vào stack
    TVALUE Pop() { return data[top--]; } // lấy ra phần tử trên đỉnh rồi giảm top
    TVALUE Peek() { return data[top - 1]; } // lấy ra phần tử dưới top
 
    int Count() const { return top + 1; } // kiểm tra số phần tử đang có trong stack
    bool IsEmpty() const { return top == EMPTY; } // kiểm tra xem stack có rỗng không?
    bool IsFull() const { return top == MAX_SIZE - 1; } // kiểm tra xem stack có đầy không?
};