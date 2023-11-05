// 다시 풀어보기 (11/3)
// 헤깔린부분 : 미리 해당 값일때 만들수 있는 개수 구하고 답 구하려해서 중복되는 값이 있었음
#include <string>
#include <vector>

using namespace std;

const int divide = 1000000007;

int solve(int n, vector<int> money){

    vector<int> dp(n+1,0);
    dp[0]=1;

    for(int i=0; i<money.size(); i++){
        for(int j=money[i]; j<=n; j++) {
            dp[j] += (dp[j-money[i]])%divide;
        }
    }
    return dp[n];
}

int solution(int n, vector<int> money) {
    int answer = 0;

    answer = solve(n, money);

    return answer;
}