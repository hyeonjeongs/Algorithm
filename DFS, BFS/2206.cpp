#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int moves[1000][1000][2];
vector<vector<int>> arr;
int n, m;
struct Data {
    int x;
    int y;
    int used;
};
int bfs(int cx, int cy) {

    queue<Data> que;
    que.push({cx, cy, 0});

    while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int used = que.front().used;
        que.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0 || nx>=m || ny<0 || ny>=n) {
                continue;
            }

            if (arr[ny][nx]==0 && moves[ny][nx][used]<0) {
                moves[ny][nx][used] = moves[y][x][used] +1;
                que.push({nx, ny, used});
            }

            if (arr[ny][nx]==1 && used ==0 && moves[ny][nx][1]<0) {
                moves[ny][nx][1] = moves[y][x][used] +1;
                que.push({nx, ny, 1});
            }

        }
    }
    int result =-1;
    if (moves[n-1][m-1][0]==-1 || moves[n-1][m-1][1]==-1) {
        result = max(moves[n-1][m-1][0], moves[n-1][m-1][1]);
    } else {
        result = min(moves[n-1][m-1][0], moves[n-1][m-1][1]);
    }
    return result;
}

int main() {
    cin >> n >> m;
    arr.assign(n, vector<int> (m, 0));
    memset(moves, -1, sizeof(moves));
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        for (int j=0; j<m; j++) {
            arr[i][j] = str[j]-'0';
        }
    }

    moves[0][0][0] = 1;

    int result = bfs(0,0);

    cout << result << '\n';

    return 0;
}