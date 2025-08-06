#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
vector<vector<int>> land;


int n, l, r;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector<vector<bool>> visited;
bool isPossible;

bool isPossibleDiff(int a, int b) {
    int diff = abs(a-b);
    return diff>=l && diff<=r;
}

bool outOfBounds(int x, int y) {
    return x<0 || x>=n || y<0 || y>=n;
}

void movePeople(int y, int x) {

    queue<pi> que;
    vector<pi> nodes;

    que.push({x, y});
    visited[y][x] = true;

    int nums = land[y][x];

    nodes.push_back({x, y});

    while(!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(outOfBounds(nx, ny) || visited[ny][nx]) {
                continue;
            }
            if(isPossibleDiff(land[cy][cx], land[ny][nx])) {
                nums += land[ny][nx];
                visited[ny][nx] = true;
                nodes.push_back({nx, ny});
                que.push({nx, ny});
                isPossible = true;
            }
        }
    }
    int score = nums/nodes.size();

    for(int i=0; i<nodes.size(); i++) {
        int xs = nodes[i].first;
        int ys = nodes[i].second;
        land[ys][xs] = score;
    }

    return;
}

int main() {


    cin >> n >> l >> r;
    land.assign(n, vector<int>(n, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>> land[i][j];
        }
    }

    int counts=0;
    while(1) {

        isPossible = false;

        visited.assign(n, vector<bool>(n, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j]) {
                    movePeople(i, j);
                }
            }
        }
        if(!isPossible) {
            break;
        }
        counts++;
    }

    cout << counts << '\n';

    return 0;
}