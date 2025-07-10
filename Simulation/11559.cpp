#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
// 뿌요 상하좌우 확인 -> 연쇄(여러 그룹이면 동시에) -> 중력 떨어뜨리기
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

vector<vector<char>> arr;
vector<pi> visited;
int findCount(int y, int x) {
    int num = 1;
    queue<pi> que;
    que.push({x, y});
    vector<vector<bool>> visit(12, vector<bool>(6,false));

    char ch = arr[y][x];
    while(!que.empty()) {
        int cx =que.front().first;
        int cy = que.front().second;
        visit[cy][cx] =true;
        visited.push_back({cx, cy});

        que.pop();
        if(ch=='.') {
            continue;
        }

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0 || nx>=6 || ny<0 || ny>=12) {
                continue;
            }
            if(visit[ny][nx]) {
                continue;
            }
            if(arr[ny][nx] !='.' && arr[ny][nx] == ch) {
                num++;
                visit[ny][nx] = true;
                que.push({nx, ny});
            }

        }
    }
    return num;

}

void dropTop(){

    for(int i=0; i<6; i++) {
        int down = -1, top = -1;
        for(int j=0; j<12; j++) {
            if(arr[j][i] != '.' && top==-1) {
                top= j;
            }
            if(arr[j][i] == '.') {
                down = j;
            }
        }
        if(down==-1 || top == -1) {
            continue;
        }
        if(down!=top) {
            int drops = down;
            for(int k=down; k>=top; k--) {
                if(arr[k][i] != '.') {
                    arr[drops--][i] =arr[k][i];
                    arr[k][i] = '.';
                }
            }
        }

    }
}

int main() {
    int result = 0;

    arr.assign(12, vector<char>(6,'.'));


    for(int i=0; i<12; i++) {
        string str;
        cin >> str;
        for(int j=0; j<str.size(); j++) {
            arr[i][j] = str[j];
        }
    }

    while(1) {

        int current = 0;

        vector<pi> copy;
        for(int i=11; i>=0; i--) {
            for(int j=0; j<6; j++) {
                if(arr[i][j] != '.') {
                    visited = copy;
                    int counts = findCount(i, j);

                    if(counts>=4) {
                        current += counts;
                        for(int k=0; k<visited.size(); k++) {
                            arr[visited[k].second][visited[k].first] = '.';
                        }
                    }
                }
            }
        }

        if(current == 0){
            break;
        } else {
            result++;
            dropTop();
        }
    }
    cout << result <<'\n';

    return 0;
}