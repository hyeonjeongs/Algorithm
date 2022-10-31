/*
 * N-Queen 다른 방식(2)
 */
#include <iostream>

using namespace std;
const int SIZE = 15;

int n, result = 0;
int check[SIZE];

bool promising(int num) {
    int col = 0;
    while (col < num) { // 같은 열 전까지만 진행
        // 두 행과 열의 차가 같은 경우 기울기 절대값이 1이라는 것이므로 같은 대각선 상에 있음
        if (check[col] == check[num] || abs(check[col] - check[num]) == (num - col)) // 같은 행, 같은 대각선인 경우 체크
            return false;
        col++;
    }
    return true;
}

void backTracking(int cnt) {
    if (cnt == n) {
        result++;
        return;
    }

    for (int i = 0; i < n; i++) {
        check[cnt] = i; //i행 cnt열에 배치하기
        if (promising(cnt)) { // 현재 놓인 퀸이 가능성 있는건지 체크
            backTracking(cnt + 1);
        }
    }
}

int main() {
    cin >> n;

    backTracking(0);
    cout << result;

    return 0;
}
