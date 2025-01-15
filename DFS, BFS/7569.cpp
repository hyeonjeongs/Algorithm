#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct NODE {
    int x;
    int y;
    int depth;
};
typedef pair<int, int> pi;

vector<vector<int>> rect;

int m, n, h;
int total=0;
int dx[] = {-1,1,0,0,0,0};
int dy[] = {0,0,1,-1, n, -n};
int result = -1;
queue<NODE> que;
void bfs() {
    while(!que.empty()) {

        int x = que.front().x;
        int y = que.front().y;
        int depth = que.front().depth;
        que.pop();
        for(int i=0; i<6; i++) {
            int nx= x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=m || ny<0 || ny>=n*h) {
                continue;
            }
            if(rect[ny][nx] == 0) {
                rect[ny][nx] = 1;
                total--;
                que.push({nx, ny, depth+1});
            }
            if(total <= 0) {
                result = depth+1;
                return;
            }


        }
    }



}
int main() {

    cin >> m >> n >> h;

    rect.assign(n*h, vector<int>(m,0));
    dy[4] = n;
    dy[5] = -n;
    for(int i=0; i<n*h; i++) {
        for(int j=0; j<m; j++) {
            cin >> rect[i][j];
            if(rect[i][j]==0) {
                total++;
            }
            if(rect[i][j]==1) {
                que.push({j, i, 0});
            }
        }
    }
    if(total==0) {
        cout << 0;
        return 0;
    }


    bfs();
    cout << result <<'\n';

    return 0;
}