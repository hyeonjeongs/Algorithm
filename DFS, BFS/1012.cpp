#include <iostream>
#include <vector>
#include<cstring>
#define MAX 50
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0}; //하 상 좌 우
int cnt, m, n; // 가로길이, 세로길이

/*
 * 접근 :
 * 1. 인접한 곳 모두 탐색해야해서 BFS, DFS 상관없음
 * 2. 좌표로 주어지므로 인접행렬로 구현해야 편함
 */

// 재귀
void dfs(int x, int y, vector<vector<int>>& cabbage, vector<vector<bool>>& visited) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;

        if (cabbage[ny][nx] == 1 && !visited[ny][nx]) {
            visited[ny][nx] = true;
            dfs(nx, ny, cabbage, visited);
        }

    }
}

int main() {
    int t, k; //테스트 케이스, 배추 심어져 있는 위치의 개수

    //입력
    cin >> t;

    while (t--) {
        cnt = 0;
        cin >> m >> n >> k;
        vector<vector<int>> cabbage(MAX, vector<int>(MAX, 0));
        vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            cabbage[y][x] = 1;
        }

        for (int i = 0; i < n; i++) { // 행
            for (int j = 0; j < m; j++) { //열
                if (cabbage[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    visited[i][j] = true;
                    dfs(j, i, cabbage, visited);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}