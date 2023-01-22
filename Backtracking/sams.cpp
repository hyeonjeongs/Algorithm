#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0}; //하 상 좌 우
vector<vector<char>> arr;
vector<bool> isExisted;

int r, c;

void backTracking(int y, int x) {

    if(isExisted[int(arr[y][x])-65]==0){
        isExisted[int(arr[y][x]) - 65] = 1;
    }

    int i;
    for (i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= c || ny < 0 || ny >= r)
            continue;
        if(isExisted[int(arr[ny][nx])-65] == 0){
            backTracking(ny, nx);
        }

    }

    // 하 상 좌 우 - 모두 있는 경우 return
    if(i==4 || y>=r || x>=c){
        return;
    }


}

int main() {
    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {

        cin >> r >> c;

        arr.assign(r, vector<char>(c, ' '));
        isExisted.assign(26, 0);
        int num=0;

        // 입력 받기
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cin >> arr[j][k];
            }
        }

        backTracking(0, 0);
        for(int a=0; a<26; a++){
            if(isExisted[a]==1){
                num++;
            }
        }
        cout<<"#"<<i+1<<" "<<num<<'\n';
    }

}