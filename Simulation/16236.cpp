/**
 * 틀린이유 : 거리 같을 때 dx, dy 순서만 정하면 가장 먼저 호출된애가 우선순위 가장 높을 것이라 생각함
 *
 * 예제입력 4번에서 잘못 나오는 것으로 보여졌음
 * 그래서 후보군에 대해 정렬하는 부분 추가
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
vector<vector<int>> space;
vector<int> fish;

struct Data {
    int x;
    int y;
    int cnt;
};

int energy = 2;
int possible_num = 0;
int dx[] = {0,-1,1,0};
int dy[] = {-1,0,0,1};
int n;
pi shark;
int times = 0;

bool outOfRange(int x, int y) {
    if(x<0 || x>=n || y<0 || y>=n) {
        return true;
    }
    return false;
}

int bfs() {
    queue<Data> que;
    que.push({shark.first, shark.second, 0});
    vector<vector<bool>> visited(n, vector<bool>(n,false));
    visited[shark.second][shark.first] = true;
    vector<Data> candidate;
    int dist =-1;

    while(!que.empty()) {
        int cx = que.front().x;
        int cy = que.front().y;
        int cn = que.front().cnt;
        que.pop();

        if(space[cy][cx] < energy && space[cy][cx]!=0) {
            if(dist == -1 || cn == dist) {
                candidate.push_back({cx,cy, cn});
                dist = cn;
            } else {
                break;
            }
        }
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(outOfRange(nx,ny) || space[ny][nx]>energy || visited[ny][nx]) {
                continue;
            }

            que.push({nx, ny, cn+1});
            visited[ny][nx]= true;
        }
    }

    if(candidate.empty()) {
        return -1;
    }

    sort(candidate.begin(), candidate.end(),[](const Data &a, const Data &b){
        if(a.y== b.y) {
            return a.x < b.x;
        }
        return a.y < b.y;
    } );

    Data results = candidate[0];
    space[results.y][results.x] = 0;
    shark.first = results.x;
    shark.second = results.y;
    times += results.cnt;
    possible_num++;

    if(possible_num== energy) {
        possible_num=0;
        energy++;
    }

    return times;
}

int main() {
    cin >> n;

    space.assign(n, vector<int>(n,0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> space[i][j];
            if(space[i][j] == 9) {
                shark = {j, i};
                space[i][j] = 0;
            }
        }
    }

    while(1) {
        int cnts = bfs();
        if(cnts<0) {
            break;
        }
    }
    cout<< times << '\n';

    return 0;
}