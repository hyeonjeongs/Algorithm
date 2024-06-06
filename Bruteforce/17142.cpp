#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Location {
    int x;
    int y;
};
struct Coord {
    int x;
    int y;
    int times;
};
vector<vector<int>> lab;
vector<Location> virus;
vector<vector<bool>> visited;
vector<bool> virus_visited;
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int total = 0; // 감염시킬 개수
int cnt = 0; // 전체 감염시켰는지
int min_num = 1e6;

bool isRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void activeVirus(int time) {
    visited.assign(n, vector<bool>(n, false));
    cnt = 0;
    queue<Coord> que;
    for(int i=0; i<virus_visited.size(); i++) {
        if(virus_visited[i]) {
            visited[virus[i].y][virus[i].x] = true;
            que.push({virus[i].x, virus[i].y, time});
        }

    }

    int current_time;
    while(!que.empty()) {

        int cx = que.front().x;
        int cy = que.front().y;
        int ct = que.front().times;
        que.pop();

        for (int i = 0; i < 4; i++) {

            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (!isRange(nx, ny) || visited[ny][nx] || lab[ny][nx] == -1) {
                continue;
            }

            visited[ny][nx] = true;
            if (lab[ny][nx] == 0) {
                cnt++;
                current_time = ct+1; // 여기도 lab이 바이러스인 경우는 체크안해야하므로 (주의)
            }
            que.push({nx, ny,ct+1});
        }

    }
    if (cnt == total) {
        min_num = min(min_num, current_time);
    }
    return;
}

void dfs(int index, int depth) {
    if (depth == m) {

        activeVirus(0);

        return;
    }

    for (int i = index; i < virus.size(); i++) { // 여기 virus 사이즈가 아니라 n으로 조합만들어서 시간초과남
        virus_visited[i] = true;
        dfs(i+1, depth + 1);
        virus_visited[i] = false;
    }

}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    lab.assign(n, vector<int>(n, 0));

    // 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            lab[i][j] = -input;

            if (input == 0) {
                total++;
            }
            if (input == 2) {
                virus.push_back(Location{j, i});
            }
        }
    }
    virus_visited.assign(virus.size(), false);

    dfs(0, 0);

    if(min_num == 1e6) {
        min_num = -1;
    }
    cout << min_num;

    return 0;
}