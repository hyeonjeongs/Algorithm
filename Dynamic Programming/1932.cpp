#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int maxSum(vector<vector<int>> rec, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[0][0] = rec[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) {
                dp[i][j] = rec[i][j] + dp[i - 1][j];
            } else if (j == i) {
                dp[i][j] = rec[i][j] + dp[i - 1][j - 1];
            } else {
                dp[i][j] = rec[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }
    sort(dp[n - 1].begin(), dp[n - 1].end(), greater<>());

    return dp[n - 1][0];
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> rec(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> rec[i][j];
        }
    }

    cout << maxSum(rec, n) << '\n';

    return 0;
}