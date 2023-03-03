#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tu;
typedef pair<int, int> ci;
int m, n;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

vector<vector<bool>> visit;
vector<ci> location;

int minDay(vector<vector<int>> &tomato) {

    int cnt=0;
    queue<tu> que;

    // 먼저 익은 토마토인거 저장하기
    for (int i = 0; i < location.size(); i++) {
        que.push(tu(location[i].first, location[i].second, 0));
        visit[location[i].first][location[i].second] = true;
    }

    while (!que.empty()) {
        int cur_row = get<0>(que.front());
        int cur_col = get<1>(que.front());
        cnt = get<2>(que.front());
        que.pop();

        for (int i = 0; i < 4; i++) {
            int new_row = cur_row + dy[i];
            int new_col = cur_col + dx[i];
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !visit[new_row][new_col] &&
                tomato[new_row][new_col] == 0) {
                visit[new_row][new_col] = true;
                que.push(tu(new_row, new_col, cnt + 1));
            }
        }
    }
    return cnt;
}

int main() {
    int result = 0;
    cin >> m >> n;
    vector<vector<int>> tomato(n, vector<int>(m, 0));
    visit.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                location.push_back(ci(i, j));
            }
        }
    }

    result = minDay(tomato);

    // 0 있으면 그냥 -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(visit[i][j] ==0 && tomato[i][j] != -1){
                result = -1;
                break;
            }
        }
    }
    cout<< result<<'\n';

    return 0;
}