#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

// 파이어스톰이랑 비슷
using namespace std;

vector<vector<int>> ice;
vector<vector<bool>> visited;
int sizes; // 행, 열 개수
int n, q; // n: 회전 가능 레벨, q : 회전 횟수
int cnt =0;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

void turnIce(int y, int x, int num) {
    vector<vector<int>> temp(num, vector<int>(num, 0));
    for(int i=0; i<num; i++) {
        for(int j=0; j<num; j++) {
            temp[i][j] = ice[y+ num-i-1][x + j]; // 여기서 실수 (ice에서 i, j 반대로 씀)
            // temp[j][sizes-i-1] = a[i+y][j+x]; // 이것도 가능
        }
    }

    for(int i=0; i<num; i++) {
        for(int j=0; j<num; j++) {
            ice[i+y][j+x] = temp[i][j];
        }
    }
}

void divideIce(int level) {
    int divide = pow(2, level);

    for(int i=0; i<sizes; i+=divide) {
        for(int j=0; j<sizes; j+=divide) {
            turnIce(i, j, divide);
        }
    }

}

void meltIce() {
    vector<pair<int,int>> melts;
    for(int i=0; i< sizes; i++) {
        for(int j=0; j<sizes; j++) {
            if(ice[i][j]<=0){
                continue;
            }
            int count=0;
            for(int k=0; k<4; k++){
                int nx = j + dx[k];
                int ny = i + dy[k];
                if(nx<0 || ny<0 || nx>=sizes || ny>=sizes) {
                    continue;
                }
                if(ice[ny][nx]>0) {
                    count++;
                }
            }
            if(count<3) {
                melts.push_back({i, j});
            }
        }
    }

    for(int i=0; i<melts.size(); i++) {
        ice[melts[i].first][melts[i].second]--;
    }
}

void dfs(int x, int y) {

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0 || nx>=sizes || ny>=sizes || visited[ny][nx]) {
            continue;
        }
        if(ice[ny][nx]>0) {
            cnt++;
            visited[ny][nx] = true;
            dfs(nx, ny);
        }
    }

}

int main() {
    int max_group = 0; // 가장 큰 그룹 크기
    int remain_ice=0; // 총 남아있는 얼음양
    cin >> n>> q;
    sizes = pow(2,n);

    ice.assign(sizes, vector<int>(sizes, 0));
    visited.assign(sizes, vector<bool>(sizes, false));
    vector<int> turnLevel(q,0);

    int result = 0;
    for(int i=0; i<sizes; i++) { // 얼음 양
        for(int j=0; j<sizes; j++) {
            cin >> ice[i][j];
            result += ice[i][j];
        }
    }

    for(int i=0; i<q; i++) { // level 수
        cin >> turnLevel[i];
    }

    for(int i=0; i<q; i++) {
        if(turnLevel[i]>=1) { // 틀린 부분 : 여기서 예외처리하려고 divideIce 만 막아야하는데 melt도 못하게함
            divideIce(turnLevel[i]);
        }
        meltIce();
    }

    for(int i=0; i<sizes; i++) {
        for(int j=0; j<sizes; j++) {
            if(!visited[i][j] && ice[i][j]>0){
                visited[i][j] = true;
                cnt=1;
                dfs(j, i);
                max_group = max(max_group, cnt);
            }
            remain_ice += ice[i][j];
        }
    }

    cout << remain_ice <<'\n';
    cout << max_group <<'\n';

    return 0;
}