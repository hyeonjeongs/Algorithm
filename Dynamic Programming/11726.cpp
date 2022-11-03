#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[1001];

    dp[1] = 1;
    dp[2] = 2;
    int i;

    for (i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007; // 오버플로우 발생하지 않도록 10007 나머지 저장해주기
    }

    cout << dp[n];

    return 0;
}