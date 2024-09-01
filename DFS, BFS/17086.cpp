#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
vector<vector<int>> shark;
int n, m;

int dx[] = {-1,1,0,0,-1,1,1,-1};
int dy[] = {0,0,1,-1,1,1,-1,-1};

struct DATA {
    int x;
    int y;
    int cnt;
};
int bfs(int y, int x) {
    int cnt = 1;
    queue<DATA> que;
    que.push({x,y,0});
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    while(!que.empty()) {
        int cx = que.front().x;
        int cy = que.front().y;
        int current = que.front().cnt;
        que.pop();

        for(int i=0; i<8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx <0 || nx >=m || ny<0 || ny>=n || visited[ny][nx]) {
                continue;
            }
            if(shark[ny][nx]==1) {
                return current+1;
            }
            visited[ny][nx] = true;
            que.push({nx, ny, current+1});
        }

    }
    return cnt;

}

int main() {
    int result = 0;

    cin>>n>>m;
    shark.assign(n, vector<int>(m,0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>shark[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(shark[i][j]==0) { // 이 부분에서 실수
                result = max(result, bfs(i,j));
            }
        }
    }
    cout << result <<'\n';

    return 0;
}