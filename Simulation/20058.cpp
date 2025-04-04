#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
typedef pair<int, int> pi;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int nn;
int sum =0;
vector<vector<int>> a;

void rotateRect(int x, int y, int sizes) {
    vector<vector<int>> temp (sizes, vector<int>(sizes, 0));
    for(int i=0; i<sizes; i++) {
        for(int j=0; j<sizes; j++) {
            temp[j][sizes-i-1] = a[i+y][j+x];
        }
    }

    
    for(int i=0; i<sizes; i++) {
        for(int j=0; j<sizes; j++) {
            a[i+y][j+x] = temp[i][j];
        }
    }
}

void divideRect(int q) {
    for(int i=0; i<nn; i+=q) {
        for(int j=0; j<nn; j+=q) {
            rotateRect(i, j, q);
        }
    }
}

void checkDirection() {
    vector<vector<bool>> checkIce(nn, vector<bool>(nn, false));
    for(int i=0; i<nn; i++) {
        for(int j=0; j<nn; j++) {
            int cnt =0;

            for(int k=0; k<4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if(nx<0 || ny<0 || nx>=nn || ny>=nn) {
                    continue;
                }
                if(a[ny][nx]>0) {
                    cnt++;
                }
            }

            if(cnt<3) {
                checkIce[i][j] = true;
            }
        }
    }

    for(int i=0; i<nn; i++) {
        for(int j=0; j<nn; j++) {
            if(checkIce[i][j] && a[i][j] >0) {
                a[i][j]--;
                sum--;
            }
        }
    }
}

int bfs() {
    vector<vector<bool>> visited(nn, vector<bool>(nn, false));
    queue<pi> que;
    int max_sum = 0;

    for(int i=0; i<nn; i++) {
        for(int j=0; j<nn; j++) {
            if(visited[i][j] || a[i][j] ==0) {
                continue;
            }
            int current = 0;
            que.push({j, i}); // (x, y)

            while(!que.empty()) {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                visited[y][x] = true;
                current ++;
                for(int k=0; k<4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx<0 || ny<0 || nx>=nn || ny>=nn || a[ny][nx]==0 || visited[ny][nx]) {
                        continue;
                    }

                    visited[ny][nx] = true;
                    que.push({nx, ny});
                }
            }

            max_sum = max(max_sum, current);
        }
    }

    return max_sum;
}

int main() {
    int n,q;
    cin>>n>>q;
    vector<int> qq(q, 0);
    nn = pow(2, n);
    a.assign(nn, vector<int>(nn, 0));

    for(int i=0; i<nn; i++) {
        for(int j=0; j<nn; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }

    for(int i=0; i<q; i++) {
        int input;
        cin>> input;
        qq[i] = pow(2, input);
    }
    for(int i=0; i<q; i++) {
        divideRect(qq[i]);
        checkDirection();
    }

    int result = bfs();
    cout<< sum <<'\n';
    cout << result <<'\n';

    return 0;
}
