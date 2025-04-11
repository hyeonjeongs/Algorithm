#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int dx[] = {1, -1, 0, 0}; // 동서남북
int dy[] = { 0,0,1,-1};
typedef pair<int, int> pi;
int n, m, f;

bool outOfSpace(int x, int y) {
    return x<0 || x>=n || y<0 || y>=n;
}

bool outOfTime(int x, int y) {
    return x<0 || x>=3*m || y<0 || y>=3*m;
}

struct SPREAD { // 시간이상현상
    int x;
    int y;
    int dir;
    int v;
    bool isPossible;
};

struct INDEX { // 어떤 도형인지랑 r,c 표현
    int idx;
    int x;
    int y;
};
struct TIMES { // 시간의벽 전개도
    int num;
    int dir;
};

INDEX out_index; // 동서남북 선택(0,1,2,3), r, c (탈출구 위치)
INDEX machine_index; // 동서남북윗 밖 (0,1,2,3,4,5) r,c (현재 타임머신 위치)
pi start_space;
vector<vector<int>> space;
vector<vector<TIMES>> times;
vector<vector<bool>> space_visit;
vector<vector<bool>> time_visit;
vector<SPREAD> spreads;
int result = 0;

void makeTimeSpace(int idx, vector<vector<int>> arr) {
    vector<vector<int>> copy = arr;

    if(idx==0) { // 동 (반시계)
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                int number = copy[j][m-1-i];
                times[m+i][2*m+j] = {number, idx};
            }
        }

    }else if(idx==1) { // 서 (시계)
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                int number = copy[m-j-1][i];
                times[m+i][j] = {number, idx};
            }
        }

    }else if(idx==2) { // 남
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                times[2*m+i][m+j] = {arr[i][j], idx};
            }
        }

    }
    else if(idx==3) { //북 (점대칭)
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                int number = copy[m-1-i][m-1-j];
                times[i][m+j] = {number, idx};
            }
        }

    } else { // 윗면 (타임머신 위치 확인)
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                if(arr[i][j] == 2){
                    machine_index = {idx, j, i};
                }
                times[m+i][m+j] = {arr[i][j], idx};
            }
        }

    }

}

