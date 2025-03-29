#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

typedef pair<int, int> pi;
vector<vector<int>> arr;
int n;
pi like_max;
pi like_loc;

bool outOfBounds(int x, int y) {
    return x<0 || x>=n || y<0 || y>=n;
}

void bfs(int a, int b, int c, int d, int current) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j]>0) {
                continue;
            }

            int empties=0, likes =0;
            for(int k=0; k<4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if(outOfBounds(nx, ny)) {
                    continue;
                }
                if(arr[ny][nx] == 0) {
                    empties++;
                }else if(arr[ny][nx]==a || arr[ny][nx]==b || arr[ny][nx]==c || arr[ny][nx]==d) {
                    likes++;
                }
            }
            if(like_max.first < likes) {
                like_max = pi(likes, empties);
                like_loc = pi(i, j);
            }
            else if(like_max.first == likes) {
                if(like_max.second < empties) {
                    like_max = pi(likes, empties);
                    like_loc = pi(i, j);
                }
            }
        }
    }
    arr[like_loc.first][like_loc.second] = current;
}

int satisfies(vector<vector<int>> like_node) {
    int sums =0;
    for(int i=0; i<n ;i++) {
        for(int j=0; j<n; j++) {
            int result =0;
            int nums = arr[i][j];

            for(int k=0; k<4; k++) { // 상하좌우에 있는 값이랑 비교
                int nx = j + dx[k];
                int ny = i + dy[k];

                if(outOfBounds(nx, ny)) {
                    continue;
                }

                for(int l=0; l<4; l++) {// 저장된 인접한애랑 비교
                    if(arr[ny][nx] == like_node[nums][l]) {
                        result++;
                        break;
                    }
                }

            }
            if(result!=0) {
                sums += pow(10, result-1);
            }
        }
    }
    return sums;
}
int main() {

    cin >> n;

    arr.assign(n, vector<int>(n, 0));
    vector<vector<int>> like_nodes(401, vector<int>(4,0));

    for(int i=0; i<n*n; i++) {
        int current, a, b, c, d;
        cin >>current >> a >> b>>c >>d;
        like_nodes[current] = {a,b,c,d};
        like_max = pi(-1,-1);
        bfs(a, b, c, d, current);
    }

    cout << satisfies(like_nodes);

    return 0;
}