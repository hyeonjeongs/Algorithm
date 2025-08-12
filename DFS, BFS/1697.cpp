// 한가지 방향을 쭉 가는게 아니라 여러방향가면서 최단경로 찾는거라서 bfs임

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int SIZE = 100000;

int bfs(int n, int k) {
    queue<int> q;
    vector<int> visited(SIZE+1, 0);

    q.push(n);
    visited[n] = 1; // 수빈 위치에서 시작
    int result = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == k) {
            result = visited[node] - 1;
            break;
        }

        vector<int> child = {node - 1, node + 1, 2 * node};

        for (int i = 0; i < 3; i++) {
            if (child[i] >= 0 && child[i] <= SIZE && !visited[child[i]]) {
                visited[child[i]] = visited[node] + 1;
                q.push(child[i]);
            }
        }
    }
    return result;
}

int main() {
    int n, k; // 수빈, 동생

    cin >> n >> k;
    cout << bfs(n, k) << '\n';

    return 0;
}
