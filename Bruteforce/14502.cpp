#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
int result = 0;
vector<vector<int>> virus;
vector<vector<int>> virus_copy;
void spreadVirus() {
    queue<pi> que;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (virus[i][j] == 2) {
                que.push({i, j});
            }
        }
    }
    while (!que.empty()) {
        int x = que.front().second;
        int y = que.front().first;
        que.pop();

        for (int k = 0; k < 4; k++) {
            int new_x = x + dx[k];
            int new_y = y + dy[k];

            if (new_x >= m || new_y >= n || new_x < 0 || new_y < 0) {
                continue;
            }

            if (virus[new_y][new_x] == 0) {
                virus[new_y][new_x] = 2;
                que.push({new_y, new_x});

            }

        }

    }


}

int countVirus() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (virus[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

void makeBlock(int wall) {

    if (wall == 3) {
        virus = virus_copy;

        spreadVirus();
        int counts = countVirus();
        result = max(result, counts);

        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (virus_copy[i][j] == 0) {
                virus_copy[i][j] = 1;
                makeBlock(wall + 1);
                virus_copy[i][j] = 0;
            }
        }
    }
}


int main() {


    cin >> n >> m;
    virus.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> virus[i][j];
        }
    }

    virus_copy = virus;
    makeBlock(0);

    cout << result << '\n';

    return 0;
}