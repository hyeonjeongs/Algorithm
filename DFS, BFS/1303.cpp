#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector<vector<char>> wars;
vector<vector<bool>> visited;
int blue_power = 0;
int white_power = 0;
int cnt=0;
int n, m;
void dfs(int x, int y) {

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || nx>=n || ny<0 || ny>=m) {
            continue;
        }
        if(visited[ny][nx] || wars[y][x] != wars[ny][nx]) {
            continue;
        }
        visited[ny][nx] = true;
        cnt++;
        dfs(nx, ny);
    }
}

int main() {

    cin >> n >> m;
    wars.assign(m, vector<char>(n, ' '));
    visited.assign(m, vector<bool>(n,  false));

    for(int i=0; i<m; i++) {
        string str;
        cin >> str;
        for(int j=0; j<n; j++) {
            wars[i][j] = str[j];
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                cnt = 1;
                visited[i][j] = true;
                dfs(j, i);
                if(wars[i][j]== 'W') {
                    white_power += cnt*cnt;
                } else {
                    blue_power += cnt*cnt;
                }
            }
        }
    }

    cout << white_power << " " << blue_power << '\n';

    return 0;
}