#include<iostream>
#include<vector>

using namespace std;
const int SIZE = 8;

int n, m;
vector<int> num(SIZE);

void backTracking(int index, int start) {
    if (index == m) {
        for (int i = 0; i < m; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++) {
        num[index] = i;
        backTracking(index + 1, i + 1); //다음 인덱스 호출
    }
}

int main() {
    cin >> n >> m;
    backTracking(0, 1);

    return 0;
}