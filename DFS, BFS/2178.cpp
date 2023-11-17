/*
 * 헤깔린부분 - 최단거리라서 dist 비교하는거 필요하다 생각했는데 거리 가장 짧은게 젤 빨리가므로 visited에서 걸려서 상관 없음
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> ci;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
vector<vector<int>> aMatrix;
int n, m;
int findShortPath(int x, int y) {

    queue<ci> que;
    vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
    vector<vector<int>> dist(n+1, vector<int>(m+1, 0));

    que.push(make_pair(x,y));
    dist[y][x] = 1;
    visited[y][x] = 1;

    while(!que.empty()){
        int a = que.front().first;
        int b = que.front().second;

        que.pop();

        for(int i=0; i<4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(nx>0 && nx<=m && ny>0 && ny<=n && aMatrix[ny][nx] ==1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                dist[ny][nx] = dist[b][a] + 1;
                que.push(make_pair(nx, ny));
            }
        }
    }
    return dist[n][m];
}

int main() {

    cin>>n>>m;

    aMatrix.assign(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &aMatrix[i][j]);
        }
    }

    cout<<findShortPath(1,1)<<'\n';

    return 0;
}