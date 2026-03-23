# include <iostream>
# include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
int n, m;
int result = 1e6;
vector<pi> virus;
vector<vector<int>> arr;
int total = 0;
struct Data {
    int x;
    int y;
    int cnt;
};
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
void bfs(vector<pi> v) {
    int counts = total;

    vector<vector<int>> copy = arr;
    queue<Data> que;
    for (int i=0; i<v.size(); i++) {
        que.push({v[i].first, v[i].second, 0});
        copy[v[i].second][v[i].first] = -2;
    }
    int maxSize =0 ;
    while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int cnt = que.front().cnt;
        que.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0 || nx>=n || ny<0 || ny>=n || copy[ny][nx]==-2 || copy[ny][nx]==1) {
                continue;
            }
            if (copy[ny][nx]==0) {
                counts--;
                maxSize = cnt+1;
            }
            copy[ny][nx] =-2;
            que.push({nx, ny, cnt+1});
        }
    }
    if (counts ==0) {
        result = min(result, maxSize);
    }

}
void dfs(vector<pi> v, int index) {
    if (v.size() == m) {
        bfs(v);
        return;
    }
    for (int i=index; i<virus.size(); i++) {
        v.push_back(virus[i]);
        dfs(v, i+1);
        v.pop_back();
    }
}
int main() {

    cin >> n >> m;
    arr.assign(n, vector<int>(n,0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
            if (arr[i][j]==2) {
                virus.push_back({j,i});
            }
            if (arr[i][j]==0) {
                total++;
            }
        }
    }

    vector<pi> v;
    dfs(v, 0);

    if (result == 1e6) {
        result = -1;
    }
    cout << result << '\n';
}
