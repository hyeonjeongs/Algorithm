#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e9;

int main(){
    int n, k;

    cin>> n>>k;
    vector<vector<int>> dp(n+1, vector<int>(k+1,0));

    for(int i=1; i<=k; i++){
        dp[1][i] = i;
    }


    for(int i=2; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%SIZE;
        }
    }

    cout<< dp[n][k] << '\n';

    return 0;
}