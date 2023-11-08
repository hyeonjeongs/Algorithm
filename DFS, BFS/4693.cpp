#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> ci;

// 상, 하, 좌, 우, 좌상향, 좌하향, 우상향, 우하향
int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int w = 1, h = 1;

void bfs(vector<vector<int>> &island, int row, int col){
    queue<ci> q;

    q.push(ci(row, col));
    island[row][col] = 0; //방문 체크

    while(!q.empty()){
        int current_row = q.front().first;
        int current_col = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int next_row = current_row + dy[i];
            int next_col = current_col + dx[i];
            if(next_col>=0 && next_col<w && next_row >=0 && next_row < h && island[next_row][next_col]){
                island[next_row][next_col] = 0;
                q.push(ci(next_row, next_col));
            }
        }
    }
}

int main() {
    while (1) {
        cin >> w >> h;
        if(w==0 && h==0){
            break;
        }
        vector<vector<int>> island(h, vector<int>(w,0));

        // 입력, 출력
        for(int i =0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> island[i][j];
            }
        }
        // 연산
        int ans =0;
        for(int i =0; i<h; i++){
            for(int j=0; j<w; j++){
                if(island[i][j] == 1){
                    bfs(island, i, j);
                    ans++; // 섬의 개수 증가
                }
            }
        }

        cout<< ans<< '\n';
    }

    return 0;
}