#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 8;
int n, m;
vector<int> arr;
int result[SIZE];
bool check[SIZE + 1] = {false};

void backTracing(int index) {
    if (index == m) { // 기저조건
        for (int i = 0; i < index; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    int before = -1; //전에 사용한 값
    for (int i = 0; i < n; i++) {
        if (!check[i] && arr[i] != before) { // 직전 수열의 마지막 항만 다른지 확인 하면 중복 수열 제거 가능
            result[index] = arr[i];
            before = arr[i];
            check[i] = true;
            backTracing(index + 1);
            check[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    backTracing(0);
}