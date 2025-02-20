/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
int result = 0;
vector<vector<int>> virus;
vector<vector<int>> virus_copy;
void spreadVirus() {
    queue<pi> que;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (virus[i][j] == 2) {
                que.push({i, j});
            }
        }
    }
    while (!que.empty()) {
        int x = que.front().second;
        int y = que.front().first;
        que.pop();

        for (int k = 0; k < 4; k++) {
            int new_x = x + dx[k];
            int new_y = y + dy[k];

            if (new_x >= m || new_y >= n || new_x < 0 || new_y < 0) {
                continue;
            }

            if (virus[new_y][new_x] == 0) {
                virus[new_y][new_x] = 2;
                que.push({new_y, new_x});

            }

        }

    }


}

int countVirus() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (virus[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

void makeBlock(int wall) {

    if (wall == 3) {
        virus = virus_copy;

        spreadVirus();
        int counts = countVirus();
        result = max(result, counts);

        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (virus_copy[i][j] == 0) {
                virus_copy[i][j] = 1;
                makeBlock(wall + 1);
                virus_copy[i][j] = 0;
            }
        }
    }
}


int main() {


    cin >> n >> m;
    virus.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> virus[i][j];
        }
    }

    virus_copy = virus;
    makeBlock(0);

    cout << result << '\n';

    return 0;
}*/



#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> space;
vector<vector<int>> copy_space;
vector<vector<bool>> visited;
vector<pair<int,int>> pairs;
int n, m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int result = 0;
void spreadVirus() {

    queue<pair<int, int>> que;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(space[i][j] == 2) {
                que.push({j, i});
            }
        }
    }

    while(!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0 || nx>=m || ny<0 || ny>=n) {
                continue;
            }
            if(space[ny][nx] == 0) {
                space[ny][nx] = 2;
                que.push({nx, ny});
            }


        }
    }

}
int countVirus() {

    int cnt=0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(space[i][j]==0) {
                cnt++;
            }
        }
    }

    return cnt;

}

void backtracking(int cnt) {
    if(cnt == 3) {
        space = copy_space;
        spreadVirus();
        result = max(result, countVirus());
        return;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(copy_space[i][j]==0) {
                copy_space[i][j] = 1;
                backtracking(cnt+1);
                copy_space[i][j] = 0;
            }
        }
    }

}

int main() {

    cin >> n>>m;
    space.assign(n, vector<int>(m,0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> space[i][j];
        }
    }
    copy_space = space;

    backtracking(0);

    cout << result;
    return 0;

}

























