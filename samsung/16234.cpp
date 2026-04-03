# include <iostream>
# include <vector>
# include <queue>

using namespace std;
typedef pair<int, int> pi;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector<vector<bool>> visited;
vector<vector<int>> land;
int n, l, r;
vector<pi> landOpen(int y, int x) {
    queue<pi> que;
    que.push({x, y});
    vector<pi> result;
    result.push_back({x, y});

    while (!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();
        for (int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx<0 || nx>=n || ny<0 || ny>=n || visited[ny][nx]) {
                continue;
            }
            int diff = abs(land[cy][cx] - land[ny][nx]);

            if (diff >=l && diff <=r) {
                result.push_back({nx, ny});
                que.push({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }
    return result;
}

void moves(vector<pi> location) {

    int total = 0;
    int cnt= location.size();
    for (int i=0; i<location.size(); i++) {
        int nx = location[i].first;
        int ny = location[i].second;
        total += land[ny][nx];
    }
    int num = total / cnt;
    for (int i=0; i<location.size(); i++) {
        int nx = location[i].first;
        int ny = location[i].second;
        land[ny][nx] = num;
    }
}

int main() {

    cin>> n >> l >> r;

    land.assign(n, vector<int>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>> land[i][j];
        }
    }
    int cnt = 0;

    while (1) {
        visited.assign(n, vector<bool>(n, false));
        bool is_possible = false;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    vector<pi> location = landOpen(i, j);
                    if (location.size()>1 ) {
                        is_possible = true;
                        moves(location);
                    }
                }
            }
        }

        if (!is_possible) {
            break;
        }
        cnt++;
    }
    cout << cnt << '\n';

    return 0;

}