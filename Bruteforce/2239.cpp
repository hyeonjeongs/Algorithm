#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> result;
bool current = false;
vector<bool> checkPossible(int y, int x, vector<vector<int>> checked) {
    vector<bool> visited(10, false);
    // 행, 열 비교
    for(int i=0; i<9; i++) {
        visited[checked[i][x]] = true;
        visited[checked[y][i]] = true;
    }

    // 9개 숫자 비교
    int cx = x - x%3;
    int cy = y - y%3;
    for(int i=cy; i<3+cy; i++) {
        for(int j=cx; j<3+cx; j++) {
            visited[checked[i][j]] = true;
        }
    }
    return visited;
}
void dfs(vector<vector<int>> checked) {

    if(current) {
        return;
    }
    int count = 0;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(checked[i][j]==0) {
                count++;
            }
        }
    }
    if(count==0) {
        result = checked;
        current = true;
        return;
    }

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(checked[i][j]==0) {

                vector<bool> visited = checkPossible(i, j, checked);
                for(int k=1; k<=9; k++) {
                    if(!visited[k]) {
                        checked[i][j] = k;
                        dfs(checked);
                    }
                }
            }
        }
    }
}

int main() {
    arr.assign(9, vector<int>(9,0));

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    vector<vector<int>> checked = arr;

    dfs(checked);


    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << result[i][j];
        }
        cout <<'\n';
    }
    return 0;
}