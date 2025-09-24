#include <iostream>
#include <vector>

using namespace std;
const int N = 5;
int adj[N][N] = {
    { 0, 1, 0, 1, 0 },
    { 0, 0, 0, 0, 1 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 1, 0, 1, 1, 0 },
}; // Danh sách kề (đỉnh từ 1 đến n)
bool visited[N] = { }; // Mảng đánh dấu các đỉnh đã thăm

// Hàm DFS
void DFS(int node) {
    // Đánh dấu nút hiện tại là đã thăm
    visited[node] = true;
    cout << char(node + 'A') << '\t';

    // Duyệt qua các nút kề của nút hiện tại
    for (int neighbor = 0; neighbor < N; neighbor++) {
        if (!visited[neighbor] && adj[node][neighbor]) {
            DFS(neighbor);
        }
    }
}


int main() {
    //int n, m; // n: số đỉnh, m: số cạnh
    //cout << "the number of top and edge: ";
    //cin >> n >> m;


    //cout << "Nhập các cạnh (u v):" << endl;
    //for (int i = 0; i < m; ++i) {
    //    int u, v;
    //    cin >> u >> v;
    //    adj[u].push_back(v);
    //    adj[v].push_back(u); // Đồ thị vô hướng (bỏ dòng này nếu đồ thị có hướng)
    //}

    for (int u = 0; u < N; u++) {
        for (bool& x : visited)
            x = false;

        cout << "Ket qua duyet tu dinh : " << char(u + 'A') << ":\n";
        DFS(u);

        cout << endl;
    }

    while (1) {

    }
    return 0;
}
