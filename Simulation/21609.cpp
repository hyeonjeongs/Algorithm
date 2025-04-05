#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
typedef pair<int, int> pi;
int n, m;
vector<vector<int>> arr;

int max_num = 0;
pi maxs;
int rainbow_count =0;
int result = 0;


bool outOfBounds(int x, int y) {
    return x<0 || x>=n || y<0 || y>=n;
}

void findBlock(int x, int y) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int min_x = x, min_y = y;
    queue<pi> que;
    que.push(pi(x,y));
    int number = arr[y][x];
    int cnt = 1;
    int rains_cnt = 0;

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
                } else if(arr[ny][nx] == 0) {
                    rains_cnt++;
                }
                cnt++;
                que.push({nx, ny});
                visited[ny][nx] = true;
            }

        }

    }

    pi copies = pi(min_x,min_y);
    if(cnt > max_num) {
        maxs = copies;
        max_num = cnt;
    } else if(cnt == max_num) {
        if(rainbow_count < rains_cnt) {
            maxs = copies;
            max_num = cnt;
            rainbow_count = rains_cnt;
        } else if(rainbow_count == rains_cnt){
            if(min_y > maxs.second) {
                maxs = copies;
            } else if(min_y == maxs.second) {
                if(min_x > maxs.first) {
                    maxs = copies;
                }
            }
        }
    }
}

void getScore(){

    vector<vector<bool>> c_visited;
    c_visited.assign(n, vector<bool>(n,false));
    queue<pi> que;
    que.push({maxs.first, maxs.second}); // (x, y)

    int number = arr[maxs.second][maxs.first];
    int score = 1;
    c_visited[maxs.second][maxs.first] = true;
    arr[maxs.second][maxs.first] =-2;


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


    for(int i=0; i<n; i++) {
        for(int j= n-1; j>=0; j--) {
            if(arr[j][i] == -2) {
                int x = i;
                int y = j;
                while(y>0 && arr[y][x]==-2) {
                    y--;
                }
                if(arr[y][x] == -1) {
                    continue;
                }
                arr[j][i] = arr[y][x];
                arr[y][x] = -2;
            }
        }
    }


}

int main() {

    cin >> n >> m;
    arr.assign(n, vector<int>(n, 0));

    pi copy = {-1,-1};

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    while(1) {

        max_num = 0;
        rainbow_count = -1;
        maxs = copy;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j] <= 0) {
                    continue;
                }

                findBlock(j, i);
            }
        }

        if(max_num<=1) {
            break;
        }

        getScore();
        dropDown();
        turnBlock();
        dropDown();

    }

    cout << result << '\n';
    return 0;

}