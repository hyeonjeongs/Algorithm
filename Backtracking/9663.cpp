#include <iostream>

using namespace std;

const int SIZE = 15;

int n, ans;
bool check_col[SIZE]; //열 체크
bool check_left[SIZE * 2]; //좌하향 대각선 체크
bool check_right[SIZE * 2]; //우하향 대각선 체크

void backtracking(int row) { //row: 행
    if (row == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!check_col[i] && !check_left[row + i] && !check_right[row - i + n]) {
            check_col[i] = true;
            check_left[row + i] = true;
            check_right[row - i + n] = true;
            backtracking(row + 1);
            //원래 상태로 돌려줘야함
            check_col[i] = false;
            check_left[row + i] = false;
            check_right[row - i + n] = false;
        }
    }

}


int main() {
    //입력
    cin >> n;

    //연산
    backtracking(0);

    //출력
    cout << ans << '\n';

    return 0;
}
