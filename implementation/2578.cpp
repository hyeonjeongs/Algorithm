#include<iostream>
#include <vector>

using namespace std;

vector<int> lines(13, 0);
int row;
int col;
void findLocation(int num, vector<vector<int>> &bingo){

    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            if(bingo[i][j] == num){
                row = i;
                col = j;
                return;
            }
        }
    }
}

int lineCheck(vector<vector<int>> &check) {
    int row_num = 0, col_num = 0, right_num = 0, left_num = 0;
    int cnt=0;

    check[row][col] = 1;

    for (int i = 1; i <= 5; i++) {
        if (check[row][i]) {
            row_num++;
        }

        if (check[i][col]) {
            col_num++;
        }

        if (row + col == 6 && check[i][6 - i]) { // 왼쪽 대각선 체크
            left_num++;
        }

        if (row - col == 0 && check[i][i]) { // 오른쪽 대각선 체크
            right_num++;
        }
    }

    if (col_num == 5 && lines[col + 5] == 0)
        lines[col + 5] = 1;
    if (row_num == 5 && lines[row] == 0)
        lines[row] = 1;
    if (left_num == 5 && lines[11] == 0) // 왼쪽 대각선
        lines[11] = 1;
    if (right_num == 5 && lines[12] == 0) // 오른쪽 대각선
        lines[12] = 1;

    for(int i=1; i<=12; i++){
        if(lines[i] ==1){
            cnt++;
        }

    }

    if(cnt>=3){
        return 1;
    }
    return 0;
}

int main() {
    vector<vector<int>> bingo(6, vector<int>(6, 0));
    vector<vector<int>> check(6, vector<int>(6, 0));

    // 빙고 숫자 채워 넣기
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> bingo[i][j];
        }
    }

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            int input;
            cin >> input;
            findLocation(input, bingo);
            if(lineCheck(check)){
                cout<< (i-1)*5 +j;
                return 0;
            }
        }
    }

    return 0;
}