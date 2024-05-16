#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> spin(n + 2, vector<int>(n + 2, 0)); // 경계 포함 배열
    int x = 0, y = 1; // 시작 위치 변경
    int result[2] = {0, 0}; // 결과 배열 크기 정의

    // 배열 경계 설정
    for (int i = 0; i <= n + 1; ++i) {
        spin[0][i] = spin[n + 1][i] = spin[i][0] = spin[i][n + 1] = -1;
    }

    int num = n * n;
    int dir = 0; // 방향 인덱스
    while (num >= 1) {
        if (spin[y][x] == 0) {
            spin[y][x] = num; // 숫자 할당
            if (num == k) {
                result[0] = y; // k가 위치한 y좌표 저장
                result[1] = x; // k가 위치한 x좌표 저장
            }
            --num; // 숫자 감소
        }

        // 다음 위치 계산
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 경계 또는 이미 숫자가 할당된 칸을 만나면 방향 전환
        if (spin[ny][nx] != 0) {
            dir = (dir + 1) % 4;
        } else {
            x = nx;
            y = ny;
        }
    }

    // 결과 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << spin[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << result[0] << ' ' << result[1] << '\n';

    return 0;
}
