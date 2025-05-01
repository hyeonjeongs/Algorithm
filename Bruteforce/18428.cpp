#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int n;

bool isPossible = false;
bool outOfBounds(int x, int y) {
    return x<0 || x>=n || y<0 || y>=n;
}
bool checkIndex(vector<vector<char>> board) {

    for(int i=0; i<n; i++) {
        for(int j=0; j<n;j++) {
            if(board[i][j] == 'T') {

                for(int k=0; k<4; k++) {
                    int cx = j;
                    int cy = i;
                    bool isStudents = false;
                    while(true) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if(outOfBounds(nx, ny) || board[ny][nx]=='O') {
                            break;
                        }
                        if(board[ny][nx]== 'S') {
                            isStudents = true;
                            break;
                        }
                        cx = nx; cy = ny;
                    }
                    if(isStudents) {
                        return false;
                    }
                }

            }
        }
    }

    return true;
}

void dfsBoard(int r, int c, vector<vector<char>> board, int cnt) {
    if(isPossible) {
        return;
    }
    if(cnt == 3) {

        if(checkIndex(board)) {
            isPossible = true;
        }
        return;
    }
    for(int i=r;i <n; i++) {
        for(int j=(i==r ? c : 0); j<n; j++) {
            if(board[i][j]== 'X') {
                board[i][j] = 'O';
                dfsBoard(i, j, board, cnt + 1);
                board[i][j] = 'X';
            }
        }
    }
}
int main() {
    string result = "YES";
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, ' '));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }
    dfsBoard(0,0, board, 0);

    if(!isPossible) {
        result = "NO";
    }
    cout << result <<'\n';

    return 0;
}