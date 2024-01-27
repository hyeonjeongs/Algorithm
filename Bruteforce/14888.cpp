#include <iostream>
#include <vector>
#include <algorithm>
// TOHAVE

using namespace std;
int n;
int my_max = -(1e9 + 1);
int my_min = 1e9 + 1;
vector<int> operation(4);
vector<int> num(11);


int calculation(int a, int b, int c) {
    switch (c) {
        case 0: //+
            return a + b;
        case 1: //-
            return a - b;
        case 2: //*
            return a * b;
        case 3: // /
            return a / b;
    }
}

void operationResult(int result, int index) {

    if (index == n) {
        my_max = max(my_max, result);
        my_min = min(my_min, result);

        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operation[i]) {
            operation[i]--;
            operationResult(calculation(result, num[index], i), index + 1);
            operation[i]++; // 원래대로 돌려주기
        }
    }


}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    // 연산자 개수
    for (int i = 0; i < 4; i++) {
        cin >> operation[i];
    }
    operationResult(num[0], 1);

    cout << my_max << '\n' << my_min << '\n';
    return 0;
}