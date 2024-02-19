#include <iostream>
#include <vector>

using namespace std;


int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector<vector<int>> high;
int num=0; // 전체 몇개의 빙산이 있는지
int year = 0; // 몇년이 지났는지
int n, m;
vector<vector<bool>> visited;
vector<vector<int>> melt_minus;
int current=0;
void dfs(int x, int y) {
    for(int i=0; i<4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x>0 && new_x<m-1 && new_y <n-1 && new_y>0 && high[new_y][new_x]>0 && !visited[new_y][new_x]){
            visited[new_y][new_x] = true;
            current++;
            dfs(new_x, new_y);
        }
    }
}

void meltIce(int x, int y) {
    int cnt =0;
    visited[y][x] = true;
    for(int i=0; i<4; i++) {
        int new_x = x+dx[i];
        int new_y = y+dy[i];
        if(high[new_y][new_x]==0) {
            cnt++;
        }
    }
    if(high[y][x] <= cnt) {
        melt_minus[y][x] = high[y][x];
        num--;
        return;
    }
    melt_minus[y][x] = cnt;
}


int main() {
    cin>>n>>m;
    high.assign(n, vector<int>(m,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>> high[i][j];
            if(high[i][j] != 0){
                num++;
            }
        }
    }

    int result=0;
    while(1){
        if(num ==0 || result>=2) {
            break;
        }
        // 덩어리 몇개인지 확인
        visited.assign(n, vector<bool>(m, false));
        result = 0;
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(high[i][j] <=0 || visited[i][j]){
                    continue;
                }
                visited[i][j] = true;
                result++;
                dfs(j, i);
            }
        }

        if(result>=2) {
            break;
        }

        // 녹이기
        visited.assign(n, vector<bool>(m, false));
        melt_minus.assign(n, vector<int>(m,0));
        for(int i=1; i<n-1; i++) {
            for(int j=1; j<m-1; j++) {
                if(high[i][j] <=0 || visited[i][j]){
                    continue;
                }
                meltIce(j, i);
                if(num ==0) {
                    break;
                }
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++) {
                high[i][j] -= melt_minus[i][j];
            }
        }
        year++;
    }

    if(num==0 && result<2) {
        year = 0;
    }

    cout <<year<<'\n';
    return 0;
}