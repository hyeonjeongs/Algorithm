#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int m, n;
vector<vector<int>> maps;
vector<vector<int>> dp;
int result = 0;

int dfs(int x, int y) {
    if (x == n - 1 && y == m - 1) {
        return 1;
    }
    if (dp[y][x] != -1) {
        return dp[y][x];
    }

    dp[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }

        if (maps[y][x] > maps[ny][nx]) {
            dp[y][x] += dfs(nx, ny);
        }
    }
    return dp[y][x];
}

int main() {

    cin >> m >> n;
    maps.assign(m, vector<int>(n, 0));
    dp.assign(m, vector<int>(n, -1));


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maps[i][j];
        }
    }

    cout << dfs(0, 0) << '\n';
    return 0;
}