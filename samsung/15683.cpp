# include <iostream>
# include <vector>
# include <queue>

using namespace std;
typedef pair<int, int> pi;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

vector<vector<bool>> visited;
vector<pi> location;
int n, m;
int result = 1e9;
bool outOfBounds(int x, int y) {
    return x<0 || x>=m || y<0 || y>=n;
}
void bfs(int index, vector<vector<int>> arr) {
    if (location.size() <= index) {
        int cnt =0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (arr[i][j] == 0) {
                    cnt++;
                }
            }
        }
        result = min(result, cnt);
        return;
    }
    int x = location[index].first;
    int y = location[index].second;

    if (arr[y][x] == 1) {
        for (int i=0; i<4; i++) {
            vector<vector<int>> copy = arr;
            int cx = x;
            int cy = y;
            while (1) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (outOfBounds(nx, ny) || copy[ny][nx] ==6) {
                    break;
                }
                if (copy[ny][nx] ==0) {
                    copy[ny][nx] = -1;
                }
                cy = ny; cx = nx;
            }
            bfs(index+1, copy);
        }
    } else if (arr[y][x] == 2) {
        for (int i=0; i<2; i++) {
            vector<vector<int>> copy = arr;
            for (int j=0; j<3; j+=2) {
                int cx = x;
                int cy = y;
                int idx = i+j;
                while (1) {
                    int nx = cx + dx[idx];
                    int ny = cy + dy[idx];
                    if (outOfBounds(nx, ny) || copy[ny][nx] ==6) {
                        break;
                    }
                    if (copy[ny][nx] ==0) {
                        copy[ny][nx] = -1;
                    }
                    cy = ny; cx = nx;
                }
            }
            bfs(index+1, copy);
        }

    }else if (arr[y][x] == 3) {

        for (int i=0; i<4; i++) {
            vector<vector<int>> copy = arr;
            for (int j=0; j<2; j++) {
                int idx = (i+j)%4;
                int cx = x;
                int cy = y;
                while (1) {
                    int nx = cx + dx[idx];
                    int ny = cy + dy[idx];
                    if (outOfBounds(nx, ny) || copy[ny][nx] ==6) {
                        break;
                    }
                    if (copy[ny][nx] ==0) {
                        copy[ny][nx] = -1;
                    }
                    cy = ny; cx = nx;
                }
            }
            bfs(index+1, copy);

        }
    } else if (arr[y][x] == 4) {
        for (int i=0; i<4; i++) {
            vector<vector<int>> copy = arr;
            for (int j=0; j<3; j++) {
                int idx = (i+j)%4;
                int cx = x;
                int cy = y;
                while (1) {
                    int nx = cx + dx[idx];
                    int ny = cy + dy[idx];
                    if (outOfBounds(nx, ny) || copy[ny][nx] ==6) {
                        break;
                    }
                    if (copy[ny][nx] ==0) {
                        copy[ny][nx] = -1;
                    }
                    cy = ny; cx = nx;
                }
            }
            bfs(index+1, copy);

        }

    } else {
        vector<vector<int>> copy = arr;
        for (int i=0; i<4; i++) {
            int cx = x;
            int cy = y;
            while (1) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (outOfBounds(nx, ny) || copy[ny][nx] ==6) {
                    break;
                }
                if (copy[ny][nx] ==0) {
                    copy[ny][nx] = -1;
                }
                cy = ny; cx = nx;
            }
        }
        bfs(index+1, copy);
    }
}

int main() {

    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    visited.assign(n, vector<bool>(m, false));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            if (arr[i][j]>0 && arr[i][j]<6) {
                location.push_back({j, i});
            }
        }
    }

    bfs(0, arr);

    cout << result << '\n';
    return 0;
}