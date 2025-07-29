#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
// 1. 구멍 결정 -> -1로 세팅
// 2. 가장자리 없애기 (둘러싸고 있는것중 0이 있으면 없애는거)
int current = 0, answer = 0;
vector<vector<int>> cheese;
vector<vector<int>> hole_cheese;
vector<vector<bool>> visited;
int height, width;
bool flag = false;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

bool outOfBounds(int x, int y) {
    return x<=0 || x>=width-1 || y<=0 || y>=height-1;
}

void bfs(int y, int x) {

    queue<pi> que;

    que.push({x, y});

    while(!que.empty()) {
        int cx= que.front().first;
        int cy =que.front().second;
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = cx+ dx[i];
            int ny = cy + dy[i];

            if(outOfBounds(nx, ny)) {
                flag = true;
                continue;
            }
            if(!visited[ny][nx] && cheese[ny][nx]==0) {
                visited[ny][nx] =true;
                que.push({nx, ny});
            }

        }
    }


}

void setHole(vector<vector<bool>> visit, int y, int x) {
    queue<pi> que;

    que.push({x, y});

    while(!que.empty()) {
        int cx= que.front().first;
        int cy =que.front().second;

        que.pop();
        hole_cheese[cy][cx] = -1;

        for(int i=0; i<4; i++) {
            int nx = cx+ dx[i];
            int ny = cy+ dy[i];

            if(outOfBounds(nx, ny)) {
                continue;
            }
            if(!visit[ny][nx] && cheese[ny][nx]==0) {
                visit[ny][nx] =true;
                que.push({nx, ny});
            }

        }
    }
}

void makeHole() {
    visited.assign(height, vector<bool>(width, 0));

    for(int i=1; i<height-1; i++) {
        for(int j=1; j<width-1; j++){
            if(!visited[i][j] && cheese[i][j] ==0) {
                vector<vector<bool>> visit = visited;
                flag = false;
                visited[i][j] =true;
                bfs(i, j);

                if(!flag) {
                    setHole(visit, i, j);
                }
            }
        }
    }
}

void removeCheese() {

    int cnt = 0;
    vector<vector<int>> copys = cheese;
    for(int i=1; i<height-1; i++)  {
        for(int j=1; j<width-1; j++) {
            if(copys[i][j] == 1) {
                for(int k=0; k<4; k++) {
                    int nx = j +dx[k];
                    int ny = i + dy[k];
                    if(copys[ny][nx] == 0 && hole_cheese[ny][nx] != -1) {
                        cheese[i][j] = 0;
                        cnt++;
                        break; // 여기서 지우고 break 안함
                    }
                }
            }
        }
    }

    if(current >0 && current-cnt == 0) {
        answer = current;
    }
    current -= cnt;
}

int main() {

    cin >> height >> width;
    cheese.assign(height, vector<int>(width, 0));
    int result = 0;

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            cin >> cheese[i][j];
            if(cheese[i][j] ==1) {
                current++;
            }
        }
    }

    while(current>0) {
        result++;
        hole_cheese = cheese;
        makeHole();
        removeCheese();

    }

    cout <<result <<'\n' << answer << '\n';

    return 0;

}