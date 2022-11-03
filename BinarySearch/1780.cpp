#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int result[3];
int paper[2187][2187];

bool isSameNum(int x, int y, int n) {
    int check = paper[x][y];
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (paper[i][j] != check) {
                return false;
            }
        }
    }

    return true;
}

void checkPaper(int x, int y, int n) {
    if (isSameNum(x, y, n)) {
        int samePaperNum = paper[x][y];
        result[samePaperNum + 1]++;
        return;
    }
    else {
        for (int i = x; i < x + n; i += n / 3)
            for (int j = y; j < y + n; j += n / 3) {
                checkPaper(i, j, n / 3);
            }
    }
}

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    checkPaper(0, 0, n);

    for (int i = 0; i < 3; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}