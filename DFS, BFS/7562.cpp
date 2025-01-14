#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {-1,-2,-2,-1,1,2,2,1};

int bfs(int n, int x1, int y1, int x2, int y2) {
    vector<vector<int>> arr(n, vector<int>(n,0));
    queue<pi> que;
    que.push({x1,y1});
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        if(x==x2 && y==y2) {
            return arr[y][x];
        }
        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n) {
                continue;
            }
            if(arr[ny][nx]>0){
                continue;
            }
            que.push({nx,ny});
            arr[ny][nx] = arr[y][x]+1;

        }

    }
    return arr[y2][x2];
}

int main() {

    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        cin>>n;
        int a,b,c,d;
        cin >> a>> b;
        cin >> c>>d;
        cout << bfs(n, a, b, c, d) <<'\n';
    }
    return 0;
}