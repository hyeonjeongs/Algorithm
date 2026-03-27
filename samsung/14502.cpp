# include <iostream>
# include <vector>
# include <queue>

using namespace std;
typedef pair<int, int> pi;
int n, m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int maxs=0;
void spreads (int y, int x, vector<vector<int>>& arr) {
    queue<pi> que;
    que.push({x, y});

    while (!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();
        for (int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx<0 || nx>=m || ny<0 || ny>=n) {
                continue;
            }
            if (arr[ny][nx]==0) {
                arr[ny][nx] = 2;
                que.push({nx, ny});
            }
        }

    }
}
void findSafeZoneNumber(vector<vector<int>> arr) {

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 2) {
                spreads(i, j, arr);
            }
        }
    }
    int cnt=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 0) {
                cnt++;
            }
        }
    }
    maxs = max(cnt, maxs);
}
int main() {


    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m,0));
    vector<pi> wall;
    vector<int> order;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] ==0) {
                order.push_back(wall.size());
                wall.push_back({i, j});
            }
        }
    }

    for (int i=0; i<wall.size()-2; i++) {

        for (int j=i+1; j<wall.size()-1; j++) {
            for (int k=j+1; k<wall.size(); k++) {
                vector<vector<int>> copy = arr;
                copy[wall[i].first][wall[i].second] = 1;
                copy[wall[j].first][wall[j].second] = 1;
                copy[wall[k].first][wall[k].second] = 1;
                findSafeZoneNumber(copy);
            }
        }
    }

    cout << maxs << '\n';

    return 0;

}