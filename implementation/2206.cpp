
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

struct Node {
    int x;
    int y;
    int cnt;
    int isUsed;
};

int n, m;
vector<vector<vector<int>>> visited;
vector<vector<int>> arr;
int result = -1;
void bfs (){

    queue<Node> que;
    que.push({0,0,1,0});
    visited[0][0][0] = 1;

    while(!que.empty()){
        int x = que.front().x;
        int y = que.front().y;
        int cnt = que.front().cnt;
        int isUsed = que.front().isUsed;
        que.pop();
        if(x==m-1 && y == n-1) {
            result =cnt;
            return;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx >=m || ny<0 || ny>=n) {
                continue;
            }
            if(arr[ny][nx] == 0 && !visited[ny][nx][isUsed]) {
                visited[ny][nx][isUsed] = true;
                que.push({nx,ny, cnt+1,isUsed});
            }
            if(isUsed==0 && arr[ny][nx] == 1 && !visited[ny][nx][1]) {
                visited[ny][nx][1] = true;
                que.push({nx,ny, cnt+1,1});
            }


        }
    }

}

int main() {

    cin >> n >> m;
    visited.assign(n, vector<vector<int>>(m, vector<int>(2, 0)));
    arr.assign(n, vector<int>(m,0));
    for(int i=0; i<n; i++) {
        string input;
        cin >>input;
        for(int j=0; j<m; j++) {
            arr[i][j] = input[j]-'0';
        }
    }

    bfs();

    cout << result << '\n';
    return 0;

}