#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
typedef pair<int, int> pi;
int n, m;
vector<vector<int>> arr;
vector<vector<bool>> visited;

int max_num = 0;
vector<pi> maxs;
int result = 0;


bool cmp(pi a, pi b) {
    if(a.first = b.first) {
        return a.second > b.second;
    }
    return a.first > b.first;
}

bool outOfBounds(int x, int y) {
    return x<0 || x>=n || y<0 || y>=n;
}

void findBlock(int x, int y) {
    int min_x = x, min_y = y;
    queue<pi> que;
    que.push(pi(x,y));
    int number = arr[y][x];
    int cnt = 1;

    while(!que.empty()) {

        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(outOfBounds(nx, ny) || visited[ny][nx]) {
                continue;
            }
            if(arr[ny][nx] == number || arr[ny][nx] == 0) {
                if(arr[ny][nx]!=0) {
                    if(min_y>ny) {
                        min_x = nx; min_y = ny;
                    } else if(min_y == ny && min_x>nx) {
                        min_x = nx; min_y = ny;
                    }
                }
                cnt++;
                que.push({nx, ny});
                visited[ny][nx] = true;
            }

        }

    }

    vector<pi> copies = {pi(min_x,min_y)};
    if(cnt > max_num) {
        maxs = copies;
        max_num = cnt;
    } else if(cnt == max_num) {
        maxs.push_back({min_x,min_y});
    }
}

void getScore(){

    vector<vector<bool>> c_visited;
    c_visited.assign(n, vector<bool>(n,false));
    queue<pi> que;
    que.push({maxs[0].first, maxs[0].second});

    int number = arr[maxs[0].second][maxs[0].first];
    int score = 1;
    c_visited[maxs[0].second][maxs[0].first] = true;


    while(!que.empty()) {

        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(outOfBounds(nx, ny) || c_visited[ny][nx]) {
                continue;
            }
            if(arr[ny][nx] == number || arr[ny][nx] ==0) {
                score++;
                arr[ny][nx]=-2;
                que.push({nx, ny});
                c_visited[ny][nx] = true;
            }

        }

    }
    result += pow(score,2);

}

void turnBlock() {

    vector<vector<int>> copy = arr;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            copy[n-j-1][i] = arr[i][j];
        }
    }

    arr = copy;
}

void dropDown() {
    // -2 만났을때
    // 0보다 큰거만났을떄
    // -1 만났을때 갈수있는곳 다시 갱신
    bool current_possible = true;
    pi moves = {-1,-1};
    queue<pi> starts;

    for(int i=0; i<n; i++) { //x
        for(int j=n-1; j>=0; j--) { // y
            if(arr[j][i] == -2 && moves.first<0) { // 빈칸
                moves = {i, j}; // (x, y)
            } else if(arr[j][i] == -1 || j==0) { // 막힌곳
                vector<vector<int>> copy = arr;
                if(moves.first<0) {
                    continue;
                }
                while(!starts.empty()) {
                    int new_x = starts.front().first;
                    int new_y = starts.front().second;
                    starts.pop();

                    copy[moves.second][moves.first] =arr[new_y][new_x];
                    copy[new_y][new_x] = -2;
                    moves = {moves.first, moves.second-1};
                }
                arr = copy;
                moves = {-1,-1};

            } else { // 움직일애들
                if(j==n-1) {
                    continue;
                }
                starts.push({i, j});
            }

        }
    }

}

int main() {

    cin >> n >> m;
    arr.assign(n, vector<int>(n, 0));

    vector<pi> copy;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    while(1) {

        max_num = 0;
        maxs = copy;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j] <= 0) {
                    continue;
                }
                visited.assign(n, vector<bool>(n, false));
                visited[i][j] = true;
                findBlock(j, i);
            }
        }

        if(max_num<=1) {
            break;
        }
        sort(maxs.begin(), maxs.end(), cmp);

        getScore();
        dropDown();
        turnBlock();
        dropDown();
        cout << " lksjfdlksd "<< endl;
        cout << result<< " , " << endl;
    }

    cout << result << '\n';
    return 0;

}