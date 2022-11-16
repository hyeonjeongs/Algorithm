#include <iostream>
#include <vector>

using namespace std;
int array_a[51][51];
int array_b[51][51];
void changeNum(int i, int j) {
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            array_a[i + k][j + l] = (array_a[i + k][j + l] + 1) % 2;
        }
    }
}

int changeArray(int n, int m) {
    int cnt = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (array_a[i][j] != array_b[i][j]) {
                changeNum(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n, m;
    int cnt;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char num;
            cin >> num;
            array_a[i][j] = num - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char num;
            cin>> num;
            array_b[i][j] = num - '0';
        }
    }

    cnt = changeArray(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array_a[i][j] != array_b[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << cnt;

    return 0;
}
