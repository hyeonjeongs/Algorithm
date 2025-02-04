#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

vector<vector<int>> arr;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
struct DATA {
    int x;
    int y;
    int total;
    int cnt;
};
int bfs(int n, int m, int k) {
    queue<DATA> que;
    que.push({1,1,1,0});
    bool visited[n+1][m+1][10];
    visited[1][1][0] = true;
    int result = -1;

    while(!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int total = que.front().total;
        int cnt = que.front().cnt;
        que.pop();

        if(x==m && y==n) {
            result = total;
            break;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<1 || nx>m || ny<1 || ny>n || visited[ny][nx][cnt]) {
                continue;
            }
            if(arr[ny][nx] == 1) {
                if(k-cnt>0) {
                    que.push({nx, ny, total+1, cnt+1});
                    visited[ny][nx][cnt+1] = true;
                }
                continue;
            }

            que.push({nx, ny, total+1, cnt});
            visited[ny][nx][cnt] = true;
        }
    }

    return result;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k;

    cin >> n >> m >> k;

    arr.assign(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    cout << bfs(n, m, k) << '\n';

    return 0;
}