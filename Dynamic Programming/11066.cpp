# include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
int sum[501], file[501], dp[501][501];

int main() {
    int t, k;
    cin >> t;

    while (t--) {
        cin >> k;

        sum[0] = 0;
        for (int i=1; i<=k ;i++) {
            int num;
            cin >> file[i];
            sum[i] = sum[i-1] + file[i];
        }

        for (int i=1; i<=k; i++) {
            for (int j=1; j<=k-i; j++) {
                dp[j][j+i] = INF;
                for (int l=j; l< i+j; l++) {
                    dp[j][i+j] = min(dp[j][i+j], sum[i+j]-sum[j-1] + dp[j][l] + dp[l+1][j+i]);
                }
            }
        }

        cout << dp[1][k]<< '\n';
    }
    return 0;
}