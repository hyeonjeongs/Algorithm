#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int n, m;
int bfs(vector<vector<int>> maps) {
    int cnt =1;
    queue<pi> que;
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    vector<vector<int>> count(n, vector<int>(m,0));
    que.push({0,0});
    visited[0][0] = true;
    count[0][0] = 1;
    while(!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();
        for(int i=0;i<4; i++) {
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx<0 || nx>=m || ny<0 || ny>=n || visited[ny][nx]) {
                continue;
            }
            if(maps[ny][nx]==0) {
                continue;
            }
            if(nx == m-1 && ny == n-1) {
                return count[cy][cx] +1;
            }
            que.push({nx, ny});
            count[ny][nx] = count[cy][cx]+1;
            visited[ny][nx] = true;
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    answer = bfs(maps);
    return answer;
}