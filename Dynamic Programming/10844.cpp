#include <iostream>
#include <vector>
const int MOD = 1e9;
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<vector<int>> dp(n+1, vector<int>(10,0));

    for(int i=1; i<=9; i++) {
        dp[1][i] = 1;
    }

    for(int i=2; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            if(j==0) {
                dp[i][j] = dp[i-1][j+1]%MOD;
                continue;
            }

            if(j==9) {
                dp[i][j] = dp[i-1][j-1]%MOD;
                continue;
            }
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%MOD;
        }
    }

    int result =0;
    for(int i=0; i<=9; i++) {
        result = (result + dp[n][i])%MOD;
    }

    cout<< result <<'\n';

    return 0;
}