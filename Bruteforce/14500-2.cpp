#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int maxs = 0;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int n, m;
using namespace std;

void backtrcking(int y, int x, int count, int sum) {
    if(count>=4) {
        maxs = max(maxs, sum);
        return;
    }

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx >=m || ny<0 || ny>=n) {
            continue;
        }
        if(!visited[ny][nx]) {
            visited[ny][nx] = true;
            backtrcking(ny, nx, count+1, sum+arr[ny][nx]);
            if(count ==2) {
                backtrcking(y, x, count+1, sum+arr[ny][nx]);
            }
            visited[ny][nx] = false;
        }
    }


}

int main() {

    cin >> n >> m;
    arr.assign(n, vector<int>(m,0));
    visited.assign(n, vector<bool>(m,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                backtrcking(i, j, 1, arr[i][j]);
                visited[i][j] = false;
            }
        }
    }
    cout<< maxs;
    return 0;

}