#include <string>
#include <vector>

using namespace std;

int pairName(int n) {
    vector<int> dp(n+1,0);
    int sum =0;
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3; i<=n; i++) {

        for(int j=0; j<i; j++) {
            sum += dp[j] * dp[i-j-1];
        }

        dp[i] = sum;
        sum = 0;
    }
    return dp[n];
}

int solution(int n) {
    int answer = 0;
    answer = pairName(n);
    return answer;
}