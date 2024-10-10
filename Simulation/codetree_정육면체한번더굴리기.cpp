#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> score;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1}; // 뒤집어지는건 3-index 로
int up = 1, front = 2, rights = 3;
void move(int dist) {
    int u = up, f = front, r = rights;
    if(dist ==0) { // 오른쪽
        u = 7-rights;
        f = front;
        r = up;
    }
    else if(dist ==1) { //아래
        u = 7-front;
        f = up;
        r = rights;

    }
    else if(dist ==2) { //왼쪽
        u = rights;
        f = front;
        r = 7-up;

    }
    else { // 위
        u = front;
        f = 7-up;
        r = rights;
    }
    up = u; front = f; rights = r;
}
int bfs(int x, int y) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int,int>> que;
    que.push({x, y});
    int num = score[y][x];
    int cnt = 0;
    visited[y][x] = true;

    while(!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();
        cnt +=num;
        for(int i=0; i<4;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=n || visited[ny][nx]) {
                continue;
            }
            if(num == score[ny][nx]) {
                que.push({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }
    return cnt;
}
int main() {
    int result =0;

    cin >> n >> m;
    score.assign(n, vector<int>(n,0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;
            score[i][j] = input;
        }
    }
    int dist = 0;
    int cx = 0, cy = 0;
    for(int i=0; i<m; i++) {
        // 움직임
        int nx = cx + dx[dist];
        int ny = cy + dy[dist];
        if(nx<0 || ny<0 || nx>=n || ny>=n) {
            dist = (dist + 2)%4; // 여기서 실수 (dist + 3으로 계산)
        }
        move(dist);
        cx += dx[dist];
        cy += dy[dist];

        // 영역 찾기
        result += bfs(cx, cy);

        // 방향 전환
        int down_num = 7- up;
        if(down_num > score[cy][cx]) {
            dist = (dist+1)%4;
        } else if(down_num < score[cy][cx]){
            dist = (dist-1 + 4)%4;
        }
    }
    cout << result <<'\n';
    return 0;
}