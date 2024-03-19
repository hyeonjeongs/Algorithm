#include <string>
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;

int insertN(int N, int  k) {
    int result = N;
    for(int i=1; i<=k; i++) {
        result = result* 10 + N;
    }
    return result;
}

int solution(int N, int number) {
    int answer = 0;
    vector<unordered_set<int>> dp(8);

    if(N==number) {
        return 1;
    }

    dp[0].insert(N);
    for(int k=1; k<8; k++) {

        dp[k].insert(insertN(N, k));

        for(int p=0; p<k; p++) {
            for(int i : dp[p]) {
                for(int j : dp[k-p-1]) {  // 여기 index 가 헤깔림
                    dp[k].insert(i+j);
                    dp[k].insert(i*j);
                    if(i>j) {
                        dp[k].insert(i-j);
                    }
                    if(j !=0) {
                        dp[k].insert(i/j);
                    }

                }
            }
        }
        if(dp[k].find(number) != dp[k].end()) {
            return k+1;
        }
    }



    return -1;
}