#include <string>
#include <vector>

using namespace std;
long long maxs = -1e6;
void calcMax(vector<int> sequence, int start) {
    vector<long long> dp(sequence.size(), 0);
    dp[0] = sequence[0]*start;
    start *= -1;
    for(int i=1; i<sequence.size(); i++) {
        long long num = sequence[i] * start;
        start *=-1;
        dp[i] = max(num, dp[i-1] + num);
    }
    for(int i=0; i<dp.size(); i++) {
        maxs = max(maxs, dp[i]);
    }
}
long long solution(vector<int> sequence) {
    long long answer = 0;


    calcMax(sequence, 1);
    calcMax(sequence, -1);

    answer = maxs;
    return answer;
}