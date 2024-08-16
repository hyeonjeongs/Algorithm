#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
vector<vector<int>> arr;
int m, n, k;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int dfs (int x, int y) {
    int cnt =1;
    queue<pi> que;
    que.push({x, y});
    
    while(!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || arr[ny][nx]!=0) {
                continue;
            }
            arr[ny][nx] = 1;
            que.push({nx, ny});
            cnt++;
        }
    }
    return cnt;

}
void makeBorder(int x1, int y1, int x2, int y2) {
    for(int i= y1; i<y2; i++) {
        for(int j=x1; j<x2; j++) {
            arr[i][j] = 1;
        }
    }
}
int main() {

    cin>> m >> n>> k;
    vector<int> result;
    arr.assign(m, vector<int>(n,0));

    for(int i=0; i<k; i++) {
        int x1, y1, x2, y2;
        cin>>x1 >> y1 >> x2 >> y2;
        makeBorder(x1, y1, x2, y2);
    }


    int cnt = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j]==0) {
                cnt ++;
                arr[i][j] = 1;
                int num =dfs(j, i);

                result.push_back(num);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << cnt << '\n';
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << ' ';
    }

    return 0;
}