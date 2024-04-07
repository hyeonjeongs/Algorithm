#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;
typedef pair<int, char> pi;
typedef pair<int, int> ii;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
void dummyGame(queue<pi> que, vector<vector<bool>> apple, int n) {
    int direction = 0;
    int x=1, y=1;
    int time=0;
    deque<ii> deq;
    vector<vector<bool>> snake(n+1, vector<bool>(n+1,false));
    snake[y][x] = true;
    deq.push_back({x, y});
    while(1) {
        // 다음 위치가 벗어나거나 true이면 break;
        time++;

        //이동 문제없나?
        int nx = x+dx[direction];
        int ny = y+dy[direction];
        if(nx<=0 || nx>n || ny<=0 || ny>n || snake[ny][nx]) {

            break;
        }

        // 이동하기(사과 확인)
        if(!apple[ny][nx]) {
            int ddx = deq.front().first;
            int ddy = deq.front().second;
            snake[ddy][ddx] = false;
            deq.pop_front();
        } else {
            apple[ny][nx] = false;
        }
        snake[ny][nx] = true;
        deq.push_back({nx, ny});
        x = nx; y = ny; // 현재 좌표 이동해주기

        // 방향 (바꿔주기)
        int way_int = que.front().first;
        if(way_int == time) {
            char way_char = que.front().second;
            if(way_char =='D') {
                direction = (direction+1)%4; // 왼쪽
            }
            if(way_char =='L') {
                direction = (direction-1+4)%4; // 오른쪽
            }
            que.pop();
        }

    }
    cout<<time<<'\n';
}

int main() {
    int n, k, l;
    queue<pi> que;
    cin>>n;
    vector<vector<bool>> apple(n+1, vector<bool>(n+1,false));
    cin>>k;

    // 행, 열
    for(int i=0; i<k; i++) {
        int rol, col;
        cin>>rol>>col;
        apple[rol][col] = true;
    }
    cin>>l;
    for(int i=0; i<l; i++) {
        int x;
        char c;
        cin>> x>>c;
        que.push({x,c});
    }

    dummyGame(que, apple, n);

    return 0;
}