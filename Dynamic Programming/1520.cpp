#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> dp;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int n, m;
int dfs(int x, int y) {

    if(x == n-1 && y ==m-1) {
        return 1;
    }
    if(dp[y][x] != -1) {
        return dp[y][x];
    }
    dp[y][x] = 0;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m) {
            continue;
        }
        if(arr[y][x] > arr[ny][nx]) {
            dp[y][x] += dfs(nx, ny);
        }

    }

    return dp[y][x];
}
int main() {

    cin >> m >> n;

    arr.assign(m, vector<int>(n,0));
    dp.assign(m, vector<int>(n,-1));
    for(int i=0; i<m ;i++) {
        for(int j=0; j<n; j++) {
            cin>> arr[i][j];
        }
    }

    cout << dfs(0,0) << '\n';

    return 0;
}