#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 64; //체스판 칸 개수


int chessChange(int row, int col, vector<vector<char>> &board) {
    int b_cnt = 0; //B로 시작하는 체스판 만들기 위한 카운트

    for (int i = 0; i < 8; i++) { //행 변화값
        for (int j = 0; j < 8; j++) { //열 변화값

            if ((i + j) % 2 == 0 && board[row + i][col + j] != 'B')
                b_cnt++;

            else if ((i + j) % 2 && board[row + i][col + j] != 'W')
                b_cnt++;

        }
    }

    //최솟값 리턴
    if (b_cnt > SIZE / 2)
        return SIZE - b_cnt;
    return b_cnt;
}

int main() {
    int n, m;
    int ans = SIZE + 1;

    //입력
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m)); //행: n, 열: m
    for (int i = 0; i < n; i++) //보드 입력
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    //연산
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int cnt = chessChange(i, j, board);//시작인덱스가 (i,j)인 체스판 만드는 최솟값
            ans = min(ans, cnt); 
        }
    }

    //출력
    cout << ans << '\n';

    return 0;
}