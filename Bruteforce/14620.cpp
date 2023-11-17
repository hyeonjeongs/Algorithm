#include <iostream>
#include <vector>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<bool>> visited;
vector<vector<int>> flowers;
int result = 10000;
int n;

void resetFlower(int x, int y) {

    visited[y][x] = false;
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        visited[new_y][new_x] = false;
    }
}

int sumFlower(int x, int y) {

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (visited[new_y][new_x]) {
            return -1;
        }
    }
    int sum = flowers[y][x];

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        visited[new_y][new_x] = true;
        sum += flowers[new_y][new_x];
    }
    return sum;
}

void minCost(int x, int y, int cnt, int cost) {
    if (cnt == 3) {
        result = min(result, cost);
        return;
    }
    for (int i = y; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (visited[i][j]) {
                continue;
            }
            int sum = sumFlower(j, i);
            if (sum != -1) {
                minCost(j, i, cnt + 1, cost + sum);
                resetFlower(j, i);
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    flowers.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> flowers[i][j];
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int sum = sumFlower(j, i);
            minCost(j, i, 1, sum);
            resetFlower(j, i);
        }
    }

    cout << result << '\n';
    return 0;
}