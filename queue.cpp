template <class TVALUE>
class Queue {
    enum { EMPTY = -1, MAX_SIZE = 10};
    
    TVALUE data[MAX_SIZE]; // mảng chứa các phần tử trong queue
    int front; // chỉ số đầu của queue
    int rear; // chỉ số cuối của queue
public:
    Queue() {
        front = rear = EMPTY; // Khi queue rỗng(chưa có phần tử nào) thì front = rear = -1
    }
    void Enqueue(TVALUE v){
        if (IsEmpty()){ // nếu queue rỗng thì khởi tạo front = 0
            front = 0;
        }
        ++ rear; // tăng rear lên 1 đơn vị
        data[rear] = v; // thêm phần tử v vào queue
    }
    TVALUE Dequeue() {
        TVALUE v = data[front]; // lấy phần tử đứng đầu queue
        ++ front; // tăng front để dịch sang phần tử tiếp theo
        return v;
    }
    TVALUE Peek() { return data[front];} // lấy ra phần tử đầu của queue nhưng không xoá
    
    int Count() const { return rear - front + 1;} // số phần tử đang có trong queue
    bool IsEmpty() const { return front == EMPTY;} // kiểm tra queue có rỗng không?
    bool IsFull() const { return rear == MAX_SIZE - 1;} // kiểm tra xem queue có đầy không?
};