#include <iostream>
#include <vector>

using namespace std;

int max_size = 0;
int maxs =0;
int total = 0;
int n, m;
vector<vector<int>> picture;
vector<vector<bool>> visited;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void dfs(int y, int x) {
    maxs++;

    for(int i=0; i<4; i++) {

        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || nx>=m || ny<0 || ny>=n) {
            continue;
        }
        if(visited[ny][nx] || picture[ny][nx]==0) {
            continue;
        }
        visited[ny][nx] = true;
        dfs(ny, nx);
    }
}

int main() {

    cin >> n >> m;
    picture.assign(n, vector<int>(m,0));
    visited.assign(n, vector<bool>(m,false));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> picture[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && picture[i][j]==1) {
                maxs=0; // max_size를 초기화하는식으로 했었음 -> 이거를 초기에는 변수로 넘겨서 그게 개수라 생각함
                visited[i][j] = true; // 여기 체크 안했었음
                dfs(i,j);
                total++;
                max_size= max(maxs, max_size);
            }
        }
    }

    cout << total <<'\n'<< max_size;
    return 0;
}