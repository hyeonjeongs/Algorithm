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
void dfs(int y, int x,vector<vector<int>> checked) {

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

                int cnt =0;
                for(int k=1; k<=9; k++) {
                    if(!visited[k]) {
                        cnt++;
                        checked[i][j] = k;
                        dfs(i, j, checked);

                    }
                }
                if(cnt==0){ // 처음에 여기 안해서  무한반복 됨
                    return;
                }

            }
        }
    }
}

int main() {
    arr.assign(9, vector<int>(9,0));

    for(int i=0; i<9; i++) {
        string input;
        cin >> input;
        for(int j=0; j<9; j++) {
            arr[i][j] = input[j] - '0';
        }
    }

    vector<vector<int>> checked(9, vector<int> (9,0));
    checked = arr;

    dfs(0,0,checked);


    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << result[i][j];
        }
        cout <<'\n';
    }
    return 0;
}