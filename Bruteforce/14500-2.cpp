#include <iostream>
#include <vector>

using namespace std;

// 11:20
vector<vector<int>> arr;
vector<vector<bool>> visited;
int result = 0;
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void dfs(int y, int x, int cnt, int sum){

    if(cnt>=4) {
        result = max(sum, result);
        return;
    }

    for(int i=0; i<4; i++) {
        int nx= x + dx[i];
        int ny= y + dy[i];
        if(nx>0 && nx<=m && ny >0 && ny<=n && !visited[ny][nx]) {
            visited[ny][nx] = true;
            if(cnt==2) {
                dfs(y, x, cnt+1, sum+arr[ny][nx]);
            }
            dfs(ny, nx, cnt+1, sum+arr[ny][nx]);

            visited[ny][nx] = false;
        }
    }
}

int main() {

    cin>> n>>m;
    arr.assign(n+2, vector<int>(m+2,0));
    visited.assign(n+2, vector<bool>(m+2,false));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                dfs(i, j, 1, arr[i][j]);
                visited[i][j] = false;
            }

        }
    }

    cout<< result <<'\n';
    return 0;
}