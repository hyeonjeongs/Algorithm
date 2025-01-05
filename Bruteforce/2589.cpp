#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int l, w;

int max_location = 0;
vector<pi> location;
vector<vector<char>> maps;

struct NUM {
    int x;
    int y;
    int depth;
};
void findLocation(int y, int x) {
    queue<NUM> que;
    que.push({x, y, 0});
    vector<vector<bool>> visited(l, vector<bool>(w, false));
    visited[y][x] = true;
    int cx, cy, cn;
    while(!que.empty()) {
        cx = que.front().x;
        cy = que.front().y;
        cn = que.front().depth;
        visited[cy][cx] = true;
        que.pop();

        if(max_location < cn) {
            cout << cn << " dddd" <<endl;
            max_location = cn;
            location[0] = {x, y};
            location[1] = {cx, cy};
        }
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0 || nx>=w || ny<0 || ny>=l || visited[ny][nx] || maps[ny][nx] == 'W') {
                continue;
            }
            que.push({nx, ny, cn+1});

        }
    }

}

int bfs() {
    queue<NUM> que;
    que.push({location[0].first, location[0].second, 0});
    vector<vector<bool>> visited(l, vector<bool>(w, false));
    visited[location[0].second][location[0].first] = true;

    int cx, cy, cn=0;
    while(!que.empty()) {
        cx = que.front().x;
        cy = que.front().y;
        cn = que.front().depth;
        visited[cy][cx] = true;
        que.pop();
        if(cx == location[1].first && cy == location[1].second) {
            break;
        }

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0 || nx>=w || ny<0 || ny>=l || visited[ny][nx] || maps[ny][nx] == 'W') {
                continue;
            }
            que.push({nx, ny, cn+1});

        }
    }
    return cn;
}

int main() {

    cin >> l >> w;

    maps.assign(l, vector<char>(w, 0));
    location.assign(2, pi(0,0));

    for(int i=0; i<l; i++) {
        for(int j=0; j<w; j++) {
            scanf("%1c", &maps[i][j]);
        }
    }

    vector<vector<bool>> visited(l, vector<bool>(w, false));
    for(int i=0; i<l; i++) {
        for(int j=0; j<w; j++) {
            if(!visited[i][j] && maps[i][j]== 'L') {
                findLocation(i, j);
                visited[i][j] = true;
            }
        }
    }

    cout << location[0].first <<", " << location[0].second <<", " << location[1].first <<", "  << location[1].second <<endl;
    cout << bfs() << '\n';
    return 0;
}