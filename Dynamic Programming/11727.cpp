#include <iostream>

using namespace std;

int dp[1000];

int tileDp(int n) {
    dp[0] = 1;
    dp[1] = 3;
    for (int i = 2; i < n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }
    return dp[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;

    // 입력
    cin >> n;
    cout << tileDp(n);

    return 0;
}