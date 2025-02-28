#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pi;
int n,m;
vector<vector<char>> board;
vector<pi> coins;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
struct NODE {
    int x1;
    int y1;
    int x2;
    int y2;
    int cnt;
};

int bfs() {

    map<vector<int>, int> maps;
    queue<NODE> que;

    NODE nodes = NODE({coins[0].first, coins[0].second, coins[1].first, coins[1].second, 0});
    vector<int> numbers = {coins[0].first, coins[0].second, coins[1].first, coins[1].second};
    que.push(nodes);
    maps.insert({numbers, 1});

    int result = -1;
    while(!que.empty()) {

        int cx1 = que.front().x1;
        int cy1 = que.front().y1;
        int cx2 = que.front().x2;
        int cy2 = que.front().y2;
        int count = que.front().cnt;
        que.pop();

        if(count>=10) { // break 아닌 이유: que에 저장된것중에 아직 가능한게 남아있을 수 있음
            continue;
        }

        for(int i=0; i<4; i++) {

            int nx1 = cx1 + dx[i];
            int ny1 = cy1 + dy[i];
            int nx2 = cx2 + dx[i];
            int ny2 = cy2 + dy[i];

            // 방문했던 곳인지
            vector<int> visited = {nx1, ny1, nx2, ny2};
            if(maps.find(visited) != maps.end()) {
                continue;
            }

            // 하나만 떨어졌는지
            int drop_count =0;
            if(nx1<0 || nx1>=m || ny1<0 || ny1>=n) {
                drop_count++;
            }
            if(nx2<0 || nx2>=m || ny2<0 || ny2>=n) {
                drop_count++;
            }
            if(drop_count==1) {
                result = count+1;
                return count+1;
            } else if(drop_count==2) {
                continue;
            }

            // 벽인 경우
            if(board[ny1][nx1] == '#') {
                nx1 = cx1;
                ny1 = cy1;
            }
            if(board[ny2][nx2] == '#') {
                nx2 = cx2;
                ny2 = cy2;
            }
            maps.insert({{nx1, ny1, nx2, ny2}, 1});
            que.push({nx1, ny1, nx2, ny2, count+1});
        }
    }
    return result;
}

int main() {

    cin >> n >> m;
    board.assign(n, vector<char>(m,' '));

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<m; j++) {
            board[i][j] = str[j];
            if(str[j] == 'o') {
                coins.push_back({j, i}); // (x, y)
                board[i][j] = '.';
            }
        }
    }

    cout << bfs() << '\n';
    return 0;

}