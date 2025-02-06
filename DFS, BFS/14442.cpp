#include <iostream>
#include <queue>

using namespace std;

int arr[1000][1000];
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
    que.push({0,0,1,0});
    bool visited[1000][1000][10] = { false };

    visited[0][0][0] = true;
    int result = -1;

    while(!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int total = que.front().total;
        int cnt = que.front().cnt;
        que.pop();

        if(x==m-1 && y==n-1) {
            result = total;
            break;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx>=m || ny<0 || ny>=n || visited[ny][nx][cnt]) {
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k;

    cin >> n >> m >> k;

    for(int i=0; i<n; i++) {
        string input;
        cin >> input;
        for(int j=0; j<m; j++) {
            arr[i][j] = input[j] - '0';
        }
    }


    cout << bfs(n, m, k) << '\n';

    return 0;
}