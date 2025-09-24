#include<iostream>
using namespace std;
class sort{
    int* arr;
    int size;
public:
    sort(int s): size(s){
        arr = new int[size];
    }
    void input(){
        std::cout << "Nhập " << size << " phần tử: ";
        for(int i = 0; i < size; i++){
            std::cin >> arr[i];
        }
    }
    void bubblesort(){
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    void insertionsort(){
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    void selectionsort(){
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
    void quicksort(int low, int high){
        if (low < high) {
            int pivot = arr[high];
            int i = (low - 1);
            for (int j = low; j < high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);
            int pi = i + 1;
            quicksort(low, pi - 1);
            quicksort(pi + 1, high);
        }
    }
    void heapify(int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(n, largest);
        }
    }
    void heapsort(){
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(size, i);
        }
        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(i, 0);
        }
    }
    void output(){
        std::cout << "Các phần tử sau khi sắp xếp: ";
        for(int i = 0; i < size; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    bool Issorted(){
        for(int i = 0; i < size - 1; i++){
            if(arr[i] > arr[i + 1]){
                return false;
            }
        }
        return true;
    }
    void choosesort(char method){
        switch(method) {
            case 'b':
                bubblesort();
                break;
            case 'i':
                insertionsort();
                break;
            case 's':
                selectionsort();
                break;
            case 'q':
                quicksort(0, size - 1);
                break;
            case 'h':
                heapsort();
                break;
            default:
                std::cout << "Lựa chọn không hợp lệ!" << std::endl;
                return;
        }
        output();
        if (Issorted()) {
            std::cout << "Mảng đã được sắp xếp." << std::endl;
        }
    }
    ~sort(){
        delete[] arr;
    }
};
int main(){
    sort s(5);
    s.input();
    char method;
    std::cout << "Chọn thuật toán (b: bubble, i: insertion, s: selection, q: quick, h: heap): ";
    std::cin >> method;
    s.choosesort(method);
    return 0;
}