void findOutLocation() { // 탈출구 찾기
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(space[i][j]==3) { // 처음 3 나오면
                for(int a=0; a<m; a++) {
                    for(int b=0; b<m; b++) {

                        for(int k=0; k<4; k++) {
                            int nx = dx[k] + j+b;
                            int ny = dy[k] + i+a;
                            if(outOfSpace(nx, ny)) {
                                continue;
                            }
                            if(space[ny][nx] == 0) {
                                start_space = {nx, ny};
                                if(k==0){ // 동
                                    out_index = {k, 3*m-1, m+a};
                                } else if(k==1) { // 서
                                    out_index = {k, 0, m+a};
                                } else if(k==2) { // 남
                                    out_index = {k, m+b, 3*m-1};
                                } else { // 북
                                    out_index = {k, m+b, 0};
                                }
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

}

struct SPREAD_RESULT {
    vector<vector<int>> space;
    vector<SPREAD> spreads;
};
SPREAD_RESULT spreadSpace(vector<vector<int>> current_space, vector<SPREAD> current_spreads, int num) {
    for(int i=0; i<current_spreads.size(); i++) {
        SPREAD current = current_spreads[i];
        if(current.isPossible) {
            if(num%current.v == 0) { // 배수인경우만 퍼뜨리기
                int nx = current.x + dx[current.dir];
                int ny = current.y + dy[current.dir];
                if(outOfSpace(nx, ny) || current_space[ny][nx]== 4 || current_space[ny][nx] == 1) {
                    current_spreads[i].isPossible = false;
                    continue;
                }
                current_space[ny][nx] = 5;
                current_spreads[i].x = nx;
                current_spreads[i].y = ny;

            }
        }
    }
    return {current_space, current_spreads};
}

struct BFS {
    int x;
    int y;
    int num;
    vector<vector<int>> space;
    vector<SPREAD> spread;
};

void bfsSpace() { // 단면도 탐색
    queue<BFS> que;
    que.push({start_space.first, start_space.second, 1, space, spreads});
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[que.front().y][que.front().x] = true;
    int mins = 1e6;


    while(!que.empty()) {
        int cx = que.front().x;
        int cy = que.front().y;
        int num = que.front().num;
        vector<vector<int>> current_space = que.front().space;
        vector<SPREAD> current_spread = que.front().spread;

        if(current_space[cy][cx] == 4) {
            mins = min(mins, num);
            machine_index = {5, cx, cy};
            spreads= current_spread;
            space = current_space;
            break;
        }

        SPREAD_RESULT current_result = spreadSpace(current_space, current_spread, result +num);
        current_space = current_result.space;
        current_spread = current_result.spreads;
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(outOfSpace(nx, ny) || visited[ny][nx] || current_space[ny][nx] ==3 || current_space[ny][nx] == 5 || current_space[ny][nx] == 1) {
                continue;
            }
            que.push({nx, ny, num+1, current_space, current_spread});
            visited[ny][nx] = true;
        }
    }

    if(mins != 1e6) {
        result += mins;
    }
}

struct BFS_TIME {
    int x;
    int y;
    int dir;
    int num;
    vector<vector<int>> space;
    vector<SPREAD> spread;
};
void bfsTimes() {

    vector<vector<bool>> visited(3*m, vector<bool>(3*m, false));
    queue<BFS_TIME> que;
    que.push({machine_index.x, machine_index.y, 4, 0, space, spreads});

    visited[que.front().y][que.front().x] = true;
    int mins = 1e5;

    while(!que.empty()) {
        int cx = que.front().x;
        int cy = que.front().y;
        int num = que.front().num;
        int dir = que.front().dir;
        vector<vector<int>> current_space = que.front().space;
        vector<SPREAD> current_spread = que.front().spread;

        if(cx == out_index.x && cy == out_index.y && out_index.idx == dir) {
            mins = min(mins, num);
            space = current_space;
            spreads = current_spread;
            break;
        }

        SPREAD_RESULT spread_result = spreadSpace(current_space, current_spread, num);
        current_spread = spread_result.spreads;
        current_space = spread_result.space;
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(outOfTime(nx, ny) || visited[ny][nx] || times[ny][nx].num == 1) {
                continue;
            }

            if(times[ny][nx].num != -1 && times[ny][nx].dir != times[cy][cx].dir) {
                dir = times[ny][nx].dir;
            }
            if(times[ny][nx].num == -1) {
                if(times[cy][cx].dir ==0){ // 동
                    if(cy ==m) {
                        nx = cy + (m-1);
                        ny = 3*m - cx - 1;
                        dir = 3;
                    }if(cy == 2*m-1) {
                        nx = 3*m - cy - 1 + (m-1);
                        ny = cx;
                        dir =2;
                    }

                } else if(times[cy][cx].dir ==1){ // 서
                    if(cy ==m) {
                        nx = 3*m - cy - 1 - (m-1);
                        ny = cx ;
                        dir = 3;
                    }if(cy == 2*m-1) {
                        nx = cy - (m-1);
                        ny = 3*m - cx - 1;
                        dir = 2;
                    }
                } else if(times[cy][cx].dir ==2){ // 남
                    if(cx ==m) {
                        nx = 3*m - cy -1;
                        ny = cx + (m-1);
                        dir = 1;
                    }if(cx == 2*m-1) {
                        nx = cy;
                        ny = 3*m - cx  -1 + (m-1);
                        dir = 0;
                    }
                } else if(times[cy][cx].dir ==3){ // 북
                    if(cx ==m) {
                        nx = cy;
                        ny = 3*m - cx - 1- (m-1);
                        dir = 1;
                    }if(cx == 2*m-1) {
                        nx = 3*m - cy - 1;
                        ny = cx- (m-1);
                        dir = 0;
                    }
                }
            }
            que.push({nx, ny,  dir, num+1, current_space, current_spread});
            visited[ny][nx] = true;
        }
    }
    if(mins != 1e5) {

        result += mins;
    }
}


int main() {
    cin >> n >> m >> f;

    space.assign(n, vector<int>(n, 0));
    times.assign(3*m, vector<TIMES>(3*m, {-1,-1}));
    space_visit.assign(n, vector<bool>(n, false));
    time_visit.assign(n, vector<bool>(n, false));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> space[i][j];
        }
    }

    for(int i=0; i<5; i++) {
        vector<vector<int>> arr(m, vector<int>(m, 0));
        for(int j=0; j<m; j++) {
            for(int k=0; k<m; k++) {
                cin >> arr[j][k];
                if(arr[j][k]==2) { // 머신위치
                    machine_index = {4, k, j};
                }
            }
        }
        makeTimeSpace(i, arr); // 전개도 만들기

    }
    for(int i=0; i<f; i++) {
        int r, c, d, v;
        cin >> r >> c >> d >> v;
        spreads.push_back({c, r, d, v, true});
    }

    findOutLocation(); // 탈출구 찾기

    bfsTimes();
    cout << result << " lskjfsd " << endl;
    int current_result = result;
    if(result == 0) {
        cout << "-1" << '\n';
        return 0;
    }

    bfsSpace();

    if(result == current_result) {
        cout << "-1" << '\n';
    } else {
        cout << result << '\n';
    }

    return 0;
}