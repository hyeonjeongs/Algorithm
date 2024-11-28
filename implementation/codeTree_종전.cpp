#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
vector<vector<int>> country;

int n;
int dx[] = {1, -1, -1, 1};
int dy[] = {-1, -1, 1, 1};
int diff = 1e6;
int total = 0;

void calcRange(vector<pi> location, vector<vector<bool>> visit) {
    vector<int> tribe(5, 0);

    // 영역 1
    for (int i = 0; i < location[3].second; i++) {
        for (int j = 0; j <= location[2].first; j++) {
            if (visit[i][j])
                continue;
            tribe[1] += country[i][j];
        }
    }
    // 영역 2
    for (int i = 0; i <= location[1].second; i++) {
        for (int j = location[2].first + 1; j < n; j++) {
            if (visit[i][j])
                continue;
            tribe[2] += country[i][j];
        }
    }
    // 영역 3
    for (int i = location[3].second; i < n; i++) {
        for (int j = 0; j < location[0].first; j++) {
            if (visit[i][j])
                continue;
            tribe[3] += country[i][j];
        }
    }
    // 영역 4
    for (int i = location[1].second + 1; i < n; i++) {
        for (int j = location[0].first; j < n; j++) {
            if (visit[i][j])
                continue;
            tribe[4] += country[i][j];
        }
    }
    
    tribe[0] = total - tribe[1] - tribe[2] - tribe[3] - tribe[4];

    int mins = 1e6;
    int maxs = 0;

    for (int i = 0; i < tribe.size(); i++) {
        mins = min(mins, tribe[i]);
        maxs = max(maxs, tribe[i]);
    }
    diff = min(diff, maxs - mins);

}

void dfs(int y, int x, int index, vector<pi> location, vector<vector<bool>> visit) {

    int nx = x + dx[index];
    int ny = y + dy[index];

    if (index == 3 && location[0].first == nx && location[0].second == ny) { //한바퀴 돈 것

        calcRange(location, visit);
        return;

    }

    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
        visit[ny][nx] = true;
        dfs(ny, nx, index, location, visit);

        if (index < 3) { // 여기 index 3일때 아래꺼 적용 되면 안됨
            location[index + 1] = {nx, ny};
            dfs(ny, nx, index + 1, location, visit);
        }

    }

}

int main() {

    cin >> n;
    country.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> country[i][j];
            total += country[i][j];
        }
    }

    vector<pi> location(4, pi(0, 0)); // (x, y)
    vector<vector<bool>> visit;
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < n - 1; j++) {
            location[0] = {j, i};
            visit.assign(n, vector<bool>(n, false));
            visit[i][j] = true;
            dfs(i, j, 0, location, visit);
        }
    }

    cout << diff <<'\n';
    return 0;
}