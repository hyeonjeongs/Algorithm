# include <iostream>
# include <vector>
# include <deque>
# include <queue>
using namespace std;
int n, k, l;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

struct DATA {
    int time;
    char chars;
};
typedef pair<int, int> pi;
queue<DATA> que;
bool outOfRange(int x, int y) {
    return x<=0 || x>n || y<=0 || y>n;
}


int main() {

    cin >> n;
    cin >> k;
    vector<vector<int> > board(n+1, vector<int>(n+1, 0));

    for (int i=0; i<k; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    }
    cin >> l;

    for (int i=0; i<l; i++) {
        int x;
        char c;
        cin >> x >> c;
        que.push({x, c});
    }

    int times = 0;
    deque<pi> deq;
    deq.push_back({1,1});
    int dir = 0;
    board[1][1] = 2;
    while (true) {
        times++;

        int nx = deq.back().first + dx[dir];
        int ny = deq.back().second + dy[dir];
        if (outOfRange(nx, ny) || board[ny][nx]==2) {
            break;
        }
        if (board[ny][nx]==0) { // 사과 없으면
            board[deq.front().second][deq.front().first] = 0;
            deq.pop_front();
        }
        deq.push_back({nx,ny});
        board[ny][nx] = 2;

        // 방향 바꾸기
        if (!que.empty()) {
            int dir_times = que.front().time;
            char chs = que.front().chars;

            if (dir_times == times) {
                que.pop();
                if (chs == 'L') {
                    dir = (dir+3)%4;
                } else {
                    dir = (dir+1)%4;
                }
            }
        }

    }
    cout << times << '\n';
}