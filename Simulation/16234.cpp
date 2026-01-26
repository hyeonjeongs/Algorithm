#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

vector<vector<int>> land;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int n, l, r;

vector<vector<int>> part;
vector<vector<bool>> visited;
int sum=0;
int movePeople(int x, int y, int cnt) {

    queue<pi> que;
    que.push({x, y});
    int total=1;
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
                sum += land[ny][nx];
                visited[ny][nx] = true;
                que.push({nx, ny});
                part[ny][nx] = cnt;
                total++;
            }
        }
    }
    if (total>1) {
        part[y][x] = cnt;
    }
    return total;
}

void unionNum(vector<pi> numbers) {
    queue<pi> que;
    vector<vector<bool>> visit(n, vector<bool>(n, false));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (part[i][j]>0) {
                pi members = numbers[part[i][j]];
                int inserts = members.second / members.first; // 삽입할 숫자
                que.push({j, i});

                while (!que.empty()) {
                    int cx = que.front().first;
                    int cy = que.front().second;
                    que.pop();

                    for (int k=0; k<4; k++) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if (nx<0 || nx>=n || ny<0 || ny>=n || visit[ny][nx]) {
                            continue;
                        }

                        if (part[ny][nx] !=part[i][j]) {
                            continue;
                        }
                        land[ny][nx] = inserts;
                        visit[ny][nx] = true;
                        que.push({nx, ny});

                    }
                }
            }
        }
    }


}
int main() {

    cin>> n >> l >> r;
    land.assign(n, vector<int> (n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> land[i][j];
        }
    }
    int days=0;
    while (1) {
        visited.assign(n, vector<bool>(n, false));
        part.assign(n, vector<int>(n, 0));
        vector<pi> numbers(n*n);
        int cnt=1;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    sum=land[i][j];
                    int total =movePeople(j, i, cnt);
                    if (total>1) {
                        numbers[cnt] = {total, sum};
                        cnt++;
                    }
                }
            }
        }
        if (cnt>1) {
            unionNum(numbers);
            days++;
        } else {
            break;
        }
    }
    cout << days<<'\n';
    return 0;

}