    #include <iostream>
    #include <vector>
    const int NUM = 10007;
    using namespace std;


    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n;
        cin >> n;
        vector<vector<int>> dp;

        dp.assign(n+1,vector<int>(10, 0));
        for(int i=0; i<=9; i++) {
            dp[1][i] = 1;
        }

        for(int i=2; i<=n; i++) {
            for(int j=0; j<10; j++) {
                if(j==0) {
                    dp[i][j] = 1;
                }
                dp[i][j] = (dp[i][j-1] + dp[i-1][j])%NUM;
            }
        }

        int result = 0;
        for(int i=0; i<=9; i++) {
            result += dp[n][i];
        }
        cout<< result%NUM;
        return 0;
    }