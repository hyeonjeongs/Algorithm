# include <iostream>
# include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int n, m;

int result = 0;
vector<pi> loc;
bool outOfBounds(int x, int y) {
    return x<0 || x>=m || y<0 || y>=n;
}
void maxNum(vector<vector<int>> virus) {
    int num=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (virus[i][j] == 0) {
                num++;
            }
        }
    }


    result = max(result, num);

}
void spreadVirus(vector<vector<int>> virus) {
    queue<pi> que;

    for (int i=0; i<loc.size(); i++) {
        que.push(loc[i]);

        while (!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for (int j=0; j<4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (outOfBounds(nx, ny) || virus[ny][nx]!=0) {
                    continue;
                }
                virus[ny][nx] =2;
                que.push({nx,ny});
            }
        }
    }
    maxNum(virus);

}

void makeWall(int y, int x, vector<vector<int>> virus, int cnt) {

    if (cnt==3) {

        spreadVirus(virus);
        return;
    }

    for (int i=y; i<n; i++) {
        for (int j = (i==y)? x:0 ; j<m; j++) {
            if (virus[i][j] == 0) {
                virus[i][j] = 1;
                makeWall(i, j, virus, cnt+1);
                virus[i][j] = 0;
            }

        }
    }

}

int main() {
    cin >> n>>m;
    vector<vector<int>> virus(n, vector<int>(m,0));


    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> virus[i][j];
            if (virus[i][j] == 2) {
                loc.push_back({j,i});
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (virus[i][j] == 0) {
                virus[i][j] = 1;
                makeWall(i, j, virus,1);
                virus[i][j] = 0;
            }

        }
    }

    cout << result << '\n';

    return 0;

}