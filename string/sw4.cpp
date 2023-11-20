#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 상하좌우
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

vector<vector<bool>> visited;
vector<int> home;
vector<vector<int>> aMatrix;
int num=0;
int n;

void bfs(int y, int x) {

    visited[y][x] = true; //방문처리
    home[num]++; // 개수 증가

    for(int i=0; i<4; i++){
        int new_x = x+dx[i];
        int new_y = y+dy[i];
        if(new_x>0 && new_x<=n && new_y>0 && new_y<=n && aMatrix[new_y][new_x] && !visited[new_y][new_x]){
            bfs(new_y, new_x);
        }
    }
}

int main() {
    cin>>n;

    aMatrix.assign(n + 1, vector<int>(n + 1, 0));
    visited.assign(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &aMatrix[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (aMatrix[i][j] == 1 && !visited[i][j]) {
                home.push_back(0);
                bfs(i, j);
                num++;
            }
        }
    }

    sort(home.begin(), home.end());

    cout<< num <<'\n';
    for(int i=0; i<home.size(); i++){
        cout<< home[i] << ' ';
    }

    return 0;
}